 .globl main

.data
filename1: .asciiz "test_file_1.txt"
filename2: .asciiz "test_file_2.txt"

.text

main:

     # add code here ...

exit:
    # syscall to end the program
    li $v0, 10    
    syscall
