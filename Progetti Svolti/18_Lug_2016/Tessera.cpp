#include "Tessera.h"

namespace MS{
	
	Tessera::Tessera(const char * t, const char * i, const char * nc, const char * CF) : Carta(t, i, nc)
	{
		this->CF = new char[strlen(CF)+1];
		strcpy(this->CF, CF);
	}
	
	Tessera::Tessera(const Tessera &t) : Carta(t)
	{
		this->CF = new char[strlen(t.CF)+1];
		strcpy(CF, t.CF);
	}
	
	bool Tessera::check(const char * s)
	{
		return(strcmp(s, this->CF)==0);
	}
	
	ostream & Tessera::print(ostream & out)const
	{
		Carta::print(out);
		out<<" "<<CF<<" "<<DataScadenza<<" "<<DataRilascio;
		return out;
	}
	
	void Tessera::set_CF(const char * s)
	{
		delete [] CF;
		CF = new char[strlen(s)+1];
		strcpy(CF,s);
	}
	
	const Tessera & Tessera::operator=(const Tessera & t)
	{
		if(this!=&t)
		{
			Carta::operator=(t);
			set_CF(t.CF);
			set_DataRilascio(t.DataRilascio);
			set_DataScadenza(t.DataScadenza);
		}
		return *this;
	}
}
