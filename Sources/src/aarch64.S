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

.global enable_irq
enable_irq:
	msr daifclr, #2
	ret

.global disable_irq
disable_irq:
	msr daifset, #2
	ret
#endif
