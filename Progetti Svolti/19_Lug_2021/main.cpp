#include <iostream>
#include "Evento.h"
#include "Riunione.h"
#include "Elenco.h"

using MS::Evento;
using MS::Riunione;
using MS::Partecipante;
using MS::Elenco;
using MS::Eccezione;

int main()
{
	Evento el;
	Partecipante p1;
	Partecipante p2("Francesco", "manna.francescopio@yahoo.it");
	Partecipante p3("Alessandri", "prova@yahoo.it");
	Partecipante p4("Giada", "bho@yahoo.it"); 
	Partecipante p5("pippo", "bho@yahoo.it"); 
	Partecipante p6("pluto", "bho@yahoo.it"); 
	Elenco e(4);
	e.insert(p1);
	e.insert(p2);
	e.insert(p3);
	e.insert(p4);
	e.insert(p5);
	e.insert(p6);
	cout << e;

//	cout << e.get_dim();
	
	Riunione r("descrizione",20, 15, "napoli", 2);
	r.get_elenco().insert(p1);
	r.get_elenco().insert(p2);
	r.get_elenco().insert(p3);
	r.get_elenco().insert(p4);
	r.get_elenco().insert(p5);
	r.get_elenco().insert(p1);
	//r.get_elenco().insert(p6);
	
	cout << r;
	return 0;
}
