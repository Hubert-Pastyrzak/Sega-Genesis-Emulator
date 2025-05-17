#pragma once

#include <stdint.h>

void memory_write(uint32_t address, uint8_t value);
uint8_t memory_read(uint32_t address);
