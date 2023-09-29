	.data
erro: .asciiz "ERRO\n"
pularLinha: .asciiz "\n"	
	.text
	.globl main
main:
	li $s0, 0
	li $s1, 0
while:
	li $v0, 5
	syscall
	beq $v0, -1, imprimir
	add $s1, $s1, 1
	add $s0, $s0, $v0
	slti $t0, $s0, 2048
	beq $t0, 0, imprimir
	j while
imprimir:
	li $v0, 1
	move $a0, $s0
	syscall
	li $v0, 4
	la $a0, pularLinha
	syscall
	beq $s1, $zero, imprimirErro
	div $s0, $s1
	mflo $a0
	li $v0, 1
	syscall
	li $v0, 10
	syscall
imprimirErro:
	la $a0, erro
	syscall