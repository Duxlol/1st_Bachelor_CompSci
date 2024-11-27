.globl main
	.data
amountOfRows:    .word 16  # The mount of rows of pixels
amountOfColumns: .word 32  # The mount of columns of pixels

promptRows: .asciiz "Please enter the row number:\n"
promptCols: .asciiz "Please enter the column number:\n"

offset: .word 128
msgShowMemoryAddress: .asciiz "The memory address for the pixel is:\n"
	.text
main:
	# rijnummer
	la $a0, promptRows  	# ask user for the row number
	li $v0, 4		# syscall print string
    	syscall			# syscall print string
	li $v0, 5 		# syscall read int
	syscall			# syscall read int
	move $t0, $v0 		# move rownumber to t0
	
	# kolomnummer
	la $a0, promptCols 	# ask user for the column number
	li $v0, 4		# syscall print string
    	syscall 		# syscall print string
	li $v0, 5		# syscall read int
	syscall			# syscall read int
	move $t1, $v0		# move collumn number to t1
		
	
	
	lw $t3, 0($s0) # rij * offset1
	mul $t3, $t0, 4 
	# colums + offset2
	# mul $t4, $t1, 4
	lw $s4, 4($t1)
	
	# (rij * offset) + (colums + offset)
	addi $t5, $s4, $s3
	
	# print result
	#la $t5, $gp
	#li $v0, 4
	#syscall
	
	
	
	