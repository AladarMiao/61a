addi sp sp -20
addi t0 t0 123
sw t0 0(sp)
push t0
lw a0 0(sp)
lwc s0 0(sp) x0
lwc s1 0(sp) t0
pop 4