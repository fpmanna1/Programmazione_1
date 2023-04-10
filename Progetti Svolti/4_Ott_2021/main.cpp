#include <iostream>
#include "Prenotazione.h"
#include "Servizi.h"
#include "Ambulatorio.h"
#include "Laboratorio.h"

using MS::Ambulatorio;
using MS::Laboratorio;
using MS::Prenotazione;
using std::cin;
using MS::Servizi;

int main()
{
	
	/*Prenotazione p;
	Prenotazione p1;
	//cin >> p;
	if(p==p1)
		cout << "ok";
		else
			cout << "non uguali"; */
	/*Servizi s;
	cin >> s;   // test effettuato quando Servizi non era una classe astratta
	cout << s; */
	
	Prenotazione p1("PREN 1");
	Prenotazione p2("PREN 2");
	Prenotazione p3("PREN 3");
	/*a.prenota(p);
	a.prenota(p1);
	cout << a; */
	Ambulatorio a;
	Laboratorio l;
	
	Servizi* punts = &a;

	punts->prenota(p1);
	
	
	cout << *punts;
	
	punts = &l;
	
	punts->prenota(p2);
	
	cout << *punts;
	
	return 0;
}
