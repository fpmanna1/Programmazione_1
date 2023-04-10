#include "Riunione.h"

namespace MS{
	Riunione::Riunione(const char * des, const int & ora , const int & min, const char * l, const int & di) : Evento(des, ora, min), e(di)
	{
		strcpy(luogo, l);
	}
	
	Riunione::Riunione(const Riunione & r) : Evento(r), e(r.e)
	{
		strcpy(luogo, r.luogo);
	}
	
	const Riunione & Riunione::operator=(const Riunione & r)
	{
		if(this!=&r)
		{
			Evento::operator=(r);
			set_luogo(r.luogo);
			e=r.e;
		}
		return *this;
	}
	
	ostream & Riunione::print(ostream & out)const
	{
		Evento::print(out);
		out << "LUOGO :"<<luogo<<endl;
		out << "ELENCO : "<<e<<endl;
		return out;
	}
	
	ostream & operator<<(ostream & out, const Riunione & r)
	{
		return r.print(out);
	}
	
	
}
