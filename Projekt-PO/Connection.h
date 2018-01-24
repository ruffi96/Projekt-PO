#pragma once
#include<iostream>
#include<string>
#include<fstream>
#include"Allconnection.h"
#include<ctime>
#include<stdlib.h>
#include<Windows.h>

using namespace std;

class Connection : public Allconnection

{
public:

	Connection(string t = "", string rp = "", string np = "") : Allconnection(t, rp, np)
	{

	}
	~Connection();
	float dlugosc;
	float cena_za_min;
	string data;
	Connection * dodaj_do_histori(Connection* connection);


};

