#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>

// -------- Define --------
#define MAX_ARRAY 10

// -------- Prototipos ----------
void inicializaTela(char array[], int tam);
char lerCaracter(char *msgTitulo);
void lerValidaCaracter(char *msgTitulo,char *msgErro,char *caracter,char *opcoes);
void guardaEmUmVetorDeTrasParaFrente(char array[MAX_ARRAY],int caracterLido, int posicao);
void printaArray(char array[],int tamArray);
void printaArrayComMensagem(char array[],int tamArray,char msg[]);
void avisoFinal(char array[], int tamArray);

/* 
	1- Ler do usuario o caracter
	2- Guardar em um array de traz para frente
	3- Printar o array

 */

int main() {
	char caracterLido,continuar;
	char array[MAX_ARRAY];
	int i = MAX_ARRAY - 1;
	
	//Inicializa vetor
	inicializaTela(array,MAX_ARRAY);
	printf("---------- Digite um numero,letra ou simbulo ate seu espaco acabar ----------\n");
	do{
		
		//Ler do usuario o caracter
		caracterLido = lerCaracter("");	
		
		//Guardar em um array de traz para frente
		guardaEmUmVetorDeTrasParaFrente(array,caracterLido,i);
		
		//Printar o array
		printaArrayComMensagem(array,MAX_ARRAY,"---------- Digite um numero,letra ou simbulo ate seu espaco acabar ----------\n");
		
		i--;
	}while(i >= 0);
	
	avisoFinal(array,MAX_ARRAY);

	
	return 0;
}

void avisoFinal(char array[], int tamArray){
	system("cls");
	printf("\nAcoubou seu espaco de memoria!\n Seu array: ");
	printaArray(array,tamArray);
}
void printaArrayComMensagem(char array[],int tamArray,char msg[]){
	int i;
	system("cls");
	printf(msg);
	for(i = 0;i < tamArray; i++){
		printf("%c", array[i]);
	}

}
void printaArray(char array[],int tamArray){
	int i;
	for(i = 0;i < tamArray; i++){
		printf("%c", array[i]);
	}

}
void inicializaTela(char array[], int tam){
	int i;
	for(i = 0;i < tam; i++){
		array[i] = ' ';
	}
}
void guardaEmUmVetorDeTrasParaFrente(char array[],int caracterLido, int posicao){
	if(array[posicao] == ' '){
		array[posicao] = caracterLido;
	}
}
char lerCaracter(char *msgTitulo)
{
	char caracter;
	fflush(stdin);
	printf(msgTitulo);
	fflush(stdin);
	caracter = getch();
	return caracter;

}
void lerValidaCaracter(char *msgTitulo,char *msgErro,char *caracter,char *opcoes)
{
	do
	{
		fflush(stdin);
		printf(msgTitulo);
		fflush(stdin);
		(*caracter) = toupper(getch());
		if(strchr(opcoes,*caracter) == 0)
		{
			printf(msgErro);
			getch();
		//	system("cls");
		}
	}while(strchr(opcoes,*caracter) == 0);
}
