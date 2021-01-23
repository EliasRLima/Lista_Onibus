#include <stdio.h>
#include <stdlib.h>


struct tipo_viagem{
    int cod_terminal;
    char data[9];
    char hora[5];
    char placa[8];
    int cod_empresa;
    struct tipo_viagem *prox;
};
typedef struct tipo_viagem elemento;

/* DECLARACOES GLOBAIS DE CONSTANTES */
const elemento VL_NULO = {0, "", "", "", 0, NULL};
#include "tad_list2.c"
#include "lista_bus.c"

int main(){

    tipo_lista lista;
    inicializa_lista(&lista);

    int menu = 0;

    while(menu != 9){
        system("cls");
        printf("Bem vindo!\n1 - carregar lista\n2 - listar dados\n3 - media tempo das viagens dos veiculos\n4 - valor a receber por empresa\n5 - inverter lista\n6 - tamanho da lista (quantidade de nodos)\n9 - Sair\nEscolha: ");
        scanf("%d",&menu);
        if(menu == 1){
            carregar_lista(&lista);
            printf("A lista tem: %d elementos\n", lista.tamanho);
            printf("Lista carregada!\n");
            system("pause");
            continue;
        }else if(menu == 2){
            listar(lista);
            system("pause");
            continue;
        }else if(menu == 3){
            media_tempo(lista);
            system("pause");
            continue;
        }else if(menu == 4){
            valor_por_empresa(lista);
            system("pause");
            continue;
        }else if(menu == 5){
            inverte(&lista);
            system("pause");
            continue;
        }else if(menu == 6){
            printf("A lista esta com %d nodos.\n",tamanho_quantidade_nodos(lista));
            system("pause");
            continue;
        }
        system("pause");
    }
    return 0;
    
}