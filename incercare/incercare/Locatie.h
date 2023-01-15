#pragma once
#include <iostream>
#include <string>
#pragma warning(disable:4996)
using namespace std;

class Locatie
{
private:

	char* denumireLocatie;
	int numarRanduri;
	int numarLocuri;

public:

	Locatie();
	Locatie(const char*, int, int);
	~Locatie();
	Locatie(const Locatie& l);
	Locatie& operator=(const Locatie& l);
	friend ostream& operator<<(ostream& out, Locatie& l);
	friend istream& operator>>(istream& in, Locatie& l);
	char* getDenumireLocatie();
	void setDenumireLocatie(char* denumireLocatie);
	int getNrLocuri();
	void setNrLocuri(int numarLocuri);
	int getNrRanduri();
	void setNrRanduri(int numarRanduri);
	int getNrMaximLocuri();
	Locatie operator++();
	Locatie operator++(int i);
	Locatie operator--();
	Locatie operator--(int i);
	
};