#include "Veicolo.h"

namespace MS{
	
	Veicolo::Veicolo() : marca(""), modello(""), potenza(0), classe(0){}
	
	Veicolo::Veicolo(const string & ma, const string & mod, int pot, int c) : marca(ma), modello(mod), potenza(pot), classe(c){}
	
	istream & Veicolo::input(istream & in)
	{
		cout<<"Inserisci la marca : ";
		in >> marca;
		cout<<"Inserisci il modello : ";
		in >> modello;
		cout<<"Inserisci la potenza : ";
		in >> potenza;
		cout<<"Inserisci la classe : ";
		in >> classe;
		return in;
	}
	
	istream & operator>>(istream & in, Veicolo & v) 
	{
		return v.input(in);
	}
	
	ostream & Veicolo::print(ostream & out)const
	{
		out << marca << " " << modello << " " << potenza << " " << classe;
		return out;
	}
	
	ostream & operator<<(ostream & out, const Veicolo & v)
	{
		return v.print(out);
	}
	
	const Veicolo & Veicolo::operator=(const Veicolo & v)
	{
		if(this!=&v)
		{
			marca=v.marca;
			modello=v.modello;
			potenza=v.potenza;
			classe=v.classe;
		}
		return *this;
	}
}
