#include <iostream>
#include "tablice.h"

using namespace std;

void Menu(){

	int nr=6;
	while(nr!=5){

		cout<<"Co chcesz zrobic"<<endl;
		cout<<"1.Utworz nowa tablice"<<endl;
		cout<<"2.Zmien zawartosc tablicy"<<endl;
		cout<<"3.Zmien rozmiar tablicy"<<endl;
		cout<<"4.Wyswietl tablice"<<endl;
		cout<<"5.Zakoncz program"<<endl;
		cout<<"Twoj wybor: ";
		cin>>nr;
		cout<<endl;

		switch(nr){
		
		case 1:
		int rozmiar;
		int* tablica;
		cout<<"Rozmiar tablicy:";
		cin>>rozmiar;
		cout<<endl;
		tablica=stworzTablice(rozmiar);
		break;	

		case 2:
		int element;
		int nowa;
		cout<<"Zakres od 1 do "<<rozmiar<<endl;
		wyswietl(tablica, rozmiar);
		cout<<"Element do zmiany: ";
		cin>>element;
		if((element<1)||(element>rozmiar)){
			cout<<"Nie ma takiej pozycji"
			break;
		}
		cout<<"Nowa wartosc:"
		cin>>nowa;
		zmianaElementu(tablica, element, rozmiar, nowa)

		case 3:
		int 2rozmiar;
		cout<<"Nowy rozmiar:";
		
		if(2rozmiar<1){
			cout<<"Zbyt maly rozmiar";
			break;	
		}
		if(2rozmiar==rozmiar){
			cout<<"Podano ten sam rozmiar";
			break;
		}
		if(2rozmiar<rozmiar){
			tablica=zmianaRozmiaru(tablica, &rozmiar, 2rozmiar);
			cout<<"Zmieniono rozmiar"
			break;
		}
	
		case 4: 
		wyswietl(tablica, rozmiar);
		break;
		
		default:
		wybor=5;
		break;
		
		}
	}	
}
