	.data
	
a:	.word 0
jumpTbl: 
	.word case0, case1, case2, default

	.text
main:
	# user input n
	li $v0, 5
	syscall
	move $t0, $v0 # t0 == input n
	
	la $t1, jumpTbl # load addres of jumptbl into t1
	
	# check if n (t0) is within range of cases
	bge $t0, 3, default # jump to default if >= 3
	blt $t0, 0, default # jump to default if negative n < 0
	sll $t0, $t0, 2 # multiply with 4 to find the right offset || *note to self (n=0 => 0*4=0 => case0)
	add $t1, $t1, $t0 # add offset to the address in the jumptbl
	
	lw $t1, 0($t1) # loads value stored in t1 || *(there is an address of the location in it right now)
	jr $t1 # jump to right offset || *(t1 contains actual target address now)
	
case0:
	# a=9
	li $t2, 9
	sw $t2, a
	j printAndExit # jump to printAndExit
case1:	
	# a=6
	li $t2, 6
	sw $t2, a
	j case2 # no break so we go to next case

case2:
	# a=8
	li $t2, 8
	sw $t2, a
	j printAndExit # jump to printAndExit

default:
	# if none of the cases matched, a=7
	li $t2, 7
	sw $t2, a
	j printAndExit # jump to printAndExit
printAndExit:
	# print a
	li $v0, 1 # print integer
	lw $a0, a
	syscall
	
	# exit the program
	li $v0, 10
	syscall


	
	