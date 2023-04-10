#include "Evento.h"

namespace MS{
	Evento::Evento(const char * l, const int & g, const int & m, const int & a, const int & dur) : data(g, m , a), durata(dur)
	{
		luogo = new char[strlen(l)+1];
		strcpy(luogo, l);
	}
	
	Evento::Evento(const Evento & e) : data(e.data), durata(e.durata)
	{
		luogo = new char[strlen(e.luogo)+1];
		strcpy(luogo, e.luogo);
	}
	
	const Evento & Evento::operator=(const Evento & e)
	{
		if(this!=&e)
		{
			set_luogo(e.luogo);
			data = e.data;
			durata = e.durata;
		}
		return *this;
	}
	
	ostream & Evento::print(ostream & out)const
	{
		out << "-----STAMPA DATI EVENTO-----"<<endl;
		out << "LUOGO : "<<luogo<<endl;
		out << "DATA : "<<data<<endl;
		out << "DURATA : "<<durata<<endl;
		return out;
	}
	
	ostream & operator<<(ostream & out, const Evento & e)
	{
		return e.print(out);
	}
	
	istream & Evento::input(istream & in)
	{
		cout << "Inserisci luogo evento : ";
		char buffer[100];
		in.getline(buffer, 100);
		set_luogo(buffer);
		cout <<"\nInserisci data evento : ";
		in >> data;
		cout << "Inserisci durata evento : ";
		in >> durata;
		return in;
	}
	
	istream & operator>>(istream & in, Evento & e)
	{
		return e.input(in);
	}
	
	bool Evento::operator==(const Evento & e)const
	{
		return(strcmp(luogo, e.luogo)==0 && durata==e.durata && data==e.data);
	}
	
}
