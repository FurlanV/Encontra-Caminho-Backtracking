/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   EncontraCaminho.h
 * Author: vinicius
 *
 * Created on September 30, 2016, 7:19 PM
 */

#include <stdlib.h>
#include <stdio.h>

#ifndef ENCONTRACAMINHO_H
#define ENCONTRACAMINHO_H

#ifdef __cplusplus
extern "C" {
#endif

    typedef struct{
        int posicaoInicialX,posicaoInicialY;
        int nLinhas;
        int nColunas;
        int **mapa;
        int movimentacoes;
    }InfoLocal;
    
    void montaMapa(InfoLocal *local, char *nomeArquivo);
    int **alocarMatrizInt(int **matriz,int nLinhas,int nColunas); 
    void imprimirMapa(InfoLocal local);
    void movimenta_cachorro(InfoLocal *local, int posicaoAtualX, int posicaoAtualY, int *marca);
    
    void move_frente(InfoLocal *local, int posicaoAtualX, int posicaoAtualY);
    void move_tras(InfoLocal *local, int posicaoAtualX, int posicaoAtualY) ;
    void move_direita(InfoLocal *local, int posicaoAtualX, int posicaoAtualY);
    void move_esquerda(InfoLocal *local, int posicaoAtualX, int posicaoAtualY);
    
    int isPossivel_frente(InfoLocal *local, int posicaoAtualX, int posicaoAtualY);
    int isPossivel_tras(InfoLocal *local, int posicaoAtualX, int posicaoAtualY);
    int isPossivel_direita(InfoLocal *local, int posicaoAtualX, int posicaoAtualY);
    int isPossivel_esquerda(InfoLocal *local, int posicaoAtualX, int posicaoAtualY);
    
    void negrito(int status);
#ifdef __cplusplus
}
#endif

#endif /* ENCONTRACAMINHO_H */

