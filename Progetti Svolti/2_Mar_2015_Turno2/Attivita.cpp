#include "Attivita.h"

namespace MS{
	
	Attivita::Attivita(const int P, const char * D, bool S) : pid(P), started(S)
	{
		descrizione = new char[strlen(D)+1];
		strcpy(descrizione, D);
	}
	
	Attivita::Attivita(const Attivita & A) : pid(A.pid), started(A.started)
	{
		descrizione = new char[strlen(A.descrizione)+1];
		strcpy(descrizione, A.descrizione);
	}
	
	const Attivita & Attivita::operator=(const Attivita & A)
	{	
		if(this!= &A)
		{
			set_pid(A.pid);
			set_descrizione(A.descrizione);
			set_started(A.started);
		}
		return *this;
	}	
	
	ostream & operator<<(ostream & out, const Attivita & A)
	{
		out << A.pid << " " << A.descrizione << " " << A.started;
		return out;
	}  
	
	istream & operator>>(istream & in, Attivita & A)
	{
		in >> A.pid;
		char buffer[100];
		in.ignore();
		in.getline(buffer, 100);
		A.descrizione=new char[strlen(buffer)+1];
		strcpy(A.descrizione, buffer);
		in>> A.started;
		return in;
	}
	
	void Attivita::Attiva()
	{
		this->started = true;
	}
	
	bool Attivita::operator==(const Attivita& a){
		return pid==a.pid && strcmp(descrizione, a.descrizione)==0;
	}
}

