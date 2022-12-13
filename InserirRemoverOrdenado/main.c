// ALUNO: JOSÉ VINÍCIUS DE CARVALHO OLIVEIRA
#include<stdlib.h>
#include<stdio.h>
#include <stdbool.h>
#include <locale.h>
#define TAM 20


int quantidade=0;
int lista[TAM];

void insere_Ord(int valor) {
	int i;

	if(quantidade==TAM-1) {
		printf("\nA lista está cheia\n");
		return;
	}
    i = quantidade;
	while(i>0 && valor<lista[i-1]){
		lista[i]=lista[i-1];
		i--;
	}

	lista[i]=valor;
	quantidade++;
	printf("\nO valor foi inserido na lista!\n");
}

void remover_Ord(int valor) {
    int i,j;
    int x=0;

	for(i=0; i < quantidade && valor >= lista[i]; i++) {
		if(valor==lista[i]) {

			for(j=i;j<quantidade-1;j++) {
				lista[j]=lista[j+1];
                quantidade--;
                i--;
                x++;
		}
	}
	if(x!=0)
		printf("O número %d foi removido com sucesso da lista!\n", valor);
	}
}

void exibir_Ord() {
	int i;

	if(quantidade==0){
		printf("\nA Lista encontra-se vazia!!\n\n");
		return;
	}
    printf("LISTA ORDENADA\n");
	for(i=0; i <= quantidade-1; i++) {
		printf("%d\n", lista[i]);
	}
}

void menuInicial() {
	printf("\nLISTA SEQUENCIAL ORDENADA\n");
	printf("\nEscolha a opção desejada: \n");
	printf("\n(1)Inserir elemento de forma ordenada");
	printf("\n(2)Remover elemento de forma ordenada");
	printf("\n(3)Exibir lista sequencial ordenada");
	printf("\n(4)Sair do programa\n\n");
}

int main() {
    setlocale(LC_ALL,"Portuguese");

	int opcao,valor;
	do {
            menuInicial();
            printf("\nInforme a opção desejada: \n");
            scanf("%d",&opcao);
            system("cls");

		switch(opcao) {
			case 1:
				printf("\nDigite o valor a ser inserido: \n");
				scanf("%d", &valor);
				insere_Ord(valor);
				getchar();
				break;

			case 2:
                if(quantidade==0){
                    printf("A lista está vazia\n");
                    return;
                }
                else{
				printf("\nDigite o valor a ser removido ");
				scanf("%d", &valor);
				remover_Ord(valor);
                }
				break;

			case 3:
				exibir_Ord();
				break;
		}

	}while(opcao!=4);

	return 0;
}

