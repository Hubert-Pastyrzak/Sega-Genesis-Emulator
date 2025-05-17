#include "m68k.h"

#include <cstdint>
#include "memory.h"
#include "reg128t.h"

//CPU registers
uint32_t d[8];
uint32_t a[8];
uint16_t sr;
uint32_t pc;

//FPU registers
reg128_t fp[8];
uint16_t fpcr;
uint16_t fpsr;
uint16_t fpiar;

int cpu_is_running = 0;

uint8_t abcd(uint8_t a, uint8_t b) {
  return (
      (((((a & 0xF0) + (b & 0xF0)) >> 4) % 10) << 4)
    | (((a & 0x0F) + (b & 0x0F)) % 10)
  );
}

void cpu_execute_abcd(uint16_t opcode) {
  int rx = (opcode & 0xE000) >> 9;
  int rm = (opcode & 0x0008) >> 3;
  int ry = opcode & 0x0007;

  if (rm) {
    //TODO: Memory
  } else {
    //TODO: Registers
  }
}

void cpu_step() {
  uint16_t opcode = (memory_read(pc) << 8) | memory_read(pc + 1);
  pc += 2;

  switch (opcode & 0xF1F0) {
    case 0xC100: {
      cpu_execute_abcd(opcode);
      break;
    }

    //TODO: Implement remaining instructions
  }
}

void cpu_run() {
  cpu_is_running = 1;
  while (cpu_is_running) {
    cpu_step();
  }
}
