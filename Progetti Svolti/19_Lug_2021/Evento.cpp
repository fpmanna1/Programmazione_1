#include "Evento.h"

namespace MS{
	
	Evento::Evento(const char * des, const int & o, const int & min) : ora(o), minuti(min)
	{
		descrizione = new char[strlen(des)+1];
		strcpy(descrizione, des);
	}
	
	Evento::Evento(const Evento & e) : ora(e.ora), minuti(e.minuti)
	{
		descrizione=new char[strlen(e.descrizione)+1];
		strcpy(descrizione, e.descrizione);
	}
	
	const Evento & Evento::operator=(const Evento & e)
	{
		if(this!=&e)
		{
			set_descrizione(e.descrizione);
			set_ora(e.ora);
			set_minuti(e.minuti);
		}
		return *this;
	}
	
	ostream & Evento::print(ostream & out)const
	{
		out << "----STAMPA INFORMAZIONI EVENTO----"<<endl;
		out << "DESCRIZIONE EVENTO : "<<descrizione<<endl;
		out << "DURATA EVENTO : "<<ora<<":"<<minuti<<endl;
		return out;
	}
	
	ostream & operator<<(ostream & out, const Evento & e)
	{
		return e.print(out);
	}
}
