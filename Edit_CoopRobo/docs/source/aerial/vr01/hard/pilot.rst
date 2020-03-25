Piloto Automatico
=================

.. Colocar a logo do PX4 aqui (tirar a foto no lab)

.. https://ardupilot.org/copter/docs/introduction.html#
.. https://docs.px4.io/master/en/getting_started/


Introdução
~~~~~~~~~~~

O PX4 é um piloto automático professional de codigo aberto, desenvolvido tanto pelo meio industrial quanto pela classe academica e apoiado pela comunidade mundial ativa. O PX4 pode ser executado em varias placas controladoras de vôo. Merecendo destaque os controladores de vôo de *hardware* aberto da série `PixHawk`_, executando o PX4 no `NuttX OS`_.

.. _Pixhawk: https://pixhawk.org
.. _NuttX OS: https://nuttx.apache.org/

.. Adicionar imagem do pixhawk do lado


O Pixhawk atua em diversos tipos de veiculos, desde de drones de corrida e carga à veiculos terrestres e submersíveis. Neste trabalho iremos focar na aplicação em aeronaves, onde o Pixhawk atua como um controlador de voo de uso geral, responsável pela aquisição, condicionamento e processamento de sinais provenientes dos sensores da aeronave e pelo controle dos atuadores da aeronave. 

Ele oferece um ambiente de programação compatível com sistemas Unix e Linux, facilitando o desenvolvimento de aplicações de software. O sistema Pixhawk possui capacidade de multithreading, ou seja, pode executar várias tarefas simultaneamente sem que uma interfira na outra através do compartilhamento de recursos do processo. Além disso, ele possui funções de piloto automático integrado com logs detalhados de missões e comportamento de voo. [..]

Dado as opções disponiveis no mercado, escolheu-se o Pixhawk1 como piloto automático por seu melhor custo benificio para o projeto.

Conceitos Basicos
~~~~~~~~~~~~~~~~~

.. Adicionar https://docs.px4.io/v1.9.0/en/getting_started/

Este topico apresenta alguns conceitos basicos a respeito de veículos aéreos não tripulados e o uso da plataforma PX4. 

Veículo aéreo não tripulado (VANT ou *drone*)
---------------------------------------------

Um VANT é todo e qualquer tipo de aeronave que pode ser controlada nos 3 eixos de liberdade e não necessita de pilotos embarcados para ser guiado, podendo ser controlado remotamente ou autonomamente.

O "cérebro" de um drone é chamado de piloto automático. Este consiste em um *software* de controle de vôo sendo executado em um *hardware* especifico para a mesma função.

Plataforma Dronecode
---------------------

O PX4 faz parte da `Dronecode Plataform`_, uma plataforma completa para desenvolvimento de drones, sob uma licença de codigo aberto a comunidade. Incluindo, entre outras, os controladores `PX4`_, a estação de controle terreste `QGroundControl`_, o `Dronecode SDK`_ e o `Dronecode Camera Manager`_.

.. _Dronecode Plataform: https://www.dronecode.org/
.. _PX4: https://px4.io/
.. _QGroundControl: http://qgroundcontrol.com/
.. _Dronecode SDK: https://www.dronecode.org/sdk/
.. _Dronecode Camera Manager: https://camera-manager.dronecode.org/en/

Sensores
~~~~~~~~~

Os sistemas baseados em PX4 utilizam diversos sensores para determinar o estado do veiculo (sendo estes essenciais para a estabilização e para possibilitar o controle autônomo).  Os estados do veículo incluem: posição, direção, velocidade, velocidade do ar, orientação (atitude), taxas de rotação em diferentes direções, nível da bateria, etc.

O sistema requer minimamente um giroscópio, acelerômetro, magnetômetro (bússola), barômetro e um sensor de velocidade do ar para o caso de asas fixas (caso do projeto). É necessário ainda um GPS ou outro sistema de posicionamento para ativar todos os modos automáticos e alguns modos assistidos. 

Os controladores da série Pixhawk já vem com um conjunto minimo de sensores incorporado. Sensores adicionais/externos podem ser conectados ao controlador.

GPS e bússula
-------------


Velocidade do ar
----------------


Distância
----------


Fluxo optico
-------------




Especificações do PixHawk1
~~~~~~~~~~~~~~~~~~~~~~~~~~~

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

   -  1 x SanDisk Ultra micro SD Card (8GB)
   -  1 x MRC0225- Cable [3-Pins DF-13] to Switch+LED
   -  1 x MRC0224- Cable [2-Pins DF-13] to Buzzer
   -  1 x I2C Splitter
   -  2 x MRC0213- Cable [6-Pins JST-GH] to [6-Pins DF-13], (Telemetry Radio, Power module and Extra)
   -  1 x MRC0216- Cable [6-Pins DF-13] to [6-Pins DF-13], (For legacy products)
   -  4 x Damping Foams
   -  3 x Decals "APM Rover", "APM Copter" and "APM Plane"


