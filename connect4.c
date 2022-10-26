#include <stdio.h>
#include <stdlib.h>

int ubacenired=0;
int gameOn = 1;

void printaj(char tabla[6][7])
{
	for(int i=0;i<6;i++){
		for(int j=0;j<7;j++){
			printf("%c ",tabla[i][j]);
		}
		printf("\n");
		}

}

void Provera(char tabla[6][7],int igrac, int kolona){
	char karakter ='X';
	if(igrac%2==0)
		karakter='O';
	int pobeda=0;
	
	//dole desno dijagonala
	for(int i = 0; i < 3; i++){
		for (int j = 0; j < 4; j++){
			if (tabla[i][j] == karakter && tabla[i + 1][j + 1] == karakter && tabla[i + 2][j + 2] == karakter && tabla[i + 3][j + 3] == karakter)
				pobeda = 3;
		}
	}
	//gore desno dijagonala
	for(int i = 5; i > 2; i--){
		for (int j = 0; j < 4; j++){
			if (tabla[i][j] == karakter && tabla[i - 1][j + 1] == karakter && tabla[i - 2][j + 2] == karakter && tabla[i - 3][j + 3] == karakter)
				pobeda = 3;
		}
	}
	
	
	if (ubacenired <= 2){		
		for (int i = ubacenired; i <= 5; i++){
			if (tabla[i][kolona] == karakter && tabla[i+1][kolona] == karakter){
				pobeda++;				
			}
		}
	}
	
	for (int i = 0; i < 6; i++){
		if (tabla[ubacenired][i] == karakter && tabla[ubacenired][i + 1] == karakter)
			pobeda++;
	}
	
	if (pobeda>=3){
		printf("Pobedio je %c Igrac",karakter);
		gameOn = 0;
	}
	
}

void dodaj(int igrac,int kolona, char tabla[6][7]){
	int red = 5;
	char karakter ='X';
	if(igrac%2==0)
		karakter='O';
	while(1){
		if (tabla[red][kolona] == '/'){
			tabla[red][kolona] = karakter;
			ubacenired=red;
			break;
		}
		else{
			red--;
		}
		if(red<0){
			printf("NEMA MESTA U KOLONI\n");
			break;
		}
	}
	printaj(tabla);
}

int main() {
	int kolona;
	int igrac = 0;
	char tabla[6][7];
	for(int i=0;i<6;i++){
		for(int j=0;j<7;j++){
			tabla[i][j]='/';
		}
	}
	while(gameOn == 1){
		printf("\nUnesite kolonu u koju zelite da ubacite: ");
		scanf("%d",&kolona);
		dodaj(igrac,kolona-1,tabla);
		Provera(tabla, igrac, kolona-1);
		igrac++;
	}
	
	return 0;
}
