#include "Pacco.h"

namespace MS{
	Pacco::Pacco(const int & cod, const float & pes, const char * ind) : codice(cod), peso(pes)
	{
		indirizzo = new char[strlen(ind)+1];
		strcpy(indirizzo, ind);
	}
	
	Pacco::Pacco(const Pacco & p) : codice(p.codice), peso(p.peso)
	{
		indirizzo = new char[strlen(p.indirizzo)+1];
		strcpy(indirizzo, p.indirizzo);
	}
	
	const Pacco & Pacco::operator=(const Pacco & p)
	{
		if(this!=&p)
		{
			set_codice(p.codice);
			set_peso(p.peso);
			set_indirizzo(p.indirizzo);
		}
		return *this;
	}
	
	ostream & Pacco::print(ostream & out)const
	{
		out << "-------STAMPA INFO DEL PACCO------"<<endl;
		out << "CODICE : "<<codice<<endl;
		out << "PESO : "<<peso<<" Kg"<<endl;
		out << "INDIRIZZO : "<<indirizzo<<endl;
		return out;
	}
	
	ostream & operator<<(ostream & out, const Pacco & p)
	{
		return p.print(out);
	}
	
	istream & Pacco::input(istream & in)
	{
		cout << "Inserisci il codice : "; in >> codice;
		cout << "Inserisci il peso : "; in >> peso;
		in.ignore();
		cout << "Inserisci l'indirizzo : ";
		char buffer[100];
		in.getline(buffer, 100);
		set_indirizzo(buffer);
		return in;
	}
	
	istream & operator>>(istream & in, Pacco & p)
	{
		return p.input(in);
	}
}
