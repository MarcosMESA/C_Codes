#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <conio.h>
#include <stdbool.h>
#include "bib.h"

#define CHAO 0
#define PAREDE 1
#define PART 2
#define BORDA 3
#define BASE 4
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
#define MORTE 32

#define OK 1
#define ERRO 2

// O MAPA

int desenhar_mapa(int player,int player2,int inili1,int inico1,bool repet, int inili2, int inico2, int inili3, int inico3,int posli,int posco,int k[15][15],int tanque1, int tanque2, int tanque3, int nivel)
{	
	int i,j;
	if(repet==true){
		for(i=0;i<15;i++){
			for(j=0;j<=15;j++){
				k[i][j]=leitor_mapa(k,repet,nivel);
			}
		}
		for(i=0;i<15;i++){
			for(j=0;j<=15;j++){
				if (k[i][j] == 0){
				k[i][j] = rand() % 9;
			if (k[i][j] < 1 || k[i][j] > 3 || k[i][j]==1|| k[i][j]==3){
				k[i][j] = 0;
			}}
			}
		}
		k[10][7]=4;
	}
	int parede = 177;
	int x = 174,jogador = player, jogador2 = player2,part=176;
	int linha,coluna;
	for (linha=0;linha<15;linha++){
		for (coluna=0;coluna<15;coluna++){
			if((linha == posli) && (coluna == posco)){
				printf(" %c ",jogador2);
				continue;
			}
			if((linha == inili1) && (coluna == inico1)){
				printf(" %c ",tanque1);
				continue;
			}
			if((linha == inili2) && (coluna == inico2)){
				printf(" %c ",tanque2);
				continue;
			}
			if((linha == inili3) && (coluna == inico3)){
				printf(" %c ",tanque3);
				continue;
		}
			
			if(k[linha][coluna] == CHAO)
			printf("   ");
			if(k[linha][coluna] == PAREDE)
			printf(" %c ",parede);
			if(k[linha][coluna] == BORDA)
			printf(" H ");
			if(k[linha][coluna] == PART)
			printf(" %c ",part);
			if(k[linha][coluna] == BASE)
			printf(" B ",part);			
		}
		printf("\n\n");
	}

	return OK;
}

int main() {
	
	int esc, jogatanque=206;
	bool nrepet = false;
	bool debug = false;
	do{
	int vira=206;
	int tanque1=206, tanque2=197, tanque3=43, jogatanque=206;
	int nivel =0;
	srand((unsigned)time(NULL));
	system ("cls");
	printf("\n\n\t\t\t\t\t\tv0.2.1b - W A S D version.\n\n\n\t\t\to-------------------------------------------------------------------o\n");
	printf("\t\t\t|\t\t\t\t\t\t\t\t    |\n");
	printf("\t\t\t|\t\t\t\t\t\t\t\t    |\n");
	printf("\t\t\t|\t\t\t\t\t\t\t\t    |\n");
	printf("\t\t\t|                           BATTLE CITY\t\t\t            |\n");
	printf("\t\t\t|\t\t\t\t\t\t\t\t    |\n");
	printf("\t\t\t|\t\t\t\t\t\t\t\t    |\n");
	printf("\t\t\to-------------------------------------------------------------------o");
	printf("\n\n");
	printf("Saudacoes, ususario.\n\nQual das opcoes gostaria de escolher?\n");
	printf("(1)JOGAR\n(2)DEBUG\n(3)PLACAR\n(4)SAIR\n\nFaca sua escolha:\n");
	scanf ("%d",&esc);
	int vidas = 3, abates = 0;
	int pontua = (rand()%13)+1;
	int inili1 = (rand()%13)+1;
	int inico1 = (rand()%13)+1;
	int inili2 = (rand()%13)+1;
	int inico2 = (rand()%13)+1;
	int inili3 = (rand()%13)+1;
	int inico3 = (rand()%13)+1;
	int posli = (rand()%13)+1;
	int posco = (rand()%13)+1;
	bool vt1=true,vt2=true,vt3=true, verifica1=true, verifica2=true, ont=true;
	int mapa[15][15];
	int tecla, tecla2, tecla3,tecla4;
	srand ((unsigned)time(NULL));
	int turno = 1;
	int escolha=2;
	
	switch(esc){
	
	case 1:
	mapa[15][15] = desenhar_mapa(204,jogatanque,inili1,inico1,true,inili2,inico2,inili3,inico3,posli,posco,mapa,tanque1,tanque2,tanque3,nivel);
	system ("cls");
	       do{
	       		if(abates < 3){
	       			if(tanque1==32)
	       				tanque1=206;
			   		tanque1=tanque1;
			   		tanque2=MORTE;
			   		tanque3=MORTE;
			   }
			   	if(abates >= 3 && abates <= 6){
			   		if(verifica1==true){
			   			nivel=1;
			   			nrepet=true;
			   			verifica1=false;
			   			inili1 = (rand()%13)+1;
						inico1 = (rand()%13)+1;
						inili2 = (rand()%13)+1;
						inico2 = (rand()%13)+1;
						inili3 = (rand()%13)+1;
						inico3 = (rand()%13)+1;
						posli =	(rand()%13)+1;
						posco = (rand()%13)+1;
					}
			   		if(tanque1==32)
	       				tanque1=206;
	       			tanque1=tanque1;
	       			if(tanque2==32)
	       				tanque2=197;
	       			tanque2=tanque2;
			   		tanque3=MORTE;
			   }
			   	if(abates >= 6){
			   		if(verifica2==true){
			   				nivel=2;
			   				nrepet=true;
			   				verifica2=false;
						}
			   		if(tanque1==32)
	       				tanque1=206;
	       			tanque1=tanque1;
	       			if(tanque2==32)
	       				tanque2=197;
	       			tanque2=tanque2;
	       			if(tanque3==32)
			   			tanque3=43;
			   		tanque3=tanque3;
			   }
	    	  tecla=rand() % 5;
	    	  tecla2=rand() % 5;
	    	  tecla3 = rand() %5;
	    	  /////////////////////////////////////ancaps ;)////////////////////////////////
	    	  system ("cls");
				desenhar_mapa(206,vira,inili1,inico1,nrepet,inili2,inico2,inili3,inico3,posli,posco,mapa,tanque1,tanque2,tanque3,nivel);
				nrepet=false;
				printf("Movimentar jogador: (w)Cima (s)Baixo (a)Esquerda (d)Direita (q)Sair \n");
				printf("Disparar: (t)+(tecla de direcao) Ex.: ta (Atirar para a Esquerda)\n");
				printf("Girar Tanque: Ocorre ao andar com o personagem. \nVidas: %d   Kills: %d\nComando: ",vidas,abates);
	    	    tecla4=getchar();
	    	    if(tecla4==ACIMA){
	    	    	turno=1;
	    		  posli= posli - 1;
				  vira = 202; 
	    		  if(mapa[posli][posco] == PAREDE || mapa[posli][posco] == PART || mapa[posli][posco] == BORDA){
	    			 posli= posli+1;
				}
				system ("cls");
				desenhar_mapa(206,vira,inili1,inico1,nrepet,inili2,inico2,inili3,inico3,posli,posco,mapa,tanque1,tanque2,tanque3,nivel);	
			}
				if(tecla4==ABAIXO){
					turno=1;
	    		   posli= posli+1;
	    		   vira = 203;
	    	         if(mapa[posli][posco] == PAREDE || mapa[posli][posco] == PART || mapa[posli][posco] == BORDA){
	    		        posli= posli - 1;
	    			
				}
				system ("cls");
				desenhar_mapa(206,vira,inili1,inico1,nrepet,inili2,inico2,inili3,inico3,posli,posco,mapa,tanque1,tanque2,tanque3,nivel);	
			
		}
			if(tecla4==DIREITA){
				turno=1;
					posco= posco + 1;	//
	    			vira = 204;	
	    		if(mapa[posli][posco] == PART || mapa[posli][posco] == PAREDE || mapa[posli][posco] == BORDA){	//
	    			posco= posco - 1;	//
	    		}
				system ("cls");
				desenhar_mapa(206,vira,inili1,inico1,nrepet,inili2,inico2,inili3,inico3,posli,posco,mapa,tanque1,tanque2,tanque3,nivel);	

	}
			if(tecla4==ESQUERDA){
				turno=1;
	    		posco= posco - 1;
	    		vira = 185;
	    		if(mapa[posli][posco] == PAREDE || mapa[posli][posco] == PART || mapa[posli][posco] == BORDA){
	    			posco= posco+1;
	    			
				}
				system ("cls");
				desenhar_mapa(206,vira,inili1,inico1,nrepet,inili2,inico2,inili3,inico3,posli,posco,mapa,tanque1,tanque2,tanque3,nivel);	
               }
            if(tecla4==ATIRAR){
            	turno=1;
            	int atiro4;
            	atiro4=getchar();
            	if(atiro4==DIREITA){
					int i=0;
					vira=205;
	    			while(mapa[posli][posco] == CHAO){
	    				if((posli==inili1) && (posco==inico1)){
	    					pontua=pontua+10;
	    					abates++;
	    					tanque1=MORTE;
						}
						if((posli==inili2) && (posco==inico2)){
							pontua=pontua+10;
							abates++;
	    					tanque2=MORTE;
						}
						if((posli==inili3) && (posco==inico3)){
							pontua=pontua+10;
							abates++;
	    					tanque3=MORTE;
						}
						posco= posco + 1;	//
						system ("cls");
							desenhar_mapa(45,vira,inili1,inico1,nrepet,inili2,inico2,inili3,inico3,posli,posco,mapa,tanque1,tanque2,tanque3,nivel);
						Sleep(100);
						i++;
					}
	    			if(mapa[posli][posco] != PAREDE && mapa[posli][posco] != BORDA){	//
	    				mapa[posli][posco]=CHAO;
	    				posco = posco-i;	//
					}
					else
						posco = posco-i;
					system ("cls");
					vira=204;
						desenhar_mapa(206,vira,inili1,inico1,nrepet,inili2,inico2,inili3,inico3,posli,posco,mapa,tanque1,tanque2,tanque3,nivel);	
				}
				if(atiro4==ESQUERDA){
					int i=0;
					vira = 205;
	    			while(mapa[posli][posco] == CHAO){
	    				if((posli==inili1) && (posco==inico1)){
	    					pontua=pontua+10;
	    					abates++;
	    					tanque1=MORTE;
						}
						if((posli==inili2) && (posco==inico2)){
							pontua=pontua+10;
							abates++;
	    					tanque2=MORTE;
						}
						if((posli==inili3) && (posco==inico3)){
							pontua=pontua+10;
							abates++;
	    					tanque3=MORTE;
						}
						posco= posco - 1;	//
						system ("cls");
						desenhar_mapa(45,vira,inili1,inico1,nrepet,inili2,inico2,inili3,inico3,posli,posco,mapa,tanque1,tanque2,tanque3,nivel);
						Sleep(100);
						i++;
					}
	    			if(mapa[posli][posco] != PAREDE && mapa[posli][posco] != BORDA){	//
	    				mapa[posli][posco]=CHAO;
	    				posco = posco+i;	//
					}
					else
						posco = posco+i;
					system ("cls");
					vira = 185;
					desenhar_mapa(206,vira,inili1,inico1,nrepet,inili2,inico2,inili3,inico3,posli,posco,mapa,tanque1,tanque2,tanque3,nivel);
				}
				if(atiro4==ABAIXO){
					int i=0;
					vira=186;
	    			while(mapa[posli][posco] == CHAO){
	    				if((posli==inili1) && (posco==inico1)){
	    					pontua=pontua+10;
	    					abates++;
	    					tanque1=MORTE;
						}
						if((posli==inili2) && (posco==inico2)){
							pontua=pontua+10;
							abates++;
	    					tanque2=MORTE;
						}
						if((posli==inili3) && (posco==inico3)){
							pontua=pontua+10;
							abates++;
	    					tanque3=MORTE;
						}
						posli= posli + 1;	//
						system ("cls");
						desenhar_mapa(45,vira,inili1,inico1,nrepet,inili2,inico2,inili3,inico3,posli,posco,mapa,tanque1,tanque2,tanque3,nivel);
						Sleep(100);
						i++;
					}
	    			if(mapa[posli][posco] != PAREDE && mapa[posli][posco] != BORDA){	//
	    				mapa[posli][posco]=CHAO;
	    				posli = posli-i;	//
					}
					else
						posli = posli-i;
					system ("cls");
					vira=203;
						desenhar_mapa(206,vira,inili1,inico1,nrepet,inili2,inico2,inili3,inico3,posli,posco,mapa,tanque1,tanque2,tanque3,nivel);
				}
				if(atiro4==ACIMA){
					int i=0;
					vira=186;
	    			while(mapa[posli][posco] == CHAO){
	    				//sistema de morte
	    				if((posli==inili1) && (posco==inico1)){
	    					pontua=pontua+10;
	    					abates++;
	    					tanque1=MORTE;
						}
						if((posli==inili2) && (posco==inico2)){
							pontua=pontua+10;
							abates++;
	    					tanque2=MORTE;
						}
						if((posli==inili3) && (posco==inico3)){
							pontua=pontua+10;
							abates++;
	    					tanque3=MORTE;
						}
						posli= posli - 1;	//
						system ("cls");
						desenhar_mapa(45,vira,inili1,inico1,nrepet,inili2,inico2,inili3,inico3,posli,posco,mapa,tanque1,tanque2,tanque3,nivel);
						Sleep(100);
						i++;
					}
	    			if(mapa[posli][posco] != PAREDE && mapa[posli][posco] != BORDA){	//
	    				mapa[posli][posco]=CHAO;
	    				posli = posli+i;	//
					}
					else
						posli=posli+i;
					system ("cls");
					vira=202;
					desenhar_mapa(206,vira,inili1,inico1,nrepet,inili2,inico2,inili3,inico3,posli,posco,mapa,tanque1,tanque2,tanque3,nivel);
				}
			}
			///////////////////////////////////////////////////fim do jogador//////////////////////////////////////////////////
	    	  if(tanque1!=32){
	    	  	if(turno==1){
	    		if(debug==true){
	    			if(tecla==1)
						printf("T1:Cima");
					if(tecla==2)
						printf("T1:Baixo");
					if(tecla==3)
						printf("T1:Direita");
					if(tecla==4)
						printf("T1:Esquerda");
					if(tecla==0)
						printf("T1:Tiro ");
	    	  		Sleep(1000);}
	    	  if(tecla==1){//cima
	    		  inili1= inili1 - 1;
					tanque1=202;
	    		  if(mapa[inili1][inico1] == BORDA || mapa[inili1][inico1] == PART || mapa[inili1][inico1] == PAREDE){
	    			 inili1= inili1+1;
				}
				system ("cls");
				desenhar_mapa(206,vira,inili1,inico1,nrepet,inili2,inico2,inili3,inico3,posli,posco,mapa,tanque1,tanque2,tanque3,nivel);
			}
				if(tecla==2){//baixo
	    		   inili1= inili1+1;
	    		   tanque1 = 203;
	    	         if(mapa[inili1][inico1] == BORDA || mapa[inili1][inico1] == PART || mapa[inili1][inico1] == PAREDE){
	    		        inili1= inili1 - 1;
	    			
				}
				system ("cls");
				desenhar_mapa(206,vira,inili1,inico1,nrepet,inili2,inico2,inili3,inico3,posli,posco,mapa,tanque1,tanque2,tanque3,nivel);
			
		}
			if(tecla==3){//direita
					inico1= inico1 + 1;	//
	    		tanque1 = 204;
	    		if(mapa[inili1][inico1] == PART || mapa[inili1][inico1] == BORDA || mapa[inili1][inico1] == PAREDE){	//
	    			inico1= inico1 - 1;	//
	    		}
				system ("cls");
				desenhar_mapa(206,vira,inili1,inico1,nrepet,inili2,inico2,inili3,inico3,posli,posco,mapa,tanque1,tanque2,tanque3,nivel);

	}
	if(tecla==4){//esquerda
	    		inico1 = inico1 - 1;
	    		tanque1 = 185;
	    		if(mapa[inili1][inico1] == BORDA || mapa[inili1][inico1] == PART || mapa[inili1][inico1] == PAREDE){
	    			inico1= inico1+1;
	    			
				}
				system ("cls");
				desenhar_mapa(206,vira,inili1,inico1,nrepet,inili2,inico2,inili3,inico3,posli,posco,mapa,tanque1,tanque2,tanque3,nivel);
               }
            if(tecla==0){
            	int atiro;
            	atiro=rand() % 4;
            	if(debug==true){
	    			if(atiro==1)
						printf("Cima");
					if(atiro==2)
						printf("Baixo");
					if(atiro==3 || atiro==0)
						printf("Direita");
					if(atiro==4)
						printf("Esquerda");
	    	  		Sleep(1000);}
            	if(atiro==3 || atiro==0){
					int i=0;
					tanque1=205;
	    			while(mapa[inili1][inico1] == CHAO){
	    				if((posli==inili1) && (posco==inico1)){
	    					jogatanque=MORTE;
	    					vidas--;
						}
						if((inili1==inili2) && (inico1==inico2)){
	    					tanque2=MORTE;
						}
						if((inili1==inili3) && (inico1==inico3)){
	    					tanque3=MORTE;
						}
						inico1= inico1 + 1;	//
						system ("cls");
						desenhar_mapa(45,vira,inili1,inico1,nrepet,inili2,inico2,inili3,inico3,posli,posco,mapa,tanque1,tanque2,tanque3,nivel);
						Sleep(50);
						i++;
					}
	    			if(mapa[inili1][inico1] != BORDA && mapa[inili1][inico1] != PAREDE){	//
	    				mapa[inili1][inico1]=CHAO;
	    				inico1 = inico1-i;	//
					}
					else
						inico1 = inico1-i;
					system ("cls");
					tanque1=204;
					desenhar_mapa(206,vira,inili1,inico1,nrepet,inili2,inico2,inili3,inico3,posli,posco,mapa,tanque1,tanque2,tanque3,nivel);
				}
				if(atiro==4){
					int i=0;
					tanque1=205;
	    			while(mapa[inili1][inico1] == CHAO && inico1 != 14){
	    				if((posli==inili1) && (posco==inico1)){
	    					jogatanque=MORTE;
	    					vidas--;
						}
						if((inili1==inili2) && (inico1==inico2)){
	    					tanque2=MORTE;
						}
						if((inili1==inili3) && (inico1==inico3)){
	    					tanque3=MORTE;
						}
						inico1= inico1 - 1;	//
						system ("cls");
						desenhar_mapa(45,vira,inili1,inico1,nrepet,inili2,inico2,inili3,inico3,posli,posco,mapa,tanque1,tanque2,tanque3,nivel);
						Sleep(100);
						i++;
					}
	    			if(mapa[inili1][inico1] != BORDA && mapa[inili1][inico1] != PAREDE){	//
	    				mapa[inili1][inico1]=CHAO;
	    				inico1 = inico1+i;	//
					}
					else
						inico1 = inico1+i;
					system ("cls");
					tanque1=185;
					desenhar_mapa(206,vira,inili1,inico1,nrepet,inili2,inico2,inili3,inico3,posli,posco,mapa,tanque1,tanque2,tanque3,nivel);	
				}
				if(atiro==2){
					int i=0;
					tanque1=186;
	    			while(mapa[inili1][inico1] == CHAO && inili1 != 13){
	    				if((posli==inili1) && (posco==inico1)){
	    					jogatanque=MORTE;
	    					vidas--;
						}
						if((inili1==inili2) && (inico1==inico2)){
	    					tanque2=MORTE;
						}
						if((inili1==inili3) && (inico1==inico3)){
	    					tanque3=MORTE;
						}
						inili1= inili1 + 1;	//
						system ("cls");
						desenhar_mapa(45,vira,inili1,inico1,nrepet,inili2,inico2,inili3,inico3,posli,posco,mapa,tanque1,tanque2,tanque3,nivel);
						Sleep(100);
						i++;
					}
	    			if(mapa[inili1][inico1] != BORDA && mapa[inili1][inico1] != PAREDE){	//
	    				mapa[inili1][inico1]=CHAO;
	    				inili1 = inili1-i;	//
					}
					else
						inili1 = inili1-i;
					system ("cls");
					tanque1=203;
					desenhar_mapa(206,vira,inili1,inico1,nrepet,inili2,inico2,inili3,inico3,posli,posco,mapa,tanque1,tanque2,tanque3,nivel);
				}
				if(atiro==1){
					int i=0;
					tanque1=186;
	    			while(mapa[inili1][inico1] == CHAO && inili1 != 13){
	    				if((posli==inili1) && (posco==inico1)){
	    					jogatanque=MORTE;
	    					vidas--;
						}
						if((inili1==inili2) && (inico1==inico2)){
	    					tanque2=MORTE;
						}
						if((inili1==inili3) && (inico1==inico3)){
	    					tanque3=MORTE;
						}
						inili1= inili1 - 1;	//
						system ("cls");
						desenhar_mapa(45,vira,inili1,inico1,nrepet,inili2,inico2,inili3,inico3,posli,posco,mapa,tanque1,tanque2,tanque3,nivel);
						Sleep(100);
						i++;
					}
	    			if(mapa[inili1][inico1] != BORDA && mapa[inili1][inico1] != PAREDE){	//
	    				mapa[inili1][inico1]=CHAO;
	    				inili1 = inili1+i;	//
					}
					else
						inili1=inili1+i;
					system ("cls");
					tanque1=202;
					desenhar_mapa(206,vira,inili1,inico1,nrepet,inili2,inico2,inili3,inico3,posli,posco,mapa,tanque1,tanque2,tanque3,nivel);	
			}}}}////////////////////////////////////// fim do tanque1 ///////////////////////////////////
	    	  if(tanque2!=32){
	    	  	if(turno == 1){
	    	  	if(debug==true){
	    			if(tecla2==1)
						printf("T2:Cima");
					if(tecla2==2)
						printf("T2:Baixo");
					if(tecla2==3)
						printf("T2:Direita");
					if(tecla2==4)
						printf("T2:Esquerda");
					if(tecla2==0)
						printf("T2:Tiro ");
	    	  		Sleep(1000);}
	    	  if(tecla2==1){
	    		  inili2= inili2 - 1;
					tanque2=193;
	    		  if(mapa[inili2][inico2] == BORDA || mapa[inili2][inico2] == PART || mapa[inili2][inico2] == PAREDE){
	    			 inili2= inili2+1;
				}
				system ("cls");
				desenhar_mapa(206,vira,inili1,inico1,nrepet,inili2,inico2,inili3,inico3,posli,posco,mapa,tanque1,tanque2,tanque3,nivel);
			}
				if(tecla2==2){
					tanque2=194;
	    		   inili2= inili2+1;
	    	         if(mapa[inili2][inico2] == BORDA || mapa[inili2][inico2] == PART || mapa[inili2][inico2] == PAREDE){
	    		        inili2= inili2 - 1;
	    			
				}
				system ("cls");
				desenhar_mapa(206,vira,inili1,inico1,nrepet,inili2,inico2,inili3,inico3,posli,posco,mapa,tanque1,tanque2,tanque3,nivel);
			
		}
			if(tecla2==3){
					inico2= inico2 + 1;	//
	    		tanque2=195;
	    		if(mapa[inili2][inico2] == PART || mapa[inili2][inico2] == BORDA || mapa[inili2][inico2] == PAREDE){	//
	    			inico2= inico2 - 1;	//
	    		}
				system ("cls");
				desenhar_mapa(206,vira,inili1,inico1,nrepet,inili2,inico2,inili3,inico3,posli,posco,mapa,tanque1,tanque2,tanque3,nivel);	

	}
	if(tecla2==4){
	    		inico2= inico2 - 1;
	    		tanque2=180;
	    		if(mapa[inili2][inico2] == BORDA || mapa[inili2][inico2] == PART || mapa[inili2][inico2] == PAREDE){
	    			inico2= inico2+1;
	    			
				}
				system ("cls");
				desenhar_mapa(206,vira,inili1,inico1,nrepet,inili2,inico2,inili3,inico3,posli,posco,mapa,tanque1,tanque2,tanque3,nivel);	
               }
            if(tecla2==0){
            	int atiro2;
            	atiro2=rand() % 4;
            	if(debug==true){
	    			if(atiro2==1)
						printf("Cima");
					if(atiro2==2)
						printf("Baixo");
					if(atiro2==3 || atiro2==0)
						printf("Direita");
					if(atiro2==4)
						printf("Esquerda");
	    	  		Sleep(1000);}
            	if(atiro2==3 || atiro2==0){
					int i=0;
					tanque2=196;
	    			while(mapa[inili2][inico2] == CHAO  && i <= 2){
	    				if((posli==inili2) && (posco==inico2)){
	    					jogatanque=MORTE;
	    					vidas--;
						}
						if((inili1==inili2) && (inico1==inico2)){
	    					tanque1=MORTE;
						}
						if((inili2==inili3) && (inico2==inico3)){
	    					tanque3=MORTE;
						}
						inico2= inico2 + 1;	//
						system ("cls");
						desenhar_mapa(45,vira,inili1,inico1,nrepet,inili2,inico2,inili3,inico3,posli,posco,mapa,tanque1,tanque2,tanque3,nivel);
						Sleep(100);
						i++;
					}
	    			if(mapa[inili2][inico2] != BORDA && mapa[inili2][inico2] != PAREDE){	//
	    				mapa[inili2][inico2]=CHAO;
	    				inico2 = inico2-i;	//
					}
					else
						inico2 = inico2-i;
						tanque2=195;
					system ("cls");
					desenhar_mapa(206,vira,inili1,inico1,nrepet,inili2,inico2,inili3,inico3,posli,posco,mapa,tanque1,tanque2,tanque3,nivel);
				}
				if(atiro2==4){
					int i=0;
					tanque2=196;
	    			while(mapa[inili2][inico2] == CHAO && i <= 2){
	    				if((posli==inili2) && (posco==inico2)){
	    					jogatanque=MORTE;
	    					vidas--;
						}
						if((inili1==inili2) && (inico1==inico2)){
	    					tanque1=MORTE;
						}
						if((inili2==inili3) && (inico2==inico3)){
	    					tanque3=MORTE;
						}
						inico2= inico2 - 1;	//
						system ("cls");
						desenhar_mapa(45,vira,inili1,inico1,nrepet,inili2,inico2,inili3,inico3,posli,posco,mapa,tanque1,tanque2,tanque3,nivel);
						Sleep(100);
						i++;
					}
	    			if(mapa[inili2][inico2] != BORDA && mapa[inili2][inico2] != PAREDE){	//
	    				mapa[inili2][inico2]=CHAO;
	    				inico2 = inico2+i;	//
					}
					else
						inico2 = inico2+i;
					system ("cls");
					tanque2=180;
					desenhar_mapa(206,vira,inili1,inico1,nrepet,inili2,inico2,inili3,inico3,posli,posco,mapa,tanque1,tanque2,tanque3,nivel);
				}
				if(atiro2==2){
					int i=0;
					tanque2=179;
	    			while(mapa[inili2][inico2] == CHAO  && i <= 2){
	    				if((posli==inili2) && (posco==inico2)){
	    					jogatanque=MORTE;
	    					vidas--;
						}
						if((inili1==inili2) && (inico1==inico2)){
	    					tanque1=MORTE;
						}
						if((inili2==inili3) && (inico2==inico3)){
	    					tanque3=MORTE;
						}
						inili2= inili2 + 1;	//
						system ("cls");
						desenhar_mapa(45,vira,inili1,inico1,nrepet,inili2,inico2,inili3,inico3,posli,posco,mapa,tanque1,tanque2,tanque3,nivel);
						Sleep(100);
						i++;
					}
	    			if(mapa[inili2][inico2] != BORDA && mapa[inili2][inico2] != PAREDE){	//
	    				mapa[inili2][inico2]=CHAO;
	    				inili2 = inili2-i;	//
					}
					else
						inili2 = inili2-i;
					system ("cls");
					tanque2=194;
					desenhar_mapa(206,vira,inili1,inico1,nrepet,inili2,inico2,inili3,inico3,posli,posco,mapa,tanque1,tanque2,tanque3,nivel);	
				}
				if(atiro2==1){
					int i=0;
					tanque2=179;
	    			while(mapa[inili2][inico2] == CHAO &&  i <= 2){
	    				if((posli==inili2) && (posco==inico2)){
	    					jogatanque=MORTE;
	    					vidas--;
						}
						if((inili1==inili2) && (inico1==inico2)){
	    					tanque1=MORTE;
						}
						if((inili2==inili3) && (inico2==inico3)){
	    					tanque3=MORTE;
						}
						inili2= inili2 - 1;	//
						system ("cls");
						desenhar_mapa(45,vira,inili1,inico1,nrepet,inili2,inico2,inili3,inico3,posli,posco,mapa,tanque1,tanque2,tanque3,nivel);
						Sleep(100);
						i++;
					}
	    			if(mapa[inili2][inico2] != BORDA && mapa[inili2][inico2] != PAREDE){	//
	    				mapa[inili2][inico2]=CHAO;
	    				inili2 = inili2+i;	//
					}
					else
						inili2=inili2+i;
					system ("cls");
					tanque2=193;
					desenhar_mapa(206,vira,inili1,inico1,nrepet,inili2,inico2,inili3,inico3,posli,posco,mapa,tanque1,tanque2,tanque3,nivel);
				}
			}}}
			//////////////////////////////////////////termina o tanque2////////////////////////////////////////////////
			if(tanque3!=32){
				if(turno==1){
				if(debug==true){
	    			if(tecla3==1)
						printf("T3:Cima");
					if(tecla3==2)
						printf("T3:Baixo");
					if(tecla3==3)
						printf("T3:Direita");
					if(tecla3==4)
						printf("T3:Esquerda");
					if(tecla3==0)
						printf("T3:Tiro ");
	    	  		Sleep(1000);}
			if(tecla3==1){
	    		  inili3= inili3 - 1;
					tanque3=94;
	    		  if(mapa[inili3][inico3] == BORDA || mapa[inili3][inico3] == PART || mapa[inili3][inico3] == PAREDE){
	    			 inili3= inili3+1;
				}
				system ("cls");
				desenhar_mapa(206,vira,inili1,inico1,nrepet,inili2,inico2,inili3,inico3,posli,posco,mapa,tanque1,tanque2,tanque3,nivel);
			}
				if(tecla3==2){
	    		   inili3= inili3+1;
	    		   tanque3=86;
	    	         if(mapa[inili3][inico3] == BORDA || mapa[inili3][inico3] == PART || mapa[inili3][inico3] == PAREDE){
	    		        inili3= inili3 - 1;
	    			
				}
				system ("cls");
				desenhar_mapa(206,vira,inili1,inico1,nrepet,inili2,inico2,inili3,inico3,posli,posco,mapa,tanque1,tanque2,tanque3,nivel);
			
		}
			if(tecla3==3){
					inico3= inico3 + 1;	//
	    		tanque3=62;
	    		if(mapa[inili3][inico3] == PART || mapa[inili3][inico3] == BORDA || mapa[inili3][inico3] == PAREDE){	//
	    			inico3= inico3 - 1;	//
	    		}
				system ("cls");
				desenhar_mapa(206,vira,inili1,inico1,nrepet,inili2,inico2,inili3,inico3,posli,posco,mapa,tanque1,tanque2,tanque3,nivel);

	}
	if(tecla3==4){
	    		inico3= inico3 - 1;
	    		tanque3=60;
	    		if(mapa[inili3][inico3] == BORDA || mapa[inili3][inico3] == PART || mapa[inili3][inico3] == PAREDE){
	    			inico3= inico3+1;
	    			
				}
				system ("cls");
				desenhar_mapa(206,vira,inili1,inico1,nrepet,inili2,inico2,inili3,inico3,posli,posco,mapa,tanque1,tanque2,tanque3,nivel);
               }
            if(tecla3==0){
            	int atiro3;
            	atiro3=rand() % 4;
            	if(debug==true){
	    			if(atiro3==1)
						printf("Cima");
					if(atiro3==2)
						printf("Baixo");
					if(atiro3==3 || tecla3==0)
						printf("Direita");
					if(atiro3==4)
						printf("Esquerda");
	    	  		Sleep(1000);}
            	if(atiro3==3 || atiro3==0){
					inico3= inico3 + 1;	//
					tanque3=196;
					if((posli==inili3) && (posco==inico3)){
	    					jogatanque=MORTE;
	    					vidas--;
						}
						if((inili3==inili2) && (inico3==inico2)){
	    					tanque2=MORTE;
						}
						if((inili1==inili3) && (inico1==inico3)){
	    					tanque1=MORTE;
						}
					system ("cls");
					desenhar_mapa(45,vira,inili1,inico1,nrepet,inili2,inico2,inili3,inico3,posli,posco,mapa,tanque1,tanque2,tanque3,nivel);
					Sleep(100);
	    			if(mapa[inili3][inico3] != BORDA){	//
	    				mapa[inili3][inico3]=CHAO;
	    				inico3 = inico3-1;	//
					}
					else
						inico3 = inico3-1;
					system ("cls");
					tanque3=62;
					desenhar_mapa(206,vira,inili1,inico1,nrepet,inili2,inico2,inili3,inico3,posli,posco,mapa,tanque1,tanque2,tanque3,nivel);
				}
				if(atiro3==4){
					tanque3=196;
					if((posli==inili3) && (posco==inico3)){
	    					jogatanque=MORTE;
	    					vidas--;
						}
						if((inili3==inili2) && (inico3==inico2)){
	    					tanque2=MORTE;
						}
						if((inili1==inili3) && (inico1==inico3)){
	    					tanque1=MORTE;
						}
					inico1= inico1 - 1;	//
					system ("cls");
					desenhar_mapa(45,vira,inili1,inico1,nrepet,inili2,inico2,inili3,inico3,posli,posco,mapa,tanque1,tanque2,tanque3,nivel);
					Sleep(100);
	    			if(mapa[inili3][inico3] != BORDA){	//
	    				mapa[inili3][inico3]=CHAO;
	    				inico3 = inico3+1;	//
					}
					else
						inico3 = inico3+1;
					system ("cls");
					tanque3=60;
					desenhar_mapa(206,vira,inili1,inico1,nrepet,inili2,inico2,inili3,inico3,posli,posco,mapa,tanque1,tanque2,tanque3,nivel);	
				}
				if(atiro3==2){
					tanque3=179;
					if((posli==inili3) && (posco==inico3)){
	    					jogatanque=MORTE;
	    					vidas--;
						}
						if((inili3==inili2) && (inico3==inico2)){
	    					tanque2=MORTE;
						}
						if((inili1==inili3) && (inico1==inico3)){
	    					tanque1=MORTE;
						}
					inili3= inili3 + 1;	//
					system ("cls");
					desenhar_mapa(45,vira,inili1,inico1,nrepet,inili2,inico2,inili3,inico3,posli,posco,mapa,tanque1,tanque2,tanque3,nivel);
					Sleep(100);
	    			if(mapa[inili3][inico3] != BORDA){	//
	    				mapa[inili3][inico3]=CHAO;
	    				inili3 = inili3-1;	//
					}
					else
						inili3 = inili3-1;
					system ("cls");
					tanque3=86;
					desenhar_mapa(206,vira,inili1,inico1,nrepet,inili2,inico2,inili3,inico3,posli,posco,mapa,tanque1,tanque2,tanque3,nivel);
				}
				if(atiro3==1){
					tanque3=179;
					if((posli==inili3) && (posco==inico3)){
	    					jogatanque=MORTE;
	    					vidas--;
						}
						if((inili3==inili2) && (inico3==inico2)){
	    					tanque2=MORTE;
						}
						if((inili1==inili3) && (inico1==inico3)){
	    					tanque1=MORTE;
						}
					inili3= inili3 - 1;	//
					system ("cls");
					desenhar_mapa(45,vira,inili1,inico1,nrepet,inili2,inico2,inili3,inico3,posli,posco,mapa,tanque1,tanque2,tanque3,nivel);
					Sleep(100);
	    			if(mapa[inili3][inico3] != BORDA){	//
	    				mapa[inili3][inico3]=CHAO;
	    				inili3 = inili3+1;	//
					}
					else
						inili3=inili3+1;
					system ("cls");
					tanque3=94;
					desenhar_mapa(206,vira,inili1,inico1,nrepet,inili2,inico2,inili3,inico3,posli,posco,mapa,tanque1,tanque2,tanque3,nivel);	
				}
			}}}
			//////////////////////////////////////////////////////////////////////////////
			 turno=0;   
			nrepet = false;
			if(tecla4==Q){
    		do{
    			system("cls");
    			printf("(1)Novo Jogo\n(2)Reiniciar Jogo\n");
    			scanf("%d",&escolha);
    			if(escolha==2){
    				nrepet=true;
    				pontua = (rand()%13)+1;
					inili1 = (rand()%13)+1;
					inico1 = (rand()%13)+1;
					inili2 = (rand()%13)+1;
					inico2 = (rand()%13)+1;
					inili3 = (rand()%13)+1;
					inico3 = (rand()%13)+1;
					posli =	(rand()%13)+1;
					posco = (rand()%13)+1;
				}
			}while(escolha!=1 && escolha!=2 );
		}
		if(vidas>0){
			jogatanque=216;
		}
			////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    }while(escolha!=1 && nivel<3 && mapa[10][7]!=CHAO && vidas!=0 && abates!=9);
    	if(jogatanque==MORTE || mapa[10][7]==CHAO){
    		system("cls");
    		printf("\tGAME OVER");
    		int final = pontua*(nivel+1);
    		placar(final);
		}
		if(abates == 9){
    		system("cls");
    		printf("\tCONGRATULATIONS!!!!!\n\tVOCE GANHOU!!!!!");
    		int final = pontua*(nivel+1);
    		placar(final);
		}
		debug=false;
		printf("\nDEBUG MODE:OFF\n");
		getch();
    break;
    case 2:
    	if(debug==false){
    		debug=true;
    		printf("\nDEBUG MODE:ON\n");
    		getch();
		}
    break;
    case 3:
    	joojadores();
    break;
	}
}while(esc!=4);	
}
