#include "Locatie.h"
Locatie::Locatie()
{
	this->denumireLocatie = new char[strlen("Necunoscuta") + 1];
	strcpy(this->denumireLocatie, "Necunoscuta");
	this->numarLocuri = 0;
	this->numarRanduri = 0;
}

Locatie::Locatie(const char* denumireLocatie, int numarRanduri, int numarLocuri):Locatie()
{
	if (denumireLocatie != nullptr)
	{
		this->denumireLocatie = new char[strlen(denumireLocatie) + 1];
		strcpy(this->denumireLocatie, denumireLocatie);
	}
	if (numarRanduri > 0)
	{
		this->numarRanduri = numarRanduri;
	}
	if (numarLocuri > 0)
	{
		this->numarLocuri = numarLocuri;
	}
}

Locatie::~Locatie()
{
	if (this->denumireLocatie != nullptr)
	{
		delete[] this->denumireLocatie;
		
	}
}

Locatie::Locatie(const Locatie& l)
{
	this->denumireLocatie = new char[strlen(l.denumireLocatie) + 1];
	strcpy(this->denumireLocatie, l.denumireLocatie);
	this->numarRanduri = l.numarRanduri;
	this->numarLocuri = l.numarLocuri;
}

Locatie& Locatie::operator=(const Locatie& l)
{
	if (this != &l)
	{
		if (this->denumireLocatie != nullptr)
		{
			delete[] this->denumireLocatie;
		}
		this->numarRanduri = l.numarRanduri;
		this->numarLocuri = l.numarLocuri;
	}
	return *this;
}

ostream& operator<<(ostream& out, Locatie& l)
{
	out << "Denumirea locatiei pentru eveniment este: " << l.denumireLocatie<<"\n";
	out << " Numarul de randuri al locatiei este: " << l.numarRanduri << "\n";
	out << " Numarul de locuri ale locatiei este: " << l.numarLocuri << "\n";
	return out;
}

istream& operator>>(istream& in, Locatie& l)
{
	cout << "Denumirea locatiei: ";
	if (l.denumireLocatie != nullptr)
	{
		delete[] l.denumireLocatie;
	}
	char buffer[200];
	in >> buffer;
	if (buffer != nullptr)
	{
		l.denumireLocatie= new char[strlen(buffer) + 1];
		strcpy(l.denumireLocatie, buffer);
	}
	cout << "\nNumarul de randuri: ";
	in >> l.numarRanduri;
	cout << "\nNumarul de locuri: ";
	in >> l.numarLocuri;
	return in;
}

char* Locatie::getDenumireLocatie()
{
	if (this->denumireLocatie != nullptr)
	{
		char* copieDenumire = new char[strlen(this->denumireLocatie) + 1];
		strcpy(copieDenumire, this->denumireLocatie);
		return copieDenumire;
	}
	else
		return nullptr;
}

void Locatie::setDenumireLocatie(char* denumireLocatie)
{
	if (denumireLocatie != nullptr)
	{
		if (this->denumireLocatie != nullptr)
		{
			delete[] this->denumireLocatie;
			this->denumireLocatie = nullptr;
		}
		this->denumireLocatie = new char[strlen(denumireLocatie) + 1];
		strcpy(this->denumireLocatie, denumireLocatie);
	}
}

int Locatie::getNrLocuri() 
{
	return this->numarLocuri;
}

void Locatie::setNrLocuri(int nrLocuri)
{
	if (nrLocuri > 0)
	{ 
		this->numarLocuri = nrLocuri;
	}
}

int Locatie::getNrRanduri() 
{
	return this->numarRanduri;
}

void Locatie::setNrRanduri(int nrRanduri)
{
	if (nrRanduri > 0)
	{
		this->numarRanduri = nrRanduri;
	}
}

Locatie Locatie::operator++() 
{
	this->numarRanduri++;
	this->numarLocuri++;
	return *this;
}

Locatie Locatie::operator++(int i) 
{
	Locatie copie = *this;
	this->numarRanduri++;
	this->numarLocuri++;
	return copie;
}

Locatie Locatie :: operator--()
{
	this->numarLocuri--;
	return *this;
}

Locatie Locatie::operator--(int i)
{
	Locatie copie = *this;
	this->numarLocuri--;
	return copie;
}

int Locatie::getNrMaximLocuri()
{
	if (this->numarLocuri > 0 && this->numarRanduri > 0)
	{
		int maxim = this->numarRanduri * this->numarLocuri;
		return maxim;
	}
}
