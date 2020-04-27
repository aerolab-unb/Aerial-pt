Particionando o Cartão SD
=========================

Este guia descreve o processo de particionamento, utilizando um sistema Linux, de um cartão SD em duas partes, denominadas de **boot** e **rootfs**. O procedimento descrito abaixo é baseado metodo recomendado pelo fabricante do computador embarcado, utilizando um script que pode ser obtido em seu `repositório GitHub`_ e seguindo os procedimentos do tutorial `How to Make 2 Partition SD Card`_ da Texas Instrument. 

.. _repositório GitHub: https://github.com/gumstix/meta-gumstix-extras/blob/dizzy/scripts/mk2partsd

.. _How to Make 2 Partition SD Card: https://processors.wiki.ti.com/index.php/How_to_Make_3_Partition_SD_Card#How_to_Make_2_Partition_SD_Card

.. Warning::
   **Leia e compreenda este artigo inteiro antes de executar qualquer procedimento descrito aqui.** 

Preparando o script
~~~~~~~~~~~~~~~~~~~

Crie um arquivo em seu compuador chamado "*mk2PartSDCard*". Copie o conteúdo do script abaixo para este arquivo e salve-o.

::
	
	#! /bin/sh
	#
	# (c) Copyright 2014 Gumstix, Inc.
	# Licensed under terms of GPLv2
	#
	# Based on mk2PartSDCard.sh from Texas Instrument
	# http://processors.wiki.ti.com/index.php/How_to_Make_3_Partition_SD_Card
	#
	# example usage: $ sudo mk2partsd /dev/sdb

	DRIVE=$1

	dd if=/dev/zero of=$DRIVE bs=1024 count=1024

	sfdisk --force $DRIVE << EOF
	128,130944,0x0C,*
	131072,,,-
	EOF

	if [ -b ${1}1 ]; then
		mkfs.vfat -F 32 -n "boot" ${DRIVE}1 
	else 
		mkfs.vfat -F 32 -n "boot" ${DRIVE}p1
	fi

	if [ -b ${1}2 ]; then
		mkfs.ext4 -L "rootfs" ${DRIVE}2
	else 
		mkfs.ext4 -L "rootfs" ${DRIVE}p2
	fi

.. Tip::
   Para modificar o espaço alocado em cada partição... 

.. Descobrir como modificar o espaço alocado 
   Dica: "Essa divisão pode ser modificada alterando-se os valores logo abaixo de "sfdisk" no script."

Torne o script executavel com o comando a seguir

::

	$ chmod 755 mk2PartSDCard

Examinando o sistema Linux
~~~~~~~~~~~~~~~~~~~~~~~~~~

Este script requer um unico parametro de entrada, que é a especificação do sistema de arquivo do dispositivo a ser particionado, neste caso o dispositivo conectado ao leitor de cartão SD. Esta seção mostra como descobrir qual a sistema de arquivo o cartão SD está conectado e no qual está conectado ao disco rígido.

.. Warning::
   **Não execute o script se não tiver certeza do dispositivo correto a particionar**. Se você especificar o dispositivo conectado ao disco rígido da máquina host em vez do leitor de cartão SD, você destruirá o disco rígido da sua máquina. 

O comando abaixo pode ser usado para examinar o sistema de armazenamento do computador Linux. Normalmente o cartão SD terá uma unica partição formatada no padrão Windows FAT, configuração tipica encontada em cartões adquiridos em varejo. 

::

	df -hT

Após executar o comando, procure pelo Cartão SD, ele apresentará um tamanho um pouco menor que o informado pelo fabricante, por exemplo, um cartão SD de 4GB pode apresensentar 3,9GB ou menos. 
Além disso, o cartão deve estar em um Sistema de Arquivo */dev/sdb* no caso de computadores com um unico leitor de cartão SD. Para maquinas com mais de um leitor de cartão, pode haver um leitor em */dev/sdb* e outro em */dev/sdc*, para este caso,  a melhor modo de saber é pela capacidade de armazenamento do cartão. 

Outra etapa importante é localizar a partição do sistema host Linux, provavelmente armazenada em */dev/sda1*, caso a maquina host possua uma unidade SATA em */dev/sda1*, ou */dev/hda*, caso a maquina tenha uma unidade IDE mais antiga. Porem, o sistema host Linux ainda pode estar em outro tipo de sistema de arquivo, portanto é importante ter cuidado.

O parametro a ser passado para o script é sistema de arquivos no qual o cartão SD está.

**Veja o exemplo abaixo.**

::

	lucas@Ubuntu-7348:~$ df -hT
	Sist. Arq.     Tipo      Tam. Usado Disp. Uso% Montado em
	udev           devtmpfs  3,9G     0  3,9G   0% /dev
	tmpfs          tmpfs     789M  2,1M  787M   1% /run
	/dev/sda6      ext4       30G   16G   13G  55% /
	tmpfs          tmpfs     3,9G   70M  3,8G   2% /dev/shm
	/dev/loop6     squashfs   15M   15M     0 100% /snap/gnome-characters/399
	tmpfs          tmpfs     789M   16K  789M   1% /run/user/121
	/dev/sdb1      vfat      954M   48K  954M   1% /media/lucas/DSC_DISK

O cartão utilizado para o exemplo possui 1GB com uma partição única formatada em Windows padrão FAT. Como pode ser visto, o resultado do comando df no sistema Linux diz que possui um cartão SD conectado ao dispositivo */dev/sdb*. Portanto, o parametro a ser passado para o script é */dev/sdb*. Outro ponto importante é que a partição do sistema host Linux está em */dev/sda6*. Isso indica que a máquina host possui uma unidade SATA em */dev/sda*. 




