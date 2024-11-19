	.data
prime: .asciiz "--Prime--"
noPrime: .asciiz "--No Prime--"

	.text
main:	# read given int to check if it's a prime
	li $v0, 5
	syscall
	move $a0, $v0
	
	li $t0, 2 # priem loop iterator beginnend bij 3
	li $t1, 1 # 1 = prime, 2 = noprime
	
	ble $a0, 1, printNoPrime # if n <= ==> printNoPrime
	beq $a0, 2, printPrime # if n = 2 ==> printPrime
	
	
checkPrime: # loop om te checken ofdat het priem is
	# define max n, t0^2
	mul $t2, $t0, $t0 # t3 = t0 * t0 = t0^2
	bgt $t2, $a0, lastCheck # if t0*t0 > iterator ==> exit
	
	div $a0, $t0
	mfhi $t3
	bne $t3, 0, increment
	
	# set prime flag to 0 because it isnt a prime
	li $t1, 2
	j lastCheck 
	
increment:
	# iterator + 1
	addi $t0, $t0, 1
	j checkPrime
lastCheck:
	beq $t1, 1, printPrime
	beq $t1, 2, printNoPrime
printPrime:	
	la $a0, prime
	li $v0, 4
	syscall
	j exit
printNoPrime:	
	la $a0, noPrime
	li $v0, 4
	syscall
	j exit
	
exit:
	li $v0, 10
	syscall