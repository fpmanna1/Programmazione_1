#include "Servizi.h"

namespace MS{
	Servizi::Servizi(const char * dir, const string & tip, const int & g, const int & m, const int & a, const int & dim) : 
		tipo(tip), data(g, m, a), dim(dim), nelem(0)
	{
		strcpy(dirigente, dir);
		vet = new T[dim];
	}
	
	Servizi::Servizi(const Servizi & s) : tipo(s.tipo), data(s.data), dim(s.dim), nelem(s.nelem)
	{
		strcpy(dirigente, s.dirigente);
		vet = new T[s.dim];
		for(int i=0; i<dim; i++)
			vet[i]=s.vet[i];
	}
	
	const Servizi & Servizi::operator=(const Servizi & s)
	{
		if(this!=&s)
		{
			strcpy(dirigente, s.dirigente);
			data = s.data;
			dim = s.dim;
			nelem = s.nelem;
			delete[] vet;
			vet = new T[dim];
			for(int i=0; i<dim; i++)
				vet[i]=s.vet[i];
		}
		return *this;
	}
	
	ostream & Servizi::print(ostream & out)const
	{
		out << "------STAMPA DATI SERVIZI--------"<<endl;
		out << "NOME DIRIGENTE : "<<dirigente<<endl;
		out << "TIPO DEL SERVIZIO : "<<tipo<<endl;
		out << "PRENOTAZIONI PER IL GIORNO "<<data<<" : "<<endl;
		for(int i=0; i<nelem; i++)
			out << vet[i]<<endl;
		return out;
	}
	
	ostream & operator<<(ostream & out, const Servizi & s)
	{
		return s.print(out);
	}
	
	istream & Servizi::input(istream & in)
	{
		cout << "Inserisci nome dirigente : ";
		in >> dirigente;
		cout << "Inserisci il tipo del servizio : ";
		in >> tipo;
		cout << "Inserisci la data : ";
		in >> data;
		return in;
	}
	
	istream & operator>>(istream & in, Servizi & s)
	{
		return s.input(in);
	}
	
	bool Servizi::inlist(const Prenotazione & p)const
	{
		for(int i=0; i<nelem; i++)
			if(vet[i]==p)
				return true;
				else
					return false;
	}
	
}
