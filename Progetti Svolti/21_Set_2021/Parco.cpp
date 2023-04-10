#include "Parco.h"

namespace MS{
	
	Parco::Parco(const Parco & p) : Attrazione(p), dim(p.dim), nelem(p.nelem)
	{
		vet = new Scheda[p.dim];
		for(int i=0; i<p.dim; i++)
			vet[i] = p.vet[i];
	}
	
	const Parco & Parco::operator=(const Parco & p)
	{
		if(this!=&p)
		{
			Attrazione::operator=(p);
			delete [] vet;
			nelem = p.nelem;
			dim = p.dim;
			vet = new Scheda[dim];
			for(int i=0; i<dim; i++)
				vet[i]=p.vet[i];
		}
		return *this;
	}
	
	ostream & Parco::print(ostream & out)const
	{
		Attrazione::print(out);
		out << endl;
		out << "---INFORMAZIONI GESTIONE ATTRAZIONI DEL PARCO-----"<<endl;
		for(int i=0; i<nelem; i++)
			out <<"Scheda n."<<i+1<<" -> "<< vet[i] << endl;
		return out;
	}
	
	ostream & operator<<(ostream & out, const Parco & p)
	{
		return p.print(out);
	}
	
	/*istream & Parco::input(istream & in)
	{
		Attrazione::input(in);
		in >> 
	} */
	
	bool Parco::inlist(Scheda & s)
	{
		for(int i=0; i<nelem; i++)
			if(vet[i] == s)
				return true;
		return false;
	}
	
	bool Parco::insert(Scheda & s)
	{
		if(nelem==dim) return false;
		if(inlist(s)) return false;
		vet[nelem]=s;
		nelem++;
		return true;
	}
	
	bool Parco::acquista_biglietto(string cod)
	{
		int i=0;
		bool trovato = false;
		for(i=0; i<nelem && !trovato; i++)
		{
			if(vet[i].get_Codice() == cod)
				trovato=true;
		}
		vet[i].decrementa(vet[i].get_Corrente());
		return true;
	}
	
	double Parco::calcolo_incasso()const //costo attrazione per numero schede
	{
		return costo * nelem;
	}
		
}
