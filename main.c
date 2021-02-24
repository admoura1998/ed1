#include <stdio.h>
#include <stdlib.h>
#define MAX_MATERIAIS 20
#define MAX_TUBOS 100
#define LINHAS 2
#define COLUNAS 3

typedef struct{
    int ton_cimento, ton_areia, ton_cal, ton_saibro, tubos;
}materiais;

int verificaQtd(){
    int qtd;
    do{
        scanf("%i", &qtd);
    }while(qtd > 20 || qtd < 0);

    return qtd;
}

void cadastraLote(materiais mat[LINHAS][COLUNAS]){
    int i,j, lote, material, qtd;
    printf("\nEm qual lote deseja inserir os materiais?");
    do{
    scanf("%i", &lote);
    }while(lote == 0);

    switch(lote){
        case 1:
            i = 1;
            j = 1;
            printf("\n1 - Cimento");
            printf("\n2 - Cal");
            scanf("%i", &material);
            switch(material){
                case 1:
                    printf("\nQual a quantidade de cimento que deseja inserir?");
                    qtd = verificaQtd();
                    mat[i][j].ton_cimento = qtd;
                    break;
                case 2:
                    printf("\nQual a quantidade de cal que deseja inserir?");
                    scanf("%i", &qtd);
                    mat[i][j].ton_cal = qtd;
                    break;
            }
            break;
        case 2:
            i = 0;
            j = 2;
            switch(material){


            }
            break;
        case 3:
            i = 0;
            j = 3;
            switch(material){


            }
            break;
    }

}

void listaQuantidade(materiais mat[LINHAS][COLUNAS]){
    int i,j;
        for(i = 1; i < LINHAS + 1; i++){
            for(j = 1; j < COLUNAS + 1; j++){
                printf("\n L[%i][%i]",i, j);
                printf("\n Areia -> %i", mat[i][j].ton_areia);
                printf("\n Cimento -> %i", mat[i][j].ton_cimento);
                printf("\n Cal -> %i", mat[i][j].ton_cal);
                printf("\n Saibro -> %i", mat[i][j].ton_saibro);
                printf("\n Tubos -> %i", mat[i][j].tubos);
                printf("\n");
            }
        }
}

void inicializaMatriz(materiais mat[LINHAS][COLUNAS]){
   int i, j;
   for(i = 1; i < LINHAS + 1; i++){
            for(j = 1; j < COLUNAS + 1; j++){
                mat[i][j].ton_areia = 0;
                mat[i][j].ton_cimento = 0;
                mat[i][j].ton_cal = 0;
                mat[i][j].ton_saibro = 0;
                mat[i][j].tubos = 0;
            }
    }

}

void menu(materiais mat[LINHAS][COLUNAS]){
    inicializaMatriz(mat);
    int num;
    do{
        printf("\n\t1 - Listar quantidade total\n");
        printf("\t2 - Listar quantidade por material\n");
        printf("\t3 - Retirar material\n");
        printf("\t4 - Verificar disponibilidade\n");
        printf("\t5 - Cadastrar lote\n");
        printf("\t6 - Sair\n");
        printf("\n\tR - ");
        scanf("%i", &num);
        switch(num){
            case 1:
                listaQuantidade(mat);
                break;
            case 2:
            case 3:
            case 4:
            case 5:
                cadastraLote(mat);
                break;
            case 6:
                num = 6;
                break;
            default:
                printf("\n\tOpcao invalida!");
        }
    }while(num != 6);

}



int main(){

    materiais mat[LINHAS][COLUNAS];
    menu(mat);






    return 0;

}
