#pragma once
#include <iostream>
#include <string>
#pragma warning(disable:4996)
#include "Locatie.h"
#include<iostream>
using namespace std;

class Eveniment
{
private:
	char* denumire;
	string data;
	string ora; 
	int pret;
	int** locuriDisponibile;
	Locatie* locatie;

public:
	
	Eveniment();
	Eveniment(const char* denumire, string data, string ora, int pret,  Locatie& locatie);
	Eveniment(const Eveniment& e);
	Eveniment& operator=(const Eveniment& e);
	~Eveniment();
	friend ostream& operator<<(ostream&, Eveniment& e);
	friend istream& operator>>(istream& in, Eveniment& e);
	char* getDenumire();
	void setDenumire(char* denumire);
	string getData();
	void setData(string data);
	string getOra();
	void setOra(string data);
	int getPret();
	void setPret(int pret);
	Locatie& getLocatie();
	int** getLocuri();
	operator int();
	Eveniment& operator+(int p);
	void setLocOcupat(int rand, int loc);
};
