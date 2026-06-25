#ifdef __aarch64__

.global delay
delay:
	subs x0, x0, #1
	bne delay
	ret

.global halt
halt:
	wfi
	ret

.global hang
hang:
	wfi
	b hang

.global enable_irq
enable_irq:
	msr daifclr, #2
	ret

.global disable_irq
disable_irq:
	msr daifset, #2
	ret

.global get_el
get_el:
	mrs x0, CurrentEL
	lsr x0, x0, #2
	ret

.global get_mpidr_el1
get_mpidr_el1:
	mrs x0, mpidr_el1
	ret

.global register_vector_table
register_vector_table:
	adrp x0, vector_table
	add  x0, x0, :lo12:vector_table
	msr vbar_el1, x0
	isb
	ret

.global brk0
brk0:
	brk #0
	ret

.global from_el1
from_el1:
	ldr x0, =__stack_top
	mov sp, x0
jump_to_main:
	// jump to Swift code, should not return
	bl Kernel_main
	// for failsafe, halt this core too
	b hang

.global from_el2
from_el2:
	mov x0, #(1 << 31)  // aarch64
	msr hcr_el2, x0

	msr cntvoff_el2, xzr

	mov x0, #5  // EL1h
	orr x0, x0, #(0xF << 6)  // mask DAIF
	msr spsr_el2, x0  // set return level to EL1

	adr x0, from_el1
	msr elr_el2, x0

	isb
	eret

.global from_el3
from_el3:
	mov x0, #(1 << 31)  // aarch64
	msr hcr_el2, x0

	mov x0, #(1 << 11)  // set ST bit (disable trapping of timer control registers)
	orr x0, x0, #(1 << 10)  // set RW bit (next lower EL in aarch64)
	msr scr_el3, x0

	mov x0, #5  // EL1 with SP_EL1 (EL1h)
	orr x0, x0, #(0xF << 6)  // mask DAIF
	msr spsr_el3, x0  // set return level to EL1

	adr x0, from_el1
	msr elr_el3, x0

	isb
	eret

#endif
