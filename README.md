# jogo-estruturas-de-dados

Este é um projeto desenvolvido para a disciplina de Algoritmos e Estruturas de Dados (SIN 211)
do curso de Sistemas de Informação da UFV CRP - Universidade Federal de Viçosa Campus Rio Paranaíba.

O projeto consiste em um jogo de três fases, onde o player ('P') deve se movimentar dentro do tabuleiro
até alcançar o objetivo ('O'). Serão fornecidas algumas sequências de comandos e o jogador deve decidir
qual delas usar e quantas vezes usar. As sequências de comandos são inseridas no jogo utilizando as estruturas
de dados pilha e fila (dinâmicas).

* SOBRE OS COMANDOS:  
	- 'F' = player (P) move para frente na direção em que estiver apontado;
	- 'D' = player (P) altera a direção uma vez no sentido horário;
	- 'E' = player (P) altera a direção uma vez no sentido anti-horário;

O jogador irá iniciar cada fase possuindo três chances de vencer, caso não consiga atingir o objetivo, o
jogador perde e o jogo termina (game over). Caso o jogador alcance o objetivo em todas as três fases, o
jogador vence e o jogo termina. Boa sorte!
______________________________________________________________________________________________________________________

	* AUTORES: 
		- Fabio Henrique Sena Bastos (Turma: 1 | Matrícula: 7554)
		- Luiz Benedito Alves Neto (Turma: 1 | Matrícula: 7557)
		- Reinaldo Gonçalves Pereira Neto (Turma: 2 | Matrícula: 7627)
______________________________________________________________________________________________________________________

    Exemplo de combinação de comandos:

    Fase 1: 
	
    1) F F
    2) E F
    3) D F F
  
    Execução possível:

    1-2-1 
    3-1-1 
    1-1-1 
    2-1-1 
    1-1-1 
    3-1-1 
    1-1-0

    Fase 2:

    1) F F F
    2) D F F
    3) E F F
    4) F F

    Execução possível:

    3-1-1  
    1-2-1  
    2-1-1  
    1-1-1  
    3-1-1  
    2-1-0  

    Fase 3:

    1) F F
    2) F E
    3) F D
    4) D F F

    Execução possível:

    1-2-1 
    4-1-1 
    1-1-1 
    2-1-1 
    1-2-1 
    4-1-1 
    1-1-0

    Execução possível para a parte 2:

    1-1-1 
    3-1-1 
    1-2-1 
    2-1-1 
    1-1-1 
    4-2-0 
