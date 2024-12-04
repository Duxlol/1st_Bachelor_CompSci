.globl main

.data
mazeFilename:    .asciiz "input_1.txt"
buffer:          .space 4096
victoryMessage:  .asciiz "You have won the game!"

amountOfRows:    .word 16  # The number of rows of pixels
amountOfColumns: .word 32  # The number of columns of pixels

wallColor:      .word 0x004286F4    # Color used for walls (blue)
passageColor:   .word 0x00000000    # Color used for passages (black)
playerColor:    .word 0x00FFFF00    # Color used for player (yellow)
exitColor:      .word 0x0000FF00    # Color used for exit (green)

.text

main:
    addi $sp, $sp, -24
    sw   $ra, 20($sp)
    sw   $fp, 16($sp)
    move $fp, $sp
    
    # load file
    la   $a0, mazeFilename
    jal  fileFunctions
    
    j exit  # nothing to do so go to exit

fileFunctions: 
    # open file
    li $v0, 13      # syscall file descriptor
    li $a1, 0
    li $a2, 0
    syscall
    move $s0, $v0   # save descriptor
    
    # read file
    li $v0, 14
    move $a0, $s0
    la $a1, buffer
    li $a2, 4096
    syscall
    
    # close file
    li $v0, 16      # syscall close file
    move $a0, $s0   # file descriptor to close
    syscall
    
    # process maze -> each byte to a bitmap -> store in memory
    la $t0, buffer  # la of buffer in t0
    li $t1, 0       # row counter
    li $t2, 0       # column counter
    
mazeProcessing:
    lw $t6, amountOfRows   # Load number of rows
    bge $t1, $t6, endProcessing  # If row index >= amountOfRows, end processing
    
    lb $t3, 0($t0)         # Load current character from buffer
    beqz $t3, endProcessing
    
    # Calculate memory address || $gp + ((rowindex * columns + columnindex) * 4)
    lw $t7, amountOfColumns
    
    mul $t4, $t1, $t7      # rowindex * columns
    add $t4, $t4, $t2      # + columnindex
    mul $t4, $t4, 4        # *4

    add $t4, $t4, $gp      # +gp
    
    beq $t3, 'w', makeWall  # if 'w' -> change to WALL (BLUE)
    beq $t3, 'p', makePath  # if 'p' -> change to PATH (BLACK)
    beq $t3, 's', makePlayer # if 's' -> change to PLAYER (YELLOW)
    beq $t3, 'u', makeExit  # if 'u' -> change to EXIT (GREEN)
    j skip
    
makeWall:
    la $t5, wallColor     # Load address of BLUE / WALL
    lw $t5, 0($t5)
    sw $t5, 0($t4)        # Store color into memory
    j skip
makePath:
    la $t5, passageColor  # Load address of BLACK / PATH
    lw $t5, 0($t5)
    sw $t5, 0($t4)
    j skip
makePlayer:
    la $t5, playerColor   # Load address of YELLOW / PLAYER
    lw $t5, 0($t5)
    sw $t5, 0($t4)
    j skip
makeExit:
    la $t5, exitColor     # Load address of GREEN / EXIT    
    lw $t5, 0($t5)
    sw $t5, 0($t4)
    j skip
skip:
    # Update column index and check if we should go to next row
    addi $t2, $t2, 1      # Increment column counter
    lw $t6, amountOfColumns
    bne $t2, $t6, continueMazeProcess  # If we haven't reached the last column, continue
    addi $t1, $t1, 1      # Increment row counter
    li $t2, 0             # Reset column index to 0 after going to next row
    
continueMazeProcess:
    addi $t0, $t0, 1      # Move to next byte in buffer
    j mazeProcessing

endProcessing:
    jr $ra

exit:
    # syscall to end the program
    li $v0, 10    
    syscall
