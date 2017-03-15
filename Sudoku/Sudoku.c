#include <stdio.h>
#include "sudoku.h"

main(){
    int tabuleiro [9][9] = 
    {
        {8,6,3,2,0,0,7,9,0},
        {0,0,0,0,6,0,0,0,0},
        {4,0,0,1,0,0,6,8,5},
        {0,0,9,0,0,0,0,0,0},
        {0,8,0,5,1,9,2,0,3},
        {0,4,0,0,0,8,1,7,9},
        {9,0,0,0,0,5,4,0,0},
        {0,5,0,7,0,0,0,3,2},
        {0,3,0,9,0,0,0,5,6}
    };

    int m2[9][9] = 
    {
        {0,8,0,7,0,6,0,0,2},
        {3,0,7,0,2,9,0,0,0},
        {2,0,0,5,0,0,9,0,8},
        {9,0,0,4,3,0,2,0,0},
        {6,0,0,0,9,0,4,0,3},
        {4,3,0,6,0,0,8,0,0},
        {8,9,0,0,5,0,7,0,0},
        {0,0,0,2,0,7,3,9,0},
        {0,2,0,0,6,1,0,0,4}
    };

    //resetarMatriz(tabuleiro);

    printMatriz(tabuleiro);

    int tentar = true, acerto=true;

    while(tentar){
        int i, j, num;
        printf("\e[1;34mInserir na posicao i:");
        scanf("%d", &i);

        printf("Inserir na posicao j:");
        scanf("%d", &j);

        printf("Inserir numero:");
        scanf("%d", &num);

        if(!validarOcupacao(tabuleiro, i, j)){
            acerto = false;
            printf("\e[1;33mPosicao ja possui um elemento\n");
        }else if(!validarVertical(tabuleiro, j, num)){
            acerto = false;
            printf("\e[1;33mVertical invalida\n");
        }else if(!validarHorizontal(tabuleiro[i], num)){
            acerto = false;
            printf("\e[1;33mHorizontal invalida\n");
        }else if(!validarQuadrante(tabuleiro, i, j, num)){
            acerto = false;
            printf("\e[1;33mQuadrante invalido\n");
        }
        
        if(!acerto){
            printf("Deseja tentar novamente?(1 - true, 0 - false): ");
            scanf("%d", &tentar);
            acerto = true;
        }else{
            tabuleiro[i][j] = num;
            printMatriz(tabuleiro);
        }

    }


    return 0;
}

void resetarMatriz(int m[9][9]){
    int i, j;
    for(i = 0; i < 9; i++){
        for(j = 0; j < 9; j++){
            m[i][j] = 0;
        }
    }

    m[0][1] = 7; m[0][2] = 1; m[0][3] = 4; m[0][4] = 5; m[0][8] = 9;
    m[1][0] = 6; m[1][1] = 3; m[1][3] = 9; m[1][4] = 7; m[1][5] = 8; m[1][7]=1;m[1][8] = 2;
}

int validarOcupacao(int m[9][9], int i, int j){
    return m[i][j] == 0;
}

int validarQuadrante(int tab[9][9], int i, int j, int num){
    int m, n, l, c;
    int qi = i/3, qj = j/3;
    for(m = 0; m < 3; m++){
        l = qi*3 + m;
        for(n = 0; n < 3; n++){
            c = qj*3 + n;
            if(tab[l][c] == num){
                return false;
            }
        }
    }

    return true;
}

int validarHorizontal(int m[9], int num){
    int i;
    for(i = 0; i < 9;i++){
        if(m[i] == num){
            return false;
        }
    }
    return true;
}

int validarVertical(int m[9][9], int j, int num){
    int i;
    for(i = 0; i < 9; i++){
        if(m[i][j] == num){
            return false;
        }
    }
    return true;
}

void printMatriz(int m[9][9]){
    int i, j, k;

    printf("\e[1;34m\n");

    for(i = -1; i < 9; i++){
        if(i != -1) {
            printf("\e[1;34m%d\t", i);
        }else{
            printf("ij\t");
        }

        for(j = 0; j < 9; j++){
            if(i == -1){
                printf("\e[1;34m%d ", j);
            }else{
                if(m[i][j] == 0){
                    printf("  ");
                }else{
                    printf("\e[1;31m%d ", m[i][j]);
                }
            }
            if((j+1)%3 == 0 && j != 8){
                printf("\e[1;34m| ");
            }else{
                //printf("\t");
            }
        }

        puts("");

        if((i+1)%3 == 0 && i != 8){
            printf("  \t");
            for(k = 0; k < 11; k++){
                printf("\e[1;34m__");
            }
            puts("");
        }
    }
}