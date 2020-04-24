Obtenção das imagens do Yocto Project
=====================================

.. https://github.com/gumstix/yocto-manifest/blob/warrior/README.md

Para realizar o processo de iniciação do sistema operacional Yocto Project no computador embarcado Gumstix, precisamos de três arquivos específicos, são eles o primeiro estágio do sistema de iniciação, o arquivo MLO (*Minimal Loader*), o segundo estágio do sistema de iniciação, o arquivo *u-boot.img* (a sigla vem de *Universal Bootloader*), e a imagem do sistema, que em nosso caso será o Yocto 1.8.2 com kernel Linux. 

.. adicionar a figura

A figura mostra um exemplo dos arquivos descritos no parágrafo anterior, observe que, neste caso, há também uma pasta compactada que contém os arquivos raiz do sistema operacional. O modo mais simples encontrado para se obter esses arquivos e a imagem do sistema operacional é seguindo os passos do arquivo `README.md`_ do `repositório do projeto Yocto para produtos Gumstix`_. A vantagem de se utilizar esse método ao invés de simplesmente obter a imagem pronta do sistema operacional é que caso seja necessário poderemos modifica-la.

.. _README.md: https://github.com/gumstix/yocto-manifest/blob/warrior/README.md
.. _repositório do projeto Yocto para produtos Gumstix: https://github.com/gumstix/yocto-manifest

Esse tutorial explica como obter a imagem e realizar todos os procedimentos através de linhas de comando do terminal do Linux. Porem, para executar essa etapa é altamente recomendado o cumprimento dos requisitos indicadas pelo projeto Yocto. 

.. _Yocto: https://www.yoctoproject.org/docs/1.7/ref-manual/ref-manual.html

.. Essas versões do Linux podem ser encontradas, junto de mais informações úteis no manual de referência do projeto `Yocto`_ , mais especificamente no item 1.3.1 *Supported Linux Distributions*.


Requisitos do Sistema
~~~~~~~~~~~~~~~~~~~~~

.. https://www.yoctoproject.org/docs/1.7/yocto-project-qs/yocto-project-qs.html#yp-resources

.. Note ::
   Para mais informações a respeito dos requisitos do sistema, consulte `System Requirements - Yocto Project Reference Manual`_.

.. _System Requirements - Yocto Project Reference Manual: https://www.yoctoproject.org/docs/1.7/ref-manual/ref-manual.html#intro-requirements

O desenvolvimento de projetos no ambiente do Yocto Project requer que alguns requisitos sejam cumpridos, são eles:

	* Um sistema com no mínimo 25 GB de espaço livre em disco executando uma distribuição Linux suportada (ou seja, versões recentes do Fedora, openSUSE, CentOS, Debian ou Ubuntu). Se o sistema host suportar vários núcleos e encadeamentos, você poderá configurar o sistema de construção do Yocto Project para diminuir significativamente o tempo necessário para construir imagens.

	* Pacotes apropriados instalados no sistema utilizado para realizar as compilações.

	* Uma distribuição do Projeto Yocto.

A equipe do Yocto Project verifica continuamente mais e mais distribuições Linux a cada versão lançada. Em geral, se você possui a versão atual menos uma das seguintes distribuições, não deve ter problemas.

	* Ubuntu

	* Fedora

	* openSUSE

	* CentOS

	* Debian

.. Note::
   Para obter uma lista mais detalhada de distribuições que suportam o Projeto Yocto, consulte a seção `Supported Linux Distributions`_ em Yocto Project Reference Manual .

.. _Supported Linux Distributions: http://www.yoctoproject.org/docs/1.7/ref-manual/ref-manual.html#detailed-supported-distros

O sistema de compilação OpenEmbedded pode ser executado nas distribuição mais modernas que possuam as seguintes versões para Git, tar e Python.

	* Git 1.8.3.1 or greater

	* tar 1.27 or greater

	* Python 3.4.0 or greater.

Além disso, recomenda-se atualizar todos os comandos do Linux que serão utilizados nessa seção.

.. Note::
   Consulte a seção `Required Git, tar, and Python Versions`_ no Yocto Project Reference Manual para obter informações.

.. _Required Git, tar, and Python Versions: http://www.yoctoproject.org/docs/1.7/ref-manual/ref-manual.html#required-git-tar-and-python-versions

É necessaria ainda a instalação dos pacotes de host essenciais para a construção da imagem. O comando a seguir instala os pacotes de host com base em sua distribuição Ubuntu:

	::

		$ sudo apt-get install gawk wget git-core diffstat unzip texinfo gcc-multilib
		$ build-essential chrpath socat cpio python python3 python3-pip python3-pexpect 
		$ xz-utils debianutils iputils-ping python3-git python3-jinja2 libegl1-mesa libsdl1.2-dev 
		$ pylint3 xterm

..    $ sudo apt-get install gawk wget git-core diffstat unzip texinfo gcc-multilib \ build-essential chrpath socat cpio python python3 python3-pip python3-pexpect \ xz-utils debianutils iputils-ping python3-git python3-jinja2 libegl1-mesa libsdl1.2-dev \ pylint3 xterm

.. Note::
   Para instalar os pacotes de host em outras distribuições Linux suportadas, consulte a seção `Required Packages for the Build Host`_ em Yocto Project Reference Manual.
   
.. _Required Packages for the Build Host: http://www.yoctoproject.org/docs/3.0.1/ref-manual/ref-manual.html#required-packages-for-the-build-host

Configurando a imagem
~~~~~~~~~~~~~~~~~~~~~

Linhas de comando Linux para obtenção e montagem da imagem.

1.  **Instalando o repositorio**

Baixa os scripts do repositorio:

	::

		$ curl http://commondatastorage.googleapis.com/git-repo-downloads/repo > repo

Torna os arquivos executaveis:

	::

		$ chmod a+x repo

Move os arquivos para o caminho do sistema:

	::

		$ sudo mv repo /usr/local/bin/

Se tudo ocorrer bem, deverá aparecer uma mensagem de utilização. Esse comando não é obrigatorio:

	::

		$ repo --help

2. **Criando um repositorio local**

Cria um diretorio para os arquivos e altera o diretorio de execução para o novo repositorio:

	:: 

		$ mkdir yocto
		$ cd yocto

Seleciona o ramo mais estavel do repositorio:

	::
		
		$ repo init -u git://github.com/gumstix/yocto-manifest.git -b fido

Uma inicialização bem-sucedida terminará com uma mensagem informando que o .repo foi inicializado no seu diretório de trabalho. Agora seu diretório deve conter uma pasta .repo onde os arquivos de controle de repositorio estão armazenados, mas não é necessario abrir o diretório.

3. **Baixando os arquivos**

Baixa os arquivos do repositorio:

	::

		$ repo sync

.. Note::
   Está etapa pode demorar mais de 20 minutos, dependendo da sua conexão de internet.

Força todos os arquivos temporarios a serem escritos em dipositivos persistentes:

	::

		$ sync

4. **Iniciando o Yocto Project Build Environment**

Copia as informações de configuração padrão no diretório **poky/build/conf** e configura algumas variáveis de ambiente para o sistema de montagem da imagem:

	::

		$ export TEMPLATECONF=meta-gumstix-extras/conf 
		$ source ./poky/oe-init-build-env

.. Note::
   Este diretório de configuração não está sob controle de revisão; você pode editar esses arquivos de configuração para sua instalação específica. 

5. **Criando a imagem**

Baixa os codigos fonte e compilando as imagens do sistema:

	::

		$ bitbake gumstix-console-image

.. Tip::
   Esse processo baixa varios gigabytes de codigo e, em seguida, faz uma enorme compilação. Portanto, certifique-se de ter pelo menos os 25GB de espaço livre. Esta etapa pode levar um dia ou mais para a criação da imagem, a depender da sua conexão de internet. Não se preocupe, é apenas a primeira compilação que demora um pouco.

Após a finalização da execução de todos os comandos, recomenda-se verificar a pasta **/yocto/build/tmp/deploy/images/overo**, essa pasta deve conter arquivos binários de kernel e bootloaders e arquivos de diretório raiz no formato .tar. 

.. Warning::
   Possíveis causas de falhas provavelmente estão relacionadas com softwares faltosos ou desatualizados, sistema operacional não compatível ou falta de espaço livre.

A figura abaixo apresenta um exemplo do conteúdo da pasta descrita, essa pasta deve ser semelhante ao obtido após a execução dos procedimentos anteriores.

.. imagem

Na figura podemos encontrar tanto os bootloaders necessários descritos anteriormente como o binário (.ubi) e arquivos do diretório raiz de algumas versões do projeto
Yocto. A versão utilizada foi a mais recente à época, "gumstix-console-image-overo-20180509042558.rootfs.tar.bz2", entretanto tudo oque foi implementado foi testado também,
na versão recomendada, "gumstix-console-image-overo.tar.bz2", portanto as duas imagens podem ser utilizadas. Os bootloaders utilizados foram "MLO-overo" e "u-boot-overo.img".


