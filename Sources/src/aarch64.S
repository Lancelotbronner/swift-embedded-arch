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

.global brk0
brk0:
	brk #0
	ret
#endif
