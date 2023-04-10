#include "Processo.h"

namespace MS{
	
	Processo::Processo(const int P, const char * D, const bool S, const char * N, char St) : Attivita(P,D,S), stato(St){
		nome = new char[strlen(N)+1];
		strcpy(nome, N);
	}
	
	Processo::Processo(const Processo & P) : Attivita(P), stato(P.stato)
	{
		nome = new char[strlen(P.nome)+1];
		strcpy(nome, P.nome);
	}
	
	const Processo & Processo::operator=(const Processo &P)
	{
		if(this!=&P)
		{
			Attivita::operator=(P);
			set_nome(P.nome);
			set_stato(P.stato);
		}
		return *this;
	}
	
	ostream & operator<<(ostream & out, const Processo & P)
	{
		out << (Attivita &)P << " " << P.nome << " " << P.stato;
		return out;	
	}
	
	istream & operator>>(istream & in, Processo & P) //non è una funzione membro, non c'è il this nascosto
	{
		in >> (Attivita &)P;
		in.ignore();
		char buffer[100];
		in.getline(buffer, 100);
		P.nome=new char[strlen(buffer)+1];
		strcpy(P.nome, buffer); //ricorda, mettere sempre un .ignore() quando devo inserire un char * con la getline
		in >> P.stato;
		return in;
	}
	
	void Processo::Attiva()
	{
		Attivita::Attiva();
		if(stato=='P' || stato=='p') stato='R';
	}
	
	bool Processo::operator==(const Processo & p)
	{
		return(Attivita::operator==(p) && strcmp(this->nome, p.nome)==0);
	}
	
	
}
