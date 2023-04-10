#include "Vettore.h"

namespace MS{
	Vettore::Vettore(const int & d) : dim(d)
	{
		vet = new T[dim];
	}
	
	Vettore::Vettore(const Vettore & v) : dim(v.dim)
	{
		vet = new T[dim];
		for(int i=0; i<dim; i++)
		{
			vet[i]=v.vet[i];
		}
	}
	
	const Vettore & Vettore::operator=(const Vettore & v)
	{
		if(this!=&v)
		{
			dim=v.dim;
			delete[] vet;
			vet = new T[v.dim];
			for(int i=0; i<dim; i++)
				vet[i]=v.vet[i];
		}
		return *this;
	}
	
	T & Vettore::operator[](const int index)
	{
		return vet[index];
	}
	
	const T & Vettore::operator[](const int index)const
	{
		return vet[index];
	}
	
	ostream & Vettore::print(ostream & out)const
	{
		for(int i=0; i<dim; i++)
		{
			if(i==dim-1)
				out <<vet[i];
				else
					out << vet[i] << " - ";
		}
		out<<endl;
		return out;
	}
	
	ostream & operator<<(ostream & out, const Vettore & v)
	{
		return v.print(out);
	}
	
	istream & Vettore::input(istream & in)
	{
		cout << "INSERIMENTO ELEMENTI ALL'INTERNO DEL VETTORE : "<<endl;
		for(int i=0; i<dim; i++)
		{
			cout << "Inserisci l'elemento n."<<i<<" : ";
			in >> vet[i];
		}
		return in;
	}
	
	istream & operator>>(istream & in, Vettore & v)
	{
		return v.input(in);
	}
	
}
