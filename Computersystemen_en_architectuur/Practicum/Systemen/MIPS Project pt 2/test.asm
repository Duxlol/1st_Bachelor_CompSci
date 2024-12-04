.globl main
.data
mazeFilename:    .asciiz "D:\school\1st_Bachelor_CompSci\Computersystemen_en_architectuur\Practicum\Systemen\MIPS Project pt 2\input_1.txt"
buffer:          .space 4096
readSuccessMsg:  .asciiz "File read successfully. Buffer contents:\n"
newlineChar:     .asciiz "\n"

.text
main:
    # Open file
    li $v0, 13       
    la $a0, mazeFilename
    li $a1, 0        # Read-only mode
    li $a2, 0        # Mode (ignored)
    syscall
    
    # Check for file open error
    bltz $v0, fileOpenError
    move $s0, $v0    # Save file descriptor
    
    # Read file
    li $v0, 14
    move $a0, $s0
    la $a1, buffer
    li $a2, 4096     # Read full buffer
    syscall
    
    # Print success message
    li $v0, 4
    la $a0, readSuccessMsg
    syscall
    
    # Print buffer contents
    la $t0, buffer   # Start of buffer
    li $t1, 0        # Counter

printBufferLoop:
    # Exit condition: null terminator or reached end of read
    lb $t2, 0($t0)
    beqz $t2, endPrint
    
    # Print character
    move $a0, $t2
    li $v0, 11       # Print character syscall
    syscall
    
    # Next character
    addi $t0, $t0, 1
    addi $t1, $t1, 1
    
    # Prevent infinite loop (optional)
    li $t3, 4096
    bge $t1, $t3, endPrint
    
    j printBufferLoop

endPrint:
    # Close file
    li $v0, 16
    move $a0, $s0
    syscall
    
    j exit

fileOpenError:
    # Print error message
    li $v0, 4
    la $a0, fileOpenErrorMsg
    syscall
    
    j exit

exit:
    # Exit program
    li $v0, 10
    syscall

.data
fileOpenErrorMsg: .asciiz "Error: Could not open file\n"