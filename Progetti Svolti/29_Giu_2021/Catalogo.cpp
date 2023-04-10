#include "Catalogo.h"

namespace MS{
	
	bool Catalogo::inlist(const char * cod)
	{
		for(int i=0; i<nelem; i++)
		{
			if(strcmp(vet[i]->get_codice(), cod)==0)
				return true;
		}
		return false;
	}
	
	bool Catalogo::insert(T s) throw (Errore) //ricorda T = Scheda*
	{
		if(inlist((*s).get_codice()))
		{
			throw Errore("Elemento non inserito: codice gia' presente!");
			return false;
		} 
		vet[nelem]=s;	
		nelem++;
		return true;
	}
	
	ostream & Catalogo::print(ostream & out)const
	{
		for(int i=0; i<nelem; i++)
		{
			out <<"ELEMENTO -> "<<i<<endl;
			out <<*vet[i]<<endl;
			out << endl;
		}
		return out;
	}
	
	ostream & operator<<(ostream & out, const Catalogo & c)
	{
		return c.print(out);
	}
}
