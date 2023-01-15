#include "Eveniment.h"
#include "Locatie.h"
using namespace std;
#pragma warning(disable:4996)
#include <string>

Eveniment::Eveniment()
{
	this->denumire = new char[strlen("Necunoscuta") + 1];
	strcpy(this->denumire, "Necunoscuta");
	this->data = "01.01.2000";
	this->ora = "00:00";
	this->pret = 0;
	this->locatie = nullptr;
	this->locuriDisponibile = nullptr;
}

Eveniment::Eveniment(const char* denumire, string data, string ora, int pret, Locatie& locatie)
{
	this->denumire = new char[strlen(denumire) + 1];
	strcpy(this->denumire, denumire);
	this->data = data;
	this->ora = ora;
	this->pret = pret;
	this->locatie = &locatie;
	locuriDisponibile = new int* [locatie.getNrRanduri()];
	for (int i = 0; i < locatie.getNrRanduri(); i++)
	{
		locuriDisponibile[i] = new int[locatie.getNrLocuri()];
	}
	for (int i = 0; i < locatie.getNrRanduri(); i++)
	{
		for (int j = 0; j < locatie.getNrLocuri(); j++)
		{
			locuriDisponibile[i][j] = 0;
		}
	}
}

Eveniment::~Eveniment()
{
	if (this->denumire != nullptr)
	{
		delete[] this->denumire;
		this->denumire = nullptr;
	}
   
}

char* Eveniment::getDenumire()
{
	if (this->denumire != nullptr)
	{
		char* copieDenumire = new char[strlen(this->denumire) + 1];
		strcpy(copieDenumire, this->denumire);
		return copieDenumire;
	}
	else
		return nullptr;
}

void Eveniment::setDenumire(char* denumire)
{
	if (denumire != nullptr)
	{
		if (this->denumire != nullptr)
		{
			delete[] this->denumire;
			this->denumire = nullptr;
		}
		this->denumire = new char[strlen(denumire) + 1];
		strcpy(this->denumire, denumire);
	}
}

string Eveniment::getData()
{
	return this->data;
}

void Eveniment::setData(string data)
{
	if (data.length() >0)
	{
		this->data = data;
	}
}

string Eveniment::getOra()
{
	return this->ora;
}

void Eveniment::setOra(string ora)
{
	if (ora.length() > 0)
	{
		this->ora = ora;
	}
}

int Eveniment::getPret()
{
	return this->pret;
}

void Eveniment::setPret(int pret)
{
	if (pret > 0)
	{
		this->pret = pret;
	}
	
}

 Locatie& Eveniment::getLocatie()
{
	
	return *locatie;
}

int** Eveniment::getLocuri()
{
	return locuriDisponibile;
}

Eveniment::Eveniment(const Eveniment& e)
{
	this->denumire = new char[strlen(e.denumire) + 1];
	strcpy(this->denumire, e.denumire);
	this->data = e.data;
	this->ora = e.ora;
	this->pret = e.pret;
	this->locuriDisponibile = new int* [e.locatie->getNrRanduri()];
	for (int i = 0; i < e.locatie->getNrRanduri(); i++)
	{
		this->locuriDisponibile[i] = new int[e.locatie->getNrLocuri()];
	}
	for (int i = 0; i < e.locatie->getNrRanduri(); i++)
	{
		for (int j = 0; j < e.locatie->getNrLocuri(); j++)
		{
			this->locuriDisponibile[i][j] = e.locuriDisponibile[i][j];
		}
	}
	this->locatie = new Locatie(*e.locatie);
}

Eveniment& Eveniment::operator=(const Eveniment& e)
{
	if (this != &e)
	{
		if (this->denumire != nullptr)
		{
			delete[] this->denumire;
			this->denumire = nullptr;
		}
		if(this->locatie!=nullptr)
		delete locatie;
		this->denumire = new char[strlen(e.denumire) + 1];
		strcpy(this->denumire, e.denumire);
		this->data = e.data;
		this->ora = e.ora;
		this->pret = e.pret;
		this->locatie = new Locatie(*e.locatie);
		if (e.locatie != nullptr)
		{
			this->locuriDisponibile= new int*[e.locatie->getNrRanduri()];
			for (int i = 0; i < e.locatie->getNrRanduri(); i++)
			{
				this->locuriDisponibile[i] = new int[e.locatie->getNrLocuri()];
			}
			for (int i = 0; i < e.locatie->getNrRanduri(); i++)
			{
				for (int j = 0; j < e.locatie->getNrLocuri(); j++)
					this->locuriDisponibile[i][j] = e.locuriDisponibile[i][j];
			}
		}

	}
	return *this;

}


ostream& operator<<(ostream& out, Eveniment& e)
{
	out << endl<<"Evenimentul care are loc este: " << e.denumire;
	out <<endl<< "Acesta are loc in data de (dd.mm.yyyy): " << e.data ;
	out<< endl<<"Ora inceperii evenimentului este ora (hh:mm): " << e.ora;
	out << endl<<"Pretul biletului este de: " << e.pret << " LEI\n";
	if (e.locuriDisponibile != nullptr)
	{
		cout << "\nAfisarea ocuparii locurilor din sala este urmatoarea " << endl;
		cout << "Locurile disponibile sunt marcate cu 0, iar cele ocupate cu 1: " << endl << endl;
		for (int i = 0; i < e.locatie->getNrRanduri(); i++, printf("\n"))
		{
			for (int j = 0; j < e.locatie->getNrLocuri(); j++)
			{
				out << e.locuriDisponibile[i][j] << " ";
			}
		}
	}
	else
	cout << "Momentan nu este disponibila afisarea ocuparii salii!";
	out << "\nEvenimentul se desfasoara in locatia cu denumirea: ";
	out << e.locatie->getDenumireLocatie()<<endl;
	out << "Numarul de randuri de care dispune locatia este: ";
	out << e.locatie->getNrRanduri()<<endl;
	out << "Numarul total de locuri al locatiei este: ";
	out << e.locatie->getNrLocuri()<<endl;
	return out;
}

istream& operator>>(istream& in, Eveniment& e)
{
	cout << "Numele evenimentului este: ";
	if (e.denumire != nullptr)
	{
		delete[] e.denumire;
	}
	char buffer[200];
	in >> buffer;
	if (buffer != nullptr)
	{
		e.denumire = new char[strlen(buffer) + 1];
		strcpy(e.denumire, buffer);
	}
	cout << endl<<"Data evenimentului(dd.mm.yyyy): ";
	//getline(in, e.data);
	in >> e.data;
	cout << endl<<"Ora evenimentului(hh:mm): ";
	//getline(in, e.ora);
	in >> e.ora;
	cout <<endl<< "Pretul pentru un bilet la eveniment: ";
	in >> e.pret;
	return in;
}

Eveniment::operator int() 
{
	return this->pret;
}

Eveniment& Eveniment:: operator+(int p)
{
	this->pret += p;
	return *this;
}

void Eveniment::setLocOcupat(int rand, int loc)
{
	if (rand <= locatie->getNrRanduri() && loc <= locatie->getNrLocuri())
	{
		if (locuriDisponibile[rand][loc] == 0)
		{
			locuriDisponibile[rand][loc] = 1;
		}
		else
			cout << "Locul dorit este deja ocupat! Incercati sa introduceti alta combinatie rand-loc." << endl;
	}
	else
		cout << "Date invalide pentru selectarea randului si locului.";
}