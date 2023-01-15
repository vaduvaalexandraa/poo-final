#include "Bilet.h"
#include "Eveniment.h"
#include "Locatie.h"
using namespace std;
#pragma warning(disable:4996)
#include <string>

int Bilet::nrBilete = 0;

Bilet::Bilet():id(nrBilete)
{
	nrBilete++;
	this->nrRand = 0;
	this->nrLoc = 0;
	this->tipBilet = new char[strlen("Necunoscut") + 1];
	strcpy(this->tipBilet, "Necunoscut");
	this->pret = 0;
	this->data = "01.01.2000";
	this->ora = "00:00";
	this->eveniment = nullptr;
}

Bilet::Bilet(const char* tipBilet, int rand, int loc, Eveniment& eveniment):id(nrBilete)
{
	nrBilete++;
	this->tipBilet = new char[strlen(tipBilet) + 1];
	strcpy(this->tipBilet, tipBilet);
	this->eveniment = &eveniment;
	this->pret = eveniment.getPret();
	this->data = eveniment.getData();
	this->ora = eveniment.getOra();
	if (rand < eveniment.getLocatie().getNrRanduri() && loc < eveniment.getLocatie().getNrLocuri())
	{
		if (eveniment.getLocuri()[rand][loc] == 0)
		{
			this->nrRand = rand;
			this->nrLoc = loc;
			eveniment.setLocOcupat(rand, loc);
		}
	}
}

Bilet::~Bilet()
{
	if (this->tipBilet != nullptr)
	{
		delete[] this->tipBilet;
		this->tipBilet = nullptr;
	}
}

Bilet::Bilet(const Bilet& bilet):id(nrBilete)
{
	nrBilete++;
	this->tipBilet = new char[strlen(bilet.tipBilet) + 1];
	strcpy(this->tipBilet, bilet.tipBilet);
	this->pret = bilet.pret;
	this->data = bilet.data;
	this->ora = bilet.ora;
	this->eveniment = bilet.eveniment;
	this->nrRand = bilet.nrRand;
	this->nrLoc = bilet.nrLoc;
}

Bilet& Bilet::operator=(Bilet& bilet)
{
	if (this != &bilet)
	{
		if (this->tipBilet != nullptr)
		{
			delete[] this->tipBilet;
			this->tipBilet = nullptr;
		}
		if (this->eveniment != nullptr)
		{
			delete this->eveniment;
		}
		this->tipBilet = new char[strlen(bilet.tipBilet) + 1];
		strcpy(this->tipBilet, bilet.tipBilet);
		this->pret = bilet.pret;
		this->data = bilet.data;
		this->ora = bilet.ora;
		this->eveniment = bilet.eveniment;
		this->nrRand = bilet.nrRand;
		this->nrLoc = bilet.nrLoc;
	}
	return *this;
}

ostream& operator<<(ostream& out, Bilet& b)
{
	out << endl << "Numele evenimentului pentru care ati achizitionat bilet este: " << b.eveniment->getDenumire();
	out << endl << "Tipul biletului achizitionat de dumneavoastra este: " << b.tipBilet;
	out << endl << "ID-ul biletului achizitionat de dumneavoastra este: " << b.id;
	out << endl << "Data evenimentului pentru care este achizitionat biletul este: " << b.data;
	out << endl << "Ora inceperii evenimentului este: " << b.ora;
	out << endl << "Pretul biletului achizitionat de dumneavoastra: " << b.pret;
	out << endl << "Randul pe care aveti loc este: " << b.nrRand;
	out << endl << "Locul corespunzator randului este: " << b.nrLoc;
	return out;
}

istream& operator>>(istream& in, Bilet& b)
{
	b.nrBilete++;
	cout << endl<<"Tipul biletului este: ";
	if (b.tipBilet != nullptr)
	{
		delete[] b.tipBilet;
		b.tipBilet = nullptr;
	}
	char buffer[200];
	in >> buffer;
	if (buffer != nullptr)
	{
		b.tipBilet = new char[strlen(buffer) + 1];
		strcpy(b.tipBilet, buffer);
	}
	cout << endl << "Numarul randului este: ";
	in >> b.nrRand;
	cout << endl << "Numarul locului corespunzator randului selectat este: ";
	in >> b.nrLoc;
	return in;
}

void Bilet::setNrLoc(int loc)
{
	if (loc > 0 && loc<eveniment->getLocatie().getNrLocuri())
	{
		this->nrLoc = loc;
	}
}

int Bilet::getNrLoc()
{
	return this->nrLoc;
}

void Bilet::setNrRand(int rand)
{
	if (rand > 0 && rand < eveniment->getLocatie().getNrRanduri())
	{
		this->nrRand = rand;
	}
}

int Bilet::getNrRand()
{
	return this->nrRand;
}

void Bilet::setTipBilet(char* tip)
{
	if (tip != nullptr)
	{
		if (this->tipBilet != nullptr)
		{
			delete[] this->tipBilet;
			this->tipBilet = nullptr;
		}
		this->tipBilet = new char[strlen(tip) + 1];
		strcpy(this->tipBilet, tip);
	}
}

char* Bilet::getTipBilet()
{
	if (this->tipBilet != nullptr)
	{
		char* copieTipBilet = new char[strlen(this->tipBilet) + 1];
		strcpy(copieTipBilet, this->tipBilet);
		return copieTipBilet;
	}
	else
		return nullptr;
}

int Bilet::getNrBilete()
{
	return nrBilete;
}


bool Bilet::operator!() 
{
	if (this->id != this->nrBilete) 
	{
		return false;
	}
	else 
		return true;
}

bool Bilet::operator!=(const Bilet& b)
{
	if (id != b.id)
	{
		return true;
	}
	else
		return false;
}