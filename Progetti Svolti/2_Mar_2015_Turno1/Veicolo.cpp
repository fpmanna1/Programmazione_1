#include "Veicolo.h"

namespace MS{
	Veicolo::Veicolo(const char * nt, const char * m)
	{
		nome_tipo = new char[strlen(nt)+1];
		strcpy(nome_tipo, nt);
		marca = new char[strlen(m)+1];
		strcpy(marca, m);
	}
	
	Veicolo::Veicolo(const Veicolo & v)
	{
		nome_tipo = new char[strlen(v.nome_tipo)+1];
		strcpy(nome_tipo, v.nome_tipo);
		marca = new char[strlen(v.marca)+1];
		strcpy(marca, v.marca);
	}
	
	const Veicolo & Veicolo::operator=(const Veicolo & v)
	{
		if(this!=&v)
		{
			set_nome_tipo(v.nome_tipo);
			set_marca(v.marca);
		}
		return *this;
	}
	
	ostream & Veicolo::print(ostream & out)const
	{
		out << "NOME TIPO : "<<nome_tipo<<endl;
		out << "MARCA : "<<marca<<endl;
		return out;
	}
	
	ostream & operator<<(ostream & out, const Veicolo & v)
	{
		return v.print(out);
	}
	
	istream & Veicolo::input(istream & in)
	{
		char buffer[100];
		in.getline(buffer, 100);
		set_nome_tipo(buffer);
		in.getline(buffer, 100);
		set_marca(buffer);
		return in;
	}
	
	istream & operator>>(istream & in, Veicolo & v)
	{
		return v.input(in);
	}
}
