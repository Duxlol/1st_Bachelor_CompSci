	.data
newLine: .asciiz "\n"
	.text
main:
	li $t0,  1 # loop counter
	
	# reading of the user input int
	li $v0, 5 # read int
	syscall
	move $t1, $v0 # move int value to temp register
loop:
	# loop till i >= n
	bgt  $t0, $t1, exit
	
	# print i
	li $v0, 1
	move $a0, $t0 # value of i from temp to function argument
	syscall
	
	# print newline
	li $v0, 4
	la $a0, newLine
	syscall
	
	# increment i
	addi $t0, $t0, 1
	
	j loop
exit:
	li $v0, 10
	syscall
	