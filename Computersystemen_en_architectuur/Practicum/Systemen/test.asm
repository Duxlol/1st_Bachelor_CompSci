.data
result: .float 0.0          # Opslag voor het resultaat
double_5: .double 5.0       # Constante 5.0
double_9: .double 9.0       # Constante 9.0
double_32: .double 32.0     # Constante 32.0
double_15: .double 15.0     # Constante 15.0 (voor argument)

.text
.globl main

# main function
main:
    # Laad 15.0 (argument) in $f12
    l.d $f12, double_15          # $f12 = fahr (15.0)
    jal f2c                      # Roep de functie f2c aan
    s.d $f0, result              # Sla resultaat (return value) op
    li $v0, 10                   # Exit
    syscall

# Function: f2c
f2c:
    # Functieproloog
    addiu $sp, $sp, -32          # Maak ruimte op de stack
    sw $ra, 28($sp)              # Sla returnadres op
    sw $fp, 24($sp)              # Sla oude framepointer op
    move $fp, $sp                # Zet nieuwe framepointer

    # Sla argument (fahr) op stack
    s.d $f12, 16($fp)            # Sla fahr op stack (double op 16($fp))

    # fraction = 5.0 / 9.0
    l.d $f4, double_5            # Laad 5.0 in $f4
    l.d $f6, double_9            # Laad 9.0 in $f6
    div.d $f8, $f4, $f6          # $f8 = 5.0 / 9.0
    s.d $f8, 8($fp)              # Sla fraction op stack

    # diff = fahr - 32.0
    l.d $f4, 16($fp)             # Laad fahr (van stack) in $f4
    l.d $f6, double_32           # Laad 32.0 in $f6
    sub.d $f10, $f4, $f6         # $f10 = fahr - 32.0
    s.d $f10, 0($fp)             # Sla diff op stack

    # return fraction * diff
    l.d $f4, 8($fp)              # Laad fraction in $f4
    l.d $f6, 0($fp)              # Laad diff in $f6
    mul.d $f0, $f4, $f6          # $f0 = fraction * diff (return value)

    # Functie-epiloog
    lw $ra, 28($sp)              # Herstel returnadres
    lw $fp, 24($sp)              # Herstel framepointer
    addiu $sp, $sp, 32           # Ruim de stack op
    jr $ra                       # Retourneer naar caller
