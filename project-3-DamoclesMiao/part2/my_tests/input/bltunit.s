addi t0 x0 2
loop: blt t0, x0, end
	addi t0 t0 -1
	jal x0, loop	
	
end: