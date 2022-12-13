#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*Implementa��o de lista encadeada circular feita em sala*/

/*Estrutura que representa um n� da lista*/
typedef struct no{
    char nome[40];
    struct no *proxNo;
} tipoNo;

/*Estrutura que guarda as informa��es de uma lista circular*/
typedef struct listaGerenciada{
    tipoNo *fim;
    int quant;
} tipoLista;

/*Fun��o que faz a inicializa��o da lista circular*/
void inicializa(tipoLista *listaEnc){
    listaEnc->fim = NULL;
    listaEnc->quant = 0;
}

/*Fun��o que retorna 1 caso a lista esteja vazia e 0 caso esteja povoada*/
int estaVazia(tipoLista *listaEnc){
    if (listaEnc->fim == NULL)
        return 1;
    else
        return 0;
}

/*Fun��o que faz a inser��o de um n� em uma lista vazia*/
int insereListaVazia(tipoLista *listaEnc, char nome[40]){
    tipoNo *nome_novo;
    nome_novo = (tipoNo*) malloc(sizeof(tipoNo));
    
    if(nome_novo == NULL)
        return 0;

    strcpy(nome_novo->nome, nome);
    nome_novo->proxNo=nome_novo;
    listaEnc->fim = nome_novo;
    listaEnc->quant++;
    
    return 1;
}

/*Fun��o que percorre a lista exibindo todos os seus nomes*/
void exibeLista(tipoLista *listaEnc){
    tipoNo *atual;  /*Vari�vel que ser� usada para percorrer a lista*/
    atual = listaEnc->fim->proxNo;
    
    printf("\nLista encadeada: ");
    printf("%2s",atual->nome);
    
    while(atual !=listaEnc->fim){
        atual = atual->proxNo;
        printf("%2s",atual->nome);
    }
}

/*Fun��o que insere elemento no inicio da lista*/
int insereNaFrente(tipoLista *listaEnc, char nome[40]){
    tipoNo *nome_novo;
    
    if(listaEnc->fim==NULL)
        insereListaVazia(listaEnc, nome);
    else{
        nome_novo = (tipoNo*)malloc(sizeof(tipoNo));
        
        if(nome_novo==NULL)
            return 0;
        
        strcpy(nome_novo->nome, nome);
        nome_novo->proxNo=listaEnc->fim->proxNo;
        listaEnc->fim->proxNo=nome_novo;
        listaEnc->quant++;
        
        return 1;
    }
}

/*Fun��o que remove elemento do final da lista*/
void removeDoFim(tipoLista *listaEnc){
    tipoNo *atual, *antigo;
    atual = listaEnc->fim->proxNo;
    
    if(atual->proxNo == atual){
        listaEnc->fim = NULL;
        listaEnc->quant--;
    }
    else{
        while(atual!=listaEnc->fim){
            antigo = atual;
            atual= atual->proxNo;
        }
        antigo->proxNo=antigo->proxNo->proxNo; /* ou recebe listaEnc->fim->proxNo;*/
        listaEnc->fim=antigo;
    }
    free(atual);
}

/*Fun��o que insere elemento ao final da lista*/
int insereNoFim(tipoLista *listaEnc, char nome[40]){
    tipoNo *nome_novo;
    
    if(listaEnc->fim == NULL)
        insereListaVazia(listaEnc, nome);
    else{
        nome_novo= (tipoNo*) malloc(sizeof (nome_novo));
    
        if(nome_novo == NULL)
            return 0;
    
        strcpy(nome_novo->nome, nome);
        nome_novo->proxNo = listaEnc->fim->proxNo;
        listaEnc->fim->proxNo = nome_novo;
        listaEnc->fim = nome_novo;
        listaEnc->quant++;
    }
}

/*Fun��o que insere elemento no inicio da lista*/
void removeDoInicio(tipoLista *listaEnc){
    tipoNo *atual;
    
    if(listaEnc->quant > 1){
        atual = listaEnc->fim->proxNo;
        printf("\nNo removido ===> %s",atual->nome);
        listaEnc->fim->proxNo = atual->proxNo;
    }
    else
        listaEnc->fim = NULL;
    
    listaEnc->quant--;
    
    free(atual);
}

/*Fun��o que destroi a lista, liberando a mem�ria*/
void destruirLista(tipoLista *listaEnc){
    while(!estaVazia(listaEnc)){
        removeDoInicio(listaEnc);
    }
}

/*Fun��o que busca dado na lista e retorna a posi��o em que o dado foi encontrado*/
int buscaDado(tipoLista *listaEnc, char nome[40]){
    tipoNo *atual;
    int cont=1;
    atual=listaEnc->fim;
    
    do{
        atual=atual->proxNo; /*O primeiro ponteiro recebido aponta para o inicio da lista*/
        
        if(atual->nome == nome)
           return cont;
        
        cont++;
    } while(atual != listaEnc->fim);
    
    return 0; /*Caso o nome n�o seja encontrado, � retornado o valor zero*/
}


void main(){
    tipoLista lista;
    char nomeAux[40];
    int op;

    inicializa(&lista);

    do{
        printf("\nMenu\n\n1 - Insere elemento em lista vazia:");
        printf("\n2 - Insere elemento na frente da lista");
        printf("\n3 - Remove do inicio");
        printf("\n4 - Insere elemento no fim da lista");
        //printf("\n5 - Busca nome na lista");
        printf("\n6 - Remove elemento do fim da lista");
        printf("\n9 - Exibe lista");
        printf("\n0 - Encerra programa");
        printf("\nEscolha sua opcao: ");
        scanf("%d",&op);
        
        switch(op){
            case 1: printf("\nDigite o elemento que deseja inserir: ");
            scanf("%s",&nomeAux);
            insereListaVazia(&lista, nomeAux);
            break;
        
            case 2: printf("\nDigite o elemento que deseja inserir: ");
                scanf("%s",&nomeAux);
                insereNaFrente(&lista, nomeAux);
                break;
            
            case 3: removeDoInicio(&lista);
                break;
            
            case 4: printf("\nDigite o elemento que deseja inserir: ");
                fflush(stdin);
                gets(nomeAux);
                insereNoFim(&lista, nomeAux);
                break;
            
            case 6: removeDoFim(&lista);
                break;
            
            case 9: exibeLista(&lista);
                break;
            
            case 0: printf("\nEncerrando programa.");
                destruirLista(&lista);
                break;
        }
    } while(op != 0);
}
