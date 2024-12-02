.data
    filename:   .asciiz "input.txt"  # Default filename
    buffer:     .space 1024           # Buffer to store file contents
    error_msg:  .asciiz "Error opening file\n"

.text
.globl main

main:
    # Stack frame setup
    addi $sp, $sp, -24   # Allocate stack space
    sw   $ra, 20($sp)    # Save return address
    sw   $fp, 16($sp)    # Save frame pointer
    move $fp, $sp        # Set new frame pointer

    # Prepare file open arguments
    la   $a0, filename   # Load filename address
    li   $a1, 0          # Flag for reading (0)
    li   $v0, 13         # Syscall for file open
    syscall

    # Check for file open error
    bltz $v0, file_error # Branch if file open failed

    # Store file descriptor
    move $s0, $v0        # Save file descriptor

    # Prepare read arguments
    move $a0, $s0        # File descriptor
    la   $a1, buffer     # Buffer to read into
    li   $a2, 1024       # Maximum bytes to read
    li   $v0, 14         # Syscall for file read
    syscall

    # Pseudo-code / Incomplete section for you to finish
    # TODO: Implement printing file contents
    # TODO: Close file descriptor
    # TODO: Handle potential read errors

file_error:
    # Print error message if file cannot be opened
    li   $v0, 4          # Syscall for print string
    la   $a0, error_msg
    syscall

exit:
    # Restore stack frame
    move $sp, $fp        # Restore stack pointer
    lw   $fp, 16($sp)    # Restore frame pointer
    lw   $ra, 20($sp)    # Restore return address
    addi $sp, $sp, 24    # Deallocate stack space

    # Exit program
    li   $v0, 10         # Syscall for exit
    syscall