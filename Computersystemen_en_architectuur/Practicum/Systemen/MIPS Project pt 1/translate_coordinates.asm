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
	# row number
	la $a0, promptRows  	# ask user for the row number
	li $v0, 4		# syscall print string
    	syscall			# syscall print string
	li $v0, 5 		# syscall read int
	syscall			# syscall read int
	move $t0, $v0 		# move rownumber to t0
	
	# column number
	la $a0, promptCols 	# ask user for the column number
	li $v0, 4		# syscall print string
    	syscall 		# syscall print string
	li $v0, 5		# syscall read int
	syscall			# syscall read int
	move $t1, $v0		# move collumn number to t1
		
	# berekenen geheugenadres $gp+((row×number of columns)+column)×4
	li $t2, 32 # load amount of colums in t2
	mul $t3, $t0, $t2 # calculate rownumber offset
	add $t4, $t3, $t1 # add column number (t4 = rownumber*#colums + columnnumber)
	mul $t5, $t4, 4   # byte offset: t5 = t4 * 4
    	add $t5, $t5, $gp # add $gp
	
	# print result
	la $a0, msgShowMemoryAddress 
	li $v0, 4 # syscall print string
	syscall # syscall print string
	 
	move $a0, $t5 # move memory address to a0
	li $v0, 1 # syscall print int
	syscall # syscall print int
	
	# exit
	li $v0, 10
	syscall