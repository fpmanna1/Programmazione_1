#include "Biglietto.h"

namespace MS{
	Biglietto::Biglietto(const int & cod, const float & cost, Evento* ev) : codice(cod), costo(cost), evento(ev){}
	
	ostream & Biglietto::print(ostream & out)const
	{
		out << "-----STAMPA INFO BIGLIETTO-----"<<endl;
		out << "CODICE : "<<codice<<endl;
		out << "COSTO :"<<costo<<" Euro"<<endl;
		out << *evento << endl;
		return out;
	}
	
	istream & Biglietto::input(istream & in)
	{
		cout << "Inserisci codice biglietto : ";
		in >> codice;
		cout << "Inserisci costo biglietto : ";
		in >> costo;
		in.ignore();
		in >> *evento;
		return in;
	}
	
	ostream & operator<<(ostream & out, const Biglietto & b)
	{
		return b.print(out);
	}
	
	istream & operator>>(istream & in, Biglietto & b)
	{
		return b.input(in);
	}
	
	bool Biglietto::operator==(const Biglietto & b)const
	{
		return(codice==b.codice && costo==b.costo && *evento == *(b.evento));
		
	}
}
