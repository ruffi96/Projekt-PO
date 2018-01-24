#pragma once
#include<iostream>
#include<string>
#include"Historia.h"
#include<vector>

using namespace std;


class User
{public:
	string login;	//numer telefonu
	string haslo;
	Historia *historia_user;
	int ID;
	string imie;		//miejscowosc
	string nazwisko;	//adres
	string miejscowosc;	//adres

	User();
	User(int,int,string,string);
	virtual ~User();
	void add_connection(string,string,string,float,float,int);	//dodaj towar do sklepu
	void * add_user();	//dodaj sklep
	int zwroc_indeks_poloczenia(string);
	void show_users(vector <class User*>);	//wyswietl wszystkie konta
	void show_information();	//wyswietl informacje o koncie 




};

