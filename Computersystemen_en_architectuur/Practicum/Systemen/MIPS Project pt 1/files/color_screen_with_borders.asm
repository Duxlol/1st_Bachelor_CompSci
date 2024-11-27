.globl main

.data

amountOfRows:    .word 16  # The mount of rows of pixels
amountOfColumns: .word 32  # The mount of columns of pixels

colorRed:       .word 0x00FF0000
colorYellow:    .word 0x00FFFF00

.text

main:

    # add code here ...

exit:
    # syscall to end the program
    li $v0, 10    
    syscall
