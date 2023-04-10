#include "Attrazione.h"

namespace MS{
	Attrazione::Attrazione() : costo(0)
	{
		nome = new char[strlen("NOME CASUALE")+1];
		strcpy(nome, "NOME CASUALE");
	}
	
	Attrazione::Attrazione(const char * n, const float & c) : costo(c)
	{
		nome = new char[strlen(n)+1];
		strcpy(nome, n);
	}
	
	Attrazione::Attrazione(const Attrazione & a) : costo(a.costo)
	{
		nome = new char[strlen(a.nome)+1];
		strcpy(nome, a.nome);
	}
	
	Attrazione::~Attrazione()
	{
		delete[] nome;
	}
	
	const Attrazione & Attrazione::operator=(const Attrazione & a)
	{
		if(this!=&a)
		{
			set_nome(a.nome);
			set_costo(a.costo);
		}
		return *this;
	}
	
	ostream & Attrazione::print(ostream & out)const
	{
		out << "NOME ATTRAZIONE : "<<nome<<endl;
		out << "COSTO ATTRAZIONE : "<<costo;
		return out;
	}
	
	ostream & operator<<(ostream & out, const Attrazione & a)
	{
		return a.print(out);
	}
	
	istream & Attrazione::input(istream & in)
	{
		cout << "Inserisci nome e costo attrazione : ";
		char buffer[100];
		in.getline(buffer, 100);
		set_nome(buffer);
		in >> costo;
		return in;
	}
	
	istream & operator>>(istream & in, Attrazione & a)
	{
		return a.input(in);
	}
}
