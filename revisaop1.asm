	.data
endText: .asciiz "\n"
	.text
	.globl main
main:
	li $v0, 5
	syscall
	move $a0, $v0
	jal sum
	move $a0, $v0
	li $v0, 1
	syscall
	la $a0, endText
	li $v0, 4
	syscall 
end:
	li $v0, 10
	syscall
sum:
	bne $a0, 0, sum_body
	li $v0, 0
	jr $ra
sum_body:
	addi $sp, $sp, -8
	sw $s0, 0($sp)
	sw $ra, 4($sp)
	move $s0, $a0
	addi $a0, $a0, -1
	jal sum
	add $v0, $v0, $s0
	lw $s0, 0($sp)
	lw $ra, 4($sp)
	addi $sp, $sp, 8
	jr $ra