#ifndef _PRODOTTO_H
#define _PRODOTTO_H

#include <iostream>
#include <cstring>
using namespace std;

class Prodotto{
	
	private:
		static const int DIM = 6;
		char Codice[DIM];
		char * Descrizione;
		
	public:
		//COSTRUTTORI E DISTRUTTORE
		//Prodotto(); //costruttore senza argomenti
		Prodotto(const char * = "", const char * = ""); //costruttore con argomenti
		Prodotto(const Prodotto &); //costruttore di copia
		~Prodotto(){delete [] this->Descrizione;} //distruttore
		
		//GETTERS AND SETTERS
		const char* get_Codice() const{return this->Codice;}
		const char* get_Descrizione() const{return this->Descrizione;}
		void set_Codice(const char *s){ strcpy(this->Codice, s);}
		void set_Descrizione(const char * s) 
		{
			delete [] Descrizione; 
			Descrizione=new char[strlen(s)+1];
			strcpy(this->Descrizione,s);
		}
			
		//OPERATORI
		bool operator==(const Prodotto &) const;
		bool operator!=(const Prodotto &) const;
		const Prodotto& operator=(const Prodotto &);
		
		friend ostream & operator<<(ostream &, const Prodotto &);
		friend istream & operator>>(istream &, Prodotto &);
		
		bool valido()const;
		
		bool duplicato();
	
};


#endif
