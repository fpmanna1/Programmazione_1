#include "Carta.h"


namespace MS{
	
	Carta::Carta(const char * t, const char * i, const char * nc)
	{
		tipo = new char[strlen(t)+1];
		strcpy(tipo,t);
		intestatario = new char[strlen(i)+1];
		strcpy(intestatario, i);
		numero_carta = new char[strlen(nc)+1];
		strcpy(numero_carta, nc);
	}
	
	Carta::Carta(const Carta & c)
	{
		tipo = new char[strlen(c.tipo)+1];
		strcpy(tipo,c.tipo);
		intestatario = new char[strlen(c.intestatario)+1];
		strcpy(intestatario, c.intestatario);
		numero_carta = new char[strlen(c.numero_carta)+1];
		strcpy(numero_carta, c.numero_carta);
	}
	
	const Carta & Carta::operator=(const Carta & c)
	{
		if(this!=&c)
		{
			set_tipo(c.tipo);
			set_intestatario(c.intestatario);
			set_numero_carta(c.numero_carta);
		}
		return *this;
	}
	
	ostream & Carta::print(ostream & out)const
	{
		out << tipo << " " << intestatario << " " << numero_carta;
		return out;
	}
	
	ostream & operator<<(ostream & out, const Carta & c)
	{
		return c.print(out);
	}
	
	istream & Carta::input(istream & in)
	{
		char buffer[200];
		in.getline(buffer, 200);
		set_tipo(buffer);
		in.getline(buffer, 200);
		set_intestatario(buffer);
		in.getline(buffer, 200);
		set_numero_carta(buffer);
		return in;
	}
	
	istream & operator>>(istream & in, Carta & c)
	{
		return c.input(in);
	}
	
	bool Carta::formato() throw (Eccezione)
	{
		bool valido=false;
		if(strlen(this->numero_carta)>7)
			valido=true;
		for(int i=0; i<5; i++)
		{
			if(numero_carta[i] < '0' || numero_carta[i] > '9')
				valido=false;
		}
		if(!valido)
		{
			throw Eccezione ("Formato della carta non compatibile, deve essere lunga almeno 8 caratteri!");
			return false;
		}
		return valido;
	}
	
}
