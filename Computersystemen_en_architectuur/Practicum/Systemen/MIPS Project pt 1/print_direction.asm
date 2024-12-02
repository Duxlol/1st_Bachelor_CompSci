 .globl main

.data
	up:     .asciiz "up\n"
	down:   .asciiz "down\n"
	left:   .asciiz "left\n"
	right:  .asciiz "right\n"
	invalid: .asciiz "Unknown input! Valid inputs: z s q d x\n"
.text

main:
	addi $sp, $sp, -8
	sw   $ra, 4($sp)	# save ra
	sw   $fp, 0($sp)	# save fp
	move $fp, $sp		# new fp

input:
	# waiting for kb input
	jal waitLoop
	
	# check input char in v0
	beq $v0, 122, z		# z
	beq $v0, 115, s		# s
	beq $v0, 113, q		# q
	beq $v0, 100, d		# d
	beq $v0, 120, exit	# x
	
	# if none ==> invalid
	li $v0, 4		# print string
	la $a0, invalid		# invalid msg
	syscall			# invalid msg print
	
	#2 sec delay
	li $v0, 32		# sleep syscall
	li $a0, 2000		# 2sec sleep in a0
	syscall			# sleep syscall
	
	j input

z:
	li $v0, 4 		# print string
	la $a0, up
	syscall			# print up
	#2 sec delay
	li $v0, 32		# sleep syscall
	li $a0, 2000		# 2sec sleep in a0
	syscall			# sleep syscall
	
	j input

s:
	li $v0,4 		# print string
	la $a0, down
	syscall			# print down
	#2 sec delay
	li $v0, 32		# sleep syscall
	li $a0, 2000		# 2sec sleep in a0
	syscall			# sleep syscall
	
	j input

q:
	li $v0,4 		# print string
	la $a0, left
	syscall			# print left
	#2 sec delay
	li $v0, 32		# sleep syscall
	li $a0, 2000		# 2sec sleep in a0
	syscall			# sleep syscall
	
	j input

d:
	li $v0,4 		# print string
	la $a0, right
	syscall			# print right
	#2 sec delay
	li $v0, 32		# sleep syscall
	li $a0, 2000		# 2sec sleep in a0
	syscall			# sleep syscall
	
	j input

waitLoop:
	lw   $t1, 0xffff0000	# mmio
	andi $t1, $t1, 0x01	# check if input ready
	beqz $t1, waitLoop	# wait if not ready
	lw   $v0, 0xffff0004	# read input
	jr   $ra		#return to caller

exit:
	move $sp, $fp
	lw $fp, 0($sp)
	lw $ra, 4($sp)
	addi $sp, $sp, 8
	
	li $v0, 10    
	syscall
