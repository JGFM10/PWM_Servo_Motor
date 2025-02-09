Resumo do Funcionamento do Código

Este código controla um servomotor e um LED RGB utilizando PWM no Raspberry Pi Pico.

- O pino GPIO 22 é configurado para controlar o servomotor.
- O pino GPIO 12 é configurado para controlar o LED RGB.
- A configuração do PWM define um período de 25.000 ciclos e um divisor de clock de 100, Resultando numa frequência de 50hz.

Vídeo Demonstrativo do Código:https://youtu.be/uA3cwNOFV5U

Funcionamento:
1. O PWM é inicializado com um ciclo de trabalho correspondente a diferentes ângulos do servomotor:
   - 3000 → 180°
   - 1850 → 90°
   - 625 → 0°
2. O servomotor e o LED alternam entre esses valores a cada 5 segundos.
3. No final, o código executa um movimento suave e contínuo de ida e volta entre 0° e 180°, variando o PWM de 625 a 3000 e retornando.

Este código pode ser utilizado para aplicações que necessitam de controle preciso de posição do servomotor e variação de intensidade do LED RGB.
