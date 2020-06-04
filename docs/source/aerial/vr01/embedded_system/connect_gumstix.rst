Primeiros passos com o Gumstix Overo
=====================================

Montando o Gumstix COM na Placa de Expansão Tobi 
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

A configuração dos computadores Gumstix Overo consiste em um computador em modulo e uma placa de expansão. O modulo Overo se conecta a uma placa de expansão Tobi através dos dois conectores AVX de 70 pinos localizados na parte inferior do COM. Coloque a placa Tobi em uma superfície plana, antiestética, alinhe a COM com o contorno branco na placa acima dos conectores e pressione delicadamente a COM até que ela se encaixe no lugar.


	.. figure:: /img/Aerial/overo_front.png
	    :align: center

	.. figure:: /img/Aerial/gs_tobi.jpg
	    :align: center

Para utilizar a câmera, a placa de câmera deve ser conectada à parte superior do Overo COM através de um cabo de fita.

Conexões do computador
~~~~~~~~~~~~~~~~~~~~~~

	.. figure:: /img/Aerial/Overo_connection.png
	    :align: center

A placa de expansão Tobi vem com portas USB Host e portas USB On-the-Go (OTG). A porta USB Host é usada exclusivamente para conectar periféricos ao sistema, enquanto a porta USB OTG pode ser usada para conectar periféricos via cabo USB OTG ou para conectar o sistema Gumstix como periférico a um sistema host separado.

.. As portas USB Host e as portas USB OTG possuem diferentes taxas de amostragem de dados USB e diferentes correntes elétricas. 

A porta USB Host utiliza uma corrente de 500 mA e aceita uma taxa de amostragem de *High-speed* (HS) a 480 Mbit/s, enquanto a porta USB OTG tem uma corrente de 100 mA e suporta três diferentes taxas de amostragem, *Low Speed* (LS) a 1,5 Mbit/s, *Full Speed* (FS) a 12 Mbit/s e *High Speed* (HS) a 480 Mbit/s. 

.. Note::
	Muitos periféricos USB usam uma taxa de sinalização de *Full Speed* (FS) e não funcionam na porta USB Host, que é apenas de *High Speed* (HS). Se você estiver com problemas para conectar periféricos USB diretamente ao sistema Gumstix, conectar os periféricos primeiro a um hub USB com alimentação e depois conectar o hub com alimentação ao sistema Gumstix geralmente resolverá o problema.

Para a conexão de mais periféricos, além da quantidade de portas USB disponíveis na placa de expansão Tobi, recomendamos a utilização de um hub USB. O hub USB **energizado** deve ser conectado a porta USB Host da placa de expansão e um hub USB não **energizado** deve ser conectado a porta OTG USB da placa de expansão com um cabo USB On-the-Go.

.. Tip::
	O vídeo `Connecting Gumstix Tobi Expansion Board to Video Monitor`_ demonstra como conectar um Overo COM a um monitor e alguns periféricos através da placa Tobi.

.. _Connecting Gumstix Tobi Expansion Board to Video Monitor: https://www.youtube.com/watch?v=FxxEBn8Z_PA

Conectando-se ao Overo
~~~~~~~~~~~~~~~~~~~~~~

Primeiramente, insira o seu cartão microSD com a imagem do sistema operacional no slot de cartão na parte superior do Overo COM. Certifique-se de que ele se encaixa firmemente no lugar.

O computador Overo pode ser acessado conectando-o a um outro computador Linux ou Windows, ou até mesmo ser ligado diretamente a um monitor DVI e conectado a diversos periféricos, como mouse, teclado, monitor, saída de som, entre outros, através da placa de expansão Tobi.

Nesse trabalho, iremos optar por liga-lo a um computador Linux e estabelecer uma conexão seria via a porta USB Console por simplicidade. 

Estabelecendo uma conexão serial via console
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Para ligar o computador embarcado ao computador conecte um cabo USB ao computador e ao USB console da placa de expansão tobi. Feito isso, uma luz verde deve se acender indicando a conexão correta. Em seguida verifique em qual porta de comunicação serial a gumstix foi conectada, no Windows isso pode ser verificado acessando o Gerenciador de Dispositivos" e em seguida "Portas(COM e LPT)", no Linux basta executar o comando:

::

	$ dmesg | grep tty

.. Note::
	O comando ``dmesg`` é um comando que imprime as mensagens núcleo que, na maioria das vezes, são mensagens dos drivers do dispositivo. Quando acrescentamos ``grep tty`` estamos realizando uma busca nas saídas da função ``dmesg`` pelo termo ``tty`` e restringindo a sua saída aquelas mensagens que contém este termo.

A placa Gumstix deve ser a última entrada a aparecer. Por exemplo:

::

	user@Ubuntu:~$ dmesg | grep tty
	[    0.000000] printk: console [tty0] enabled
	[ 4214.120990] usb 2-1: FTDI USB Serial Device converter now attached to **ttyUSB0**


Em seguida será necessário executar um programa para emular o terminal, recomenda-se o programa screen, caso ainda não o tenha instalado basta executar a linha de comando ``sudo apt-get install screen``, ou no caso de utilizar o sistema operacional Windows recomenda-se o PuTTY. Estes programas que emulam terminais e executam apenas a tarefa de imprimir os caracteres recebidos pela porta serial, ou USB no caso, e enviar por essa mesma porta os caracteres digitados. 

Para iniciar o terminal de comunicação com a Gumstix basta executar, por exemplo, a seguinte linha de comando: 

::

	$ sudo screen /dev/<Nome do dispositivo USB> 115200

No caso da linha de comando do exemplo apresentada anteriormente, o termo ``ttyUSB0`` foi a porta encontrada ao utilizar o comando "dmesg" e "115200" é a velocidade de comunicação em *baud*. Nesse momento a comunicação entre a gumstix e o computador deve ser estabelecida e assim que a gumstix for ligada os caracteres devem começar a ser impressos na tela do computador.

Inicialize o sistema
~~~~~~~~~~~~~~~~~~~~~~

Feita conexão com o console, o Overo COM estará pronta para ser ligado. Para inicializar o sistema basta conectar a fonte de alimentação de 5 Volts à sua placa de expansão. Os indicadores LED no COM devem acender em azul e verde. O processo de inicialização será exibido no terminal da sua máquina host. 

Porém, antes de ligá-la, é importante comentar que o fabricante recomenda a limpeza de variáveis da memória flash sempre que iniciar uma **nova versão do sistema operacional no computador embarcado pela primeira vez**. Para fazê-lo basta interromper o processo de boot antes de seu início no momento em que aparece uma contagem regressiva na tela. O processo tipico de inicialização será similar ao seguinte:

::

	reading u-boot.img
	reading u-boot.img


	U-Boot 2012.04.01 (Jul 19 2012 - 17:31:34)

	OMAP36XX/37XX-GP ES1.2, CPU-OPP2, L3-165MHz, Max CPU Clock 1 Ghz
	Gumstix Overo board + LPDDR/NAND
	I2C:   ready
	DRAM:  512 MiB
	NAND:  512 MiB
	MMC:   OMAP SD/MMC: 0
	In:    serial
	Out:   serial
	Err:   serial
	Board revision: 1
	Direct connection on mmc2
	timed out in wait_for_pin: I2C_STAT=1000
	I2C read: I/O error
	Unrecognized expansion board
	Die ID #2d3800229ff8000001683b060a00b012
	Net:   smc911x-0
	Hit any key to stop autoboot:  0
	Overo # 

Uma vez interrompido o boot do sistema basta executar o comando ``nand erase 240000 20000`` para limpar as variáveis salvas e ``reset`` para reiniciar o processo de boot, como mostrado a seguir:

::

	# nand erase 240000 20000
	# reset


.. Note:: 
	Se os LEDs azul e verde no COM não acenderem e não for exibido nada no seu terminal, tente pressionar o botão de reset na placa de expansão até ver um processo de inicialização. Se o problema persistir, a imagem pode não ter sido instalada com sucesso. Recomenda-se que você tente instalar novamente ou usar uma imagem diferente.

A figura a seguir ilustra este procedimento. Os caracteres são impressos rapidamente e a contagem de tempo é de apenas 1 segundo para os núcleos do projeto Yocto, portanto é necessário ficar atento para interromper o processo.

.. adicionar imagem

Feito isso o processo de boot deve iniciar e diversas mensagens irão aparecer na tela. É importante verificar, na primeira vez que se inicia o sistema operacional, se nenhuma mensagem de erro aparece e, se tudo ocorrer bem, ao final do processo será exigido uma senha, se o computador embarcado chegou a esse ponto provavelmente tudo está em ordem.
A senha de acesso ao sistema Yocto é "root" e para o sistema Ubuntu gumstix, caso necessário, a senha é igual ao usuário.

Salvando a imagem do SO na memória flash
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

O computador embarcado Overo WaterSTORM COM da Gumstix R conta com uma memória interna não volátil de 1 GB do tipo Flash, memória suficiente para armazenarmos o sistema operacional. Apesar de o mais recomendado ser continuar usando o cartão SD, por possuir mais memória e ser transferido entre dispositivos com mais facilidade, ter o sistema operacional salvo na memória flash do computador embarcado pode ser útil. 

O site do fabricante descreve quatro maneiras distintas de se realizar este procedimento a maneira
que apresentou o melhor resultado foi a última das opções explicadas e é resumida a instalar na memória flash tudo o que foi instalado no cartão de memória e somado ao binário do núcleo através de um script fornecido em seu endereço eletrônico. O script desejado está disponivel em `Flashing with U-Boot - Write Images to Flash`_, porém, todo o processo será detalhadamente descrito a seguir.

.. _Flashing with U-Boot - Write Images to Flash: https://www.gumstix.com/support/faq/write-images-flash#flash-with-uboot

1. Com o cartão SD bootavel conectado ao seu computador host, acesse o diretorio ``/boot`` na partição *rootfs*. Por exemplo, assuma que o *rootfs* está montado em **/media/user/rootfs/**:

:: 

	$ cd /media/rootfs/boot

2. Crie um script para gravar os arquivos na memoria flash com o nome *flash-all.cmd*. Para isso basta executar o comando:

::

	$ nano flash-all.cmd

Copiar e colar o script:

::

	nand erase.chip

	# switch to 1-bit ECC and write MLO
	load mmc 0:2 ${loadaddr} /boot/MLO
	nandecc hw
	nand write ${loadaddr} 0x0 ${filesize}
	nand write ${loadaddr} 0x20000 ${filesize}
	nand write ${loadaddr} 0x40000 ${filesize}
	nand write ${loadaddr} 0x60000 ${filesize}

	# switch back to BCH8 and write u-boot
	nandecc sw bch8
	load mmc 0:2 ${loadaddr} /boot/u-boot.img
	nand write ${loadaddr} u-boot ${filesize}

	# write the kernel (if uImage...otherwise skip)
	load mmc 0:2 ${loadaddr} /boot/uImage
	nand write ${loadaddr} linux ${filesize}

	# write the filesystem
	load mmc 0:2 ${loadaddr} /boot/rootfs.ubi
	nand write ${loadaddr} rootfs ${filesize}

Em seguida confirme o nome do arquivo (**Ctrl+o**) e saia do editor de texto (**Ctrl+X**).

3. Para tornar o script executável e adiciona-lo à partição de boot do cartão SD bootável, basta executar e seguinte linha de comando, assumindo que a partição de inicialização esteja montada em /media/boot:

.. Warning::	
	Lembre-se de editar os nomes dos arquivos no script para coincidirem com os nomes dos arquivos que serão adicionados a seguir.

::

	$ mkimage -A arm -O linux -T script -C none -a 0 -e 0 -n "flash-all" -d flash-all.cmd /media/boot/flash-all.scr


.. Note::
	O comando ``mkimage`` é um comando utilizado para fazer imagens para serem utilizadas pelo "u-boot", as opções do comando e suas explicações são facilmente obtidas digitando ``man mkimage`` no terminal do Linux.
	
4. Desmonte, insira o cartão microSD no seu computador embarcado, inicie-o e aguarde o carregamento do u-boot. Interrompa o processo de inicialização quando vir **Hit any key to stop autoboot** e insira o comando:

::

	# mmc rescan 0; load mmc 0 ${loadaddr} flash-all.scr; source ${loadaddr}

Retire o cartão SD e reinicie o seu sistema. Se tudo correu bem, seu sistema deve iniciar normalmente.

Referências
-----------

   	* PITA, H. C. Desenvolvimento de sistema de comunicação multiplataforma para veículos aéreos de asa fixa. Faculdade de Tecnologia, Universidade de Brasília, 2018.
      
	* `4. Boot Your System`_ - gumstix.com

	* `Write Images to Flash`_ - gumstix.com

.. _4. Boot Your System: https://www.gumstix.com/support/getting-started/boot-system

.. _Write Images to Flash: https://www.gumstix.com/support/faq/write-images-flash
