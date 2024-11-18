	.data
begin_message:	.asciiz "This is my "
back_message: 	.asciiz "-th MIPS-program"
	.text
main:
	# get int input from user
	li $v0, 5 # read int
	syscall
	move $t0, $v0 # moves int to temp register
	
	# print beginning msg
	la $a0, begin_message
	li $v0, 4 # print string
	syscall
	
	# print int
	move $a0, $t0 # moves temp register value to function argument
	li $v0, 1 # print int
	syscall
	
	# print back msg
	la $a0, back_message
	li $v0, 4 # print string
	syscall
exit:
	li $v0, 10
	syscall