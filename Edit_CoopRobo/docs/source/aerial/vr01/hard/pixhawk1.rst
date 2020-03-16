Piwhawk 1
=========

.. Colocar a imagem do pixhawk aqui (tirar a foto no lab)

.. https://ardupilot.org/copter/docs/introduction.html#
.. https://docs.px4.io/master/en/getting_started/


Introdução
~~~~~~~~

O Pixhawk® 1 é um piloto automático que serve como um controlador de voo de uso geral baseado no projeto de hardware aberto FMUv2 que roda o PX4 no sistema operacional NuttX. 
O Pixhawk é uma plataforma completa de hardware e software, responsável pela aquisição, condicionamento e processamento de sinais provenientes dos sensores da aeronave e pelo controle dos atuadores da aeronave. Ele oferece um ambiente de programação compatível com sistemas Unix e Linux, facilitando o desenvolvimento de aplicações de software. O sistema Pixhawk possui capacidade de multithreading, ou seja, pode executar várias tarefas simultaneamente sem que uma interfira na outra através do compartilhamento de recursos do processo. Além disso, ele possui funções de piloto automático integrado com logs detalhados de missões e comportamento de voo. [TG1 do Eduardo Moura]

Especificações
===============

-  **Processador**

   -  32-bit ARM Cortex M4 core with FPU
   -  168 Mhz/256 KB RAM/2 MB Flash
   -  32-bit failsafe co-processor

-  **Sensores**

   -  MPU6000 as main accel and gyro
   -  ST Micro 16-bit gyroscope
   -  ST Micro 14-bit accelerometer/compass (magnetometer)
   -  MEAS barometer

-  **Power**

   -  Ideal diode controller with automatic failover
   -  Servo rail high-power (7 V) and high-current ready
   -  All peripheral outputs over-current protected, all inputs ESD
      protected

-  **Interface**

   -  5x UART serial ports, 1 high-power capable, 2 with HW flow
      control
   -  Spektrum DSM/DSM2/DSM-X Satellite input
   -  Futaba S.BUS input (output not yet implemented)
   -  PPM sum signal
   -  RSSI (PWM or voltage) input
   -  I2C, SPI, 2x CAN, USB
   -  3.3V and 6.6V ADC inputs

-  **Dimensões**

   -  Weight 38 g (1.3 oz)
   -  Width 50 mm (2.0”)
   -  Height 15.5 mm (.6”)
   -  Length 81.5 mm (3.2”)
   
-  **Itens inclusos**
   -  1 x SanDisk Ultra micro SD Card (8GB).
   -  1 x MRC0225- Cable [3-Pins DF-13] to Switch+LED.
   -  1 x MRC0224- Cable [2-Pins DF-13] to Buzzer.
   -  1 x I2C Splitter.
   -  2 x MRC0213- Cable [6-Pins JST-GH] to [6-Pins DF-13], (Telemetry Radio, Power module and Extra).
   -  1 x MRC0216- Cable [6-Pins DF-13] to [6-Pins DF-13], (For legacy products).
   -  4 x Damping Foams.
   -  3 x Decals "APM Rover", "APM Copter" and "APM Plane".

