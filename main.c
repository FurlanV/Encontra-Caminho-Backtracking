/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: vinicius
 *
 * Created on September 30, 2016, 7:15 PM
 */

#include "EncontraCaminho.h"

/*
 * 
 */
int main(int argc, char** argv) {

    InfoLocal local;
    int marca;
    char nomeArquivo[30];
    int arq = 1;
    int opc;


    while (arq) {

        printf("Digite o nome do arquivo: ");
        scanf("%s", nomeArquivo);
        getchar();

        if (montaMapa(&local, nomeArquivo)) {

            printf("1- Resolver caminho | 2- Resolver caminho em modo análise\n");
            scanf("%d", &opc);

            switch (opc) {
                case 1:
                    imprimirMapa(local);
                    printf("\nVa apertando 'Enter' para ir para o próximo passo\n");
                    getchar();
                    movimenta_cachorro(&local, local.posicaoInicialX, local.posicaoInicialY, &marca);
                    break;
                case 2:
                    imprimirMapa(local);
                    printf("\nVa apertando 'Enter' para ir para o próximo passo\n");
                    getchar();
                    movimenta_cachorro(&local, local.posicaoInicialX, local.posicaoInicialY, &marca);
                    printf("O cachorro se movimentou %d vezes e chegou na linha %d - coluna %d\n\n", local.movimentacoes, local.linhaAtual, local.ColunaAtual);
                    break;
                default:

                    break;
            }

            printf("Deseja carregar um novo mapa ?\n0- Nao | 1- Sim\n");
            scanf("%d", &arq);

            while (arq < 0 || arq > 1) {
                printf("0- Nao | 1- Sim");
                scanf("%d", &arq);
            }
        }
    }
    return (EXIT_SUCCESS);
}

