// Projekt-PO.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include"User.h"
#include"Allusers.h"
#include"Connection.h"
#include"Historia.h"
#include"Menu.h"
#include"User.h"

using namespace std;

vector <string> konto_inf;
vector <string> konto_his;

void wczytaj_konta()
{
	string zmienna;
	fstream plik;
	int i = 0;
	plik.open("KONTA.txt", ios::in);
	{
		if (plik.good() != false)
			return;
		else
		{
			while (getline(plik, zmienna))
			{
				if (i % 2 == 0) // NAZWA PLIKU Z INFORMACJAMI
					konto_inf.push_back(zmienna);
				else
				{
					konto_his.push_back(zmienna);
				}
					i++;
			}
		}
	}
	plik.close();
	plik.clear();
	
}

int wybor_indeksu(vector <User  *> uzytkownicy )
{
	unsigned int wybor_ind;
	int indeks = -1;
	cout << "\nWybierz konto, którego chcesz uzyć :\n";
	for (unsigned int i = 1; i <= uzytkownicy.size(); i++)
		cout << i << ". " << uzytkownicy[i - 1]->login << "\n";
	cin >> wybor_ind;
	cin.ignore();
	cin.clear();
	for (unsigned int i = 1; i <= uzytkownicy.size(); i++)
	{
		if (wybor_ind == i)
		{
			indeks = i - 1;
			break;
		}
	}
	return indeks;
}

void wpisz_nazwy_kont()
{
	fstream plik;
	plik.open("KONTA.txt", ios::out);
	{
		for (unsigned i = 0; i<konto_inf.size(); i++)
		{
			plik << konto_inf[i] << "\n";
			plik << konto_his[i] << "\n";
		}
	}
	plik.close();
	plik.clear();
}


int main()
{
	string login, haslo;
	Menu *menu = new Menu;
	int k = 0;
	int ID = 1;
	User * konto;
	vector <class User*> konta;
	wczytaj_konta();
	int z = konto_inf.size();
	menu->meeenu();
	[]()->string { return "!!!"; }();
	cout << endl << endl;
	menu->meeenu(1);

	
	system("pause");
	while (true)
	{
	

		cout << "	Znajdujesz się w części logowania\n\n";
	point1:
		k = 0;
		cout << "	Podaj swój login : \n";
		cin >> login;
		cout << "\n	Podaj swoje haslo : \n";
		cin >> haslo;
		int index;
		int log = 0;
		int has = 0;
		for (int i = 0; i < konta.size(); i++)
		{
			if (login == konta[i]->login)
				log = 1;
			if ((log == 1) && (haslo == konta[i]->haslo))
				has = 1;
			if (log == 1 && has == 1)
			{
				index = i;
				break;
			}
		}

		if (log != 1)
		{
			if (login == "admin" && haslo == "admin")
				log = 2;
			else
			{
				system("cls");
				cout << "Podałes nieprawidlowy login lub haslo, wprowadz jeszcze raz...\n\n";
				goto point1;
			}
		}
		string typ;
		string godzina;
		string nazwa;

		string str2;

		
		string x = "POLACZENIA.txt";
		char wybor;
		char kINF[30];
		char kHIS[30];
		string templ;
		string str;
		string temp2;
		string lol;
		string zi;
		string zh;
		string lol2;
		string e;
		int indeks;
		int o;
		while (true)
		{
		start:
			system("cls");
			if (log == 1)
			{
			start1:
				system("cls");
				menu->menu_user(login);		//wyswietla menu uzytkownika
				cin >> wybor;
				switch (wybor)
				{
				case '1':			//Wyswietl historie poloczen
					cout << endl << endl;
					cout << "Historia polaczen konta o numerze : " << konta[index]->login<<endl<<endl;
					konta[index]->historia_user->show_allconnection();
					cout << endl;
					system("pause");
					goto start1;
					break;
				case '2':			//wyswietl liczbe poloczen
					if (konta[index]->historia_user->poloczenia_historii.size() == 0)
					{
						cout << "\nNie mozna wyswietlic, brak historii poloaczen";
						goto start1;
					}
					else
					{
						cout << endl << "Liczba odebranych poloczen to " << konta[index]->historia_user->liczba_odebranych();
						cout << endl;
						cout << endl << "Liczba nieodebranych polaczen to " << konta[index]->historia_user->liczba_nieodebranych();
						cout << endl;
						cout << endl << "Laczna liczba wszystkich polaczen to " << konta[index]->historia_user->liczba_wszystkich_poloczen();
						cout << endl << endl;
						system("pause");
					}
					goto start1;
					break;
				case '3':			//wyswietl kwote przeznaczono na poloczenia
					cout << endl << endl;
					cout<<"\nKwota przeznaczona na polaczenia wynosi "<<konta[index]->historia_user->kwota_polaczen();
					cout << endl;
					system("pause");
					goto start1;
					break;
				case '4':			//wyswietl dane o koncie
					konta[index]->show_information();
					cout << endl;
					system("pause");
					goto start1;
					break;
				case '5':			//wyswietl najdluzsze poloczenie
					konta[index]->historia_user->najdluzsze();
					cout << endl; 
					system("pause");
					goto start1;
					break;
				case 'Q':			//wylogowuje
					goto point1;
					break;
				default:
					cout << "\n Na pewno chcesz:\n 1.wylogowac\n\n 2. wyjsc z programy ?\n";
					int a;
					cin >> a;
					if (a == 1)
					{
						if (k == 0)
							goto point1;
						else
							goto start2;
					}
					else
						goto end;
					break;
				}
			}
			else
			{
			start2:
				system("cls");
				menu->menu_admin();		//wyswietla menu administratora
				cin >> wybor;
				switch (wybor)
				{
				case '1':
				{//dodaj konto
					ID = rand() % 10000 + 123 + ID;
					konto = new User(-1, ID, "", "");
					konta.push_back(konto);
					e = konto->login;
					lol = e;
					lol2 = e;
					auto k = e.size();
					zh = ".txt\0";
					//lol[k] = '.';
					//lol[k + 1] = 't';
					//lol[k + 2] = 'x';
					//lol[k + 3] = 't';
					//lol[k + 4] = '\0';

					str = lol+zh;

					konto_his.push_back(str);
					zi = "_INF.txt\0";
					//lol2[k] = '_';
					//lol2[k + 1] = 'I';
					//lol2[k + 2] = 'N';
					//lol2[k + 3] = 'F';
					//lol2[k + 4] = '.';
					//lol2[k + 5] = 't';
					//lol2[k + 6] = 'x';
					//lol2[k + 7] = 't';
					//lol2[k + 8] = '\0';

					str2 = lol2+zi;
					konto_inf.push_back(str2);
					ID++;

					system("pause");
					goto start2;
					break;
				}
				case '2':			//usun konto
				{indeks = wybor_indeksu(konta);
				int wybor_ind;
				if (indeks > -1)
				{
					cout << "\nJestes pewny ze chcesz usunac to konto wraz z cala historia ?\n";
					konta[indeks]->show_information();
					cout << "\n1.Tak\n2.Nie\n";
					cin >> wybor_ind;
					if (wybor_ind == 1)
					{
						templ = konto_inf[indeks];
						for (unsigned int i = 0; i < templ.length(); i++)
							kINF[i] = templ[i];
						kINF[templ.length()] = '\0';
						templ = konto_his[indeks];
						for (unsigned int i = 0; i < templ.length(); i++)
							kHIS[i] = templ[i];
						kHIS[templ.length()] = '\0';
						remove(kHIS);
						remove(kINF);
						konta.erase(konta.begin() + indeks); //usuniecie z wektora
						konto_inf.erase(konto_inf.begin() + indeks); //usuniecie z wektora nazwa (pozniejsze nadpisanie pliku NAZWY.txt
						konto_his.erase(konto_his.begin() + indeks);// ---.-----
						wpisz_nazwy_kont();
						Sleep(1000);
						cout << "\nKonto zostalo usuniete!\n";
					}
					else
						cout << "\nUsuniecie niemozliwe\n";
				}
				system("pause");
				goto start2;
				break;
				}
				case '3':			//wyswietl wszystkie konta i ich historie
				{
					for (unsigned int i = 0; i < konta.size(); i++)
					{
						cout << "\nINFORMACJE O KONCIE:\n";
						konta[i]->show_information();
						cout << "\n\nHISTORIA KONTA: " << konta[i]->login << "\n";
						konta[i]->historia_user->show_allconnection();
						cout << endl;
					}
					system("PAUSE");
					goto start2;
					break;
				}
				case '4': {			//wejdz w wybrane konto
					cout << "\nNa które konto chcesz się przełączyć?\n";
					
					for (unsigned int i = 0; i < konta.size(); i++)
					{
						cout << i + 1 << ". " << konta[i]->login;
					}
					cin >> o;
					if (o >= konta.size())
					{
						goto start2;
					}
					else
					{
						login = konta[o - 1]->login;
						goto start1;
					}
				}
				case '5': {			//dodaj poloczenie
					cout << "\n\nDo ktorego konta chcesz dodac poloczenie?\n";

					for (unsigned int i = 0; i < konta.size(); i++)
					{
						cout << i + 1 << ". " << konta[i]->login;
					}
					cin >> o;
					typ = menu->wyswietl_typ();
					godzina = menu->wyswietl_godzine(typ);
					nazwa = menu->wyswietl_nazwe();
					konta[o - 1]->historia_user->add_connection(typ, godzina, nazwa,konta[o-1]->login);

					system("pause");
					goto start2;
					break; }
				/*case '6':	//wyswietl statystyki
				{
					if (konta[index]->historia_user->poloczenia_historii.size() == 0)
					{
						cout << "\nNie mozna wyswietlic, brak historii poloaczen";
						goto start1;
					}
					else
					{
						cout << endl << endl;
						cout << "\nLiczbe jakich polaczen chcesz wyswietlic ?\n ";
						cout << "\n1.Odebranych\n";
						cout << "\n2.Niedebranych\n";
						cout << "\n3.Wszystkich \n";
						while (true)
						{
							int z;
							cin >> z;
							switch (z)
							{
							case'1':
								cout << endl << "Liczba odebranych poloczen to " << konta[index]->historia_user->liczba_odebranych();
								cout << endl;
								system("pause");
								break;
							case'2':
								cout << endl << "Liczba nieodebranych polaczen to " << konta[index]->historia_user->liczba_nieodebranych();
								cout << endl;
								system("pause");
								break;
							case'3':
								cout << endl << "Laczna liczba wszystkich polaczen to " << konta[index]->historia_user->liczba_wszystkich_poloczen();
								cout << endl;
								system("pause");
								break;
							default:
								cout << "\n\n WYBOR NIEPOPRAWNY, WYBIERZ JESZCZE RAZ..\n";
								break;
							}
							if (z == 1 || z == 2 || z == 3)
								goto start1;
						}
					}

				system("pause");
				goto start2;
				break;
				}*/
				case 'Q':			//wylogowuje
					cout << "\n Na pewno chcesz:\n 1.wylogowac\n \n2. wyjsc z programy ?\n";
					int a;
					cin >> a;
					if (a == 1)
						goto point1;
					else
						goto end;					
					break;
				default: {
					cout << "\n\n WYBOR NIEPOPRAWNY, SPROBUJ JESZCZE RAZ..\n";
					system("pause");
					goto start2;
					break; }
				}

			}

		}




	}
end:
	system("cls");
	cout << "\n\nDo zobaczenia następnym razem ;)\n\n";
	system("pause");
    return 0;
}

