/*
	- Jogo da Memória em Linguagem C
	- Data: 15/02/2024
	- Philipe Souza França

*/
//Bibliotecas:

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <windows.h>
#include <conio.h>
#include <time.h>


int main(void) {
	//variáveis
	int i= 0, j = 0, acertos = 0;
	char c;
	int numeros[5];
	int respostas[5];
	
	//comando de regionalização
	setlocale(LC_ALL, "Portuguese");
	//título do programa
	SetConsoleTitle("Jogo da Memoria");
	
	srand(time(NULL)); //somente para gerar números aleatórios
	
	printf("Este programa vai gerar 5 números aleatórios entre 1 e 30.\n\n");
	printf("Decore os números exibidos em 5 segundos e depois escreva-os na \nordem em que foram exibidos.\n\n");
	printf("Pressione ENTER para iniciar");
	
	do{
		c = getch();
	}while (c != 13);
	
	for (i=0;i<5;i++){
		numeros[i] = (rand() %30)+1;
	}
	
	j=5;
	
	do{
		system("cls");
		printf("Decore os números abaixo em %d\n\n\n", j);
		j--;
		for (i=0;i<5;i++){
			printf("%d\t", numeros[i]);
		}
		Sleep (1000);
	}while (j>0);
	
	system("cls");
	printf("Informe os números que foram exibidos\n\n");
	
	for (i=0;i<5;i++){
		printf("\t%d número: ", i+1);
		scanf("%d", &respostas[i]);
		if(respostas[i]==numeros[i]){
			acertos++;
		}
	}
	
	if (acertos==5){
		printf("\n\nParabéns! Sua memória é muito boa. Veja os números exibidos:\n\n\t");
		for (i=0;i<5;i++){
			printf("%d\t", numeros[i]);
		}
	}
	else
	{
		printf("\n\nQue pena! Sua memória não está muito boa. Veja os números exibidos:\n\n\t");
		for (i=0;i<5;i++){
			printf("%d\t", numeros[i]);
		}
	}
	printf("\n\n");
	system("pause");
	return 0;
}
