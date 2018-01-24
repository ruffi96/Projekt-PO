#include "stdafx.h"
#include "User.h"
#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include<sstream>

using namespace std;



User::User()
{
	//dtor
}

User::User(int flag, int id, string nazwa_inf, string nazwa_)
{
	fstream plik;
	if (flag == -1)
	{
		this->ID = id;
		cout << "	Podaj numer telefonu:\n";
		cin >> login;
		cout << "\n	Podaj has³o do konta: \n";
		cin >> haslo;
		cout << "\n	Podaj imie w³aœciciela:\n";
		cin >> imie;
		cout << "\n	Podaj nazwisko w³aœciciela:\n";
		cin >> nazwisko;
		cout << "\n	W jakiej miejscowosci sie znajduje:\n";
		cin >> miejscowosc;
		
		auto k = this->login.size();
		char zmienna[28];
		for (int i = 0; i<this->login.size(); i++)
			zmienna[i] = login[i];
		zmienna[k] = '_';
		zmienna[k + 1] = 'I';
		zmienna[k + 2] = 'N';
		zmienna[k + 3] = 'F';
		zmienna[k + 4] = '.';
		zmienna[k + 5] = 't';
		zmienna[k + 6] = 'x';
		zmienna[k + 7] = 't';
		zmienna[k + 8] = '\0';

		plik.open(zmienna, ios::out);
		{
			plik << ID << "\n";
			plik << login << "\n";
			plik <<haslo << "\n";
			plik << imie << "\n";
			plik << nazwisko << "\n";
			plik << miejscowosc << "\n";
			
		}
		plik.close();
		plik.clear();
		char  zmienna1[24];
		for (int i = 0; i<this->login.size(); i++)
			zmienna1[i] = login[i];
		zmienna1[k] = '.';
		zmienna1[k + 1] = 't';
		zmienna1[k + 2] = 'x';
		zmienna1[k + 3] = 't';
		zmienna1[k + 4] = '\0';
		plik.open("KONTA.txt", ios::app);
		{
			plik << zmienna << "\n";
			plik << zmienna1 << "\n";
		}
		add_user();
	}
	else
	{
		int i = 0;
		string temp;
		char nazwainf[28];
		cout << nazwa_inf;
		cout << nazwa_;
		for (unsigned int i = 0; i<nazwa_inf.length(); i++)
			nazwainf[i] = nazwa_inf[i];
		cout << nazwainf;

		fstream plik;
		plik.open(nazwainf, ios::in);
		{
			if (plik.good() == false)
			{

			}
			else
			{
				while (getline(plik, temp))
				{
					if (i % 6 == 0)
					{
						int w;
						istringstream iss(temp);
						iss >> w;
						ID = w;
					}
					else if (i % 6 == 1)
						login = temp;
					else if (i % 6 == 2)
						haslo = temp;
					else if (i % 6 == 3)
						imie = temp;
					else if (i % 6 == 4)
						nazwisko = temp;
					else if (i % 6 == 5)
						miejscowosc = temp;
					i++;
				}
			}
		}
		plik.close();
		plik.clear();
		char nazwapol[20];
		for (unsigned int i = 0; i<nazwa_.length(); i++)
			nazwapol[i] = nazwa_[i];
		nazwapol[nazwa_.length()] = '\0';
		historia_user = new Historia(nazwapol);
	}

}

User::~User()
{
}

void User::add_connection(string typ, string rodzaj, string nazwa, float cena, float ilosc, int k)
{
	Connection * poloczenie = new Connection(typ, rodzaj, nazwa);

	poloczenie->dlugosc = ilosc;
	poloczenie->cena_za_min = cena;
	//poloczenie->cena_za_poloczenie = ilosc * cena;
	historia_user->poloczenia_historii.push_back(poloczenie);

}

void * User::add_user()
{
	auto k = this->login.length();
	char zmienna[24];
	for (int i = 0; i<this->login.size(); i++)
		zmienna[i] = this->login[i];
	zmienna[k] = '.';
	zmienna[k + 1] = 't';
	zmienna[k + 2] = 'x';
	zmienna[k + 3] = 't';
	zmienna[k + 4] = '\0';
	historia_user = new Historia(zmienna);
	historia_user->update_produkt_w_baza(zmienna);
	return this;
	
}

int User::zwroc_indeks_poloczenia(string n)
{
	int wynik = -1;
	for (unsigned int i = 0; i<historia_user->poloczenia_historii.size() ; i++)
	{
		if (n == historia_user->poloczenia_historii[i]->nazwa)
		{
			wynik = i;
			break;
		}
	}
	return wynik;
}

void User::show_users(vector<class User*> uzytkownicy)
{
	for (unsigned int i = 0; i<uzytkownicy.size(); i++)
	{
		cout << uzytkownicy[i]->login;
		cout << uzytkownicy[i]->imie;
		cout << uzytkownicy[i]->nazwisko;
		uzytkownicy[i]->historia_user->show_allconnection();
	}
}


void User::show_information()
{
	cout << "Numer telefonu :	 " << login;
	cout << "\nHaslo :  " << haslo;
	cout << "\nImie u¿ytkownika :	 " << imie;
	cout << "\nNazwisko u¿ytkownika :	 " << nazwisko;
	cout << "\nPochodzenie u¿ytkownika :	 " <<miejscowosc;
}


