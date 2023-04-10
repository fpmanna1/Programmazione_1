#include "Pittura.h"

namespace MS{
	Pittura::Pittura() : Scheda()
	{
		tecnica = new char[1];
		strcpy(tecnica, "");
		strcpy(tipo, "");
	}
	
	Pittura::Pittura(const char *tit, const char *des, const char *cod, Autore *aut, const char *tec, const char tip[lenght]) : Scheda(tit, des, cod, aut)
	{
		tecnica = new char[strlen(tec)+1];
		strcpy(tecnica, tec);
		strcpy(tipo, tip);
	}
	
	Pittura::Pittura(const Pittura & p) : Scheda(p)
	{
		tecnica = new char[strlen(p.tecnica)+1];
		strcpy(tecnica, p.tecnica);
		strcpy(tipo, p.tipo);
	}
	
	const Pittura & Pittura::operator=(const Pittura & p)
	{
		if(this!=&p)
		{
			Scheda::operator=(p);
			set_tecnica(p.tecnica);
			set_tipo(p.tipo);
		}
		return *this;
	}
	
	ostream & Pittura::print(ostream & out)const
	{
		Scheda::print(out);
		out <<"Tecnica : "<<tecnica<<endl;
		out <<"Tipo : "<<tipo<<endl;
		return out;
	}
	
	ostream & operator<<(ostream & out, const Pittura & p)
	{
		p.print(out);
		return out;
	}
	
	istream & Pittura::input(istream & in)
	{
		Scheda::input(in);
		char buffer[100];
		in.getline(buffer, 100);
		set_tecnica(buffer);
		in>>tipo;
		return in;
	}
	
	istream & operator>>(istream & in, Pittura & p)
	{
		return p.input(in);
	}
	
	
}
