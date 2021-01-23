#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int carregar_lista(tipo_lista *lista){
    FILE *arq;
    arq = fopen("2019-09-06.txt","r");

    elemento p;
    
    if (!arq){
        printf("Falha ao abrir arquivo.\n");
        return NULL;
    }

    int i;

    inicializa_lista(lista); //reiniciar a lista

    char txt[100];

    while(fgets(txt, 100, arq) != (char*)EOF){
        if(feof(arq)){
            break;
        }
        char *token = strtok(txt," ");
        
        p.cod_terminal = (int)atof(token);
        token = strtok(NULL, " ");
        strcpy(p.data, token);
        token = strtok(NULL, " ");
        strcpy(p.hora, token);
        token = strtok(NULL, " ");
        strcpy(p.placa, token);
        token = strtok(NULL, " ");
        p.cod_empresa = (int)atof(token);

        incluir_elemento(lista,tamanho_quantidade_nodos(*lista)+1,p);

    }fclose(arq);

     return 1;
}

int listar(tipo_lista l){
    if(l.tamanho == 0){
        printf("Lista vazia!\n");
        return 1;
    }
    printf("terminal\tdata    \thora\tplaca  \t   empresa\n");
    int i;
    
    elemento e;
    for(i=1;i<=l.tamanho;i++){
        int j = obter_elemento(l, i, &e);
        if(j){
            printf("%d       \t%s\t%s\t%s\t   %d\n", e.cod_terminal, e.data, e.hora, e.placa, e.cod_empresa);
        }
    }
    return 1;
}

//usadas em media_tempo
int buscar(tipo_lista l, int idxMax, char texto[]){ //busca se tem a mesma placa em nodos anteriores
    elemento v;
    obter_elemento(l,idxMax,&v);
    if(idxMax > 0){
        if(strcmp(v.placa,texto) == 0){
            return 1;
        }
        return buscar(l, idxMax-1, texto);
    }
    return 0;

}

int tempo2Minuto(char i[]){ //transforma HHMM em um valor inteiro com minutos

    int dH = i[0] - 48;
    int uH = i[1] - 48;
    int horas = (dH * 10) + uH;

    int dM = i[2] - 48;
    int uM = i[3] - 48;
    int minutos = (dM * 10) + uM;
    
    minutos += horas * 60;
    return minutos;
}

int media_tempo(tipo_lista l){
    if(l.tamanho == 0){
        printf("Lista vazia!\n");
        return 1;
    }

    int i;
    elemento v;
    

    printf("Onibus\tMedia(minutos)\n");
    for(i = 1; i <= l.tamanho; i++){
        if(!obter_elemento(l,i,&v)){
            return 1;
        }
        if(buscar(l, i-1, v.placa)){ //tirar os que ja foram calculados
            continue;
        }

        //fazendo calculo
        int soma = 0,num = 0;

        int horasaida = tempo2Minuto(v.hora);

        elemento b;
        int idx_b = i+1;
        while(obter_elemento(l,idx_b++,&b) != 0){
            if(strcmp(b.placa, v.placa)==0){//se igual
                soma += tempo2Minuto(b.hora) - horasaida;
                num++;
                horasaida = tempo2Minuto(b.hora);
            }
        }

        if(num == 0){
            soma = 0;
            num = 1;
        }

        if(soma < 0) //corrigir quando lista ta invertida
            soma *= -1;
        
        printf("%s\t%0.0f\n",v.placa,((float)soma)/num);


    }

    return 0;
}

int buscarEmpresa(tipo_lista l, int idxMax, int empresa){

    elemento v;
    obter_elemento(l,idxMax,&v);

    if(idxMax > 0){
        if(v.cod_empresa == empresa){
            return 1;
        }
        return buscarEmpresa(l, idxMax-1, empresa);
    }
    return 0;

}

int valor_por_empresa(tipo_lista l){
    if(l.tamanho == 0){
        printf("Lista vazia!\n");
        return 1;
    }

    int i;
    elemento v;

    printf("\nEmpresa\tOnibus\tGanhos\n");
    for(i = 1; i <= l.tamanho; i++){
        if(!obter_elemento(l,i,&v)){
            printf("Falhou em obter elemento!");
            return 1;
        }
        if(buscar(l, i-1, v.placa)){ //tirar os que ja foram calculados
            continue;
        }

        //fazendo calculo
        int valor = 100;

        elemento b;
        int idx_b = i+1;
        while(obter_elemento(l,idx_b++,&b) != 0){
            if(strcmp(b.placa, v.placa)==0){//se igual
                valor += 100;
            }
        }

        printf("%d\t%s\tR$ %d.00\n",v.cod_empresa,v.placa,valor);

    }


    printf("\nEmpresa\tTotal\n");
    for(i = 1; i <= l.tamanho; i++){
        if(!obter_elemento(l,i,&v)){
            return 1;
        }
        if(buscarEmpresa(l, i-1, v.cod_empresa)){ //tirar os que ja foram calculados
            continue;
        }

        //fazendo calculo
        int valor = 100;

        elemento b;
        int idx_b = i+1;
        while(obter_elemento(l,idx_b++,&b) != 0){
            if(b.cod_empresa == v.cod_empresa){//se igual
                valor += 100;
            }
        }

        printf("%d\tR$ %d.00\n",v.cod_empresa,valor);

    }
    printf("\n");

    
    return 0;

}




