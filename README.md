/*Jogo Desenvolvido por:
Ana Clara Nobre Mendes,
Rodrigo Nuntes de Castro,
Moises Cavalcante*/

drifts
======

--------------------------------------------------- O J O G O -----------------------------------------------------

O projeto consiste no desenvolvimento, na linguagem C++ empregando a biblioteca SDL(http://www.libsdl.org), de um jogo conhecido como Drifts. Para desenvolvê-lo foi necessário o suporte da biblioteca SDL nas máquinas utilizadas.
O jogo consiste em o usuário comandar com o mouse o movimento de uma bola amarela em uma área da tela. O objetivo do jogo é colar à bola amarela o maior número de bolas verdes que for possível, evitando as bolas púrpuras. Tocar uma bola azul transforma suas bolas verdes em pontos e as faz desaparecer. É necessário estar carregando pelo menos três bolas verdes para receber pontos.
O objetivo do jogo é o acúmulo de pontos, o usuário poderá acumular o maior número de pontos com as bolas verdes antes de suas vidas acabarem, o jogador começa com 3 vidas e as perde a medida que toca nas bolas púrpuras.

------------------------------------------------- C O N F I G U R A Ç Ã O ------------------------------------------

A biblioteca SDL funciona independente do Sistema Operacional(S.O.) utilizado para execução do jogo, entretanto cada S.O. possue uma configuração diferente para utilizá-la. No nosso caso criamos o jogo passível de execução no sistema Windows e Linux.
No Windows o usuário só precisa fazer o download de todo o diretório do jogo e executar o .exe existente, pois a pasta está composta por tudo o que a biblioteca precisa para executar e compilar, imagens por exemplo precisam de outras bibliotecas para sofrerem renderização.
Já no sistema Linux é necessário fazer o download da biblioteca SDL, por meio dos comandos;
“apt-get install(Ubuntu) ou yum install(Fedora)” dos seguintes componentes:

SDL2-devel.x86_64 | SDL2_image-devel.x86_64 | SDL2_mixer-devel.x86_64

Após o download, automaticamente a biblioteca estará instalada no sistema e devidamente configurada em sua máquina.
Com um editor de texto com build, por exemplo, o Sublime Text você precisará compilar o arquivo drifts.cpp e depois executar no terminal o executável "drifts".
É preciso apenas acessar o terminal, e digitar: 

./drifts

Entretanto, se você quer compilar diretamente o arquivo drifts.cpp, pode digitar diretamente no terminal:

g++ -o drifts drifts.cpp -lSDL2 -lSDL2_image

---------------------------------------------------- P O N T U A Ç Ã O ----------------------------------------------

O usuário começará o jogo por meio do movimento da bola amarela, se a lista de bolas verdes comandadas pelo mouse, que o usuário coletou no jogo, tocar uma bola púrpura, o jogador perde uma vida (ou encerra o jogo se o jogador tiver somente uma vida), já se ele obtiver no mínimo três bolas verdes e encostar em uma bola azul, o jogador obterá (3)três pontos em seu score, portanto quanto maior a quantidade de bola verde ele conseguir captar, maior a quantidade de pontos obtidos. 
Assim, é necessário agrupar três bolas verdes para que seja contado um ponto. 
Bolas adicionais conferem pontos extras, da seguinte forma: 4 bl (5 pt), 5 bl (11 pt), 6 bl (17 pt), 7 bl (25 pt), 8 bl (33 pt), 9 bl (41 pt) e 10 ou mais bls (51 pt). Vence o jogo o jogador que obtiver maior pontuação e não morrer 3(três) vezes, portanto, sem “Game Over”.
