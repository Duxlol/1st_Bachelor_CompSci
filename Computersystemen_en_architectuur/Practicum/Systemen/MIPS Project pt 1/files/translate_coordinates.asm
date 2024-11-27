.globl main

.data

amountOfRows:    .word 16  # The mount of rows of pixels
amountOfColumns: .word 32  # The mount of columns of pixels

promptRows: .asciiz "Please enter the row number:\n"
promptCols: .asciiz "Please enter the column number:\n"

msgShowMemoryAddress: .asciiz "The memory address for the pixel is:\n"

.text

main:

    li $v0, 4		# print string
    la $a0, promptRows  # message to ask the user for the row number
    syscall
    
    li $v0, 5  # read integer
    syscall    # ask the user for a row number
    
    # add code here ...

exit:

    li $v0, 10  # syscall to end the program
    syscall
