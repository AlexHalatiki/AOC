	.data
nextLine: .asciiz "\n"
	.text
	.globl main
main:
while:
	li $v0, 5
	syscall
	beq $v0, 0, end
	move $a0, $v0
	li $v0, 5
	syscall
	move $a1, $v0
	jal digitCounter
	move $a0, $v0
	li $v0, 1
	syscall
	li $v0, 4
	la $a0, nextLine
	syscall
	j while
end:
	li $v0, 10
	syscall
digitCounter:
	slti $t0, $a0, 1
	beq $t0, 1, endFunction
	li $t0, 10
	divu $a0, $t0
	add $sp, $sp, -8
	sw $s0, 0($sp)
	sw $ra, 4($sp)
	mfhi $s0
	mflo $a0
	jal digitCounter
	bne $s0, $a1, notAdd
	add $v0 , $v0 , 1
notAdd:
	lw $s0, 0($sp)
	lw $ra, 4($sp)
	add $sp, $sp, 8
	jr $ra
endFunction:
	li $v0, 0
	jr $ra