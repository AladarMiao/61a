loop: beq s1, x0, end
	lw t0, 0(s1)
	addi t0, t0, 1
	sw t0, 0(s1)
	lw s1, 4(s1)
	jal x0, loop
end: