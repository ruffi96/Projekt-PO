// Projekt-PO.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<string>
#include<list>
#include<fstream>
#include"User.h"
#include"Allusers.h"

using namespace std;

list <string> konto_his;

void wczytaj_konta()
{
	string zmienna;
	int i = 0;

	fstream plik;
	plik.open("c:\\dane.txt"); //daj tutaj swoja sciezke
	if (plik.good() == true)
	{
		int nr_wiersza = 0;
		string wiersz;
		while (!plik.eof())  // pamietaj ze petla wykona sie dodtkowo o 1 obrot wiecej
		{
			getline(plik, wiersz);
			nr_wiersza++;
			//cout<<wiersz<<endl;
		}
		cout << nr_wiersza << endl;
	}
	else cout << "ERROR\n\n";
	system("pause");


	plik.open("konta.txt", ios::in);
	{
		if (plik.good() == false)
			return;
		else
		{
			while (getline(plik, zmienna))
			{
				if (i % 2 == 0) // NAZWA PLIKU Z INFORMACJAMI
					nazwy_plikow_inf.push_back(zmienna);
				else
					nazwy_plikow_prod.push_back(zmienna);
				i++;
			}
		}
	}
	plik.close();
	plik.clear();
}

int main()
{
	string login, haslo;
	User* nowy = new User;

	Allusers *wszyscy = new Allusers;
	wszyscy->uzytokownicy
		

	cout << "	Witaj !";
	cout << "Połączyłeś się z systemem historii połączeń użytkowników,za chwilę pojawi się opcja logowania\n w celu zalogowania się wpisz swój numer telefonu, a następnie hasło do konta";
	system("pause");

	cout << "	Podaj swój login : \n";
	cin >> login;
	cout << "\n	Podaj swoje haslo : \n";
	cin >> haslo;

	wszyscy->czy_istnieje(login);
	nowy->login = login;
	nowy->haslo = haslo;

    return 0;
}

