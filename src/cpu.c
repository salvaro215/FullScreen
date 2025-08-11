#include "cpu.h"
#include <stdio.h>

void cpu_reset(CPUState *cpu) {
    for (int i = 0; i < 16; i++)
        cpu->registers[i] = 0;
    cpu->cpsr = 0;

    // PC (R15) apunta a 0x08000000 por defecto en GBA
    cpu->registers[15] = 0x08000000;
    printf("CPU reseteada. PC = 0x%08X\n", cpu->registers[15]);
}

void cpu_step(CPUState *cpu) {
    // Aquí ejecutaremos una instrucción ARM o Thumb (a futuro)
    // Por ahora solo avanzamos el PC para probar
    cpu->registers[15] += 4;
}
