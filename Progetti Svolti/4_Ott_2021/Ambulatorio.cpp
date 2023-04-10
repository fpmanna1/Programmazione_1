#include "Ambulatorio.h"

namespace MS{
	Ambulatorio::Ambulatorio(const char * dir, const string & tip, const int & g, const int & m, const int & a, const int & dim, const char * sp) : 
		Servizi(dir, tip, g, m, a, dim)
	{
		spec = new char[strlen(sp)+1];
		strcpy(spec, sp);
	}
	
	Ambulatorio::Ambulatorio(const Ambulatorio & a) : Servizi(a)
	{
		spec = new char[strlen(a.spec)+1];
		strcpy(spec, a.spec);
	}
	
	const Ambulatorio & Ambulatorio::operator=(const Ambulatorio & a)
	{
		if(this!=&a)
		{
			Servizi::operator=(a);
			set_spec(a.spec);
		}
		return *this;
	}
	
	ostream & Ambulatorio::print(ostream & out)const
	{
		Servizi::print(out);
		out << "------STAMPA DATI AMBULATORIO------"<<endl;
		out << "SPECIALIZZAZIONE : "<<spec<<endl;
		return out;
	}
	
	ostream & operator<<(ostream & out, const Ambulatorio & a)
	{
		return a.print(out);
	}
	
	istream & Ambulatorio::input(istream & in)
	{
		Servizi::input(in);
		in.ignore();
		cout << "Inserisci la specializzazione : ";
		char buffer[100];
		in.getline(buffer, 100);
		set_spec(buffer);
		return in;
	}
	
	istream & operator>>(istream & in, Ambulatorio & a)
	{
		return a.input(in);
	}
	
	bool Ambulatorio::prenota(const Prenotazione & p) throw(Eccezione)
	{
		if(full()) return false;
		if(inlist(p))
		{
			throw Eccezione("Inserimento non riuscito, prenotazione gia' presente!");
			return false;
		}
		vet[nelem]=p;
		nelem++;
		return true;
	}
}
