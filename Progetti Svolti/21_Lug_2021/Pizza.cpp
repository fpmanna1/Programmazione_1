#include "Pizza.h"

namespace MS{
	Pizza::Pizza(const int cod, const char * tip, const float prez, const char * n, const Ingredienti & i ) : Voce(cod, tip, prez)//, Ingredienti(i)
	{
		nome = new char[strlen(n)+1];
		strcpy(nome, n);
	}
	
	Pizza::Pizza(const Pizza & p) : Voce(p)//, Ingredienti(p.ingredienti)
	{
		nome = new char[strlen(p.nome)+1];
		strcpy(nome, p.nome);
	}
	
	ostream & Pizza::print(ostream & out)const
	{
		out << "Nome : "<<nome<<endl;
		out << "Ingredienti: "<<ingredienti<<endl;
		return out;
	}
	
	istream & Pizza::input(istream & in)
	{
		Voce::input(in);
		cout << "Inserisci il nome della pizza : ";
		char buffer[100];
		in.ignore();
		in.getline(buffer, 100);
		nome = new char[strlen(buffer)+1];
		strcpy(nome, buffer);
		cout << "Quanti ingredienti ha ? ";
		int n;
		in >> n;
		for(int i=0; i<n; i++)
		{
			string temp;
			in >> temp;
			ingredienti.push(temp);
		}
		return in;
	}
	
	ostream & operator<<(ostream & out, const Pizza & p)
	{
		return p.print(out);
	}
	
	const Pizza & Pizza::operator=(const Pizza & p)
	{
		if(this!=&p)
		{
			ingredienti=p.ingredienti;
			delete [] nome;
			nome=new char[strlen(p.nome)+1];
			strcpy(nome,p.nome); 
		}
		return *this;
	}
}
