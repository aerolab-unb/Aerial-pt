Montando o Pixhawk
==================

Este topico tem como objetivo mostrar como montar o controlador de voo 3DR Pixhawk e seus principais perifericos.

Orientação
~~~~~~~~~~~~

Os controladores de voo possuem uma seta que marca a orientação do mesmo. Recomenda-se que o Pixhawk seja colocado na aeronave de forma que a seta aponte para a frente do veiculo.

.. adicionar imagem da seta

.. Tip::
   Se o controlador não puder ser montado com a orientação recomendada, será necessario um ajuste do piloto automatico via software. O procedimento para ajustar a orientação está disponivel em `Orientação do piloto automático`_.

.. _Orientação do piloto automático: 

Isolamento de vibrações
~~~~~~~~~~~~~~~~~~~~~~~

As placas Pixhawk possuem acelerometros e giroscopios embutidos, sendo sensiveis a vibrações. Altos niveis de vibração podem causar uma serie de problemas, incluindo redução do desempenho de voo, voos mais curtos e maior desgaste do veiculo. Em casos extremos, a vibração pode levar a falhas dos sensores, resultando em falhas de estimativa ou até mesmo a interrupção do voo.

Por essa razão, o Pixhawk vem com *espumas de amortecimento de vibrações*. 

.. adicionar imagem 

O Pixhawk deve ser montado na aeronave utilizando as espumas antivibratórias incluidas no kit. Ele deve ser posicionado o mais proximo possivel do centro de gravidade do veiculo.

.. Tip::
   Para determinar se os niveis de vibração estão muito altos e utilizar algumas tecnicas para melhorar as caracteristicas de vibração, recomenda-se o topico `PX4 user guide > Vibration Isolation`_.

.. _PX4 user guide > Vibration Isolation: https://docs.px4.io/v1.9.0/en/assembly/vibration_isolation.html#vibration-isolation

Conexões
~~~~~~~~~

A imagem abaixo apresenta as conexões dos sensores e demais itens inclusos no Pixhawk. Cada parte será analisada com mais detalhes nas seções a seguir.    

.. Adicionar imagem das conexões do pixhawk (não esquecerr do airspeed)


Campainha e interruptor de segurança (obrigatório)
--------------------------------------------------

A campainha fornece sinais sonoros que indicam a situação do VANT. Enquanto o interruptor atua na segurança da aeronave, bloqueando e desbloqueando os motores.


.. Note::
   O interruptor de segurança é ativado por padrão e quando ativado, não permite o voo, bloqueando os motores. Para desativar o modo de segurança, pressione e segure o interruptor por 1 segundo. Você pode ativar o modo de segurança novamente pressionando o interruptor.

Para conectar a campainha e o interruptor de segurança (itens obrigatórios), basta liga-lós ao Pixhawk como mostrado abaixo.

.. image:: /img/Aerial/px1_buzzer_and_safety_switch.jpg
    :align: center


GPS + Compass (obrigatório)
-----------------------------

O GPS, outro dispositivo obrigatorio, deve ser conectado à porta GPS (6 pinos) usando o cabo de 6 fios fornecida no kit. A conexão da bússola é opcional, porém recomendamos fortemente sua utilização. Para conecta-lá, ligue um cabo de 4 fios à porta I2C, como mostrado abaixo.

.. adicionar imagem do gps/bussola

.. Note::
   O GPS/bússola deve ser montado no chassi da aeronave o mais longe possivel de outros componentes eletronicos, com a seta indicadora voltada para a frente e o mais alinhada possivel com o Pixhawk. 

Rádio controle (opcional)
-------------------------

O sistema de rádio com controle remoto (RC) é necessario caso deseje controlar manualmente seu veículo, já que o PX4 não requer um sistema de rádio para modos de vôo autônomo.

Para conectar o sistema de rádio controle, será necessario selecionar um transmissor/receptor compaivel e depois vinculá-lo para que eles se comuniquem. 

.. Tip::
   Leia as instruções que acompanham seu transmissor/receptor.

As instruções a seguir mostram como conectar os diferentes tipos de receptores ao Pixhawk:

* Os receptores Spektrum e DSM se conectam à entrada SPKT/DSM . 

.. image:: /img/Aerial/pixhawk_3dr_receiver_spektrum.jpg

* Os receptores PPM-SUM e S.BUS conectam-se aos pinos de terra, potência e sinal RC , conforme mostrado. 

.. image:: /img/Aerial/pixhawk_3dr_receiver_ppm_sbus.jpg

* Os receptores PPM e PWM que possuem um fio individual para cada canal devem se conectar à porta RC por meio de um codificador PPM (os receptores PPM-Sum usam um único fio de sinal para todos os canais).

Para obter mais informações sobre a seleção de um sistema de rádio, a compatibilidade do receptor e a ligação do seu par transmissor e receptor, consulte: `Transmissores e receptores de controle remoto`_.

.. _Transmissores e receptores de controle remoto: https://docs.px4.io/v1.9.0/en/getting_started/rc_transmitter_receiver.html


Telemetria (opcional)
----------------------












