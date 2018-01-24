#pragma once
#include<iostream>
#include<fstream>
#include<string>

using namespace std;

class Menu
{
public:
	Menu();
	virtual ~Menu();

	string wyswietl_typ();
	string wyswietl_godzine(string);
	string wyswietl_nazwe();
	void menu_admin();
	void meeenu(int);
	void meeenu();
	void menu_user(string);
	template <class TypPrzyjety, class TypRzutowany>
	TypRzutowany zwroc_typ_przyjety(TypPrzyjety a)
	{
		if (sizeof(a) == 1)
			return (TypRzutowany)a - 48;
		else
			return (TypRzutowany)a + 48;
	}

};

