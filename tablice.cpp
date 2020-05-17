#include <iostream>

using namespace std;

int* stworzTablice(int rozmiar){
	int* tablica
	tablica=(int*)malloc(rozmiar*sizeof(int));
	for(int i=0;i<rozmiar;i++){
		tablica[i]=0;
	}
	return tablica;
}

void wyswietl(*int tablica,int rozmiar){
	for(int i=0;i<rozmiar;i++){
		cout<<tablica[i];	
	}
	cout<<endl;
}

void zmianaElementu(int* tablica, int element, int rozmiar, int nowa){

	tablica[element-1]=nowa;
	return;
	
}

int* zmianaRozmiaru(int* tablica, int* 1rozmiar, int 2rozmiar)
{
	int* n_tablica=stworzTablice(2rozmiar);
	int tmp_rozmiar=*1rozmiar;
	if(2rozmiar<*1rozmiar){
		tmp_rozmiar=n_rozmiar;
	}
	for(int=0;i<tmp_rozmiar;i++){
		n_tablica[i]=tablica[i];
	}
	*1rozmiar=2rozmiar;
	return n_tablica;
}
