#include "Scheda.h"

namespace MS{
	
	Scheda::Scheda()
	{
		titolo = new char[1];
		strcpy(titolo, "");
		descrizione = new char[1];
		strcpy(descrizione, "");
		codice = new char[1];
		strcpy(codice, "");
		autore=0;
	}
	
	Scheda::Scheda(const char * t, const char * d, const char * c, Autore * aut)
	{
		titolo = new char[strlen(t)+1];
		strcpy(titolo, t);
		descrizione = new char[strlen(d)+1];
		strcpy(descrizione, d);
		codice = new char[strlen(c)+1];
		strcpy(codice, c);
		autore = aut;
	}
	
	Scheda::Scheda(const Scheda & s)
	{
		titolo = new char[strlen(s.titolo)+1];
		strcpy(titolo, s.titolo);
		descrizione = new char[strlen(s.descrizione)+1];
		strcpy(descrizione, s.descrizione);
		codice = new char[strlen(s.codice)+1];
		strcpy(codice, s.codice);
		autore = s.autore;
	}
	
	const Scheda & Scheda::operator=(const Scheda & s)
	{
		if(!(this==&s))
		{
			set_titolo(s.titolo);
			set_descrizione(s.descrizione);
			set_codice(s.codice);
			set_autore(s.autore);
		}
		return *this;
	}
	
	void Scheda::set_titolo(const char * t)
	{
		delete [] titolo;
		titolo = new char[strlen(t)+1];
		strcpy(titolo, t);
	}
	
	void Scheda::set_descrizione(const char * d)
	{
		delete [] descrizione;
		descrizione = new char[strlen(d)+1];
		strcpy(descrizione, d);
	}
	
	void Scheda::set_codice(const char * c)
	{
		delete [] codice;
		codice = new char[strlen(c)+1];
		strcpy(codice, c);
	}
	
	ostream & Scheda::print(ostream & out)const
	{
		out << "Titolo : "<<titolo<<endl;
		out << "Descrizione : "<<descrizione<<endl;
		out << "Codice : "<<codice<<endl;
		out << "Info Autore : "<<*autore<<endl;
		return out;
	}
	
	ostream & operator<<(ostream & out, const Scheda & s)
	{
		return s.print(out);
	}
	
	istream & Scheda::input(istream & in)
	{
		char buffer[100];
		in.getline(buffer, 100);
		set_titolo(buffer);
		in.getline(buffer, 100);
		set_descrizione(buffer);
		in.getline(buffer, 100);
		set_codice(buffer);
		in>>*autore;
		return in;
	}
	
	istream & operator>>(istream & in, Scheda & s)
	{
		return s.input(in);
	}
}
