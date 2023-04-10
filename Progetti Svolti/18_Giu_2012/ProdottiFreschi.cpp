#include "ProdottiFreschi.h"

namespace MS{
	
	ProdottiFreschi::ProdottiFreschi() : Alimentari()
	{
		DataConfezione=new char[1];
		strcpy(DataConfezione, "");
	}
	
	ProdottiFreschi::ProdottiFreschi(const char * cod, const char * d, int ms, float c, const char * dc) : Alimentari(cod, d, ms, c)
	{
		DataConfezione=new char[strlen(dc)+1];
		strcpy(DataConfezione, dc);
	}
	
	ProdottiFreschi::ProdottiFreschi(const ProdottiFreschi & p) : Alimentari(p)
	{
		DataConfezione=new char[strlen(p.DataConfezione)+1];
		strcpy(DataConfezione, p.DataConfezione);
	}
	
	const ProdottiFreschi & ProdottiFreschi::operator=(const ProdottiFreschi & p)
	{
		if(this!=&p)
		{
			Alimentari::operator=(p);
			set_DataConfezione(p.DataConfezione);
		}
		return *this;
	}
	
	void ProdottiFreschi::set_DataConfezione(const char * dc)
	{
		delete [] DataConfezione;
		DataConfezione = new char[strlen(dc)+1];
		strcpy(DataConfezione, dc);
	}
	
	void ProdottiFreschi::offerta()
	{
		if(this->MeseScadenza==12)
			costo-=(costo * 20)/100;
	}
	
	ostream & ProdottiFreschi::stampa(ostream & out)const
	{
		Alimentari::stampa(out);
		out << "\nDATA CONFEZIONE -> "<<DataConfezione;
		return out;
	}
	
	ostream & operator<<(ostream & out, const ProdottiFreschi & p)
	{
		return p.stampa(out);
	}
	
	istream & ProdottiFreschi::input(istream & in)
	{
		Alimentari::input(in);
		in.ignore();
		char buffer[100];
		in.getline(buffer, 100);
		set_DataConfezione(buffer);
		return in;
	}
	
	istream & operator>>(istream & in, ProdottiFreschi & p)
	{
		return p.input(in);
	}
	
	
	void ProdottiFreschi::store(ofstream & file)const
	{
		Alimentari::store(file);
		stampa(file);
	}
}
