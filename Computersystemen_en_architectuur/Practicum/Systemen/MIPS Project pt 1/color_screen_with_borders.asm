.globl main

.data
amountOfRows:    .word 16		# The mount of rows of pixels
amountOfColumns: .word 32		# The mount of columns of pixels

colorRed:       .word 0x00FF0000
colorYellow:    .word 0x00FFFF00

.text

main:
	# Load data
	lw $t0, colorRed
	lw $t1, colorYellow
	lw $t2, amountOfColumns
	lw $t3, amountOfRows

	mul $t4, $t2, $t3		# total # of pixels
	li $t5, 0			# pixel index to 0
    
    
fillRed:
	mul $t6, $t5, 4			# pixel offset
	add $t6, $t6, $gp		# add gp to offset
	sw $t0, ($t6)			# set calculated memory address to red
	addi $t5, $t5, 1		# increment pixel index
	blt $t5, $t4, fillRed		# color every pixel red untill we reach all pixels
	
	# color rows
	li $t7, 0			# index for top row
	jal colorRow			# function to color the row
	subi $t7, $t3, 1		# index for bottom row || row 16 but goes from 0-15 so -1
	jal colorRow			# function to color the row
	
	# color colums
	li $t7, 0			# index for left colum
	jal colorColumn			# function to color the column
	subi $t7, $t2, 1		# index for right column
	jal colorColumn			# function to color the column
	j exit
	
colorRow:
	li $t8, 0			# row index
rowLoop:
	# $gp + (rowindex * columns + columnindex) * 4
	mul $t9, $t7, $t2 		# rowindex * columns
	add $t9, $t9, $t8		# +columnindex
	mul $t9, $t9, 4			# *4
	add $t9, $t9, $gp		# +gp
	sw $t1, ($t9)			# make calculated address yellow
	addi $t8, $t8, 1		# increment index
	blt $t8, $t2, rowLoop
	jr $ra
colorColumn:
	li $t8, 0			# column index
columnLoop:
	# $gp + (rowindex * columns + columnindex) * 4
	mul $t9, $t8, $t2 		# rowindex * columns
	add $t9, $t9, $t7		# +columnindex
	mul $t9, $t9, 4			# *4
	add $t9, $t9, $gp		# +gp
	sw $t1, ($t9)			# make calculated address yellow
	addi $t8, $t8, 1		# increment index
	blt $t8, $t2, columnLoop
	jr $ra
	
	
exit:
    li $v0, 10    
    syscall
    
##### COLORING OF SPECIFIC PIXEL #####
