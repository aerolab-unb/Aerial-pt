Procedimento
============

Montagem das Partições
~~~~~~~~~~~~~~~~~~~~~~

O procedimento de montagem de uma partição de memória consiste em uma atividade do sistema operacional para garantir que a transferência de informação será feita da maneira correta, basicamente o dispositivo conectado é lido por inteiro para identificar os arquivos nele armazenados e aonde podem ser escritas novas informações sem que haja sobreposição de dados.

Para isso, abra o terminal e insira os comandos abaixo:

 ::
    
   $sudo mount −t vfat /dev/<*mmcblk0p*>1/  media/*Nome_de_Usuário*/boot  (Comando para montar a partição boot)
   $sudo mount -t ext4 /dev/<*mmcblk0p*>2/  media/*Nome_de_Usuário*/rootfs  (Comando para montar a partição rootfs) 
   
.. Note::
   Os dois nomes entre asteriscos devem ser mudados. Sobre *Nome_de_Usuário* deve ser mudado para o nome do login da máquina em uso e sobre *mmcblk0p* deve ser mudado para o nome do arquivo que o sistema cria automaticamente quando reconhece o cartão pela primeira vez e esse arquivo estará presente em /dev com nome semelhante ao *mmcblk0p*.

Cópia e Extração de Arquivos 
~~~~~~~~~~~~~~~~~~~~~~~~~~~~ 
Cópia
----- 

Dois arquivos de nome MLO e u-boot.img devem ser copiados para a partição boot do cartão de memória. Para isso,para que os comando a seguir funcionem, é necessário que esteja na pasta que contém os arquivos pelo terminal. 

Comando para entrar na pasta que contém os arquivos:
 
 ::
 
   $ cd yocto | cd temp | cd deploy | cd images | cd overo
   
Após esses comandos, o terminal estará como a imagem abaixo:

.. IMAGEM DO TERMINAL AINDA SERA COLOCADA

Após os passos anterios, digite os seguintes comandos:

  ::
  
   $ sudo cp MLO /media/*Nome_de_Usuário*/boot/
   $ sudo cp u-boot.img /media/*Nome_de_Usuário*/boot 
   
Extração
--------

Com o terminal na mesma pasta que foi realizada o procedimento de cópia dos arquivos, insira o seguinte comando para extração do diretório do sistema:

::

  $ sudo tar -xjvf gumstix-console-image-overo.tar.bz2 -C /media/*Nome_de_Usuário*/rootfs   
  

Resultado no Cartão de Memoria
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Partição boot:

.. figure:: /img/Aerial/SD_card/boot.png
	:align: center


Partição rootfs:  

.. figure:: /img/Aerial/SD_card/rootfs.png
	:align: center

   
   
   
       
