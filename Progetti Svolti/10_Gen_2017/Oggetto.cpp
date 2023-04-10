#include "Oggetto.h"

namespace MS{
	Oggetto::Oggetto(const int & cod, const char * des, const char * f) : codice(cod)
	{
		descrizione = new char[strlen(des)+1];
		strcpy(descrizione, des);
		forma = new char[strlen(f)+1];
		strcpy(forma, f);
	}
	
	Oggetto::Oggetto(const Oggetto & o) : codice(o.codice)
	{
		descrizione = new char[strlen(o.descrizione)+1];
		strcpy(descrizione, o.descrizione);
		forma = new char[strlen(o.forma)+1];
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
	
	bool Oggetto::operator==(const Oggetto & o)const
	{
		return(codice==o.codice && strcmp(descrizione, o.descrizione)==0 && strcmp(forma, o.forma)==0);
	}
	
	bool Oggetto::operator!=(const Oggetto & o)const
	{
		return(!Oggetto::operator==(o));
	}
	
	ostream & Oggetto::print(ostream & out)const
	{
		out << "-----STAMPA INFO OGGETTO------"<<endl;
		out << "CODICE : "<<codice<<endl;
		out << "DESCRIZIONE : "<<descrizione<<endl;
		out << "FORMA : "<<forma<<endl;
		return out;
	}
	
	ostream & operator<<(ostream & out, const Oggetto & o)
	{
		return o.print(out);
	}
	
	istream & Oggetto::input(istream & in)
	{
		cout << "Inserisci il codice : ";
		in >> codice;
		in.ignore();
		char buffer[100];
		cout << "Inserisci la descrizione : ";
		in.getline(buffer, 100);
		set_descrizione(buffer);
		cout << "Inserisci la forma : ";
		in.getline(buffer, 100);
		set_forma(buffer);
		return in;
	}
	
	istream & operator>>(istream & in, Oggetto & o)
	{
		return o.input(in);
	}
}
