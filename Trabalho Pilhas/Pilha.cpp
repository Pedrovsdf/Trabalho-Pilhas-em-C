#include <stdio.h>
#include <stdio.h>
#define MAX_CHAR 13
#define MAX_VALOR (MAX_CHAR-1)/2

struct Pilha{
    char valor[MAX_VALOR];
    int length;
};

void push(char valor, Pilha *pilha){
	pilha->length = pilha->length+1;
	
	if(pilha->length > MAX_VALOR){
		pilha->length = 0;
	} else {
		pilha->valor[pilha->length] = valor;
	}
}

void pop(Pilha *pilha){
	pilha->length--;
}

char top(Pilha *pilha){
	return pilha->valor[pilha->length];
}

bool isEmpty(Pilha *pilha){	
	return pilha->length == 0;
}

int main(){
	struct Pilha pilha;
	char valor[MAX_VALOR];
	bool esta_comparando = false;
	pilha.length = 0;
	
	printf("Digite os caracteres: ");
	scanf("%s", &valor);
	
	for(int i = 0; i < MAX_CHAR; i++){
		char valor_atual = valor[i];
		
		if(valor_atual != '1' && valor_atual != '0' && valor_atual != '+'){
			printf("ERRO: So podem existir caracteres '0', '1' e '+'.");
			return 1;
		} 
		
		if(valor_atual == '+'){
			if(isEmpty(&pilha)){
				printf("ERRO: Devem existir caracteres antes do '+' para ser comparado.");
				return 1;
			}
			if(esta_comparando){
				printf("ERRO: So pode existir um '+'.");
				return 1;
			}
			esta_comparando = true;
		} else {
			if(esta_comparando){
				if(top(&pilha) != valor_atual || isEmpty(&pilha)){
					printf("ERRO: Nao e o inverso.");
					printf("\nItens comparados: %c %c", valor_atual, top(&pilha));
					return 1;
				}
				pop(&pilha);
			} else {
				push(valor_atual, &pilha);
			}
		}
	}
	if(esta_comparando == false){
		printf("ERRO: Só deve existir '+' para ser comparado.");
		return 1;
	}
	if(!isEmpty(&pilha)){
		printf("ERRO: Os valores nao sao inversos.");
		printf("Quantidade de valores restantes: %i %c", pilha.length, top(&pilha));
		return 1;
	}
	
	printf("Os valores de fato sao inversos.");
	
	return 0;
}
