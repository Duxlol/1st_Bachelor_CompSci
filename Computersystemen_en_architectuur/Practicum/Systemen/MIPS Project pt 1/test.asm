.globl main
.data
filename1: .asciiz "test_file_1.txt"
filename2: .asciiz "test_file_2.txt"
buffer:    .space 2048
newLine:   .asciiz "\n"
errorMsg:  .asciiz "Error: Unable to open file.\n"

.text
main:
    # Set up stack frame
    addi $sp, $sp, -24
    sw   $ra, 20($sp)
    sw   $fp, 16($sp)
    move $fp, $sp
    
    # Process 1st file
    la   $a0, filename1
    jal  print_file

    # Process 2nd file
    la   $a0, filename2
    jal  print_file
    
    # Exit
    li $v0, 10
    syscall

print_file:
    # Open file
    li $v0, 13            # Syscall to open file
   
