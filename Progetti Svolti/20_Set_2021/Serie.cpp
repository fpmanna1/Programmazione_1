#include "Serie.h"
#include "Tutorial.h"

namespace MS{
	
	ostream & Serie::print(ostream & out)const throw(Errore)
	{
		nodo * temp = testa;
		out << titolo;
		while(temp)
		{
			if(!temp->elem.check())
				throw Errore("c'è un codice non corretto!");   
			temp=temp->next;
		} 
		temp = testa;
		while(temp!=NULL)
		{
			temp->elem.print(out);
			temp=temp->next;
			out<<endl;
		}
		return out;
	}
	
	ostream & operator<<(ostream & out, const Serie & s)
	{
		return s.print(out);
	}
	
	void Serie::insert(const T & t)
	{
		if(!inlist(t.get_codice()))
		{
			nodo * q = new nodo();
			q->elem = t;
			q->next = testa;
			testa = q;
		}else
			throw Errore("impossibile inserire elemento: codice gia' presente!");
	}
	
	bool Serie::inlist(const char * c)
	{
		nodo * temp = new nodo();
		temp=testa;
		while(temp!=NULL)
		{
			if(strcmp(c, temp->elem.get_codice()) == 0) //se le due stringhe sono uguali
				return true;
			temp = temp->next;
		}
		return false;
	}
	
}
