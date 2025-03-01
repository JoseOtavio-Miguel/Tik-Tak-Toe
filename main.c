#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


#define TAM 3
#define JOGADOR1 1
#define JOGADOR2 2


void menu(char tabuleiro[TAM][TAM]);
void exibe_tabuleiro(char tabuleiro[TAM][TAM]);
bool executa_jogada(int pos[2], char tabuleiro[TAM][TAM], int jogador);
bool jogada_valida(char tabuleiro[TAM][TAM], int jogador);



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


    while (vencedor != true)
    {
        bool jogada;
        char vez_jogador[] = "jogador1";
        // Limpa a tela antes de exibir o tabuleiro
        system("cls");
        exibe_tabuleiro(tabuleiro);

        if(cont_jogadas % 2 == 1){
            printf("\n Vez : Jogador 1");
            jogada = jogada_valida(tabuleiro, JOGADOR1);
        }
        else{
            printf("\n Vez : Computador");
            jogada = jogada_valida(tabuleiro, JOGADOR2);
        }

        if (jogada == true)
        {
            // Adiciona ao contador se a jogada for válida
            cont_jogadas++;
        }
    }
}

// Define a função responsável por imprimir o tabuleiro
void exibe_tabuleiro(char pos[TAM][TAM]){
    printf("\n %c | %c | %c ", pos[0][0], pos[0][1], pos[0][2]);
    printf("\n %c | %c | %c ", pos[1][0], pos[1][1], pos[1][2]);
    printf("\n %c | %c | %c ", pos[2][0], pos[2][1], pos[2][2]);
}


//Define a função que irá validar as jogadas
bool jogada_valida(char tabuleiro[TAM][TAM], int jogador){
    int pos[2] = {};
    int valida_entrada;
    bool executa;

    printf("\nDigite as posiçoes [X, Y] : ");
    valida_entrada = scanf("%d %d", &pos[0], &pos[1]);

    if (valida_entrada != 2){
        printf("Entrada inválida! Por favor, Digite as posiçoes [X, Y] : \n");
        while(getchar() != '\n');
    }
    else {
        printf("Posição válida: [%d, %d]\n", pos[0], pos[1]);
    }

    executa = executa_jogada(pos, tabuleiro, jogador);
    if (executa == false){
        return false;
    }

    return true;
}

bool executa_jogada(int pos[2], char tabuleiro[TAM][TAM], int jogador){
    printf("\n Jogador : %d ", jogador);

    if (tabuleiro[pos[0]][pos[1]] == ' '){
        if (jogador == 1){
            tabuleiro[pos[0]][pos[1]] = 'X';
            return true;
        }
        else if (jogador == 2){
            tabuleiro[pos[0]][pos[1]] = 'O';
            return true;
        }
        else{
            printf("Posição Inválida ! ");
            return false;
        }
    }
}















