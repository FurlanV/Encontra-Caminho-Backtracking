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
    
    printf("Digite o nome do arquivo: ");
    scanf("%s",nomeArquivo);
    getchar();
    while(arq){
        montaMapa(&local, nomeArquivo);
        imprimirMapa(local);
        movimenta_cachorro(&local, local.posicaoInicialX, local.posicaoInicialY, &marca);
        printf("O cachorro se movimentou %d vezes\n\n",local.movimentacoes);
        printf("Deseja carregar um novo mapa ?\n0- Nao | 1- Sim\n");
        scanf("%d",&arq);
        
        while(arq < 0 || arq > 1){
            printf("0- Nao | 1- Sim");
            scanf("%d",&arq);
        }
        
        if(arq == 1){
            printf("Digite o nome do arquivo: ");
            scanf("%s",nomeArquivo);
        }
    }
    
    return (EXIT_SUCCESS);
}

