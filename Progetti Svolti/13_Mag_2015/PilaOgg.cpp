#include "PilaOgg.h"

using std::cout; using std::endl;

namespace MS{
	
	PilaOgg::PilaOgg(const char * f) : Pila(dim)
	{
		forma = new char[strlen(f)+1];
		strcpy(forma,f);
	}
	
	PilaOgg::PilaOgg(const PilaOgg & p) : Pila(p)
	{
		forma = new char[strlen(p.forma)+1];
		strcpy(forma, p.forma);	
	}
	
	const PilaOgg & PilaOgg::operator=(const PilaOgg & p)
	{
		if(this!=&p)
		{
			Pila::operator=(p);
			set_forma(p.forma);
		}
		return *this;	
	}
	
	bool PilaOgg::check(const T& t)
	{
		if(strcmp(forma, t.get_forma())==0) //se la forma dell'elemento che voglio aggiungere è uguale alla forma prevista dalla pila
			return true;
		return false;
	}
	
	void PilaOgg::push(const T& t) throw (bad_insert)
	{
		if(check(t))
		{
			vet[nelem]=t;
			nelem++;
		}else{
			throw bad_insert("Forma non compatibile con la pila!");
		}
	}
	
	void PilaOgg::print()
	{
		cout<<"Questa e\' una pila in cui ogni elemento e\' un "<<this->forma<<endl;
		Pila::print();
	}
	
	void PilaOgg::fileprint(ofstream & of)
	{
		for(int i=0; i<get_nelem(); i++)
		{
			of << vet[i]<<endl;
		}
		return;
	}
	
	
	
}
