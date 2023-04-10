#include "Pila.h"

namespace MS{
	
	Pila::Pila(const int dim) : nelem(0)
	{
		vet = new T[dim];
		//this->dim=dim; non lo faccio perchè ho fissato dim
	}
	
	Pila::~Pila()
	{
		delete[] vet;
	}
	
	void Pila::push(const T& t)
	{
		vet[nelem]=t;
		nelem++;
	}
	
	void Pila::pop(T& t)
	{
		t=vet[nelem-1];
		nelem--;
	}
	
	void Pila::top(T& t)
	{
		t=vet[nelem-1];
	}
	
	void Pila::print()
	{
		short int temp=nelem-1;
		for(int i=0; i<nelem; i++) //la pila la stampo al contrario
		{
			cout<<vet[temp]<<endl;
			temp--;
		}
	}
	
	Pila::Pila(const Pila & p) : /*dim(p.dim), */ nelem(p.nelem)
	{
		vet = new T[p.dim];
		for(int i=0; i<dim; i++)
		{
			vet[i]=p.vet[i];
		}
		//oppure vet = new T[p.dim]; dim = p.dim;
	}
	
	const Pila & Pila::operator=(const Pila &p)
	{
		if(this!=&p)
		{
			if(dim == p.dim) //sarà sempre vera dunque
			{
				delete [] vet;
				vet = new T[p.dim];
				for(int i=0; i<dim; i++)
				{
					vet[i]=p.vet[i];
				}
			}else{
				cout<<"errore, le due pile devono avere dimensioni uguali!"<<endl;
				exit(23);
			}
			}
		return *this;
	}
}
