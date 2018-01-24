#pragma once
#include<iostream>
#include<list>
#include<string>
#include"User.h"

using namespace std;

class Allusers
{
public:
	list<User> uzytokownicy;


	Allusers();
	bool czy_istnieje();
	void czy_haslo_ok();

	~Allusers();
};

