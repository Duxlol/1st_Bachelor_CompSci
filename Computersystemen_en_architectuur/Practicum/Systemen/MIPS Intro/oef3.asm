	.data
newLine: .asciiz "\n"
space: .asciiz " "
	.text
main:
	# reading user input n
	li $v0, 5
	syscall
	move $t0, $v0
	
	# loop counter k 
	li $t1, 1
	
loop:
	bgt $t1, $t0, exit
	
	li $t2, 1 # i (begint bij 1)
	
loop2: 
	bgt $t2, $t1, loop3 # if i > k, print a newline character
	
	# print i
	li $v0, 1
	move $a0, $t2
	syscall
	
	# print space
	la $a0, space
	li $v0, 4
	syscall
	
	#increment i
	addi $t2, $t2, 1
	
	j loop2
loop3:
	# print newline
	la $a0, newLine
	li $v0, 4
	syscall
	
	# increment k
	addi $t1, $t1, 1
	
	j loop
exit:
	li $v0, 10
	syscall