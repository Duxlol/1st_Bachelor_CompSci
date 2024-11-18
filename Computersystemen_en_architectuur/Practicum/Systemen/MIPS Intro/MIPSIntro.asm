	.data
begin_message:	.asciiz "This is my "
back_message: 	.asciiz "-th MIPS-program"
	.text
main:
	# get int input from user
	li $v0, 5 # syscall code for int
	syscall
	move $t0, $v0
	
	# print beginning msg
	la $a0, begin_message
	li $v0, 4
	syscall
	
	# print int
	move $a0, $t0
	li $v0, 1
	syscall
	
	# print back msg
	la $a0, back_message
	li $v0, 4
	syscall
exit:
	li $v0, 10
	syscall