#include "tablice.h"

/*void Komorka::ustaw(int x)
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
*/
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
	std::string d;
	
	plik >> lkolumn >> lwierszy;
	stworzTablice( lkolumn, lwierszy);
	
	
	while(i<this->lwierszy)
		{
			while(j<this->lkolumn)
			{
				if (plik.eof())
					break;
				plik >> d;
				tablica[j][i]->zmien_wartosc(const_cast<char*>(d.c_str()));
				j += 1;
			}
			i += 1;
			j = 0;
		}
	
	
	
	plik.close();
}


int Tablica::stworzTablice(int lkolumn, int lwierszy)
{	
	

	tablica = new komorka * *[lkolumn];
	for(int i=0;i<lkolumn;i++)
	{
		tablica[i]= new komorka* [lwierszy];
	}
	for(int i=0;i<lkolumn;i++)
	{
		
		for (int j = 0; j < lwierszy; j++) {
			if(tab[i]==0)
				tablica[i][j]=new komorka_float();
			if(tab[i]==1)
				tablica[i][j]=new komorka_int();
			if(tab[i]==2)
				tablica[i][j]=new komorka_string();
		}
	}
	/*tab = new int[lkolumn];
	Komorka** tablica = new Komorka* [lkolumn];
	for (int i = 0; i < lkolumn; i++)
		tablica[i] = new Komorka [lwierszy];
	for (int i = 0; i < lwierszy; i++)
		for (int j = 0; j < lkolumn; j++)
			tablica[j][i].ustaw(0);

	
	this->tablica = tablica;
	this->lkolumn = lkolumn;
	this->lwierszy = lwierszy;*/
}

int Tablica::zmianaZawart( int wybierz_w, int wybierz_k)
{
	
	std::string nowyString;
	int t=tab[wybierz_k];
	cout<<"Podaj nowa wartosc komorki:";
	
	cin>>nowyString;
	tablica[wybierz_k][wybierz_w]->zmien_wartosc(const_cast<char*>(nowyString.c_str()));

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
		delete [] tablica[i];
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
			tablica[i][j]->wyswietl_wartosc();
			
		}
		cout<<endl;		
	}


}




int Tablica::zapis(int t) {
	fstream plik;
	plik.open(DANE, ios::trunc | ios::out);
	plik << lkolumn << endl;
	cout << lwierszy << endl;
	
		for (int i = 0; i < lwierszy; i++)
		{
			for (int j = 0; j < lkolumn; j++)
				plik << tablica[j][i]->get_x() << " ";
			plik << endl;
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
				suma += tablica[j][i]->get_x(); 
		}	
		cout << "Suma kolumn wynosi: "<<suma;
	}
	if(t==1)
	{
		for (int i = 0; i < lkolumn; i++)
		{
				suma += tablica[j][i]->get_x(); 
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
	for(int i=0;i<lwierszy;i++)
	{
		if(t==0||t==1)
			suma+=tablica[j][i]->get_x();
	}
	cout<<"Suma wierszy wynosi: "<<suma;
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
			if (min > tablica[i][j]->get_x())
				min = tablica[i][j]->get_x();
		cout << min;
		min = INT16_MAX;
	}
	cout << "  min";
	cout << endl;
	for (int i = 0; i < lkolumn; i++)
	{
		for (int j = 0; j < lwierszy; j++)
			if (max < tablica[i][j]->get_x())
				max = tablica[i][j]->get_x();
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
			if (min > tablica[i][j]->get_x())
				min = tablica[i][j]->get_x();
		cout << min;
		min = INT16_MAX;
	}
	cout << "  min";
	cout << endl;
	for (int i = 0; i < lkolumn; i++)
	{
		for (int j = 0; j < lwierszy; j++)
			if (max < tablica[i][j]->get_x())
				max = tablica[i][j]->get_x();
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
				if (min > tablica[j][i]->get_x())
					min = tablica[j][i]->get_x();
				if (max < tablica[j][i]->get_x())
					max = tablica[j][i]->get_x();
				cout <<" "<< tablica[j][i]->get_x();
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
				if (min > tablica[j][i]->get_x())
					min = tablica[j][i]->get_x();
				if (max < tablica[j][i]->get_x())
					max = tablica[j][i]->get_x();
				cout <<" "<< tablica[j][i]->get_x();
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
				suma += tablica[j][i]->get_x(); 
		}	
	
		cout << "Srednia wartosci kolumny wynosi: "<<suma/lwierszy;
	}
	if(t==1)
		{
		for (int i = 0; i < lkolumn; i++)
		{
				suma += tablica[j][i]->get_x(); 
		}	
	
		cout << "Srednia wartosci kolumny wynosi: "<<(float)suma/lwierszy;
		
	}
	if(t==2)
	{
		cout<<"Nie mozna wykonac dla string"<<endl;
	}
	cout << endl;
}


int Tablica::sredniaw( int j, int t)
{
	int suma = 0;
	
	this->wyswietl();
	

	cout << endl;
	for(int i=0;i<lwierszy;i++)
	{
		if(t==0||t==1)
			suma+=tablica[j][i]->get_x();
	}
	cout<<"Srednia wierszy wynosi: "<<(float)suma/lkolumn;
	cout << endl;
}

