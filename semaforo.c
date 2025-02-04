#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "hardware/timer.h"

// Definição dos pinos dos LEDs
#define LED_VERMELHO 13
#define LED_AMARELO 11
#define LED_VERDE 12

#define DELAY_TEMPO 3000   // Tempo de atraso de 3 segundos

// Variáveis globais
volatile int estado_semaforo = 0;
struct repeating_timer timer;

// Callback do semáforo
bool semaforo_callback(struct repeating_timer *t) {
    gpio_put(LED_VERMELHO, 0);
    gpio_put(LED_AMARELO, 0);
    gpio_put(LED_VERDE, 0);

    switch (estado_semaforo) {
        case 0: // Vermelho
            gpio_put(LED_VERMELHO, 1);
            break;
        case 1: // Amarelo
            gpio_put(LED_AMARELO, 1);
            break;
        case 2: // Verde
            gpio_put(LED_VERDE, 1);
            break;
    }
    estado_semaforo = (estado_semaforo + 1) % 3;
    return true;
}

int main() {
    stdio_init_all();

    // Configuração dos LEDs
    gpio_init(LED_VERMELHO);
    gpio_init(LED_AMARELO);
    gpio_init(LED_VERDE);
    gpio_set_dir(LED_VERMELHO, GPIO_OUT);
    gpio_set_dir(LED_AMARELO, GPIO_OUT);
    gpio_set_dir(LED_VERDE, GPIO_OUT);

    // Inicia temporizador do semáforo (alterna a cada 3s)
    add_repeating_timer_ms(DELAY_TEMPO, semaforo_callback, NULL, &timer);
    
    while (true) {
        printf("Semáforo rodando...\n");
        sleep_ms(1000);
    }
}
