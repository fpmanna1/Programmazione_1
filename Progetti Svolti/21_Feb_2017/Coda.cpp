#include "Coda.h"

namespace MS{
	
	Coda::Coda(const Coda &c) : testa(c.testa), coda(c.coda), nelem(c.nelem)
	{
		vet = new T[dim];
		for(int i=0; i<dim; i++)
			vet[i]=c.vet[i];
	}
	
	const Coda & Coda::operator=(const Coda &c)
	{
		if(this!=&c)
		{
			testa=c.testa;
			coda=c.coda;
			nelem=c.nelem;
			delete [] vet;
			vet = new T[dim];
			for(int i=0; i<dim; i++)
				vet[i]=c.vet[i];
		}
		return *this;
	}
	
	bool Coda::insert(const T & t) throw(Eccezione)
	{
		if(!full() && !ricerca(t))
		{
			nelem++;
			vet[coda]=t;
			coda=(coda+1)%dim;
			return true;
		}
		throw Eccezione("inserimento non riuscito, elemento gia' presente!");
		return false;
	}
	
	ostream & Coda::print(ostream & out)const
	{
		for(int i=testa; i<coda; i++)
			out << *vet[i]<<endl;
		return out;
	}
	
	bool Coda::pop()
	{
		if(!empty())
		{
			nelem--;
			testa=(testa+1)%dim;
			return true;
		}
		return false;
		
	}
	
	bool Coda::ricerca(const T& t)const
	{
		for(int i=0; i<nelem; i++)
		{
			if(*vet[i]==*t) // uso * perchè il vettore contiene un puntatore quindi devo dereferenziarlo per accedere al dato a cui esso punta
				return true;
		}
		return false;
	}
	
	ostream & operator<<(ostream & out, const Coda &c)
	{
		return c.print(out);
	}
}
