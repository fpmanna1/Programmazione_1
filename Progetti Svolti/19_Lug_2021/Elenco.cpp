#include "Elenco.h"

namespace MS{
	
	const Elenco & Elenco::operator=(const Elenco & e)
	{
		if(this!=&e)
		{
			dim = e.dim;
			nelem = e.nelem;
			for(int i=0; i<dim; i++)
				vet[i]=e.vet[i];
		}
		return *this;
	}
	
	ostream & operator<<(ostream & out, const Elenco & e)
	{
		out << "-----STAMPA DELL'ELENCO-----"<<endl;
		for(int i=0; i<e.nelem; i++)
		{
			out << "Elemento "<<i<<endl;
			out << e.vet[i]<<endl;
			out << endl;
		}
		return out;
	}
	
	bool Elenco::insert(T p)
	{
		if(full()) infinito();
		vet[nelem]=p;
		nelem++;
		return true;
	}
	
	bool Elenco::inlist(T p, int & pos)const
	{
		for(int i=0; i<nelem; i++)
			if(vet[i]==p)
			{
				pos=i;
				return true;
			}
		return false;
	}
	
	bool Elenco::elimina(T p)
	{
		int pos;
		if(!inlist(p, pos)) return false;
		for(int j=pos; j<nelem-1; j++)
		{
			vet[j] = vet[j+1];
		}
		nelem--;
		return true;
	}
	
	const Elenco & Elenco::infinito()
	{
		if(full())
		{
			T* temp;
			temp = new T[dim+1];
			for(int i=0; i<dim; i++)
				temp[i]=vet[i];
			delete[] vet;
			dim++;
			vet = new T[dim];
			for(int i=0; i<dim; i++)
			{
				vet[i]=temp[i];
			}
			delete temp;
		}
		return *this;
	}
}
