#include "Concerto.h"

namespace MS{
	Concerto::Concerto(const char * l, const int & g, const int & m, const int & a, const int & dur, 
	const char * orc, const char * dir) : Evento(l, g, m, a, dur)
	{
		strcpy(orchestra, orc);
		direttore = new char[strlen(dir)+1];
		strcpy(direttore, dir);
	}
	
	Concerto::Concerto(const Concerto & c) : Evento(c)
	{
		strcpy(orchestra, c.orchestra);
		direttore = new char[strlen(c.direttore)+1];
		strcpy(direttore, c.direttore);
	}
	
	const Concerto & Concerto::operator=(const Concerto & c)
	{
		if(this!=&c)
		{
			Evento::operator=(c);
			strcpy(orchestra, c.orchestra);
			set_direttore(c.direttore);
		}
		return *this;
	}
	
	ostream & Concerto::print(ostream & out)const
	{
		Evento::print(out);
		cout << "-----STAMPA INFO CONCERTO-----"<<endl;
		out << "ORCHESTRA : "<<orchestra<<endl;
		out << "DIRETTORE : "<<direttore<<endl;
		return out;
	}
	
	ostream & operator<<(ostream & out, const Concerto & c)
	{
		return c.print(out);
	}
	
	istream & Concerto::input(istream & in)
	{
		Evento::input(in);
		cout << "Inserisci nome dell'orchestra : ";
		in >> orchestra;
		char buffer[100];
		in.ignore();
		cout << "Inserisci nome direttore : ";
		in.getline(buffer, 100);
		set_direttore(buffer);
		return in;
	}
	
	istream & operator>>(istream & in, Concerto & c)
	{
		return c.input(in);
	}
}
