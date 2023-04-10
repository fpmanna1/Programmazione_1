#include "Esercitazione.h"

namespace MS{
	Esercitazione::Esercitazione() : max(0)
	{
		descrizione = new char[1];
		strcpy(descrizione, "");
	}
	
	Esercitazione::Esercitazione(const char cod[5] , const char * tit, Docente * tut, int m, const char * des) : Tutorial(cod, tit, tut), max(m)
	{
		descrizione = new char[strlen(des)+1];
		strcpy(descrizione, des);
	}
	
	Esercitazione::Esercitazione(const Esercitazione & e) : Tutorial(e), max(e.max)
	{
		descrizione = new char[strlen(e.descrizione)+1];
		strcpy(descrizione, e.descrizione);
	}
	
	const Esercitazione & Esercitazione::operator=(const Esercitazione & e)
	{
		if(this!=&e)
		{
			Tutorial::operator=(e);
			set_max(e.max);
			set_des(e.descrizione);
		}
		return *this;
	}
	
	ostream & Esercitazione::print(ostream & out)const
	{
		Tutorial::print(out);
		out << " " << max << " " << descrizione;
		return out;
	}
	
	ostream & operator<<(ostream & out, const Esercitazione & e)
	{
		e.print(out);
		return out;
	}
	
	istream & Esercitazione::input(istream & in)
	{
		char buffer[100];
		Tutorial::input(in);
		in >> max;
		in.getline(buffer, 100);
		set_des(buffer);
		return in;	
	}
	
	istream & operator>>(istream & in, Esercitazione & e)
	{
		e.input(in);
		return in;
	}
}
