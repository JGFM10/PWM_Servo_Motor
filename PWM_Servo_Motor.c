#include <stdio.h> //biblioteca padrão da linguagem C
#include "pico/stdlib.h" //subconjunto central de bibliotecas do SDK Pico
#include "pico/time.h" //biblioteca para gerenciamento de tempo
#include "hardware/irq.h" //biblioteca para gerenciamento de interrupções
#include "hardware/pwm.h" //biblioteca para controlar o hardware de PWM

#define SERVO_PIN 22 // Define o pino GPIO 22 para o servomotor
#define LED_PIN 12 // Define o pino GPIO 12 para controle do LED RGB
const uint16_t WRAP_PERIOD = 25000; //valor máximo do contador - WRAP
const float PWM_DIVISER = 100.0; //divisor do clock para o PWM

//função para configurar o módulo PWM
void pwm_setup()
{

    gpio_set_function(SERVO_PIN, GPIO_FUNC_PWM); // Configura o pino do servomotor para função PWM
    gpio_set_function(LED_PIN, GPIO_FUNC_PWM); // Configura o pino do LED RGB para função PWM

    uint slice_num_servo = pwm_gpio_to_slice_num(SERVO_PIN); // Obtém o número do slice PWM do pino do servomotor
    uint slice_num_led = pwm_gpio_to_slice_num(LED_PIN); // Obtém o número do slice PWM do pino do servomotor

    pwm_set_clkdiv(slice_num_servo, PWM_DIVISER); //define o divisor de clock do PWM
    pwm_set_clkdiv(slice_num_led, PWM_DIVISER); //define o divisor de clock do PWM

    pwm_set_wrap(slice_num_servo, WRAP_PERIOD); //definir o valor de wrap
    pwm_set_wrap(slice_num_led, WRAP_PERIOD); //definir o valor de wrap

    pwm_set_gpio_level(SERVO_PIN, 0); //definir o cico de trabalho (duty cycle) do pwm
    pwm_set_gpio_level(LED_PIN, 0); //definir o cico de trabalho (duty cycle) do pwm


    pwm_set_enabled(slice_num_servo, true); //habilita o pwm no slice correspondente
    pwm_set_enabled(slice_num_led, true); //habilita o pwm no slice correspondente
}


int main() {
    stdio_init_all(); // Inicializa a comunicação padrão do sistema

    pwm_setup(); //configura o PWM



    //loop principal
    while (true) {

        pwm_set_gpio_level(SERVO_PIN, 3000); //define o nível atual do PWM (duty cycle)
        pwm_set_gpio_level(LED_PIN, 3000); //definir o cico de trabalho (duty cycle) do pwm
        printf("Ciclo ativo: 3000\n");//imprimir ciclo ativo do PWM 
        sleep_ms(5000); // Atraso de 5 segundo
        

        pwm_set_gpio_level(SERVO_PIN, 1850); //define o nível atual do PWM (duty cycle)
        pwm_set_gpio_level(LED_PIN, 1850); //definir o cico de trabalho (duty cycle) do pwm
        printf("Ciclo ativo: 1850\n");//imprimir ciclo ativo do PWM 
        sleep_ms(5000); // Atraso de 5 segundo

        pwm_set_gpio_level(SERVO_PIN, 625); //define o nível atual do PWM (duty cycle)
        pwm_set_gpio_level(LED_PIN, 625); //definir o cico de trabalho (duty cycle) do pwm
        printf("Ciclo ativo: 625\n");//imprimir ciclo ativo do PWM 
        sleep_ms(5000); // Atraso de 5 segundo

         // Loop que começa em 0, vai até 3000, incrementando de 5 em 5
    for (int i = 625; i <= 3000; i += 5) {
        printf("Ciclo ativo: %d\n", i); // Imprime o valor atual de i
        pwm_set_gpio_level(SERVO_PIN, i); //define o nível atual do PWM (duty cycle)
        pwm_set_gpio_level(LED_PIN, i); //definir o cico de trabalho (duty cycle) do pwm
        sleep_ms(10);
    }
    for (int i = 3000; i >= 625; i -= 5) {
        printf("Ciclo ativo: %d\n", i); // Imprime o valor atual de i
        pwm_set_gpio_level(SERVO_PIN, i); //define o nível atual do PWM (duty cycle)
        pwm_set_gpio_level(LED_PIN, i); //definir o cico de trabalho (duty cycle) do pwm
        sleep_ms(10);
    }
    }
}


