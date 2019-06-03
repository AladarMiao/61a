addi s0 x0 -1
addi s1 x0 -2
addi t0 x0 -1

beq s0 s1 bad-loop
beq s1 s0 bad-loop
blt s0 s1 bad-loop
blt s0 s0 bad-loop
bne s0 t0 bad-loop
bne t0 s0 bad-loop
bltu s0 s1 bad-loop
bltu s0 s0 bad-loop
bltu s1 s0 main
jal x0 bad-loop

main:
	jal a0 func
	jal x0 done

func:
	jalr x0 a0 0
	jal x0 bad-loop
bad-loop:
	add x0 x0 x0
	jal x0 bad-loop
done:
	add x0 x0 x0
	jal x0 n1
n1:
	beq s0 t0 n2
n2:
	blt s1 s0 n3
n3:
	bne s0 s1 n4
n4:
	addi t1 x0 2