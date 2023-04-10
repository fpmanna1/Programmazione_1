#include "Pizza.h"

namespace MS{
	Pizza::Pizza(const int & cod, const char * piatt, const float & cos, const char * nom, const Lista & ing) : Voce(cod, piatt, cos)
	, ingredienti(ing)
	{
		nome = new char[strlen(nom)+1];
		strcpy(nome, nom);
	}
	
	Pizza::Pizza(const Pizza & p) : Voce(p), ingredienti(p.ingredienti)
	{
		nome = new char[strlen(p.nome)+1];
		strcpy(nome, p.nome);
	}
	
	const Pizza & Pizza::operator=(const Pizza & p)
	{
		if(this!=&p)
		{
			Voce::operator=(p);
			ingredienti=p.ingredienti;
			set_nome(p.nome);
		}
		return *this;
	}
	
	ostream & Pizza::print(ostream & out)const
	{
		Voce::print(out);
		out << "-----STAMPA DATI PIZZA------"<<endl;
		out << "NOME : "<<nome<<endl;
		out << "LISTA DI INGREDIENTI : "<<endl;
		out << ingredienti<<endl;
		return out;
	}
	
	ostream & operator<<(ostream & out, const Pizza & p)
	{
		p.print(out);
	}
	
	istream & Pizza::input(istream & in)
	{
		Voce::input(in);
		in.ignore();
		cout << "Inserisci il nome della pizza : ";
		char buffer[100];
		in.getline(buffer, 100);
		set_nome(buffer);
		int num;
		cout << "Quanti ingredienti vuoi inserire ? "; in >> num;
		string s;
		for(int i=0; i<num; i++)
		{
			cout << "Ingrediente "<<i<<" : ";
			in >> s;
			ingredienti.push(s);
		}
		return in;
	}
	
	istream & operator>>(istream & in, Pizza & p)
	{
		return p.input(in);
	}
	
}
