#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <windows.h>


#define TAM 3
#define JOGADOR1 1
#define JOGADOR2 2


void menu(char tabuleiro[TAM][TAM]);
void exibeTabuleiro(char tabuleiro[TAM][TAM]);
bool executaJogada(int pos[2], char tabuleiro[TAM][TAM], int jogador, int* cont_jogadas);
bool jogadaValida(char tabuleiro[TAM][TAM], int jogador, int* cont_jogada);
bool verificaVitoriaJogador1(char tabuleiro[TAM][TAM], bool vencedor);
bool verificaVitoriaJogador2(char tabuleiro[TAM][TAM], bool vencedor);



int main(){
    //Define a matriz com as posições das Peças
    char tabuleiro[TAM][TAM] = {
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '}};

    menu(tabuleiro);
}


void menu(char tabuleiro[TAM][TAM]){
    bool vencedor = false;
    // Inicia um contador de Rounds
    int cont_jogadas = 1;
    // Inicia a variável que define qual jogador deve jogar, iniciando com 1


    while (vencedor != true && cont_jogadas <= 9)
    {
        bool jogada;
        // Limpa a tela antes de exibir o tabuleiro
        exibeTabuleiro(tabuleiro);

        if(cont_jogadas % 2 == 1){
            printf("\n Vez : Jogador 1");
            jogada = jogadaValida(tabuleiro, JOGADOR1, &cont_jogadas);
            vencedor = verificaVitoriaJogador1(tabuleiro, vencedor);
        }
        else{
            printf("\n Vez : Jogador2");
            jogada = jogadaValida(tabuleiro, JOGADOR2, &cont_jogadas);
            vencedor = verificaVitoriaJogador2(tabuleiro, vencedor);
        }


        // Verifica se há ganhador
        if (vencedor == true){
                if (cont_jogadas %2 == 0){
                    printf("Vitoria do Jogador 1 !");
                }
                else{
                    printf("Vitoria do Jogador2 !");
                }
        }

        Sleep(1000);
        system("cls");
    }
}

// Define a função que verifica se há um vencedor
bool verificaVitoriaJogador1(char tabuleiro[TAM][TAM], bool vencedor){
    int cont_linha[] = {0, 0, 0};
    int cont_coluna[] = {0, 0, 0};
    int diagonal[] = {0, 0};

    // Valida se há vencedor analisando as linhas
    // Percorre toda a linha
    for (int i=0; i<3; i++){
        // Inicia o contador igual a 0 dentro da linha
        int contador = 0;
            //Percorre toda a coluna
        for (int j=0; j<3; j++){
            if(tabuleiro[i][j] == 'X'){
                contador++;
            }
        }
        cont_linha[i] = contador;
    }

    for (int i=0; i<3; i++){
        int contador = 0;
        for (int j=0; j<3; j++){
            if(tabuleiro[j][i] == 'X'){
                contador++;
            }
        }
        cont_coluna[i] = contador;
    }


    for (int i=0; i<3; i++){
        int contador = 0;
        int cont_coluna = 2;
        if (tabuleiro[i][i] == 'X'){
            contador ++;
        }
        else if (tabuleiro[i][cont_coluna] == 'X'){
            cont_coluna--;
            diagonal[1]++;
        }
    }

    // Verifica se algum caso de vitoria foi confirmado
    for(int i=0; i<3; i++){
        if (cont_linha[i] == 3 || cont_coluna[i] == 3){
            return true;
        }
    }
    if(diagonal[0] == 3 || diagonal[1] == 3){
        return true;
    }
    else{
        return false;
    }
}

// Define a função que verifica se há um vencedor
bool verificaVitoriaJogador2(char tabuleiro[TAM][TAM], bool vencedor){
    int cont_linha[] = {0, 0, 0};
    int cont_coluna[] = {0, 0, 0};
    int diagonal[] = {0, 0};

    // Valida se há vencedor analisando as linhas
    // Percorre toda a linha
    for (int i=0; i<3; i++){
        // Inicia o contador igual a 0 dentro da linha
        int contador = 0;
            //Percorre toda a coluna
        for (int j=0; j<3; j++){
            if(tabuleiro[i][j] == 'O'){
                contador++;
            }
        }
        cont_linha[i] = contador;
    }

    for (int i=0; i<3; i++){
        int contador = 0;
        for (int j=0; j<3; j++){
            if(tabuleiro[j][i] == 'O'){
                contador++;
            }
        }
        cont_coluna[i] = contador;
    }


    for (int i=0; i<3; i++){
        int contador = 0;
        int cont_coluna = 2;
        if (tabuleiro[i][i] == 'O'){
            contador ++;
        }
        else if (tabuleiro[i][cont_coluna] == 'O'){
            cont_coluna--;
            diagonal[1]++;
        }
    }


    // Verifica se algum caso de vitoria foi confirmado
    for(int i=0; i<3; i++){
        if (cont_linha[i] == 3 || cont_coluna[i] == 3){
            return true;
            continue;
        }
    }
    if(diagonal[0] == 3 || diagonal[1] == 3){
        return true;
    }
    else{
        return false;
    }
}


// Define a função responsável por imprimir o tabuleiro
void exibeTabuleiro(char pos[TAM][TAM]) {
    printf("\n    1   2   3  "); // Índices de coluna
    printf("\n  -------------");

    for (int i = 0; i < TAM; i++) {
        printf("\n%d |", i + 1); // Índices de linha
        for (int j = 0; j < TAM; j++) {
            printf(" %c |", pos[i][j]);
        }
        printf("\n  -------------");
    }
    printf("\n");
}


//Define a função que irá validar as jogadas
bool jogadaValida(char tabuleiro[TAM][TAM], int jogador, int* cont_jogadas){
    int pos[2] = {};
    int valida_entrada;
    bool executa;

    printf("\nDigite as posiçoes [X, Y] : ");
    valida_entrada = scanf("%d %d", &pos[0], &pos[1]);

    if (valida_entrada != 2){
        printf("\nEntrada inválida! Por favor, Digite as posiçoes [X, Y] : \n");
        while(getchar() != '\n');
    }

    executa = executaJogada(pos, tabuleiro, jogador, cont_jogadas);
    if (executa == false){
        return false;
    }

    return true;
}

bool executaJogada(int pos[2], char tabuleiro[TAM][TAM], int jogador, int* cont_jogadas){
    if (tabuleiro[pos[0]-1][pos[1]-1] == ' '){
        if (jogador == 1){
            printf("\nPosicao valida: [%d, %d]. Alocando ao Tabuleiro...\n", pos[0], pos[1]);
            tabuleiro[pos[0]-1][pos[1]-1] = 'X';
            (*cont_jogadas)++;
            return true;
        }
        else if (jogador == 2){
            printf("\nPosicao valida: [%d, %d]. Alocando ao Tabuleiro...\n", pos[0], pos[1]);
            tabuleiro[pos[0]-1][pos[1]-1] = 'O';
            (*cont_jogadas)++;
            return true;
        }
    }
    else{
        printf("\nPosicao Invalida !");
        return false;
        }
}
