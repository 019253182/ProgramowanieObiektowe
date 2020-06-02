#ifndef TABLICE_H
#define TABLICE_H
#define DANE "DANE.txt"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;
class Komorka
{
	public:
	int wartosc;
	float wartoscFloat;
	std::string wartoscString;
	void ustaw(int x);
	void ustaw(float x);
	void ustaw(std::string x);

};
/**
 *klasa Tablica ktora zawiera
 *
 *tablice
 *liczbe kolumn
 *liczbe wierszy
 */
class Tablica
{
	public:
		Komorka** tablica;	
		int lkolumn;
		int lwierszy;
		int typ;
	
	void wybierzTyp(int t);

/**
 *
 *funkcja wczytaj sluzy do wczytania tablicy z pliku i funkcjonuje przy wykorzystaniu struktury
 *
 */
	int wczytaj(int t);
/**
 *
 *funkcja udostepnia wczesniej zajete miejsce na nowa tablice
 *
 */

	int stworzTablice( int lkolumn, int lwierszy);
/**
 *funkcja zmienia zawartosc tablicy i korzysta z klasy Tablica
 *
 *wybierz_w sluzy do wybrania wiersza 
 *wybierz_k sluzy do wybrania kolumny 
 *nowy nowa element 
 *
 */
	int zmianaZawart( int wybierz_w, int wybierz_k, int nowy, int t);

	int zmianaZawart( int wybierz_w, int wybierz_k, float nowy, int t);

	int zmianaZawart( int wybierz_w, int wybierz_k, std::string nowy, int t);
	
/**
 *funkcja zmienia rozmiar tablicy i korzysta z klasy Tablica
 *
 *n_lkolumn to nowaliczba kolumn 
 *n_lwierszy to nowa liczba wierszy 
 *
 */

	int zmiana_rozmiaru( int n_lkolumn, int n_lwierszy);
/**
 *
 *funkcja wyswietla utworzona tablice i korzysta z klasy Tablica
 *
 */

	int wyswietl(int t);
/**
 *
 *funkcja zapisuje utworzona tablice do pliku i korzysta z klasy Tablica
 *
 */

	int zapis(int t);
/**
 *
 *funkcja sumuje wartosci wybranej kolumny i korzysta z klasy Tablica
 *
 *j to zmienna wyboru kolumny
 */

	int sumak( int j, int t);
/**
 *
 *funkcja sumuje wartosci wybranego wiersza i korzysta z klasy Tablica
 *
 *j to zmienna wyboru wiersza
 */

	int sumaw( int j, int t);
/**
 *
 *funkcja wyznacza maksymalna i minimalna wartosc kolumn i korzysta z klasy Tablica
 *
 */
	int maxmin_k(int t);
/**
 *
 *funkcja wyznacza maksymalna i minimalna wartosc kolumn i korzysta z klasy Tablica
 *
 */
	int maxmin_w(int t);
/**
 *
 *funkcja podaje srednia wartosci wybranej kolumny i korzysta z klasy Tablica
 *
 *j to zmienna wyboru kolumny
 */

	int sredniak( int j, int t);
/**
 *
 *funkcja podaje srednia wartosci wybranego wiersza i korzysta z klasy Tablica
 *
 *j to zmienna wyboru wiersza
 */

	int sredniaw( int j, int t);
};
#endif
 
