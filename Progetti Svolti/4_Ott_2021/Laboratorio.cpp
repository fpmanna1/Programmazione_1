#include "Laboratorio.h"

namespace MS{
	Laboratorio::Laboratorio(const char * dir, const string & tip, const int & g, const int & m, const int & a, const int & dim, const char * ana) : 
		Servizi(dir, tip, g, m, a, dim)
	{
		analisi = new char[strlen(ana)+1];
		strcpy(analisi, ana);
	}
	
	Laboratorio::Laboratorio(const Laboratorio & l) : Servizi(l)
	{
		analisi = new char[strlen(l.analisi)+1];
		strcpy(analisi, l.analisi);
	}
	
	const Laboratorio & Laboratorio::operator=(const Laboratorio & l)
	{
		if(this!=&l)
		{
			Servizi::operator=(l);
			set_ana(l.analisi);
		}
		return *this;
	}
	
	ostream & Laboratorio::print(ostream & out)const
	{
		Servizi::print(out);
		out << "------STAMPA DATI LABORATORIO------"<<endl;
		out << "TIPO ANALISI : "<<analisi<<endl;
		return out;
	}
	
	ostream & operator<<(ostream & out, const Laboratorio & l)
	{
		return l.print(out);
	}
	
	istream & Laboratorio::input(istream & in)
	{
		Servizi::input(in);
		in.ignore();
		cout << "Inserisci il tipo delle analisi : ";
		char buffer[100];
		in.getline(buffer, 100);
		set_ana(buffer);
		return in;
	}
	
	istream & operator>>(istream & in, Laboratorio & l)
	{
		return l.input(in);
	}
	
	bool Laboratorio::prenota(const Prenotazione & p)
	{
		if(full()) return false; //shift a destra delle prenotazioni
		for(int i=nelem; i>=0; i--)
			vet[i+1]=vet[i];
		vet[0]=p;
		nelem++;
		return true;
	}
}
