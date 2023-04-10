#include "Moto.h"

namespace MS{
	Moto::Moto(const char * nt, const char * m, const char * t) : Veicolo(nt, m)
	{
		tipo = new char[strlen(t)+1];
		strcpy(tipo, t);
	}
	
	Moto::Moto(const Moto & m) : Veicolo(m)
	{
		tipo = new char[strlen(m.tipo)+1];
		strcpy(tipo, m.tipo);
	}
	
	const Moto & Moto::operator=(const Moto & m)
	{
		if(this!=&m)
		{
			Veicolo::operator=(m);
			set_tipo(m.tipo);
		}
		return *this;
	}
	
	ostream & Moto::print(ostream & out)const
	{
		Veicolo::print(out);
		out << "ALIMENTAZIONE : "<<tipo<<endl;
		return out;
	}
	
	ostream & operator<<(ostream & out, const Moto & m)
	{
		return m.print(out);
	}
	
	istream & Moto::input(istream & in)
	{
		Veicolo::input(in);
		char buffer[100];
		in.getline(buffer, 100);
		set_tipo(buffer);
		return in;
	}
	
	istream & operator>>(istream & in, Moto & m)
	{
		return m.input(in);
	}
	
	const char * Moto::totext()
	{
		
	}
}
