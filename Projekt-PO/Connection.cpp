#include "stdafx.h"
#include "Connection.h"
#include<iostream>
#include<string>

using namespace std;


Connection::~Connection()
{
	//dtor
}

Connection * Connection::dodaj_do_histori(Connection * connection)	//funkcja uzywana do dodawania polaczenia do historii
{
	srand(time(NULL));
	float ile;
	string z;
	cout << "Podaj d³ugoœæ rozmowy:\n";
	cin >> ile;
	connection->dlugosc = ile;
	cout << "Jaka jest cena za polaczenie(zl/min): \n";
	cin >> ile;
	connection->cena_za_min = ile;
	cout << "Podaj date tegopoloczenia(dd-mm-yyyy) : \n";
	cin >> z;
	connection->data = z;
	cout << endl;
	system("pause");
	return this;
}
