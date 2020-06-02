#include <iostream>
#include "tablice.h"

using namespace std;

void menu(Tablica* arr){

	int t;
		cout<<"Wybierz typ: "<<endl;
		cout<<"0->float , 1->int , 2->string"<<endl;
						
		do{
		cin>>t;
		}
		while((t!=0)&&(t!=1)&&(t!=2));
		arr->wybierzTyp(t);

	int nr=14;
	while(nr!=13){

		cout<<"Co chcesz zrobic"<<endl;
		cout<<"1.Wczytaj tablice"<<endl;
		cout<<"2.Utworz nowa tablice"<<endl;
		cout<<"3.Zmien zawartosc komorki"<<endl;
		cout<<"4.Zmien rozmiar tablicy"<<endl;
		cout<<"5.Wyswietl tablice"<<endl;
		cout<<"6.Zapisz w pliku"<<endl;
		cout<<"7.Suma wartosci kolumny"<<endl;
		cout<<"8.Suma wartosci wiersza"<<endl;
		cout<<"9.Wartosci max i min kolumn"<<endl;
		cout<<"10.Wartosci max i min wierszy"<<endl;
		cout<<"11.Wartosc srednia kolumny"<<endl;
		cout<<"12.Wartosc srednia wiersza"<<endl;
		cout<<"13.Zakoncz program"<<endl;
		cout<<"Twoj wybor: ";
		cin>>nr;
		cout<<endl;

		switch(nr){
		
		case 1:
		arr->wczytaj(arr->typ);
		cout << "Wczytano"<<endl;
		break;
	
		case 2:
		int lkolumn, lwierszy;
		cout << "Liczba kolumn: ";
		cin >> lkolumn;
		cout << "Liczba wierszy: ";
		cin >> lwierszy;
		arr->stworzTablice( lkolumn, lwierszy);
		break;
		
		case 3:
		int wybierz_w, wybierz_k, nowy;
		cout<< "Ilosc kolumn: "; 
		cout<< arr->lkolumn <<endl;
		cout<< "Ilosc wierszy ";
 		cout<< arr->lwierszy <<endl;
		arr->wyswietl(arr->typ);
		cout<< "Ktora pozycje zmienic?" <<endl;
		cout<< "Kolumna nr: ";
		cin >> wybierz_k;
		cout << "Wiersz nr: ";
		cin >> wybierz_w;
		if ((wybierz_k>arr->lkolumn)||(wybierz_k<1)||(wybierz_w>arr->lwierszy)||(wybierz_k<1))
		{
	                cout << "Nie ma takiej pozycji\n";
			break;
		}
		else
	        {
                	cout << "Nowy element: ";
                	cin >> nowy;
		}
		arr->zmianaZawart( wybierz_w, wybierz_k, nowy, arr->typ);
		break;		
		
		case 4:
		int n_lkolumn, n_lwierszy, wybor;
		cout << "Podaj liczbe kolumn: ";
		cin >> n_lkolumn;
		cout << "Podaj liczbe wierszy ";
		cin >> n_lwierszy;
		if((n_lkolumn < 1) || (n_lwierszy <1))
		{
			cout << "Rozmiar nie moze byc mniejszy od 1"<<endl;
			break;
		}
		if((n_lkolumn==arr->lkolumn)&&(n_lwierszy==arr->lwierszy))
		{
			cout << "Takie same wymiary, brak zmian"<<endl;
                	break;
        	}
		if((n_lkolumn<arr->lkolumn)||(n_lwierszy<arr->lwierszy))
		{
                	cout << "Uciac elementy?"<<endl;
                	cout << "1.Tak\n2.Nie\n";
                	cin >> wybor;
		}
		if(wybor==0)
		{
			cout << "Nic nie zmieniono"<<endl;
			break;
		}
		else
			arr->zmiana_rozmiaru( n_lkolumn, n_lwierszy);
			break;
		
		case 5:
		arr->wyswietl(arr->typ);
		break;

		case 6:
		arr->zapis(arr->typ);
		cout << "Poprawny zapis"<<endl;
		break;
		
		case 7:
		int u;
		cout<<"Ktora kolumne wybrac:";
		cin>>u;
		arr->sumak( u, arr->typ);
		break;
	
		case 8:
		int r;
		cout<<"Ktory wiersz wybrac:";
		cin>>r;
		arr->sumaw( r,arr->typ);
		break;

		case 9:
		arr->maxmin_k(arr->typ);
		break;

		case 10:
		arr->maxmin_w(arr->typ);
		break;

		case 11:
		int z;
		cout<<"Ktora kolumne wybrac:";
		cin>>z;
		arr->sredniak( z,arr->typ);
		break;
	
		case 12:
		int v;
		cout<<"Ktory wiersz wybrac:";
		cin>>v;
		arr->sredniaw( v,arr->typ);
		break;

		default:
		nr=13;
		break;
		
		}
	}	
}
