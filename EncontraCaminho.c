#include "EncontraCaminho.h"

int montaMapa(InfoLocal *local, char *nomeArquivo) {
   
    FILE *file;
    char ch;
    int i, j, valor, marca = 0;


    file = fopen(nomeArquivo, "r");

    if (file) {
        fscanf(file, "%d %d\n", &local->nLinhas, &local->nColunas);

        local->mapa = alocarMatrizInt(local->mapa, local->nLinhas, local->nColunas);
        local->movimentacoes = 0;

        if (!local->mapa)
            printf("Erro, o mapa não existe\n");
        else {
            for (i = 0; i < local->nLinhas; i++) {
                for (j = 0; j < local->nColunas + 1; j++) { //+1 para que o \n nao seja contado na proxima linha e a matriz tenha numeros indesejados
                    ch = fgetc(file);

                    if (ch != '\n') {

                        if (atoi(&ch) == 2) {
                            local->posicaoInicialX = i;
                            local->posicaoInicialY = j;
                        }

                        valor = atoi(&ch); //atoi le um char e devolve o inteiro correspondente
                        local->mapa[i][j] = valor;
                    }
                }
            }
            
            return 1;
        }
    } else {
        printf("Erro ! Arquivo não encontrado\n");
        return 0;
    }
}

int **alocarMatrizInt(int **matriz, int nLinhas, int nColunas) {

    int i;

    matriz = (int**) malloc(sizeof (int*)*nLinhas);
    for (i = 0; i < nLinhas; i++)
        matriz[i] = (int*) malloc(sizeof (int)*nColunas);

    return matriz;
}

void imprimirMapa(InfoLocal local) {
    int i, j,v,h;
    for (i = 0; i < local.nLinhas; i++) {
        for (j = 0; j < local.nColunas; j++) {
            
            if(local.mapa[i][j] == 2){
                
                v = i;
                h = j;
                
                negrito(1);
                printf("%d ", local.mapa[i][j]);
                negrito(0);
            } else 
                printf("%d ", local.mapa[i][j]);
        }
        printf("\n");
    }

    printf("\n");
    printf("Posicao do cachorro:  linha: %d - coluna: %d\n",v,h);
    getchar();
}

void move_frente(InfoLocal *local, int posicaoAtualX, int posicaoAtualY) {
    local->mapa[posicaoAtualX][posicaoAtualY] = 1;
    local->mapa[posicaoAtualX - 1][posicaoAtualY] = 2;

    local->movimentacoes++;
}

void move_direita(InfoLocal *local, int posicaoAtualX, int posicaoAtualY) {
    local->mapa[posicaoAtualX][posicaoAtualY] = 1;
    local->mapa[posicaoAtualX][posicaoAtualY + 1] = 2;

    local->movimentacoes++;
}

void move_esquerda(InfoLocal *local, int posicaoAtualX, int posicaoAtualY) {
    local->mapa[posicaoAtualX][posicaoAtualY] = 1;
    local->mapa[posicaoAtualX][posicaoAtualY - 1] = 2;

    local->movimentacoes++;
}

void move_tras(InfoLocal *local, int posicaoAtualX, int posicaoAtualY) {
    local->mapa[posicaoAtualX][posicaoAtualY] = 1;
    local->mapa[posicaoAtualX + 1][posicaoAtualY] = 2;

    local->movimentacoes++;
}

int isPossivel_direita(InfoLocal *local, int posicaoAtualX, int posicaoAtualY) {

    if ((local->mapa[posicaoAtualX][posicaoAtualY + 1]) == 1)
        return 1;
    else
        return 0;
}

int isPossivel_esquerda(InfoLocal *local, int posicaoAtualX, int posicaoAtualY) {

    if ((local->mapa[posicaoAtualX][posicaoAtualY - 1]) == 1)
        return 1;
    else
        return 0;
}

int isPossivel_frente(InfoLocal *local, int posicaoAtualX, int posicaoAtualY) {

    if ((local->mapa[posicaoAtualX - 1][posicaoAtualY]) == 1)
        return 1;
    else
        return 0;
}

int isPossivel_tras(InfoLocal *local, int posicaoAtualX, int posicaoAtualY) {
    if ((local->mapa[posicaoAtualX + 1][posicaoAtualY]) == 1)
        return 1;
    else
        return 0;
}

void movimenta_cachorro(InfoLocal *local, int posicaoAtualX, int posicaoAtualY, int *marca) {

    int i, j, posicao = -1;
    if (posicaoAtualX == 0) {
        printf("O cachorro esta na primeira linha da tabela !\n");
        return;
    }

    if (isPossivel_frente(local, posicaoAtualX, posicaoAtualY) && *marca == 0) { //se der pra mover para frente, movemos para frente

        move_frente(local, posicaoAtualX, posicaoAtualY);
        imprimirMapa(*local);
        local->linhaAtual = posicaoAtualX-1;
        local->ColunaAtual = posicaoAtualY;
        movimenta_cachorro(local, posicaoAtualX - 1, posicaoAtualY, marca);

    } else {
        if (isPossivel_direita(local, posicaoAtualX, posicaoAtualY) || isPossivel_esquerda(local, posicaoAtualX, posicaoAtualY)) { //se é possivel ir para os lados, o cachorro procura a entrada mais proxima

            for (i = *marca + 1; i < local->nColunas; i++) {
                if ((local->mapa[posicaoAtualX - 1][i]) == 1) {
                    posicao = i;
                    break;
                }
            }

            if (posicao >= 0) { //Posicao marca se na parede existe saida mais proxima, caso a parede nao tenha saida, o cachorro para e a função termia
                if (posicao < posicaoAtualY && isPossivel_esquerda(local, posicaoAtualX, posicaoAtualY)) { // e a da entrada fica em um elemento menor quando comparado ao elemento do cachorro, entao nos movemos para a esquerda
                    move_esquerda(local, posicaoAtualX, posicaoAtualY);
                    imprimirMapa(*local);
                    local->linhaAtual = posicaoAtualX;
                    local->ColunaAtual = posicaoAtualY-1;
                    movimenta_cachorro(local, posicaoAtualX, posicaoAtualY - 1, marca);
                } else if (posicao > posicaoAtualY && isPossivel_direita(local, posicaoAtualX, posicaoAtualY)) {
                    move_direita(local, posicaoAtualX, posicaoAtualY);
                    imprimirMapa(*local);
                    local->linhaAtual = posicaoAtualX;
                    local->ColunaAtual = posicaoAtualY+1;
                    movimenta_cachorro(local, posicaoAtualX, posicaoAtualY + 1, marca);
                } else {
                    if (isPossivel_frente(local, posicaoAtualX, posicaoAtualY)) {
                        move_frente(local, posicaoAtualX, posicaoAtualY);
                        imprimirMapa(*local);
                        *marca = 0;
                        local->linhaAtual = posicaoAtualX-1;
                        local->ColunaAtual = posicaoAtualY;
                        movimenta_cachorro(local, posicaoAtualX - 1, posicaoAtualY, marca);
                    } else if (isPossivel_tras(local, posicaoAtualX, posicaoAtualY)) {
                        move_tras(local, posicaoAtualX, posicaoAtualY);
                        imprimirMapa(*local);
                        *marca = posicaoAtualY;
                        local->linhaAtual = posicaoAtualX+1;
                        local->ColunaAtual = posicaoAtualY;
                        movimenta_cachorro(local, posicaoAtualX + 1, posicaoAtualY, marca);
                    }
                }
            } else {
                printf("O cachorro se movimentou %d vezes e percebeu que o labirinto nao tem saida !!\n",local->movimentacoes);
                return;
            }
        } else if (isPossivel_direita(local, posicaoAtualX, posicaoAtualY) && !isPossivel_esquerda(local, posicaoAtualX, posicaoAtualY)) {

            if (isPossivel_frente(local, posicaoAtualX, posicaoAtualY)) {
                move_frente(local, posicaoAtualX, posicaoAtualY);
                imprimirMapa(*local);
                local->linhaAtual = posicaoAtualX-1;
                local->ColunaAtual = posicaoAtualY;
                movimenta_cachorro(local, posicaoAtualX - 1, posicaoAtualY, marca);
            } else {
                move_direita(local, posicaoAtualX, posicaoAtualY);
                imprimirMapa(*local);
                local->linhaAtual = posicaoAtualX;
                local->ColunaAtual = posicaoAtualY+1;
                movimenta_cachorro(local, posicaoAtualX, posicaoAtualY + 1, marca);
            }
        }
        else if (!isPossivel_direita(local, posicaoAtualX, posicaoAtualY) && isPossivel_esquerda(local, posicaoAtualX, posicaoAtualY)) {

            if (isPossivel_frente(local, posicaoAtualX, posicaoAtualY)) {
                move_frente(local, posicaoAtualX, posicaoAtualY);
                imprimirMapa(*local);
                local->linhaAtual = posicaoAtualX-1;
                local->ColunaAtual = posicaoAtualY;
                movimenta_cachorro(local, posicaoAtualX - 1, posicaoAtualY, marca);
            } else {
                move_esquerda(local, posicaoAtualX, posicaoAtualY);
                imprimirMapa(*local);
                local->linhaAtual = posicaoAtualX;
                local->ColunaAtual = posicaoAtualY+1;
                movimenta_cachorro(local, posicaoAtualX, posicaoAtualY + 1, marca);
            }
        } else { // se nao existe caminho nos movemos para tras e tentamos outro caminho
            
            move_tras(local, posicaoAtualX, posicaoAtualY);
            imprimirMapa(*local);
            *marca = posicaoAtualY;
            local->linhaAtual = posicaoAtualX+1;
            local->ColunaAtual = posicaoAtualY;
            movimenta_cachorro(local, posicaoAtualX + 1, posicaoAtualY, marca);
        }
    }
}

void negrito(int status) {
    static const char *seq[] = {"\x1b[0m", "\x1b[1m"};
    printf("%s", seq[status]);
}