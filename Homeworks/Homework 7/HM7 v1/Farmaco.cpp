#include "Farmaco.h"

namespace MyNS{
	
	Farmaco::Farmaco(const char * N, const char * P, const float C, const Data & D) /*:costo(C), */ : scadenza(D) {
		nome = new char[strlen(N)+1];
		strcpy(nome,N);
		pa = new char[strlen(P)+1];
		strcpy(pa, P);
		costo=C;
		//scadenza=D;
	}
	
	Farmaco::Farmaco(const Farmaco & f) : costo(f.costo), scadenza(f.scadenza)
	{
		nome=new char[strlen(f.nome)+1];
		strcpy(nome, f.nome);
		pa=new char[strlen(f.pa)+1];
		strcpy(pa, f.pa);
	}
	
	ostream & operator<<(ostream & out, const Farmaco & f)
	{
		out << f.nome << " " << f.pa << " " << f.costo << " " << f.scadenza ;
		return out;
	}
	
	istream & operator>>(istream & in, Farmaco &f)
	{
		delete[] f.nome;
		delete[] f.pa;
		char buffer[100];
		in.getline(buffer, 100);
		f.nome = new char[strlen(buffer)+1];
		strcpy(f.nome, buffer);
		in.getline(buffer,100);
		f.pa = new char[strlen(buffer)+1];
		strcpy(f.pa, buffer);
		in>>f.costo;
		in>>f.scadenza;
		return in;
	}
	
/*	bool Farmaco::check_data(const Data & D) const throw(Eccezioni)
	{
		if(scadenza < D)
			throw Eccezioni(scadenza);
		return true;	
	}
	*/

}
