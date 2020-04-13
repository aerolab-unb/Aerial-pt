Pouso automático
=================

Após a conexão do lidar ao sistema via PWM, alguns parâmetros do piloto automático devem ser alterados para que ele reconheça o sensor. Esses parâmetros podem ser facilmente alterados através do QGroundControl. São eles: 

* RNG_FND = 5, indica que a conexão ocorre via PWM.

* RNDFND_MAX_CM = 4000, representa a distância máxima em que o sensor é confiável.

* RNDFND_STOP_PIN = 55, pino conectado ao sinal de ativação do lidar. Permite que o dispositivo reinicie o sensor caso ele para de fornecer dados.

* Os parâmetros RNDFND_SCALING e RNDFND_OFFSET devem ser ajustados de forma a se calibrar o sensor (costumam ser aproximadamente 0 e 1, respectivamente).

.. adicionar imagem configurando

O sensor pode ser testado pelo QGroundControl, onde as leituras podem ser observadas no campo *sonar range*. Após a configuração do sensor, o piloto automático será capaz de pousar a aeronave de forma muito mais rápida e precisa. O pouso ocorre pelo envio do comando *Land* ao controlador, mas para que ele ocorra corretamente deve-se definir a posição da pista de pouso e deve-se ajustar os parâmetros de pouso, como, por exemplo, a velocidade com que o avião deve pousar. Durante esse trabalho não foi realizado nenhum pouso automático. A documentação detalhada sobre pousos automáticos pode ser encontrada em `Automatic Landing`_.

.. _Automatic Landing: . http://ardupilot.org/plane/docs/automatic-landing.html.
