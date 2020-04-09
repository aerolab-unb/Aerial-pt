QGroundControl
=================

O QGroundControl é uma das principais estações de controle em solo (ECS) disponiveis atualmente a trabalhar com pilotos automáticos compatíveis com MAVLink, incluindo o PX4 e ArduPilot. 

Para aplicar neste projeto, escolheu-se o QGroundControl como ECS por fornece uso fácil e direto para iniciantes, além de oferecer, a usuarios experientes, suporte a recursos avançados no controle completo de vôo e configurações do veículo com PX4. 

Além disso, QGroundControl é uma das ECSs mais estáveis em relação as outras, possui uma interface simples e eficiente e está disponivel em diversos sistemas operacionais, sendo os principais Windows, Mac OS X, Linux, Android e o iOS.


Requisitos de sistema
~~~~~~~~~~~~~~~~~~~~~~

O QGroundControl pode ser executado normalmente na maioria dos computadores modernos. Um computador com um i5 e pelo menos 8 GB de RAM terá bom desempenho em todos os aplicativos do programa. Para uma experiência melhor, é aconselhável ter o sistema operacional em sua última versão estável.


Instalação
~~~~~~~~~~~~

-  **Windows**
     
   -  Instalação do QGroundControl para Windows Vista ou posterior: 
      
      1. Efetue o download do instalador do `QGroundControl.exe <https://s3-us-west-2.amazonaws.com/qgroundcontrol/latest/QGroundControl-installer.exe>`_
      2. Clique dias vezes no executvel para abrir o instalador

 
-  **Mac OS X**

   -  Instalação do QGroundControl para Mac OS 10.10 ou posterior:

      1. Efetue o download do `QGroundControl.dmg <https://s3-us-west-2.amazonaws.com/qgroundcontrol/latest/QGroundControl.dmg>`_
      2. Clique duas vezes no arquivo .dmg para instalar 
      3. Mova o aplicativo $ QGroundControl para a pasta Application



-  **Ubuntu**

O Ubuntu possui um gerenciador de modem serial (*serial modem manager*) que interfere nas aplicações envolvendo robotica que utilizam uma porta serial (ou serial USB). Antes da instalação do *QGroundControl* é necessario remover tal gerenciador de modens e conceder ao seu usuario as permissões para acessar a porta serial. Também é preciso instalar o GStreamer para possibilitar o streaming de video.
   
   - Antes de instalar o QGroundControl pela primeira vez:

    1. Digite no prompt de comando:
      
       ::
         
           sudo usermod -a -G dialout $USER
           sudo apt-get remove modemmanager -y
           sudo apt install gstreamer1.0-plugins-bad gstreamer1.0-libav -y

    2. Execute logout e login novamente para ativar a alteração nas permissões de usuario.

   -  Instalação do QGroundControl para Ubuntu Linux 16.04 LTS ou posterior:

    1. Efetue o download do `QGroundControl.AppImage <https://s3-us-west-2.amazonaws.com/qgroundcontrol/latest/QGroundControl.AppImage>`_
    2. Instale e execute os comandos do terminal:

       ::
         
           cd Downloads
           chmod +x ./QGroundControl.AppImage
           ./QGroundControl.AppImage

.. Tip::
   A ultima linha de comando não é necessário se o usuário for ao gerenciador de arquivos, procurar o arquivo QGroundControl baixado e clicar duas vezes nele.

-  **Android**
    
   - O QGroundControl está disponível no Google Play Store em `QGroundControl - play.google.com <https://play.google.com/store/apps/details?id=org.mavlink.qgroundcontrol>`_ .

 

-  **IOS**

   -  O QGroundControl está disponível na App Store.


