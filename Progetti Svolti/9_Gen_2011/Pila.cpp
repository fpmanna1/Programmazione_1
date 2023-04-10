#include "Pila.h"

namespace MS{
	bool Pila::push(const T & t)
	{
		if(full()) return false;
		nodo * temp = new nodo;
		temp->elem = t;
		temp->next = testa;
		testa=temp;
		return true;
	}
	
	bool Pila::pop(const T &)
	{
		if(empty()) return false;
		nodo * temp = testa;
		T elem = temp->elem;
		testa = testa->next;
		delete temp;
		return true;
	}
	
	const T & Pila::top()const
	{
		if(!empty())
			return(testa->elem);
	}
	
	ostream & operator<<(ostream & out, const Pila & p)
	{
		return p.print(out);
	}
	
	ostream & Pila::print(ostream & out)const
	{
		cout << "-----STAMPA DELLA PILA -----"<<endl;
		nodo * temp = testa;
		while(temp)
		{
			out << temp->elem<<endl;
			temp=temp->next;
		}
		return out;
	}
	
	void Pila::leggidafile(ifstream & in)
	{
		T t;
		int num;
		in.open("./dati.txt");
		if(in) throw FileExcep("errore nell'apertura del file!");
		nodo* temp = new nodo;
		temp=testa;
		while(in.eof())
		{
			//in >> t.get_codice() >> t.get_peso() >> num >> t.get_indirizzo();
			in >> t;
			push(t);
			temp = temp->next;
		}
		in.close();
	}
	
	
}
