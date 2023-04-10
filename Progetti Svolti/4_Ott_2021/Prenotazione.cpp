#include "Prenotazione.h"

namespace MS{
	Prenotazione::Prenotazione(const char * cod, const char * n, const char * c, const int & an, const string & tip, const string & prest) : 
	anno_nascita(an), tipo(tip), prestazione(prest){
		strcpy(codice, cod);
		nome = new char[strlen(n)+1];
		strcpy(nome, n);
		cognome = new char[strlen(c)+1];
		strcpy(cognome, c);
	}
	
	Prenotazione::Prenotazione(const Prenotazione & p) : anno_nascita(p.anno_nascita), tipo(p.tipo), prestazione(p.prestazione)
	{
		strcpy(codice, p.codice);
		nome = new char[strlen(p.nome)+1];
		strcpy(nome, p.nome);
		cognome = new char[strlen(p.cognome)+1];
		strcpy(cognome, p.cognome);
	}
	
	const Prenotazione & Prenotazione::operator=(const Prenotazione & p)
	{
		if(this!=&p)
		{
			strcpy(codice, p.codice);
			set_nome(p.nome);
			set_cognome(p.cognome);
			anno_nascita = p.anno_nascita;
			tipo = p.tipo;
			prestazione = p.prestazione;
		}
		return *this;
	}
	
	ostream & Prenotazione::print(ostream & out)const
	{
		out << "-----STAMPA DATI PRENOTAZIONE------"<<endl;
		out << "CODICE : "<<codice<<endl;
		out << "NOME : "<<nome<<endl;
		out << "COGNOME : "<<cognome<<endl;
		out << "TIPO SERVIZIO :"<<tipo<<endl;
		out << "PRESTAZIONE RICHIESTA : "<<prestazione<<endl;
		return out;
	}
	
	ostream & operator<<(ostream & out, const Prenotazione & p)
	{
		return p.print(out);
	}
	
	istream & Prenotazione::input(istream & in)
	{
		cout << "Inserisci codice : ";
		in >> codice;
		in.ignore();
		char buffer[100];
		cout << "Inserisci nome prenotato : ";
		in.getline(buffer, 100);
		set_nome(buffer);
		cout << "Inserisci cognome prenotato : ";
		in.getline(buffer, 100);
		set_cognome(buffer);
		cout << "Inserisci tipo servizio : ";
		in >> tipo;
		cout << "Inserisci prestazione richiesta : ";
		in >> prestazione;
		return in;
	}
	
	istream & operator>>(istream & in, Prenotazione & p)
	{
		return p.input(in);
	}
	
	bool Prenotazione::operator==(const Prenotazione & p)const
	{
		return(strcmp(codice, p.codice) == 0 && strcmp(nome, p.nome) == 0 && strcmp(cognome, p.cognome) == 0 && tipo == p.tipo && prestazione == p.prestazione);
	}
}
