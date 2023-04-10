#include "Cellulare.h"

namespace MS{
	Cellulare::Cellulare(const int & cod, const char * des, const char * form, const char * mod, const float & cos) : Oggetto(cod, des, form), costo(cos)
	{
		modello = new char[strlen(mod)+1];
		strcpy(modello, mod);
	}
	
	Cellulare::Cellulare(const Cellulare & c) : Oggetto(c), costo(c.costo)
	{
		modello = new char[strlen(c.modello)+1];
		strcpy(modello, c.modello);
	}
	
	const Cellulare & Cellulare::operator=(const Cellulare & c)
	{
		if(this!=&c)
		{
			Oggetto::operator=(c);
			set_modello(c.modello);
			set_costo(c.costo);
		}
		return *this;
	}
	
	bool Cellulare::operator==(const Cellulare & c)const
	{
		return(Oggetto::operator==(c) && costo == c.costo && strcmp(modello, c.modello));
	}
	
	ostream & Cellulare::print(ostream & out)const
	{
		Oggetto::print(out);
		out << "-----STAMPA INFO CELLULARE------"<<endl;
		out << "MODELLO : "<<modello<<endl;
		out << "COSTO : "<<costo<<endl;
		return out;
	}
	
	ostream & operator<<(ostream & out, const Cellulare & c)
	{
		return c.print(out);
	}
	
	istream & Cellulare::input(istream & in)
	{
		Oggetto::input(in);
		char buffer[100];
		cout << "Inserisci il modello : ";
		in.getline(buffer, 100);
		set_modello(buffer);
		cout << "Inserisci il costo : ";
		in >> costo;
		return in;
	}
	
	istream & operator>>(istream & in, Cellulare & c)
	{
		return c.input(in);
	}
}
