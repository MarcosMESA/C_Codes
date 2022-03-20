#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <conio.h>
#include <stdbool.h>
#include "bib.h"

#define CHAO 48
#define PAREDE 49
#define PART 50
#define BORDA 51
#define SEU TANQUE 4
#define TANQUE1 10
#define TANQUE2 11
#define TANQUE3 12
#define TIRO 45

#define ATIRAR 116
#define ACIMA 119
#define ABAIXO 115
#define DIREITA 100
#define ESQUERDA 97

#define Q 113

#define OK 1
#define ERRO 2

leitor_mapa(int k[][15],bool repet, int nivel){
	if(repet=true){
		int maps = nivel;
		FILE *file;
		if(maps==0){
			file = fopen ("mapa1.txt", "r");}
		if(maps==1){
			file = fopen ("mapa2.txt", "r");}
		if(maps==2){
			file = fopen ("mapa3.txt", "r");}
		else{
			maps = 0;}
    	int i = 0, j=0,l=0;

  		fscanf(file, "%d", &i);
    	for(j=0;j<15;j++){
  			for(l=0;l<15;l++){ 
    			k[j][l]=i;
      			fscanf(file, "%d", &i);     
			}
		}
 		fclose (file);
 	}
}
placar(int pontua){
  FILE *pont;
  char palavra[10];
  pont = fopen("placar.txt", "a+");
  if(pont == NULL)
  {
  printf("Erro na abertura do arquivo!");
  return 1;
  }
  printf("\n\n\tDigite seu nick: ");
  scanf("%s", palavra);
  fprintf(pont, "%s %d \n", palavra, pontua);
  fclose(pont);
}
joojadores(){
	FILE *pont;
  	char palavra[200];
  	pont = fopen("placar.txt", "r");
  	if(pont == NULL)
  	{
  		printf("Erro na abertura do arquivo!");
  		return 1;
  	}
	system("cls");
  	while(fgets(palavra, 200, pont)) {
  		
  		puts(palavra);
  		
 	}
	getch();
  	fclose(pont);
}
