#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>

int main() {
	int map[10][10];
	int x,y,posx=0,posy=0,mov,cont;
	bool remap=false;
	srand(time(NULL));
	do{
		//criar matriz de mapa
		for(y=0;y<10;y++){
			for(x=0;x<10;x++){
				if(remap==false){
					map[x][y]=rand()%4;
				}
				if(map[x][y]!=1&&map[x][y]!=5){
					map[x][y]=0;
				}
			}
		}
		remap=true;
		//mostrar mapa
		for(y=0;y<10;y++){
			for(x=0;x<10;x++){
				if(y==posy&&x==posx){
					printf(" X ");
					continue;
				}
				printf(" %d ", map[x][y]);
			}
			printf("\n");
		}
		//movimentos
		mov=rand()%4;
		if(mov==1&&posx<9&&map[posx+1][posy]!=1){
			if(map[posx+1][posy]==1){
				cont++;
				map[posx+1][posy]=0;
			}
			posx++;
		}
		if(mov==2&&posx>0&&map[posx-1][posy]!=1){
			if(map[posx-1][posy]==1){
				cont++;
				map[posx-1][posy]=0;
			}
			posx--;
		}
		if(mov==3&&posy<9){
			if(map[posx][posy+1]==1){
				cont++;
				map[posx][posy+1]=0;
			}
			posy++;
		}
		if(mov==0&&posy>0){
			if(map[posx][posy-1]==1){
				cont++;
				map[posx][posy-1]=0;
			}
			posy--;
		}
		printf("\n\nPontos: %d", cont);
		Sleep(1000);
		system("cls");
	}while(true);
	return 0;
}
