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
	ret

.global get_mpidr_el1
get_mpidr_el1:
	mrs x0, mpidr_el1
	ret

.global get_hcr_el2
get_mpidr_el2:
	mrs x0, hcr_el2
	ret
.global set_hcr_el2
set_hcr_el2:
	msr hcr_el2, x0
	ret

.global eret
eret:
	isb
	eret

.global set_elr_el2
set_elr_el2:
	msr elr_el2, x0
	ret

.global set_elr_el3
set_elr_el3:
	msr elr_el3, x0
	ret

.global brk0
brk0:
	brk #0
	ret

.global set_sp
set_sp:
	mov sp, x0
	ret

.global set_scr_el3
set_scr_el3:
	msr scr_el3, x0
	ret

.global set_spsr_el2
set_spsr_el2:
	msr spsr_el2, x0
	ret

.global set_spsr_el3
set_spsr_el3:
	msr spsr_el3, x0
	ret

.global zero_cntvoff_el2
zero_cntvoff_el2:
	msr cntvoff_el2, xzr
#endif
