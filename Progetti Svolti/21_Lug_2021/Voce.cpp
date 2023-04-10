#include "Voce.h"

namespace MS{
	
	Voce::Voce() : codice(1234), prezzo(5.0)
	{
		tipo = new char[1];
		strcpy(tipo, "unknown");
	}
	
	Voce::Voce(const int cod, const char * t, const float p) : codice(cod), prezzo(p)
	{
		tipo = new char[strlen(t)+1];
		strcpy(tipo, t);
	}
	
	Voce::Voce(const Voce & v) : codice(v.codice), prezzo(v.prezzo)
	{
		tipo = new char[strlen(v.tipo)+1];
		strcpy(tipo, v.tipo);
	}
	
	const Voce & Voce::operator=(const Voce & v)
	{
		if(this!=&v)
		{
			delete [] tipo;
			codice = v.codice;
			tipo = new char[strlen(v.tipo)+1];
			strcpy(tipo, v.tipo);
			prezzo = v.prezzo;
		}
		return *this;
	}
	
	ostream & Voce::print(ostream & out)const
	{
		out << "Codice : "<<codice<<endl;
		out << "Tipo : "<<tipo<<endl;
		out << "Prezzo : "<<prezzo<<endl;
		return out;
	}
	
	ostream & operator<<(ostream & out, const Voce & v)
	{
		return v.print(out);
	}
	
	istream & Voce::input(istream & in)
	{
		char buffer[100];
		in>>codice;
		in.ignore();
		in.getline(buffer, 100);
		delete [] tipo;
		tipo = new char[strlen(buffer)+1];
		strcpy(tipo, buffer);
		in>>prezzo;
		return in;
	}
	
	istream & operator>>(istream & in, Voce & v)
	{
		return v.input(in);
	}
}
