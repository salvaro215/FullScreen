#ifndef CPU_H
#define CPU_H

#include <stdint.h>

// Estado base de la CPU ARM7TDMI
typedef struct {
    uint32_t registers[16];  // R0-R15 (PC es R15)
    uint32_t cpsr;           // Registro de estado
} CPUState;

void cpu_reset(CPUState *cpu);
void cpu_step(CPUState *cpu);

#endif // CPU_H
