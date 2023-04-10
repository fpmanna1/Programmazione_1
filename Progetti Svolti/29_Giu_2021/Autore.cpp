#include "Autore.h"

namespace MS{
	Autore::Autore(const string & n, int na, int m) : nome(n), nascita(na), morte(m){}
	
	Autore::Autore(const Autore & a) : nome(a.nome), nascita(a.nascita), morte(a.morte){}
	
	const Autore & Autore::operator=(const Autore & a)
	{
		if(this!=&a)
		{
			set_nome(a.nome);
			set_nascita(a.nascita);
			set_morte(a.morte);
		}
		return * this;
	}
	
	ostream & operator<<(ostream & out, const Autore & a)
	{
		out <<"Nome : "<< a.nome <<endl;
		out <<"Anno Nascita : " << a.nascita <<endl;
		out <<"Anno Morte : " << a.morte;
		return out;
	}
	
	istream & operator>>(istream & in, Autore & a)
	{
		cout << "Inserisci dati autore : ";
		in >> a.nome; 
		in >> a.nascita;
		in >> a.morte;
		return in;
	}
}
