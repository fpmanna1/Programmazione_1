#include "Elenco.h"

namespace MS{
	bool Elenco::push(const T & t) throw(Errore)
	{
		if(full()==true) return false;
		if(inlist(t)==true) throw Errore("Inserimento non riuscito, biglietto gia' presente!");
		nodo* temp= new nodo;
		temp->elem = t;
		temp->next=testa;
		testa=temp;
		return true;
	}
	
	bool Elenco::inlist(const Biglietto & b)const
	{
		if(empty()==true) return false;
		nodo* temp = testa;
		while(temp!=NULL)
		{
			if(temp->elem == b)
				return true;
			temp=temp->next;
		}
		return false;
	}
	
	ostream & Elenco::print(ostream & out)const
	{
		nodo* temp = testa;
		short int i=1;
		while(temp!=NULL)
		{
			out << "------BIGLIETTO NUM."<<i<<"------------"<<endl;
			out << temp->elem;
			temp=temp->next;
			out << endl;
			i++;
		}
		return out;
	}
	
	ostream & operator<<(ostream & out, const Elenco & e)
	{
		return e.print(out);
	}
	
	void Elenco::store()const
	{
		ofstream file;
		file.open("./data.txt");
		if(!file)
			cout << "Errore nell'apertura del file!"<<endl;
			else
				print(file);
		file.close();
	}
}
