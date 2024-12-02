.globl main
.data
filename1: .asciiz "test_file_1.txt"
filename2: .asciiz "test_file_2.txt"
buffer:    .space 2048
newLine:   .asciiz "\n"

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
    	
    	j exit

print_file:    
	# open file
	li $v0, 13         # syscall file descriptor
	li $a1, 0
	li $a2, 0
	syscall
	move $s0, $v0        # save descriptor

	# read file
	li $v0, 14
	move $a0, $s0
	la $a1, buffer
	li $a2, 2048
	syscall

	# print file
	li $v0, 4
	la $a0, buffer
	syscall

	# print newline
	la $a0, newLine
	li $v0, 4
	syscall
	
	# close file
	li $v0, 16		# syscall close file
	move $a0, $s0		# file descriptor to close
	syscall
	
	jr $ra

	    
exit:
	move $sp, $fp
	lw   $fp, 16($sp)
	lw   $ra, 20($sp)
	addi $sp, $sp, 24

	# syscall to end the program
	li $v0, 10    
	syscall
