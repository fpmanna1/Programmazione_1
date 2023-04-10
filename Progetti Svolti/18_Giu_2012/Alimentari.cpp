#include "Alimentari.h"

namespace MS{
	
	Alimentari::Alimentari() : MeseScadenza(12), costo(0.0)
	{
		codice = new char[1];
		strcpy(codice, "");
		descrizione = new char[1];
		strcpy(descrizione, "");
	}
	
	Alimentari::Alimentari(const char * cod, const char * d, int ms, float c) : MeseScadenza(ms), costo(c)
	{
		codice=new char[strlen(cod)+1];
		strcpy(codice, cod);
		descrizione=new char[strlen(d)+1];
		strcpy(descrizione, d);
	}
	
	Alimentari::Alimentari(const Alimentari & a) : MeseScadenza(a.MeseScadenza), costo(a.costo)
	{
		codice=new char[strlen(a.codice)+1];
		strcpy(codice, a.codice);
		descrizione=new char[strlen(a.descrizione)+1];
		strcpy(descrizione, a.descrizione);
	}
	
	const Alimentari & Alimentari::operator=(const Alimentari & a)
	{
		if(this!=&a)
		{
			set_codice(a.codice);
			set_descrizione(a.descrizione);
			set_MeseScadenza(a.MeseScadenza);
			set_costo(a.costo);
		}
		return * this;
	}
	
	void Alimentari::set_codice(const char * cod)
	{
		delete [] codice;
		codice = new char[strlen(cod)+1];
		strcpy(codice, cod);
	}
	
	void Alimentari::set_descrizione(const char * d)
	{
		delete [] descrizione;
		descrizione = new char[strlen(d)+1];
		strcpy(descrizione, d);
	}
	
	ostream & Alimentari::stampa(ostream & out)const
	{
		out << "CODICE -> "<<codice<<endl;
		out << "DESCRIZIONE -> "<<descrizione<<endl;
		out << "MESE DI SCADENZA -> "<<MeseScadenza<<endl;
		out << "COSTO -> "<<costo;
		return out;
	}
	
	ostream & operator<<(ostream & out, const Alimentari & a)
	{
		return a.stampa(out);
	}
	
	istream & Alimentari::input(istream & in) 
	{
		char buffer[100];
		in.getline(buffer, 100);
		set_codice(buffer);
		in.getline(buffer, 100);
		set_descrizione(buffer);
		in>>MeseScadenza;
		in>>costo;
		return in;
	}
	
	istream & operator>>(istream & in, Alimentari & a)
	{
		return a.input(in);
	}
	
	void Alimentari::store(ofstream & file)const
	{
		file.open("output.txt");
		stampa(file);
		file.close();	
	}
}
