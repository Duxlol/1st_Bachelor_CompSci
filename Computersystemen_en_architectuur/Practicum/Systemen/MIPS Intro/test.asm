	.data
prime: .asciiz "--Prime--"
noPrime: .asciiz "-No Prime--"

	.text
main:	# read given int to check if it's a prime
	li $v0, 5
	syscall
	move $a0, $v0
	
	j printPrime
	

printPrime:	
	la $a0, prime
	li $v0, 4
	syscall
	j exit

exit:
	li $v0, 10
	syscall