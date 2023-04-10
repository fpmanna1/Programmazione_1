#include "Lista.h"

namespace MS{
	Lista::Lista(const Lista & l){ 
		testa=0;
		nodo * temp = new nodo;
		temp=l.testa;
		while(temp!=NULL)
		{
			push(temp->elem);
			temp = temp->next;
		}
	}
	
	const Lista & Lista::operator=(const Lista & l)
	{
		if(this!=&l)
		{
			elimina();
			testa=0;
			nodo * temp = new nodo;
			temp=l.testa;
			while(temp!=NULL)
			{
				push(temp->elem);
				temp = temp->next;
			}
		}
		return *this;
	} 
	
	bool Lista::push(const T & s) throw (Errore)
	{
		if(!inlist(s))
		{
			nodo* temp = new nodo;
			temp->elem = s;
			temp->next=testa;
			testa=temp;
		}
		else	
			throw Errore("Elemento gia' presente");
		return false;
	}
	
	bool Lista::inlist(const T & s)const
	{
		nodo* temp = new nodo;
		temp=testa;
		while(temp!=NULL)
		{
			if(temp->elem == s)
				return true;
			temp=temp->next;
		}
		return false;
	}
	
	ostream & Lista::print(ostream & out)const
	{
		if(!empty()){
			out << "----STAMPA DELLA LISTA------"<<endl;
			nodo* temp = testa;
			while(temp)
			{
				out << temp->elem << endl;
				temp=temp->next;
			}
		}
		return out;
	}
	
	ostream & operator<<(ostream & out, const Lista & l)
	{
		return l.print(out);
	}
	
	void Lista::elimina()
	{
		nodo* temp;
		while(testa)
		{
			temp=testa;
			testa=testa->next;
			delete temp;
		}
	}
}
