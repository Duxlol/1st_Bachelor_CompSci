 .globl main

.data

.text

main:
    # add code here ...

exit:
    # syscall to end the program
    li $v0, 10    
    syscall
