#pragma once
#include<iostream>
#include<string>
#include<ctime>
#include<vector>
#include"Connection.h"

class Historia
{
public:
	string naz;

	Historia();
	Historia(string nazwa);
	virtual ~Historia();
	vector<class Connection*> poloczenia_historii;
	void add_connection(string, string, string,string);	//dodaj produkt
	int kwota_polaczen();
	void najdluzsze();
	int zwroc_indeks(string nazwa_pol,string data,string godzina); //zwraca czy dane poloczenie istnieje czy nie 
	void update_produkt_w_baza(string nazwa);
	int liczba_odebranych();
	int liczba_nieodebranych();
	int liczba_wszystkich_poloczen();

	friend bool porownaj(string, string);
	void show_allconnection();	//wyswietl poloczenia
	void show_allconnection_sort_ilo();		//wyswietl poloczenia posortowane wedlug czasa trwania11
	bool szukaj_poloczenia(string nazwa);	//szukaj produktu( poloczenia)
	void wyswietl_rodzajami(string, string);
	//int zwroc_indeks(string nazwa_pol, string data, string godzina);
};

