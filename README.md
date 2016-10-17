# Encontra-Caminho-Backtracking

Um espaço geográfico é representado por uma matriz, onde cada célula representa um quadrado de
1 metro quadrado. Temos neste espaço um cachorro, cuja posição inicial está
representada por um quadrado marcado com '2' (ou seja, o cachorro está inicialmente nesta posição).
O cachorro deverá caminhar pelos vários quadrados (ou seja, várias posições) até chegar
em uma das células da primeira linha da tabela (linha de cima).
Os quadrados marcados com '3' representam paredes, pelas quais o cachorro obviamente não pode
passar. O cachorro só pode movimentar para cima, para baixo e para os lados. Ou seja,
não pode se movimentar nas diagonais.
Você deverá escrever um programa na linguagem C que utilize um algoritmo projetado
por você, que leia um arquivo com as informações do local onde o cachorro está bem
como sua exata posição inicial. Seu programa deverá então movimentar o cachorro até
que ele chegue em uma das células da primeira linha da tabela, mostrando na tela cada
movimentação feita.
Seu programa deverá obrigatoriamente usar backtracking. Uma função recursiva
chamada movimenta_cachorro deverá ser criada. Isso significa que primeiramente vocêdeverá encontrar a posição inicial do cachorro. Quando encontrar deverá chamar esta
função uma única vez, e a partir daí ela chamará ela mesma, até que o cachorro chegue na
primeira linha (linha zero).
