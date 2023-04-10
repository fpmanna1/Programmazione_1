#include "Oggetto.h"

namespace MS{
	
	Oggetto::Oggetto(int c,  const char * d, const char * f) : codice(c)
	{
		descrizione = new char[strlen(d)+1];
		forma = new char[strlen(f)+1];
		strcpy(descrizione, d);
		strcpy(forma, f);
	}
	
	Oggetto::Oggetto(const Oggetto & o) : codice(o.codice)
	{
		descrizione = new char[strlen(o.descrizione)+1];
		forma = new char[strlen(o.forma)+1];
		strcpy(descrizione, o.descrizione);
		strcpy(forma, o.forma);
	}
	
	const Oggetto & Oggetto::operator=(const Oggetto & o)
	{
		if(this!=&o)
		{
			set_codice(o.codice);
			set_descrizione(o.descrizione);
			set_forma(o.forma);
		}
		return *this;
	}
	
	ostream & operator<<(ostream & out, const Oggetto & o)
	{
		out << o.codice << " " << o.descrizione << " " << o.forma;
		return out;
	}
	
	istream & operator>>(istream & in, Oggetto & o)
	{ 
		in >> o.codice;
		char buffer[200];
		in.ignore();
		in.getline(buffer, 200);
		o.descrizione = new char[strlen(buffer)+1];
		strcpy(o.descrizione, buffer);
		in.getline(buffer, 200);
		o.forma = new char[strlen(buffer)+1];
		strcpy(o.forma, buffer);
		return in;
	}
}
