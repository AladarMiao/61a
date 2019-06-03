bne s0 s0 hue
jal ra go
jal x0 end
addi t1 x0 7


go:
	addi s1 x0 23
	jalr x0 ra 0

hue:
	addi t1 x0 222
end: