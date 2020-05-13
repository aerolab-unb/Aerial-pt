Particionando o Cartão SD
=========================

.. https://www.gumstix.com/support/getting-started/create-bootable-microsd-card
.. https://processors.wiki.ti.com/index.php/How_to_Make_3_Partition_SD_Card#How_to_Make_2_Partition_SD_Card

Este guia descreve o processo de particionamento, utilizando um sistema Linux, de um cartão SD em duas partes, denominadas de **boot** e **rootfs** com o objetivo de gerar um cartão SD bootável. O procedimento descrito abaixo é realizado utilizando o gerenciador de discos do proprio Ubuntu, não sendo necessário instalar novos *softwares*. 

Usualmente, o cartão SD é configurado em uma única partição formatada no padrão Windows FAT, configuração típica encontrada em cartões adquiridos em varejo. Porém, aqui particionaremos o cartão SD em duas partes, que serão denominadas **boot** e **rootfs**, sendo o sistema de gestão de arquivos da partição **boot** "VFAT" e da partição **rootfs** "ext4".

A figura abaixo apresenta um exemplo de cartão de memória com as partições já definidas, montadas e contendo o sistema operacional do computador embarcado. No exemplo o cartão SD possui um total de 4 GB, porém, para o projeto Yocto, um cartão de memória de 2 GB deve ser suficiente.

.. figure:: /img/Aerial/SD_parted.png

Procedimentos
~~~~~~~~~~~~~

.. Warning::
      A versão do sistema operacional utilizada nas atividades foi Ubuntu 14.04 (LTS). Os procedimentos podem ter algumas diferenças a depender da versão e distribuição do Linux a ser utilizada.



.. fontes
.. repositório GitHub: https://github.com/gumstix/meta-gumstix-extras/blob/dizzy/scripts/mk2partsd
.. How to Make 2 Partition SD Card: https://processors.wiki.ti.com/index.php/How_to_Make_3_Partition_SD_Card#How_to_Make_2_Partition_SD_Card
.. Create Bootable MicroSD Card: https://www.gumstix.com/support/getting-started/create-bootable-microsd-card