.globl main
.data
filename1: .asciiz "test_file_1.txt"
filename2: .asciiz "test_file_2.txt"
buffer:    .space 1024
newline:   .asciiz "\n"

.text
main:

	addi $sp, $sp, -24
	sw   $ra, 20($sp)
	sw   $fp, 16($sp)
	move $fp, $sp
    	
    	# 1st file
    	la   $a0, filename1
    	jal  print_file

    	# 2nd file
    	la   $a0, filename2
    	jal  print_file

print_file:
	move $t0, $a0
    
	# open
	move $a0, $t0
	li   $a1, 0
	li   $v0, 13         # syscall file descriptor
	syscall
	
	move $s0, $v0        # save descriptor ?

	# read file
	move $a0, $s0        # File descriptor
	# ... still have to make this
	syscall

	# print file
	li   $v0, 4          # print string
	la   $a0, buffer     # load buffer
	syscall

	# print newline

	# close file

	    
exit:
	move $sp, $fp
	lw   $fp, 16($sp)
	lw   $ra, 20($sp)
	addi $sp, $sp, 24

	# syscall to end the program
	li $v0, 10    
	syscall