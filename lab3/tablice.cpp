#include "tablice.h"



void Tablica::wczytaj() 
{
	fstream plik;
	plik.open(DANE);
	int lwierszy;
	int lkolumn;
	int i;
	int j;
	i = j = 0;
	
	plik >> lkolumn >> lwierszy;
	stworzTablice( lkolumn, lwierszy);
	while(i<this->lwierszy)
	{
		while(j<this->lkolumn)
		{
			if (plik.eof())
				break;
			plik >> this->tablica[j][i];
			j += 1;
		}
		i += 1;
		j = 0;
	}
	plik.close();
}


void Tablica::stworzTablice( int lkolumn, int lwierszy)
{	
	int** tablica = (int**)malloc(lkolumn * sizeof(int*));
	for (int i = 0; i < lkolumn; i++)
		tablica[i] = (int*)malloc(lwierszy*sizeof(int));
	for (int i = 0; i < lwierszy; i++)
		for (int j = 0; j < lkolumn; j++)
			tablica[j][i] = 0;
	this->tablica = tablica;
	this->lkolumn = lkolumn;
	this->lwierszy = lwierszy;
}


void Tablica::zmianaZawart( int wybierz_w, int wybierz_k, int nowy)
{
	this->tablica[wybierz_k-1][wybierz_w-1]=nowy;
	return;
}


void Tablica::zmiana_rozmiaru( int n_lkolumn, int n_lwierszy)
{	
	int a_lkolumn = this->lkolumn;
	int a_lwierszy = this->lwierszy;
	Tablica* nowa = (Tablica*)malloc(sizeof(Tablica));
	stworzTablice( n_lkolumn, n_lwierszy);
	if (n_lkolumn < this->lkolumn)
		a_lkolumn = n_lkolumn;
	if (n_lwierszy < this->lwierszy)
		a_lwierszy = n_lwierszy;
	for(int i=0;i<a_lwierszy;i++)
		for(int j=0;j<a_lkolumn;j++)
			tablica[j][i]=this->tablica[j][i];
	free(this->tablica);
	this->tablica = tablica;
	this->lkolumn = n_lkolumn;
	this->lwierszy = n_lwierszy;
}


void Tablica::wyswietl()
{
	for (int i = 0; i < lwierszy; i++)
	{
		for (int j = 0; j < lkolumn; j++)
			cout<<" "<<tablica[j][i];
		cout << endl;
	}
}


void Tablica::zapis() {
	fstream plik;
	plik.open(DANE, ios::trunc | ios::out);
	plik << lkolumn << endl;
	cout << lwierszy << endl;
	for (int i = 0; i < lwierszy; i++)
	{
		for (int j = 0; j < lkolumn; j++)
			plik << tablica[j][i] << " ";
		plik << endl;
	}
}


void Tablica::sumak( int j)
{
	int suma = 0;
	wyswietl();
	cout << endl;
	for (int i = 0; i < lkolumn; i++)
	{
			suma += tablica[j][i]; 
	}	
	
	cout << "Suma kolumn wynosi: "<<suma;
	cout << endl;
}


void Tablica::sumaw( int j)
{
	int suma = 0;
	wyswietl();
	cout << endl;
	for (int i = 0; i < lwierszy; i++)
	{
			suma += tablica[i][j];
	}	
	
	cout << "Suma wierszy wynosi: "<<suma;
	cout << endl;
}


void Tablica::maxmin_k()
{
	wyswietl();
	cout << endl;
	int min = INT16_MAX;
	int max = INT16_MIN;
	for (int i = 0; i < lkolumn; i++)
	{
		for (int j = 0; j < lwierszy; j++)
			if (min > tablica[i][j])
				min = tablica[i][j];
		cout << min;
		min = INT16_MAX;
	}
	cout << "  min";
	cout << endl;
	for (int i = 0; i < lkolumn; i++)
	{
		for (int j = 0; j < lwierszy; j++)
			if (max < tablica[i][j])
				max = tablica[i][j];
		cout << max;
		max = INT16_MIN;
	}
	cout << " max";
	cout << endl;
}


void Tablica::maxmin_w()
{
	cout << endl;
	char a = ' ';
	int min = INT16_MAX;
	int max = INT16_MIN;
	for (int i = 0; i < lwierszy; i++)
	{
		for (int j = 0; j < lkolumn; j++)
		{
			if (min > tablica[j][i])
				min = tablica[j][i];
			if (max < tablica[j][i])
				max = tablica[j][i];
			cout <<" "<< tablica[j][i];
		}
		cout << min << max;
		min = INT16_MAX;
		max = INT16_MIN;
	}
	for (int i = 0; i < lkolumn; i++)
		cout << a;
	cout << "       min  max" << endl;
}


void Tablica::sredniak( int j)
{
	float suma = 0;
	wyswietl();
	cout << endl;
	for (int i = 0; i < lkolumn; i++)
	{
			suma += tablica[j][i]; 
	}	
	
	cout << "Srednia wartosci kolumny wynosi: "<<suma/lwierszy;
	cout << endl;
}


void Tablica::sredniaw( int j)
{
	float suma = 0;
	wyswietl();
	cout << endl;
	for (int i = 0; i < lwierszy; i++)
	{
			suma += tablica[i][j];
	}	
	
	cout << "Srednia wartosci wiersza wynosi: "<<suma/lkolumn;
	cout << endl;
}

