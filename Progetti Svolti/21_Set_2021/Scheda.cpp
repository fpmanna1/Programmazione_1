#include "Scheda.h"

namespace MS{
	Scheda::Scheda() : codice("1234"), X(20), M(20), corrente(20){}
	
	Scheda::Scheda(const string & cod, int  m, int  x, int corr) : codice(cod), M(m)
	{
		if(x<m)
			x=m;
		X=x;
		corr=x;
		corrente = corr;
	}
	
	ostream & Scheda::print(ostream & out)const
	{
		out << "CODICE : "<<codice<<endl;
		out << "VALORE MINIMO : "<<M<<endl;
		out << "CREDITO INIZIALE : "<<X<<endl;
		out << "CREDITO RESIDUO : "<<corrente;
		return out;	
	}
	
	istream & Scheda::input(istream & in)
	{
		cout << "Inserisci Codice, Valore Minimo, Credito Iniziale e Credito Residuo : ";
		in >> codice >> M >> X >> corrente;
		return in;
		
	}
	
	void Scheda::decrementa(const int & c) throw(Eccezione)
	{
		if(corrente < c)
			this->corrente -= c;
			else
				throw Eccezione("Credito residuo non sufficiente");
	}
	
	ostream & operator<<(ostream & out, const Scheda & s)
	{
		return s.print(out);
	}
	
	istream & operator>>(istream & in, Scheda & s)
	{
		return s.input(in);
	}
	
	bool Scheda::operator==(const Scheda & s)
	{
		return(codice==s.codice && M==s.M && X==s.X && corrente==s.corrente);
	}
}
