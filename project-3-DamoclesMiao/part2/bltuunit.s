addi s1 x0 -3
addi t0 x0 2
loop: bltu t0, s1, end
	addi t0 t0 -1
	jal x0, loop	
	
end: