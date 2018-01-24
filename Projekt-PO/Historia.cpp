#include "stdafx.h"
#include "Historia.h"
#include<iostream>
#include<string>
#include<fstream>
#include<ctime>
#include<vector>
#include<sstream>
#include"Connection.h"

using namespace std;

Historia::Historia()
{
	cout << " ";
}

Historia::Historia(string nazwa)
{
	naz = "HISTORIA";
	fstream plik;
	string zmienna;
	int i = 0;
	float k;
	plik.open(nazwa, ios::in);
	{
		if (plik.good() == false)
		{
			return;
		}
		else
		{
			Connection * nowy = new Connection;
			while (getline(plik, zmienna))
			{
				if (i % 6 == 0)
					nowy->nazwa = zmienna;
				else if (i % 6 == 1)
					nowy->typ = zmienna;
				else if (i % 6 == 2)
					nowy->godzina = zmienna;
				else if (i % 6 == 3)
				{
					k = strtof((zmienna).c_str(), 0); //ZAMIANA STRING NA FLOAT
					nowy->dlugosc = k;
				}
				else if (i % 6 == 4)
				{
					k = strtof((zmienna).c_str(), 0); //ZAMIANA STRING NA FLOAT
					nowy->cena_za_min = k;
				}
				else if (i % 6 == 5)
					nowy->data = zmienna;
				i++;
			}
		}
	}
	plik.close();
	plik.clear();
}


Historia::~Historia()
{
}

int Historia::zwroc_indeks(string nazwa_pol,string data,string godzina)
{
	for (unsigned int i = 0; i<poloczenia_historii.size(); i++)
	{
		if ((nazwa_pol == poloczenia_historii[i]->nazwa)&&(data==poloczenia_historii[i]->data)&&(godzina==poloczenia_historii[i]->godzina))
		{
			return i;
		}
	}
	return -1;
}

void Historia::update_produkt_w_baza(string nazwa)
{
	fstream plik;
	string zmienna;
	plik.open(nazwa, ios::out);
	{
		for (unsigned int i = 0; i<poloczenia_historii.size(); i++)
		{
			plik << poloczenia_historii[i]->nazwa << "\n";
			plik << poloczenia_historii[i]->typ << "\n";
			plik << poloczenia_historii[i]->godzina << "\n";
			plik << poloczenia_historii[i]->dlugosc << "\n";
			plik << poloczenia_historii[i]->cena_za_min << "\n";
			plik << poloczenia_historii[i]->data << "\n";
		}
	}
	plik.close();
	plik.clear();

}

int Historia::liczba_nieodebranych()
{
	int a=0;
	for (unsigned int i = 0; i < poloczenia_historii.size(); i++)
	{
		if (poloczenia_historii[i]->typ != "ODEBRANE")
		{
			a = a + 1;
		}
	}
	return a;
}

int Historia::kwota_polaczen()
{
	float a = 0, b = 0;
	if (poloczenia_historii.size() == 0)
	{
		cout << "Brak historii polaczen";
	}
	else
	{
		for (unsigned int i = 0; i < poloczenia_historii.size(); i++)
		{
			a = poloczenia_historii[i]->dlugosc*poloczenia_historii[i]->cena_za_min;
			b = b + a;
			
		}
	}
	
	cout << endl;
	return b;
}

void Historia::najdluzsze()
{
	float a = 0;
	int b = 0;
	if (poloczenia_historii.size() == 0)
		cout << "Brak historii polaczen";
	else
	{
		for (unsigned int i = 0; i < poloczenia_historii.size(); i++)
		{
			if (a <= poloczenia_historii[i]->dlugosc)
			{
				a = poloczenia_historii[i]->dlugosc;
				b=i;
			}
		}
		cout << "\nNajdluzsze polaczenie to :\n\n";
		cout << "-----------------------------\n";
		cout << "TYP:\t   " << poloczenia_historii[b]->typ << "\n";
		cout << "GODZINA:\t   " << poloczenia_historii[b]->godzina << "\n";
		cout << "NAZWA:\t   " << poloczenia_historii[b]->nazwa << "\n";
		cout << "CENA ZA MIN:\t   " << poloczenia_historii[b]->cena_za_min << " ZL";
		cout << "DLUGOSC:\t   " << poloczenia_historii[b]->dlugosc;
		cout << "\nDATA POLOCZENIA:   \t   " << poloczenia_historii[b]->data;
		cout << "\n";
		cout << "-----------------------------\n";
	}

	cout << endl;
}
int Historia::liczba_wszystkich_poloczen()
{
	int a = poloczenia_historii.size();
	
	return a;
}

int Historia::liczba_odebranych()
{
	int a = 0;
	for (unsigned int i = 0; i < poloczenia_historii.size(); i++)
	{
		if (poloczenia_historii[i]->typ == "ODEBRANE")
		{
			a = a + 1;
		}
	}
	return a;
}

void Historia::show_allconnection()
{
	cout << "------Poloczenia  " << naz << " ------\n";
	if (poloczenia_historii.size() == 0)
		cout << "Brak historii polaczen";
	else
	{
		for (unsigned int i = 0; i < poloczenia_historii.size(); i++)
		{
			cout << "-----------------------------\n";
			cout << "TYP:\t   " << poloczenia_historii[i]->typ << "\n";
			cout << "GODZINA:\t   " << poloczenia_historii[i]->godzina << "\n";
			cout << "NAZWA:\t   " << poloczenia_historii[i]->nazwa << "\n";
			cout << "CENA ZA MIN:\t   " << poloczenia_historii[i]->cena_za_min << " ZL";
			cout << "DLUGOSC:\t   " << poloczenia_historii[i]->dlugosc;
			cout << "\nDATA POLOCZENIA:   \t   " << poloczenia_historii[i]->data;
			cout << "\n";
		}
	}
	cout << "-----------------------------\n";
	cout << endl;
}
typedef unsigned int ui;
void Historia::show_allconnection_sort_ilo()
{

	struct tablica
	{
		float wartosc;
		ui indeks;
	};
	ui dlugosc = poloczenia_historii.size();
	tablica * tab = new tablica[dlugosc];
	for (ui i = 0; i<dlugosc; i++)
	{
		tab[i].wartosc = poloczenia_historii[i]->dlugosc;
		tab[i].indeks = i;
	}
	for (ui i = 0; i<dlugosc - 1; i++)
	{
		for (ui j = 0; j<dlugosc - 1; j++)
		{
			if (tab[j].wartosc < tab[j + 1].wartosc)
			{
				swap(tab[j].wartosc, tab[j + 1].wartosc);
				swap(tab[j].indeks, tab[j + 1].indeks);
			}
		}
	}
	bool flag;
	int indeks;
	cout << "-------POLOCZENIA POSORTOWANE WEDLUG CZASU TRWANIA POLOCZENIA------\n";
	for (unsigned int i = 0; i<poloczenia_historii.size(); i++)
	{
		indeks = tab[i].indeks;
		cout << "-----------------------------\n";
		cout << "TYP:\t   " << poloczenia_historii[indeks]->typ << "\n";
		cout << "GODZINA:\t   " << poloczenia_historii[indeks]->godzina << "\n";
		cout << "NAZWA:\t   " << poloczenia_historii[indeks]->nazwa << "\n";
		cout << "DLUGOSC:\t   " << poloczenia_historii[indeks]->dlugosc << endl;
		cout << "DATA:\t	" << poloczenia_historii[i]->data<<endl;
	}
	cout << "-----------------------------\n";
	cout << endl;
}

void Historia::add_connection(string typ, string rodzaj, string nazwa,string user)
{
	bool flag;
	if (typ == "ODEBRANE")
		flag = true;
	else
		flag = false;
	cout << "Dodajesz poloczenie z   " << nazwa << " ?\n";

	int k = zwroc_indeks(nazwa,rodzaj,typ);	//zwraca czy dane poloczenie istnieje czy nie 
	
	Connection * poloczenie = new Connection(typ, rodzaj, nazwa);
	poloczenie->dodaj_do_histori(poloczenie);
	poloczenia_historii.push_back(poloczenie);
	char x[15] = "POLOCZENIA.txt";
	user = user + ".txt\0";
	update_produkt_w_baza(user);
	
}

bool Historia::szukaj_poloczenia(string nazwa)
{
	for (unsigned int i = 0; i<poloczenia_historii.size(); i++)
	{
		if (nazwa == poloczenia_historii[i]->nazwa)
			return true;
	}
	return false;
}

void Historia::wyswietl_rodzajami(string typ, string rodzaj)
{
	cout << "***Historia po³¹czeñ***:\n";
	cout << typ << " / " << rodzaj << endl;
	for (unsigned int i = 0; i < poloczenia_historii.size(); i++)
	{
		if ((poloczenia_historii[i]->typ == typ) && (poloczenia_historii[i]->godzina == rodzaj))
		{
			cout << poloczenia_historii[i]->nazwa << endl;
			cout << "Czas trwania rozmowy: " << poloczenia_historii[i]->dlugosc;
			cout << " min\n";
			cout << " zl/min";
			cout << " " << poloczenia_historii[i]->cena_za_min;
			cout << endl;

		}
	}

}

bool porownaj(string n1, string n2)
{
	if (n1 == n2)
		return true;
	else
		return false;
}
