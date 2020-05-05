Instalando o Sistema Operacional
================================

A instalação do sistema operacional não é uma tarefa trivial, além disso existe uma escassez de documentação detalhada e completa que explique como instalar o sistema operacional no computador embarcado, logo será documentado nesta seção os procedimentos necessários para a instalação de um sistema operacional. Na fase atual dos trabalhos instalamos ambos os sistemas, de tal forma, podemos decidir posteriormente qual dos dois sistemas será melhor para nossa aplicação. 

.. Note:: 
   Os tutoriais oficiais podem ser encontrados no site da `Gumstix`_ e nos repositórios do GitHub do projeto `Yocto`_ e `Ubuntu`_ para produtos Gumstix.

.. _Gumstix: https://www.gumstix.com/
.. _Yocto: https://github.com/gumstix/yocto-manifest
.. _Ubuntu: https://github.com/gumstix/live-build

Obtenção das imagens do SO
~~~~~~~~~~~~~~~~~~~~~~~~~~

.. https://github.com/gumstix/yocto-manifest/blob/warrior/README.md

Essencialmente o dispositivo precisa apenas executar um pequeno programa, geralmente localizado em uma memória não volátil do tipo *Read-Only Memory* (ROM), para acessar a outro dispositivo de memória não volátil que armazene o sistema operacional, e carregar o sistema operacional na memória volátil de rápido acesso ou *Random Access Memory* (RAM) onde ele poderá ser executado. Em sistemas mais robustos ocorre, na verdade, um encadeamento desses pequenos programas, chamados de bootloaders, onde um primeiro estágio executa um segundo estágio que carrega programas mais complexos e, por sua vez, executa um terceiro estágio e assim por diante até que o sistema operacional seja completamente carregado e esteja pronto para ser executado por si só.

Existem dois métodos para obter os sistemas operacionais para o Gumstix Overo. O primeiro método é baixar uma imagem pré-compilada diretamente do Gumstix. O segundo método é construir você mesmo a imagem em seu computador. A criação manual da imagem do sistema operacional possui benefícios adicionais, como personalização ou adição de pacotes binários adicionais à sua imagem base. Também compus um arquivo bash que cria scripts para o processo de criação manual que é referenciado e explicado no final desta documentação. A possibilidade de personalização será muito importante no desenvolvimento do projeto.

	.. toctree::
	   :maxdepth: 2

	   yocto/yocto_image

Preparando o Cartão de Memória
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Uma vez obtida a imagem do sistema operacional podemos transferir os arquivos para o computador embarcado para, enfim, ligá-lo. Essa tarefa será realizada por meio de um cartão SD que funcionará como o disco rígido do computador embarcado.

Logo, o cartão SD irá conter tanto os programas necessários para boot, que serão utilizados apenas na inicialização do computador, quanto os outros programas, que podem ser utilizados a qualquer momento e realizarão modificações constantes no cartão SD. Portanto a melhor maneira de lidar com essa divisão é particionar o cartão SD em duas partições que serão denominadas boot e rootfs.

Esse é um procedimento muito comum e existem inúmeras maneiras de fazê-lo, entretanto, a maneira recomendada é apresentada no tópico abaixo e é baseada nas recomendações do fabricante. Um ponto negativo deste procedimento é o excesso de memória alocada para a partição de boot, no caso são reservados 528 MB à partição de boot e utilizam-se menos de 100 MB. Sendo assim, caso futuramente venha a faltar espaço para armazenamento de dados será possível ampliar a partição roots refazendo esta divisão.


	.. toctree::
	   :maxdepth: 2

	   SD_card

