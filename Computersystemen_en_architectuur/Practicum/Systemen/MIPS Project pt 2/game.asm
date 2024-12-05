 .globl main

.data
mazeFilename:    .asciiz "input_1.txt"
buffer:          .space 4096
victoryMessage:  .asciiz "You have won the game!"

amountOfRows:    .word 16  # The mount of rows of pixels
amountOfColumns: .word 32  # The mount of columns of pixels

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
    	
    	j exit 			# nothing to do so go to exit

fileFunctions: 
	# open file
	li $v0, 13		# syscall file descriptor
	li $a1, 0
	li $a2, 0
	syscall
	move $s0, $v0		# save descriptor
	
	# read file
	li $v0, 14
	move $a0, $s0
	la $a1, buffer
	li $a2, 4096
	syscall
	
	# close file
	li $v0, 16		# syscall close file
	move $a0, $s0		# file descriptor to close
	syscall
	
	# process maze -> each byte to a bitmap -> store in memory
	la $t0, buffer		# la of buffer in t0
	li $t1, 0		# rows counter
	li $t2, 0		# colums counter
	
mazeProcessing:
	lb $t3, 0($t0)
	beqz $t3, endProcessing
	
	# calculate mem address || $gp + ((rowindex * columns + columnindex) * 4)
	lw $t7, amountOfColumns
	
	mul $t4, $t1, $t7	# rowindex * columns
	add $t4, $t4, $t2	# +columnindex
	mul $t4, $t4, 4		# *4

	add $t4, $t4, $gp 	# +gp
	
	beq $t3, 'w', makeWall	# if w as current buffer -> change to BLUE which is a WALL
	beq $t3, 'p', makePath 	# if p -> change to BLACK which is a PATH
	beq $t3, 's', makePlayer# if s -> change to YELLOW which is PLAYER
	beq $t3, 'u', makeExit	# if u -> change to GREEN which is EXIT
	j skip
	
makeWall:
	la $t5, wallColor	# load address of BLUE / WALL
	lw $t5, 0($t5)
	sw $t5, 0($t4)		# load color into t5
	j skip
makePath:
	la $t5, passageColor	# load address of BLACK / PATH
	lw $t5, 0($t5)
	sw $t5, 0($t4)
	j skip
makePlayer:
	la $t5, playerColor	# load address of YELLOW / PLAYER
	lw $t5, 0($t5)
	sw $t5, 0($t4)
	j skip
makeExit:
	la $t5, exitColor	# load address of GREEN / EXIT	
	lw $t5, 0($t5)
	sw $t5, 0($t4)
	j skip
skip:
	# update column index and check if we should go to next row
	addi $t2, $t2, 1	# column counter =+ 1
	li $t6, 34
	#lw $t6, 0($t6)
	bne $t6, $t2, continueMazeProcess # if we're not at the last column, add 1 to buffer
	addi $t1, $t1, 1	# we're at the last column so we start processing the next row
	li $t2, 0		# set column index to 0 after going to next row
	
continueMazeProcess:
	addi $t0, $t0, 1	# add 1 to buffer to continue processing till we're at column 32
	j mazeProcessing

endProcessing:
	jr $ra

exit:
    # syscall to end the program
    li $v0, 10    
    syscall
