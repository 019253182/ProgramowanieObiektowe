#ifndef TABLICE_H
#define TABLICE_H
#define DANE "DANE.txt"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;
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
		int** tablica;	
		int lkolumn;
		int lwierszy;

/**
 *
 *funkcja wczytaj sluzy do wczytania tablicy z pliku i funkcjonuje przy wykorzystaniu struktury
 *
 */
	void wczytaj();
/**
 *
 *funkcja udostepnia wczesniej zajete miejsce na nowa tablice
 *
 */

	void stworzTablice( int lkolumn, int lwierszy);
/**
 *funkcja zmienia zawartosc tablicy i korzysta z klasy Tablica
 *
 *wybierz_w sluzy do wybrania wiersza 
 *wybierz_k sluzy do wybrania kolumny 
 *nowy nowa element 
 *
 */

	void zmianaZawart( int wybierz_w, int wybierz_k, int nowy);
/**
 *funkcja zmienia rozmiar tablicy i korzysta z klasy Tablica
 *
 *n_lkolumn to nowaliczba kolumn 
 *n_lwierszy to nowa liczba wierszy 
 *
 */

	void zmiana_rozmiaru( int n_lkolumn, int n_lwierszy);
/**
 *
 *funkcja wyswietla utworzona tablice i korzysta z klasy Tablica
 *
 */

	void wyswietl();
/**
 *
 *funkcja zapisuje utworzona tablice do pliku i korzysta z klasy Tablica
 *
 */

	void zapis();
/**
 *
 *funkcja sumuje wartosci wybranej kolumny i korzysta z klasy Tablica
 *
 *j to zmienna wyboru kolumny
 */

	void sumak( int j);
/**
 *
 *funkcja sumuje wartosci wybranego wiersza i korzysta z klasy Tablica
 *
 *j to zmienna wyboru wiersza
 */

	void sumaw( int j);
/**
 *
 *funkcja wyznacza maksymalna i minimalna wartosc kolumn i korzysta z klasy Tablica
 *
 */
	void maxmin_k();
/**
 *
 *funkcja wyznacza maksymalna i minimalna wartosc kolumn i korzysta z klasy Tablica
 *
 */
	void maxmin_w();
/**
 *
 *funkcja podaje srednia wartosci wybranej kolumny i korzysta z klasy Tablica
 *
 *j to zmienna wyboru kolumny
 */

	void sredniak( int j);
/**
 *
 *funkcja podaje srednia wartosci wybranego wiersza i korzysta z klasy Tablica
 *
 *j to zmienna wyboru wiersza
 */

	void sredniaw( int j);
};
#endif
 
