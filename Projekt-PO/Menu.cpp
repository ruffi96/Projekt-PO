#include "stdafx.h"
#include "Menu.h"
#include<iostream>
#include<fstream>
#include<string>

using namespace std;


Menu::Menu()
{
	//dtor
}

void Menu::menu_admin()
{
	cout << "		Menu Administratora\n";
	cout << "	1.Dodaj konto\n";
	cout << "	2.Usuñ konto\n";
	cout << "	3.Wyswietl konta i ich historie\n";
	//cout << "	4.Wejdz w wybrane konto\n";
	cout << "	5.Dodaj poloczenie";
	//cout << "	6.Wyswietl statystyki\n";
	cout << "	Aby sie wylogowaæ kliknij Q\n";




}

void Menu::meeenu(int)
{
	cout << "Polaczyles sie z systemem historii polaczen uzytkownikow,za chwilê pojawi siê opcja logowania\n\n w celu zalogowania sie wpisz swoj numer telefonu, a nastepnie has³o do konta" << endl << endl;

}

void Menu::meeenu()
{
	cout << "	Witaj ";
}

void Menu::menu_user(string naz)
{
	cout << "		Menu Uzytkownika  "<<naz<<" \n";
	cout << "	1.Wyœwietl historie poloaczen\n";
	cout << "	2.Wyswietl liczbe poloczen\n";
	cout << "	3.Wyswietl kwote przeznaczona na poloczenia\n";
	cout << "	4.Wyswietl dane o koncie \n";
	cout << "	5.Wyœwietl najd³uzsze poloczenien\n";
	cout << "	Aby sie wylogowaæ kliknij Q\n";
}



Menu::~Menu()
{
	//dtor
}

string Menu::wyswietl_typ()
{
	char wybor;
	system("cls");
	cout << "			DODAWANIE POLOCZENIA\n";

	cout << "\n1. Odebrane";
	cout << "\n2.Nieodebrane\n";
	while (true)
	{
		cin >> wybor;
		switch(wybor)
		{
		case '1':
			return "ODEBRANE";
		case '2':
			return "NIEODEBRANE";
		default:
			cout << "	PROSZE PODAC JESZCZE RAZ\n";
			break;
		}
	}
}

string Menu::wyswietl_godzine(string typ)
{
	string a;
	if (typ == "ODEBRANE")
	{
		cout << "Podaj godzine odebrania poloczenia (podanie odpowiedzi na wygladac nastepujaco \"ggmm\")";
		while (true)
		{
			cin >> a;
			return a;
		}
		

	}
	else
	{
		cout << "Podaj godzine nieodebrania poloczenia (podanie odpowiedzi na wygladac nastepujaco \"ggmm\")";
		while (true)
		{
			cin >> a;
			return a;
		}

	}

}

string Menu::wyswietl_nazwe()
{
	string nazwa;
	cout << "\nPodaj numer :\n";
	cin.ignore();
	getline(cin, nazwa);
	return nazwa;
	
}
