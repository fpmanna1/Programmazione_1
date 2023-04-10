#include "Voce.h"

namespace MS{
	Voce::Voce(const int & cod, const char * p, const float & cos) : codice(cod), costo(cos)
	{
		piatto = new char[strlen(p)+1];
		strcpy(piatto, p);
	}
	
	Voce::Voce(const Voce & v) : codice(v.codice), costo(v.costo)
	{
		piatto = new char[strlen(v.piatto)+1];
		strcpy(piatto, v.piatto);
	}
	
	const Voce & Voce::operator=(const Voce & v)
	{
		if(this!=&v)
		{
			set_codice(v.codice);
			set_piatto(v.piatto);
			set_costo(v.costo);
		}
		return *this;
	}
	
	ostream & Voce::print(ostream & out)const
	{
		out << "-----STAMPA DATI VOCE------"<<endl;
		out << "CODICE : "<<codice<<endl;
		out << "TIPO PIATTO : "<<piatto<<endl;
		out << "COSTO : "<<costo<<endl;
		return out;
	}
	
	ostream & operator<<(ostream & out, const Voce & v)
	{
		return v.print(out);
	}
	
	istream & Voce::input(istream & in)
	{
		cout << "Inserisci il codice : ";
		in >> codice;
		cout << "Inserisci il tipo del piatto : ";
		in.ignore();
		char buffer[100];
		in.getline(buffer, 100);
		set_piatto(buffer);
		cout << "Inserisci il costo : ";
		in >> costo;
		return in;
	}
	
	istream & operator>>(istream & in, Voce & v)
	{
		return v.input(in);
	}
}
