#include "Lista.h"
using std::cout;

namespace MS{
	
	Lista::~Lista(){
		nodo * temp = new nodo;
		while(testa!=NULL)
		{
			temp=testa;
			testa=testa->next;
			delete temp;
		}
	}
	
	bool Lista::insertCoda(const P& p)throw (Eccezione){ //inserimento in coda (FIFO)
		if(full()) return false;
		if(empty()) {insertTesta(p); return true;}
		
		if(inlist(p)){
			throw Eccezione("elemento gia' in lista!\n");
			return false;
		}
		
		nodo * temp = testa; //creo un nodo temporaneo che mi permette di salvare il vecchio valore della testa
		while(temp->next!=NULL) //arrivo all'ultimo elemento della lista
			temp=temp->next;
		nodo * q=new nodo; //creo il nodo che verrà aggiunto in coda
		q->elem=p; //inserisco il processo nel nodo che poi andrà in coda
		q->next=0; //faccio in modo che sia l'ultimo elemento della coda
		temp->next=q; //il vecchio elemento in coda adesso punta la nuovo elemento in coda
		return true; //il bool è legato alla riuscita o meno dell'operazione
	}
	
	bool Lista::insertTesta(const P& p) throw(Eccezione)
	{
		if(full()) return false;
		
		if(inlist(p)){
			throw Eccezione("elemento gia' in lista!\n");
			return false;
		}
		
		nodo * q = new nodo;
		q->elem=p;
		q->next=testa;
		testa=q;
		return true;
	}
	
	bool Lista::estrazione(P& p)  //eliminazione dalla coda del primo processo pronto (quello più vecchio, più vicino alla testa)
	{
		nodo * temp=testa;
		if(empty() || assenza()) return false; //caso lista vuota
		nodo * pr=new nodo;
		if(temp->elem.get_stato()=='p' || temp->elem.get_stato()=='P')
		{
			rimuoviTesta(pr->elem); //caso con primo processo pronto in testa
			return true;
		}
		while(temp->next!=NULL)
		{
			if(temp->next->elem.get_stato()=='p' || temp->next->elem.get_stato()=='P')
			{
				nodo * temp1 = temp->next;
				temp->next=temp->next->next;
				delete temp;
				return true;
			}
			temp=temp->next;
		} 
		return true;
 	}

	bool Lista::assenza() //torna true se è assente un processo pronto
	{
		nodo * temp=testa;
		while(temp!=NULL)
		{
			if(temp->elem.get_stato()=='p' || temp->elem.get_stato()=='P')
				return false;
			temp=temp->next;
		}
		return true;
	}
	
	bool Lista::rimuoviTesta(P & p)
	{
		nodo * temp= new nodo;
		p=testa->elem;
		temp=testa;
		testa=testa->next;
		delete temp;
		return true;
	}
	
	int Lista::getP()const
	{
		nodo * temp = testa;
		int occorrenze;
		while(temp!=NULL)
		{
			if(temp->elem.get_stato()=='p' || temp->elem.get_stato()=='P')
			{
				occorrenze++;
			}
			temp=temp->next;
		}
		return occorrenze;
	}
	
	bool Lista::show()const
	{
		if(empty()) return false;
		nodo * temp=testa;
		while(temp)
		{
			cout << temp->elem << "\t" << endl;
			temp=temp->next;
		}	
		return true;
	}
	
	bool Lista::inlist(const P& p)const
	{
		nodo * temp = new nodo;
		temp=testa;
		while(temp!=NULL)
		{
			if(temp->elem == p)
				return true;
			temp=temp->next;
		}
		return false;
	}
	
	void Lista::store(ofstream &out)
	{ /*
		nodo * temp=testa;
		while(temp!=NULL)
		{
			//out <<(Processo &) temp->elem;
			out<<6;
			temp=temp->next;
		} */
	} 
	
	
	
	
	
	
	
}
