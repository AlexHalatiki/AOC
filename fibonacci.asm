	.text
	.globl main
main:
	li $v0, 5
	syscall
	move $a0, $v0
	jal fib
	move $a0, $v0
	li $v0, 1
	syscall
end:
	li $v0, 10
	syscall
fib:
	slti $t0, $a0, 3
	beq $t0, 1, return
	add $sp, $sp, -8
	sw $s0, 0($sp)
	sw $ra, 4($sp)
	move $s0, $a0
	add $s0, $s0, -1
	move $a0, $s0
	jal fib
	add $s0, $s0, -1
	move $a0, $s0
	move $s0, $v0
	jal fib
	add $v0, $v0, $s0
	lw $s0, 0($sp)
	lw $ra, 4($sp)
	add $sp, $sp, 8
	jr $ra
return:
	beq $a0, 0, zero
	move $v0, $a0
	jr $ra
zero:
	li $v0, 1
	jr $ra