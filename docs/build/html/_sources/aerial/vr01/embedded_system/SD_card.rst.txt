Particionando o Cartão SD
=========================

.. https://www.gumstix.com/support/getting-started/create-bootable-microsd-card
.. https://processors.wiki.ti.com/index.php/How_to_Make_3_Partition_SD_Card#How_to_Make_2_Partition_SD_Card

Este guia descreve o processo de particionamento, utilizando um sistema Linux, de um cartão SD em duas partes, denominadas de **boot** e **rootfs** com o objetivo de gerar um cartão SD bootável. O procedimento descrito abaixo é baseado método recomendado pelo fabricante do computador embarcado, utilizando um script que pode ser obtido em seu `repositório GitHub`_ e seguindo os procedimentos do tutorial `How to Make 2 Partition SD Card`_ da Texas Instrument e `Create Bootable MicroSD Card`_ da Gumstix. 

.. _repositório GitHub: https://github.com/gumstix/meta-gumstix-extras/blob/dizzy/scripts/mk2partsd
.. _How to Make 2 Partition SD Card: https://processors.wiki.ti.com/index.php/How_to_Make_3_Partition_SD_Card#How_to_Make_2_Partition_SD_Card
.. _Create Bootable MicroSD Card: https://www.gumstix.com/support/getting-started/create-bootable-microsd-card

.. Warning::
   **Leia e compreenda este artigo inteiro antes de executar qualquer procedimento descrito aqui.** 

Preparando o script
~~~~~~~~~~~~~~~~~~~

Crie um arquivo em seu computador chamado "*mk2PartSDCard*". Copie o conteúdo do script abaixo para este arquivo e salve-o.

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

Torne o script executável com o comando a seguir

	::

		$ chmod 755 mk2PartSDCard

.. Warning::
   **Não execute o script se não tiver certeza do dispositivo correto a particionar**. Se você especificar o dispositivo conectado ao disco rígido da máquina host em vez do leitor de cartão SD, você destruirá o disco rígido da sua máquina. 

Examinando o sistema Linux
~~~~~~~~~~~~~~~~~~~~~~~~~~

Este script requer um único parâmetro de entrada, que é a especificação do sistema de arquivo do dispositivo a ser particionado, neste caso o dispositivo conectado ao leitor de cartão SD. Esta seção mostra como descobrir a qual sistema de arquivo o cartão SD está conectado.

O comando abaixo pode ser usado para examinar o sistema de armazenamento do computador Linux. Normalmente o cartão SD terá uma única partição formatada no padrão Windows FAT, configuração típica encontrada em cartões adquiridos em varejo. 

	::

		df -hT

Após executar o comando, procure pelo Cartão SD, ele pode apresentar um tamanho menor que o informado pelo fabricante, por exemplo, um cartão SD de 4GB pode apresentar 3,9GB ou menos. 
Além disso, o cartão provavelmente estará em um Sistema de Arquivo */dev/sdb* no caso de computadores com um unico leitor de cartão SD. Para máquinas com mais de um leitor de cartão, pode haver um leitor em */dev/sdb* e outro em */dev/sdc*, para este caso, a melhor modo de saber é pela capacidade de armazenamento do cartão. 

O parâmetro a ser passado para o script é sistema de arquivos no qual o cartão SD está.

.. Warning::
   **Não passe em hipótese alguma a partição do sistema host Linux como parâmetro. Passar a partição associada ao disco rígido da máquina host para esse script destruirá o disco rígido da máquina host**.

**Veja o exemplo abaixo.**

	::

		lucas@Ubuntu-7348:~$ **df -hT**
		Sist. Arq.     Tipo      Tam. Usado Disp. Uso% Montado em
		udev           devtmpfs  3,9G     0  3,9G   0% /dev
		tmpfs          tmpfs     789M  2,1M  787M   1% /run
		/dev/sda1      ext4       30G   16G   13G  55% /
		tmpfs          tmpfs     3,9G   70M  3,8G   2% /dev/shm
		/dev/loop6     squashfs   15M   15M     0 100% /snap/gnome-characters/399
		tmpfs          tmpfs     789M   16K  789M   1% /run/user/121
		**/dev/sdb1      vfat      954M   48K  954M   1% /media/lucas/DSC_DISK**

O cartão utilizado para o exemplo possui 1GB com uma partição única formatada em Windows padrão FAT. Como pode ser visto, o resultado do comando ``df -hT`` no sistema Linux diz que há um cartão SD conectado ao dispositivo */dev/sdb*. Portanto, o parâmetro a ser passado para o script é */dev/sdb*. Além disso, podemos verificar que a partição do sistema host Linux está em */dev/sda1*. Isso indica que a máquina host possui uma unidade SATA em */dev/sda*. 

Executando o script
~~~~~~~~~~~~~~~~~~~

Após verificar o dispositivo correto a ser particionado, é necessário desmontar qualquer diretório do dispositivo. Para isso utilize o comando:

	::

			$ umount <device name>

No exemplo acima, o diretório */media/lucas/DSC_DISK* está montado em */dev/sdb1*, portanto para desmonta-lo é necessário executar o seguinte comando:

	::

		$ umount /dev/sdb1

O script deve ser executado com permissão de super usuário especificando o leitor de cartão SD. No Ubuntu, isso é feito acrescentando ``sudo`` antes do comando. 

	::

		$ sudo ./mk2partsd <device name>

No caso do exemplo apresentado, o comando a ser realizado é:

	::

		$ sudo ./mk2PartSDCard /dev/sdb


Quando a senha for solicitada pelo sistema, use a senha da conta do usuário para confirmar o procedimento.

Em uma execução bem-sucedida, o terminal será semelhante a imagem a seguir. Um erro pode aparecer é do **sfdisk** (como mostrado abaixo), porém este pode ser ignorado com segurança.
	
.. adicionar imagem