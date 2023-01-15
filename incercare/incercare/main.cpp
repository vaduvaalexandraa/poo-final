#include<iostream>
#include "Eveniment.h"
#include "Bilet.h"
#include "Locatie.h"
using namespace std;
#pragma warning(disable:4996)

void Meniu()
{
	cout << "1)Adaugati locatie noua." << endl;
	cout << "2)Vizualizati locatie." << endl;
	cout << "3)Adaugati eveniment nou." << endl;
	cout << "4)Achizitie bilet." << endl;
	cout << "5)Exit menu!" << endl;
}

int main()
{
	//declarare de locatie
	Locatie l("Cinema", 3, 10);
	Locatie lo;
	//declarare de eveniment
	Eveniment e("Film", "12.12.2022", "20:20", 19, l);
	Eveniment lol;
	//ocuparea a doua locuri pt a testa functionalitatea setLocOcupat
	e.setLocOcupat(0, 9);
	e.setLocOcupat(1, 9);
	lol = e;
	//afisare eveniment
	cout << lol;
	//declarare bilet
	Bilet bii;
	Bilet b("Standard", 2, 3, e);
	bii = b;
	//cout << b;
	//cin >> bii;
	//cin >> lol;
	//cout << lol;

	Locatie locatie1;
	Bilet bilet1;
	Eveniment eveniment1;
	int op = 0;

	do
	{
		Meniu();
		cout << "Selectati optiunea dorita: " << endl;
		cin >> op;
		system("cls"); //clear the screen
		switch (op)
		{
		case 1:
			cin.ignore();
			cin >> locatie1;
			cout << endl << "Locatia si caracteristicile specifice ei au fost adaugate!" << endl;
			break;
		case 2:
			system("cls");
			cout << locatie1 << endl;
			break;
		case 3:
			system("cls");
			cin.ignore();
			cin >> eveniment1;
			cout << "Evenimentul si caracteristicile aferente lui au fost adaugate!" << endl;
			break;
		case 4:
			system("cls");
			cin.ignore();
			cin >> bilet1;
			cout << "Bilet inregistrat cu succes!" << endl;
			break;
		}
	} while (op != 5);
	return 0;
}