#ifndef FARMACO_H
#define FARMACO_H

#include "Data.h"
#include <cstring>
#include "Eccezioni.h"
using std::ostream; using std::istream;

namespace MyNS{

class Farmaco{
	friend ostream & operator<<(ostream & , const Farmaco & );
	friend istream & operator>>(istream &, Farmaco &);
	
	private:
		char * nome;
		char * pa;
		float costo;
		Data scadenza;
		
	public:
		Farmaco(); //COSTRUTTORE SENZA ARGOMENTI
		Farmaco(const char * ="", const char * ="", const float = 0.0, const Data & =0); //COSTRUTTORE CON ARGOMENTI E PARAMETRI DI DEFAULT
		Farmaco(const Farmaco &); //COSTRUTTORE DI COPIA
		virtual ~Farmaco(){delete [] nome; delete [] pa;} //DISTRUTTORE
		
		
		//GETTERS AND SETTERS
		const char * get_Nome()const{return this->nome;}
		const char * get_Pa()const{return this->pa;}
		float get_Costo()const{return this->costo;};
		Data get_Data()const{return this->scadenza;};
		void set_Nome(char * n)
		{
			delete this->nome;
			nome=new char[strlen(n)+1];
			strcpy(nome,n);
		}
		void set_Pa(char * PrA)
		{
			delete pa;
			pa=new char[strlen(PrA)+1];
			strcpy(pa, PrA);
		}
		
	//	bool check_data(const Data &) const throw(Eccezione);
		
		virtual float calc_cost() const = 0;
		bool check_data(const Data & ) const throw(Eccezioni);
		
		
		
};

}

#endif

