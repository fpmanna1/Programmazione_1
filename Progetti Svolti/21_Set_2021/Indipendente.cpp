#include "Indipendente.h"

namespace MS{
	Indipendente::Indipendente() : Attrazione(), incasso_corrente(0)
	{
		titolare = new char[14];
		strcpy(titolare, "TITOLARE_PROV");
	}
	
	Indipendente::Indipendente(const char * nom, const float & cost, const char * tit, const int & incas) : Attrazione(nom, cost), incasso_corrente(incas)
	{
		titolare = new char[strlen(tit)+1];
		strcpy(titolare, tit);
	}
	
	Indipendente::Indipendente(const Indipendente & i) : Attrazione(i), incasso_corrente(i.incasso_corrente)
	{
		titolare = new char[strlen(i.titolare)+1];
		strcpy(titolare, i.titolare);
	}
	
	const Indipendente & Indipendente::operator=(const Indipendente & i)
	{
		if(this!=&i)
		{
			Attrazione::operator=(i);
			set_titolare(i.titolare);
			incasso_corrente=i.incasso_corrente;
		}
		return *this;
	}
	bool Indipendente::acquista_biglietto(string s)
	{
		if(titolare == s) 
		{
			incasso_corrente+=costo;
			return true;
		}
		return false;
	}
	
	double Indipendente::calcolo_incasso()const
	{
		return incasso_corrente;
	}
	
	ostream & Indipendente::print(ostream & out)const
	{
		Attrazione::print(out);
		out << endl;
		out << "---INFORMAZIONI GESTIONE ATTRAZIONI INDIPENDENTI-----"<<endl;
		out << "TITOLARE : "<<titolare<<endl;
		out << "INCASSO CORRENTE : "<<incasso_corrente;
		return out;
	}
	
	ostream & operator<<(ostream & out, const Indipendente & i)
	{
		return i.print(out);
	}
	

}
