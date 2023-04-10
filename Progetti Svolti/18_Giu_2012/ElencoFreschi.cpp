#include "ElencoFreschi.h"

namespace MS{
	
	ElencoFreschi::~ElencoFreschi()
	{
		nodo * temp;
		while(testa!=NULL)
		{
			temp=testa;
			testa=testa->next;
			delete temp;
		}
	}
	
	void ElencoFreschi::insert(T & t) throw(Duplicato) 
	{
		if(!inlist(t))
		{
			nodo * q= new nodo();
			q->elem=t;
			q->next=testa;
			testa=q;
		}else{
			throw Duplicato ("Codice gia' presente, e\' un duplicato!", t.get_codice());
		}
	}
	
	bool ElencoFreschi::inlist(const T & t)const
	{
		if(empty())
			return false;
		nodo * temp = testa;
		while(temp!=NULL)
		{
			if(strcmp(temp->elem.get_codice(),t.get_codice())==0)
				return true;
			temp=temp->next;
		}
		return false;
	}
	
	ostream & ElencoFreschi::show(ostream & out)const
	{
		if(!empty())
		{
			nodo * temp = testa;
			while(temp!=NULL)
			{
				out<<temp->elem<<endl;
				out<<endl;
				temp = temp-> next;
			}
		}
		return out;
	}
	
	void ElencoFreschi::store(ofstream & file)const
	{
		file.open("output_elenco.txt");
		show(file);
		file.close();
	}
	
	ostream & operator<<(ostream & out, const ElencoFreschi & e)
	{
		return e.show(out);	
	}
	
	void ElencoFreschi::elimina(const char * cod) //avrei potuto usare la inlist, ma avrei dovuto modificare il parametro di input
	{
		nodo * temp = new nodo();
		temp=testa;
		while(temp->next!=NULL)
		{
			if(strcmp(testa->elem.get_codice(), cod)==0)
			{
				//fai una pop
				nodo * temp5 = new nodo();
				temp5 = testa;
				testa=testa->next;
				delete temp5;
				
			}
			if(strcmp(temp->next->elem.get_codice(),cod)==0)
			{
				nodo * temp2 = temp; //elemento precedente rispetto a quello che voglio eliminare
				nodo * temp3 = temp->next; //elemento che voglio eliminare
				nodo * temp4 = temp->next->next; //elemento successivo rispetto a quello che voglio eliminare
				temp2->next=temp4;
				delete temp3;
				return;
			}
			temp=temp->next;
		}
	}
}
