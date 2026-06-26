#pragma once

#include <stdbool.h>
#include <stdint.h>

typedef void (*addr_t)();

void delay(uint64_t);
void halt();
void enable_irq();
void disable_irq();
