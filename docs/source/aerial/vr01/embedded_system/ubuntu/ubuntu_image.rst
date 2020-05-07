Obtenção das imagens do Ubuntu
==============================

Dentre os sistemas Ubuntu, foi escolhido o Ubuntu 15.04 por ser uma versão estável e adaptada para o sistema embarcado Gumstix Overo, além de ser a versão recomendada pelo proprio fabricante.

Esse tutorial explica como construir manualmente uma imagem do **Ubuntu 15.04** para placas Gumstix Overo COMs e realizar todos os procedimentos através de linhas de comando do terminal do Linux. Este topico é baseado nas instruções apresentadas no arquivo `README.md`_ do `repositório sobre Ubuntu para produtos Gumstix`_.

.. _README.md: https://github.com/gumstix/live-build/blob/master/README.md
.. _repositório sobre Ubuntu para produtos Gumstix: https://github.com/gumstix/live-build

Infelizmente, existe uma grande escassez de documentação detalhada e completa que explique como construir a imagem do sistema operacional Ubuntu 15.04 e quais os requisitos do sistema para realizar esta atividade. 

Configurando a imagem
~~~~~~~~~~~~~~~~~~~~~

Linhas de comando Linux para obtenção e montagem da imagem.

1. Instale as ferramentas necessárias em seu computador:

    ::

        $ sudo apt-get install -y git live-build qemu-user-static gcc-arm-linux-gnueabihf

2. Faça uma copia local do repositorio e altera o diretório de execução para este novo repositório

    ::

        $ git clone git://github.com/gumstix/live-build.git
        $ cd live-build

3. Escolha um tipo de imagem e uma máquina para construir. Este repositório suporta as máquinas Gumstix Overo, Duovero e Pepper.

    +--------------------+---------------------------------------+
    | **Nome da imagem** |             **Descrição**             |
    +--------------------+---------------------------------------+
    |        overo       |       Gumstix Overo COMs Series       |
    +--------------------+---------------------------------------+
    |       duovero      |      Gumstix DuoVero COMs Series      |
    +--------------------+---------------------------------------+
    |       pepper       | Gumstix™ Pepper Single Board Computer |
    +--------------------+---------------------------------------+


    +--------------------+--------------------------------------------------------------------+
    | **Nome da imagem** |                            **Descrição**                           |
    +--------------------+--------------------------------------------------------------------+
    |    vivid-console   |    Imagem de console do Ubuntu 15.04 orientada a desenvolvedores   |
    +--------------------+--------------------------------------------------------------------+
    |     vivid-lxde     | Ubuntu 15.04 "Vivid Vervet" com um ambiente de desktop leve (LXDE) |
    +--------------------+--------------------------------------------------------------------+
    |     sid-console    |       Imagem de console para desenvolvimento do Debian (Sid)       |
    +--------------------+--------------------------------------------------------------------+

Em seguida, execute o comando abaixo substituindo **<machine>** pela nome da maquina em que deseja instalar a imagem e **<image>** pelo nome da imagem que deseja, conforme apresentado nas tabelas acima.

    ::

        $ make MACHINE=<machine> IMAGE=<image> -j4

Por exemplo, para o desenvolvimento do projeto no computador embarcado Gumstix Overo, optou-se pela imagem **inserir** devido .... Logo, o comando executado foi:

    ::

        $ make MACHINE=overo IMAGE=vivid-console -j4

..  Note::
   Esse processo baixa vários gigabytes de código e, em seguida, faz uma enorme compilação. Portanto, esta etapa pode levar um tempo consideravel para a criação da imagem, a depender da sua conexão de internet. 

Se tudo ocorrer corretamente, os arquivos binarios para o carregamento de inicialização *u-boot* e um pasta compactada *tar* contendo os arquivos raiz do sistema operacional serão criados.

.. INSTALAR NO CARTÃO SD
.. https://github.com/gumstix/live-build/blob/master/README.md