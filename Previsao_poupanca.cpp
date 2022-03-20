#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

int main(){
	int resp;
	do{
		int meses, aux=1;
		float grana, valoriz;
		printf("Digite o valor do dinheiro em conta: ");
		scanf("%f",&grana);
		printf("\n\nDigite o numero de meses: ");
		scanf("%d",&meses);
		printf("\n\nValor Total | Mes | Valorizacao");
		do{
			grana=grana+(grana*0.005);
			valoriz=(0.5*aux);
			printf("\n%.2f | %d | %.2f %", grana, aux, valoriz);
			aux++;
		}while(aux<=meses);
		printf("\n\nDeseja continuar? (1-s / 2-n)\n");
		scanf("%d",&resp);
	}while(resp==1);
	getch();
}
