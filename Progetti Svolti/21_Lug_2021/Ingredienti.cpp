#include "Ingredienti.h"

namespace MS{
	Ingredienti::~Ingredienti()
	{
		nodo * temp = new nodo;
		while(temp)
		{
			temp = testa;
			testa = testa->next;
			delete temp;
		}
	}
	
	void Ingredienti::push(const string & s) throw (Errore)
	{
		nodo * q = new nodo;
		if(!inlist(s))
		{
			
			q->elem = s;
			q->next = testa;
			testa = q;
		}else{
			throw Errore("ingrediente gia' presente nella lista!");
		}
	}
	
	bool Ingredienti::inlist(const string & s)const
	{
		if(testa == 0) return false;
		nodo * temp = testa;
		while(temp!=NULL)
		{
			if(temp->elem == s)
			{
				delete temp;
				return true;
			}
			temp = temp->next;
		}
		delete temp;
		return false;
	}
	
	ostream & Ingredienti::print(ostream & out)const
	{
		nodo * temp = new nodo;
		temp = testa;
		int j=0;
		while(temp!=NULL)
		{
			out << j+1 << " : " <<temp->elem << endl;
			temp = temp->next;
			j++;
		}
		return out;
	}
	
	ostream & operator<<(ostream & out, const Ingredienti & i)
	{
		return i.print(out);
	}
	
	const Ingredienti & Ingredienti::operator=(const Ingredienti & i)
	{
		if(this!=&i)
		{
			nodo * temp = testa;
			nodo * temp2 = i.testa;
			while(temp2!=NULL)
			{
				push(temp2->elem);
				temp2 = temp2->next;
			}
		}
		return *this;
	}  
	
	/*Ingredienti::Ingredienti(const Ingredienti & i)
	{
		nodo * temp = testa;
		nodo * temp2 = i.testa;
		while(temp2!=NULL)
		{
			push(temp2->elem);
			temp2 = temp2->next;
		}
	} */
	
	
}
