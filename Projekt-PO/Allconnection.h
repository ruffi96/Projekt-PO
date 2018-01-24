#pragma once
#include<iostream>
#include<fstream>
#include <string>

using namespace std;

class Allconnection
{
public:
	string typ;
	string godzina;
	string nazwa;

	Allconnection(string="",string="",string="");
	virtual ~Allconnection();
};

