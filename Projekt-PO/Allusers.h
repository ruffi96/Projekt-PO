#pragma once
#include<iostream>
#include<vector>
#include<string>
#include"User.h"

using namespace std;

class Allusers
{
public:
	vector<class User> uzytokownicy;


	Allusers();
	bool czy_istnieje();
	void czy_haslo_ok();

	~Allusers();
};

