Firmware
=========


A instalação do *firmware* no hardware do controlador de vôo pode ser efetuada de duas formas, pelo uso de um programa de Estação de Controle Terrestre (ECT) ou diretamente pelo uso de ferramentas de desenvolvedor sem o uso de um programa auxiliar. Uma ECT é uma aplicação de *software* que roda em um computador terrestre e se comunica com o veiculo pelo uso de telemetria sem fio.  [*] 

As principais ECT's disponiveis são Mission Planner, APM Planner 2, MAVProxy, QGroundControl e UgCS.
Para aplicar neste projeto, escolheu-se o QGroundControl por fornecer uso facil e direto para iniciantes, boa documentação, programa mais estavel em relação aos demais e ainda oferecer recursos avançados para usuarios experientes.

.. adicionar links de download, instalação e documentação oficial

.. Tip::
    Antes de iniciar esta seção, recomenda-se o download e instalação do QGroundControl em seu computador.

.. Note::
    A documentação oficial do QGroundControl está disponivel aqui.

Instalação estável
~~~~~~~~~~~~~~~~~~~

Recomenda-se a instalação da versão mais recente do PX4, a fim de obter as correções de bug e as melhores e mais recentes funções.

.. Note::
    Antes de instalar o firmware, todas as coneções USB do veiculo devem ser desconectadas e o veiculo não deve ser alimentado por uma bateria.

1. Selecione o icone da engrenagem (**Configuração do veículo**) na barra de ferramentas superior e, em seguida, selecione **Firmware** na barra lateral.

.. Adicionar imagem

2. Conecte o Pixhawk diretamente ao seu computador via USB (não conecte através de um hub USB).

3. Selecione a opção **PX4 Flight Stack X.x.x Release** para instalar a versão mais recente do PX4 em seu controlador de voo (detectado automaticamente).

.. Adicionar imagem

4. Clique em **OK** para iniciar a instalação. 

.. Adicionar imagem

	O firmware seguirá com varias etapas de atualização (doownload do novo firmware, exclusão da versão antiga, etc.). O progresso geral é exibido em uma barra de progresso. 

Assim que a instalação acabar e o firmware estiver instalado, o controlador será reiniciado e reconectado.
 
Mais informações
----------------

* `PX4 user guide > Firmware`_.
.. _PX4 user guide > Firmware: https://docs.px4.io/v1.9.0/en/config/firmware.html  
* `QGroundControl user guide > Firmware`_.
.. _QGroundControl user guide > Firmware: https://docs.qgroundcontrol.com/en/SetupView/Firmware.html
* `PX4 Setup Video`_ (Youtube)
.. _PX4 Setup Video: https://www.youtube.com/watch?v=91VGmdSlbo4&feature=youtu.be




