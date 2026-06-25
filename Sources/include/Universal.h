#include <stdbool.h>
#include <stdint.h>

void delay(uint64_t);
void halt();
[[noreturn]] void hang();
void enable_irq();
void disable_irq();
[[noreturn]] void _start_asm();
