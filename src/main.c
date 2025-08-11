#include <stdio.h>
#include <stdbool.h>
#include "cpu.h"
#include "cpu.c"

//variables globales
static CPUState cpu;


// Prototipos futuros
void emu_init(void);
void emu_loop(void);

// Función principal del emulador
int main(void) {
    printf("Iniciando el emulador de Game Boy Advance\n");
    emu_init();

    // Loop principal del emulador
    while (&cpu < 0x0A000000) { // Limite para pruebas
        emu_loop();
        // Para no consumir CPU sin parar (más adelante ajustaremos)
    }

    return 0;
}

void emu_init(void) {
    printf("Inicializando subsistemas\n");
    cpu_reset(&cpu);
}

void emu_loop(void) {
    cpu_step(&cpu);
    printf("PC = 0x%08X\n", cpu.registers[15]); 
}
