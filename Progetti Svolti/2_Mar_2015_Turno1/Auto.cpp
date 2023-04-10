#include "Auto.h"

namespace MS{
	Auto::Auto(const char * nt, const char * m, const char * a) : Veicolo(nt, m)
	{
		alim = new char[strlen(a)+1];
		strcpy(alim, a);
	}
	
	Auto::Auto(const Auto & a) : Veicolo(a)
	{
		alim = new char[strlen(a.alim)+1];
		strcpy(alim, a.alim);
	}
	
	const Auto & Auto::operator=(const Auto & a)
	{
		if(this!=&a)
		{
			Veicolo::operator=(a);
			set_alim(a.alim);
		}
		return *this;
	}
	
	ostream & Auto::print(ostream & out)const
	{
		Veicolo::print(out);
		out << "ALIMENTAZIONE : "<<alim<<endl;
		return out;
	}
	
	ostream & operator<<(ostream & out, const Auto & a)
	{
		return a.print(out);
	}
	
	istream & Auto::input(istream & in)
	{
		Veicolo::input(in);
		char buffer[100];
		in.getline(buffer, 100);
		set_alim(buffer);
		return in;
	}
	
	istream & operator>>(istream & in, Auto & a)
	{
		return a.input(in);
	}
	
	const char * Auto::totext()
	{
		char buffer[200];
		strcat(buffer, this->get_nome_tipo());
		strcat(buffer, " ");
		strcat(buffer, this->get_marca());
		strcat(buffer, " ");
		strcat(buffer, this->alim);
		char * stringa;
		stringa = new char[strlen(buffer)+1];
		return stringa;
	}
	
}
