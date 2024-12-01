.data
prompt:    .asciiz "Press a key: "
up:        .asciiz "up\n"
down:      .asciiz "down\n"
left:      .asciiz "left\n"
right:     .asciiz "right\n"
unknown:   .asciiz "Unknown input! Valid inputs: z s q d x\n"
exit_msg:  .asciiz "Exiting program.\n"

.text
.globl main

main:
    # Setup stackframe voor main
    addi $sp, $sp, -8   # Maak ruimte voor return adres en $s0
    sw $ra, 4($sp)      # Sla return adres op
    sw $s0, 0($sp)      # Sla register $s0 op

main_loop:
    jal print_prompt    # Roep functie aan om prompt te printen
    jal read_input      # Roep functie aan om input te lezen
    move $a0, $v0       # Zet de ingelezen waarde in $a0
    jal process_input   # Verwerk de input

    # Controleer of programma moet afsluiten
    li $t1, 'x'
    beq $v0, $t1, exit_program
    j main_loop         # Herhaal de lus

exit_program:
    jal print_exit      # Print afsluitbericht

    # Herstel stackframe en sluit af
    lw $s0, 0($sp)      # Herstel $s0
    lw $ra, 4($sp)      # Herstel return adres
    addi $sp, $sp, 8    # Ruimte terug vrijmaken
    li $v0, 10          # Exit syscall
    syscall

# Functie: print_prompt
# Print de prompt "Press a key: "
print_prompt:
    addi $sp, $sp, -8   # Stackframe maken
    sw $ra, 4($sp)      # Sla return adres op

    li $v0, 4           # Print string syscall
    la $a0, prompt      # Laad prompt adres
    syscall

    lw $ra, 4($sp)      # Herstel return adres
    addi $sp, $sp, 8    # Ruimte vrijmaken
    jr $ra              # Ga terug naar de aanroeper

# Functie: read_input
# Leest een karakter in van de gebruiker
read_input:
    addi $sp, $sp, -8   # Stackframe maken
    sw $ra, 4($sp)      # Sla return adres op

    li $v0, 12          # Read char syscall
    syscall
    move $v0, $v0       # Retourneer ingelezen karakter

    lw $ra, 4($sp)      # Herstel return adres
    addi $sp, $sp, 8    # Ruimte vrijmaken
    jr $ra              # Ga terug naar de aanroeper

# Functie: process_input
# Verwerkt de ingelezen input en print de juiste boodschap
process_input:
    addi $sp, $sp, -8   # Stackframe maken
    sw $ra, 4($sp)      # Sla return adres op
    sw $a0, 0($sp)      # Sla $a0 (input karakter) op

    lw $t0, 0($sp)      # Laad input karakter
    li $t1, 'z'
    beq $t0, $t1, print_up
    li $t1, 's'
    beq $t0, $t1, print_down
    li $t1, 'q'
    beq $t0, $t1, print_left
    li $t1, 'd'
    beq $t0, $t1, print_right
    li $t1, 'x'
    beq $t0, $t1, return_input

    # Default case
    la $a0, unknown
    j print_message

print_up:
    la $a0, up
    j print_message

print_down:
    la $a0, down
    j print_message

print_left:
    la $a0, left
    j print_message

print_right:
    la $a0, right

print_message:
    li $v0, 4          # Print string syscall
    syscall
    j end_process

return_input:
    move $v0, $t0       # Retourneer input naar $v0

end_process:
    lw $ra, 4($sp)      # Herstel return adres
    addi $sp, $sp, 8    # Ruimte vrijmaken
    jr $ra              # Ga terug naar de aanroeper

# Functie: print_exit
# Print afsluitbericht
print_exit:
    addi $sp, $sp, -8   # Stackframe maken
    sw $ra, 4($sp)      # Sla return adres op

    li $v0, 4           # Print string syscall
    la $a0, exit_msg    # Laad afsluitbericht
    syscall

    lw $ra, 4($sp)      # Herstel return adres
    addi $sp, $sp, 8    # Ruimte vrijmaken
    jr $ra              # Ga terug naar de aanroeper
