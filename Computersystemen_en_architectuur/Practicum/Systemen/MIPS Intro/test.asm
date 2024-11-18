    .data
newline: .asciiz "\n"
space:   .asciiz " "

    .text  
main:
    li $v0, 5           # Read integer n
    syscall
    move $t0, $v0       # Store n in $t0

    li $t1, 1           # Initialize row counter k = 1

loop:
    bgt $t1, $t0, exit  # Exit if k > n

    li $t2, 1           # Initialize number counter i = 1

print_row:
    bgt $t2, $t1, next_row  # If i > k, go to next row

    li $v0, 1           # Print i
    move $a0, $t2
    syscall
  
    li $v0, 4           # Print space
    la $a0, space
    syscall

    addi $t2, $t2, 1    # Increment i
    j print_row

next_row:
    li $v0, 4           # Print newline
    la $a0, newline
    syscall

    addi $t1, $t1, 1    # Increment row counter k
    j loop

exit:
    li $v0, 10          # Exit program
    syscall
