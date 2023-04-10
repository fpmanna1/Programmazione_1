#include "Libro.h"

namespace MS{
	Libro::Libro(const int & cod, const char * des, const char * form, const char * tit, const int & pag) : Oggetto(cod, des, form), pagine(pag)
	{
		titolo = new char[strlen(tit)+1];
		strcpy(titolo, tit);
	}
	
	Libro::Libro(const Libro & l) : Oggetto(l), pagine(l.pagine)
	{
		titolo = new char[strlen(l.titolo)+1];
		strcpy(titolo, l.titolo);
	}
	
	const Libro & Libro::operator=(const Libro & l)
	{
		if(this!=&l)
		{
			Oggetto::operator=(l);
			set_titolo(l.titolo);
			set_pagine(l.pagine);
		}
		return *this;
	}
	
	bool Libro::operator==(const Libro & l)const
	{
		return(Oggetto::operator==(l) && pagine == l.pagine && strcmp(titolo, l.titolo));
	}
	
	ostream & Libro::print(ostream & out)const
	{
		Oggetto::print(out);
		out << "-----STAMPA INFO LIBRO------"<<endl;
		out << "TITOLO : "<<titolo<<endl;
		out << "NUMERO DI PAGINE : "<<pagine<<endl;
		return out;
	}
	
	ostream & operator<<(ostream & out, const Libro & l)
	{
		return l.print(out);
	}
	
	istream & Libro::input(istream & in)
	{
		Oggetto::input(in);
		char buffer[100];
		cout << "Inserisci il titolo : ";
		in.getline(buffer, 100);
		set_titolo(buffer);
		cout << "Inserisci il numero delle pagine : ";
		in >> pagine;
		return in;
	}
	
	istream & operator>>(istream & in, Libro & l)
	{
		return l.input(in);
	}
}
