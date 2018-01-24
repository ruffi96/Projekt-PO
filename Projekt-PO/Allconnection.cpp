#include "stdafx.h"
#include "Allconnection.h"
#include<iostream>
#include<string>

Allconnection::Allconnection(string typ, string godzina, string nazwa)
{
	this->typ = typ;
	this->nazwa = nazwa;
	this->godzina = godzina;
}

Allconnection::~Allconnection()
{
	//dtor
}
