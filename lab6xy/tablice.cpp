#include "tablice.h"

void Komorka::ustaw(int x)
{
	this->wartosc = x;
}

void Komorka::ustaw(float x)
{
	this->wartoscFloat = x;
}

void Komorka::ustaw(std::string& x)
{
	this->wartoscString = x;
}

void Tablica::wybierzTyp(int t)
{
	this->typ = t;
}


int Tablica::wczytaj(int t) 
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
	if(t == 0)
	{
		while(i<this->lwierszy)
		{
			while(j<this->lkolumn)
			{
				if (plik.eof())
					break;
				plik >> this->tablica[j][i].wartoscFloat;
				j += 1;
			}
			i += 1;
			j = 0;
		}
	}
	if(t == 1)
	{
		while(i<this->lwierszy)
		{
			while(j<this->lkolumn)
			{
				if (plik.eof())
					break;
				plik >> this->tablica[j][i].wartosc;
				j += 1;
			}
			i += 1;
			j = 0;
		}	
	}
	if(t == 2)
	{
		while(i<this->lwierszy)
		{
			while(j<this->lkolumn)
			{
				if (plik.eof())
					break;
				plik >> this->tablica[j][i].wartoscString;
				j += 1;
			}
			i += 1;
			j = 0;
		}	
	}
	
	plik.close();
}


int Tablica::stworzTablice( int lkolumn, int lwierszy )
{	
	tab = new int[lkolumn];
	Komorka** tablica = new Komorka* [lkolumn];
	for (int i = 0; i < lkolumn; i++)
		tablica[i] = new Komorka [lwierszy];
	for (int i = 0; i < lwierszy; i++)
		for (int j = 0; j < lkolumn; j++)
			tablica[j][i].ustaw(0);

	
	this->tablica = tablica;
	this->lkolumn = lkolumn;
	this->lwierszy = lwierszy;
}

int Tablica::zmianaZawart( int wybierz_w, int wybierz_k)
{
	int nowyInt;
	float nowyFloat;
	std::string nowyString;
	int t=tab[wybierz_k];
	cout<<"Podaj nowa wartosc komorki:";
	if(t==0)
	{
		cin>>nowyFloat;
		this->tablica[wybierz_k-1][wybierz_w-1].ustaw(nowyFloat);
	}
	if(t==1)
	{
		cin>>nowyInt;
		this->tablica[wybierz_k-1][wybierz_w-1].ustaw(nowyInt);
	}
	if(t==2)
	{
		cin>>nowyString;
		this->tablica[wybierz_k-1][wybierz_w-1].ustaw(nowyString);
	}
	return 0;
}

/**int Tablica::zmianaZawart( int wybierz_w, int wybierz_k, int t)
{
	int nowyInt;
	float nowyFloat;
	std::string nowyString;
	cout<<"Podaj nowa wartosc komorki:";
	if(t==0)
	{
		cin>>nowyFloat;
		this->tablica[wybierz_k-1][wybierz_w-1].ustaw(nowyFloat);
	}
	if(t==1)
	{
		cin>>nowyInt;
		this->tablica[wybierz_k-1][wybierz_w-1].ustaw(nowyInt);
	}
	if(t==2)
	{
		getline(cin, nowyString);
		this->tablica[wybierz_k-1][wybierz_w-1].ustaw(nowyString);
	}
	return 0;
}*/


int Tablica::zmiana_rozmiaru( int n_lkolumn, int n_lwierszy)
{	
	realloc(tab,n_lkolumn);
	int a_lkolumn = this->lkolumn;
	int a_lwierszy = this->lwierszy;
	Tablica* nowa = new Tablica;
	stworzTablice( n_lkolumn, n_lwierszy);
	if (n_lkolumn < this->lkolumn)
		a_lkolumn = n_lkolumn;
	if (n_lwierszy < this->lwierszy)
		a_lwierszy = n_lwierszy;
	for(int i=0;i<a_lwierszy;i++)
		for(int j=0;j<a_lkolumn;j++)
			tablica[j][i]=this->tablica[j][i];
	for(int i=0;i<a_lwierszy;i++)
		delete tablica[i];
		for(int j=0;j<a_lkolumn;j++)
			delete [] tablica;
	delete[] this->tablica;
	this->tablica = tablica;
	this->lkolumn = n_lkolumn;
	this->lwierszy = n_lwierszy;
}

int Tablica::wyswietl()
{

	for (int j=0; j<lwierszy; j++)
	{
		for(int i = 0; i < lkolumn; i++)
		{
			int t=tab[i];
			if(t==0)
			{
				cout<<" "<<tablica[i][j].wartoscFloat;
			}
			if(t==1)
			{	
				cout<<" "<<tablica[i][j].wartosc;
			}
			if(t==2)
			{
				cout<<" "<<tablica[i][j].wartoscString;
			}
		}
		cout<<endl;		
	}


}




int Tablica::zapis(int t) {
	fstream plik;
	plik.open(DANE, ios::trunc | ios::out);
	plik << lkolumn << endl;
	cout << lwierszy << endl;
	if(t==0)
	{
		for (int i = 0; i < lwierszy; i++)
		{
			for (int j = 0; j < lkolumn; j++)
				plik << tablica[j][i].wartoscFloat << " ";
			plik << endl;
		}
	}
	if(t==1)
	{
		for (int i = 0; i < lwierszy; i++)
		{
			for (int j = 0; j < lkolumn; j++)
				plik << tablica[j][i].wartosc << " ";
			plik << endl;
		}
	}
	if(t==2)
	{
		for (int i = 0; i < lwierszy; i++)
		{
			for (int j = 0; j < lkolumn; j++)
				plik << tablica[j][i].wartosc << " ";
			plik << endl;
		}
	}
}


int Tablica::sumak( int j, int t)
{
	
	float suma = 0;
	
	this->wyswietl();
	

	cout << endl;
	if(t == 0)
	{
		for (int i = 0; i < lkolumn; i++)
		{
				suma += tablica[j][i].wartoscFloat; 
		}	
		cout << "Suma kolumn wynosi: "<<suma;
	}
	if(t==1)
	{
		for (int i = 0; i < lkolumn; i++)
		{
				suma += tablica[j][i].wartosc; 
		}	
		cout << "Suma kolumn wynosi: "<<suma;
	}
	if(t==2)
	{
		cout<<"Nie mozna wykonac dla tablicy string"<<endl;
	}
	cout << endl;
}


int Tablica::sumaw( int j, int t)
{
	int suma = 0;
	
	this->wyswietl();
	

	cout << endl;
	if(t==0)
	{
		for (int i = 0; i < lwierszy; i++)
		{
				suma += tablica[i][j].wartoscFloat;
		}
		cout << "Suma wierszy wynosi: "<<suma;
	}	
	if(t==1)
	{
		for (int i = 0; i < lwierszy; i++)
		{
				suma += tablica[i][j].wartosc;
		}
		cout << "Suma wierszy wynosi: "<<suma;
	}	
	if(t==2)
	{
		cout<<"Nie mozna wykonac dla tablicy string"<<endl;
	}
	cout << endl;
}


int Tablica::maxmin_k(int t)
{
	
	this->wyswietl();
			

	cout << endl;
	int min = INT16_MAX;
	int max = INT16_MIN;
	if(t==0)
	{
	for (int i = 0; i < lkolumn; i++)
	{
		for (int j = 0; j < lwierszy; j++)
			if (min > tablica[i][j].wartoscFloat)
				min = tablica[i][j].wartoscFloat;
		cout << min;
		min = INT16_MAX;
	}
	cout << "  min";
	cout << endl;
	for (int i = 0; i < lkolumn; i++)
	{
		for (int j = 0; j < lwierszy; j++)
			if (max < tablica[i][j].wartoscFloat)
				max = tablica[i][j].wartoscFloat;
		cout << max;
		max = INT16_MIN;
	}
	cout << " max";
	}
	if(t==1)
	{
	for (int i = 0; i < lkolumn; i++)
	{
		for (int j = 0; j < lwierszy; j++)
			if (min > tablica[i][j].wartosc)
				min = tablica[i][j].wartosc;
		cout << min;
		min = INT16_MAX;
	}
	cout << "  min";
	cout << endl;
	for (int i = 0; i < lkolumn; i++)
	{
		for (int j = 0; j < lwierszy; j++)
			if (max < tablica[i][j].wartosc)
				max = tablica[i][j].wartosc;
		cout << max;
		max = INT16_MIN;
	}
	cout << " max";
	}
	if(t==2)
	{
		cout<<"Nie mozna wykonac dla tablicy string";
	}
	cout << endl;
}


int Tablica::maxmin_w(int t)
{
	cout << endl;
	char a = ' ';
	int min = INT16_MAX;
	int max = INT16_MIN;
	if(t==0)
	{
		for (int i = 0; i < lwierszy; i++)
		{
			for (int j = 0; j < lkolumn; j++)
			{
				if (min > tablica[j][i].wartoscFloat)
					min = tablica[j][i].wartoscFloat;
				if (max < tablica[j][i].wartoscFloat)
					max = tablica[j][i].wartoscFloat;
				cout <<" "<< tablica[j][i].wartoscFloat;
			}
			cout << min << max;
			min = INT16_MAX;
			max = INT16_MIN;
		}
		for (int i = 0; i < lkolumn; i++)
			cout << a;
		cout << "       min  max" << endl;
	}
	if(t==1)
	{
		for (int i = 0; i < lwierszy; i++)
		{
			for (int j = 0; j < lkolumn; j++)
			{
				if (min > tablica[j][i].wartosc)
					min = tablica[j][i].wartosc;
				if (max < tablica[j][i].wartosc)
					max = tablica[j][i].wartosc;
				cout <<" "<< tablica[j][i].wartosc;
			}
			cout << min << max;
			min = INT16_MAX;
			max = INT16_MIN;
		}
		for (int i = 0; i < lkolumn; i++)
			cout << a;
		cout << "       min  max" << endl;
	}
	if(t==2)
	{
		cout<<"Nie mozna wykonac dla tablicy string"<<endl;	
	}
}


int Tablica::sredniak( int j, int t)
{
	float suma = 0;
	
	this->wyswietl();
		

	cout << endl;
	if(t==0)
	{
		for (int i = 0; i < lkolumn; i++)
		{
				suma += tablica[j][i].wartoscFloat; 
		}	
	
		cout << "Srednia wartosci kolumny wynosi: "<<suma/lwierszy;
	}
	if(t==1)
		{
		for (int i = 0; i < lkolumn; i++)
		{
				suma += tablica[j][i].wartosc; 
		}	
	
		cout << "Srednia wartosci kolumny wynosi: "<<suma/lwierszy;
	}
	if(t==2)
	{
		cout<<"Nie mozna wykonac dla string"<<endl;
	}
	cout << endl;
}


int Tablica::sredniaw( int j, int t)
{
	float suma = 0;
	
	this->wyswietl();
		

	cout << endl;
	if(t==0)
	{
		for (int i = 0; i < lwierszy; i++)
		{
				suma += tablica[i][j].wartoscFloat;
		}	
	
		cout << "Srednia wartosci wiersza wynosi: "<<suma/lkolumn;
	}
	if(t==1)
	{
		for (int i = 0; i < lwierszy; i++)
		{
				suma += tablica[i][j].wartosc;
		}	
	
		cout << "Srednia wartosci wiersza wynosi: "<<suma/lkolumn;
	}
	if(t==2)
	{
		cout<<"Nie mozna wykonac dla tablicy string"<<endl;
	}
		
	cout << endl;
}

