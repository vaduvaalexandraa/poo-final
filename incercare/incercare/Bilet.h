#pragma once
#include <iostream>
#include <string>
#include "Locatie.h"
#include"Eveniment.h"
#pragma warning(disable:4996)
using namespace std;

class Bilet
{
private:
	static int nrBilete;
	const int id;
	char* tipBilet;
	int nrLoc;
	int nrRand;
	int pret;
	string data;
	string ora;
	Eveniment* eveniment;

public:

	Bilet();
	Bilet(const char* tipBilet,int rand, int loc, Eveniment& eveniment);
	Bilet& operator=(Bilet& bilet);
	Bilet(const Bilet& bilet);
	~Bilet();
	friend ostream& operator<<(ostream& out, Bilet& b);
	friend istream& operator>>(istream& in, Bilet& b);

	int getNrRand();
	void setNrRand(int rand);
	int getNrLoc();
	void setNrLoc(int loc);
	char* getTipBilet();
	void setTipBilet(char* tip);
	static int getNrBilete();
	bool operator!();
	bool operator!=(const Bilet& b);
};