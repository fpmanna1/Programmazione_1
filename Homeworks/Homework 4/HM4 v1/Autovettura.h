#ifndef AUTOVETTURA_H
#define AUTOVETTURA_H

#include "Veicolo.h"

bool check_Classe(short int);

class Autovettura: public Veicolo{

	private:
		char * Modello;
		short int Classe;
		
	protected:
   		virtual ostream & write(ostream &) const;
    	virtual istream & read(istream &);
	
	public:
		//COSTRUTTORI
		Autovettura(const char * = "" , const char * = "" , const char * = "", short int =2);
		Autovettura(const Autovettura&);
		virtual double calcolo_Pedaggio()const;
		virtual ~Autovettura(){delete [] this->Modello;}
		
		//GETTERS AND SETTERS
		const char * get_Modello()const {return this->Modello; }
		short int get_Classe() const {return this->Classe;}
		void set_Modello(const char *);
		void set_Classe(short int C){if(check_Classe(C)) Classe = C;}
		
		//OPERATORI
		bool operator==(const Autovettura &A) const{return (Veicolo::operator==(A) && !strcmp(Modello, A.Modello) && Classe == A.Classe);}
		bool operator!=(const Autovettura &A) const{return !(*this==A);}
		bool operator>(const Autovettura &A) const{return (Classe>A.Classe);}
		bool operator<(const Autovettura &A) const{return (Classe<A.Classe);}
		const Autovettura& operator=(const Autovettura &);
		friend ostream & operator<<(ostream &out, const Autovettura &A)
		{return (A.write(out));}
		/*
			//operator<<(output, (Veicolo&)A);
			output << (Veicolo&)A;
			output << A.Modello;
			output << A.Classe;
			return output;
		
		*/
		friend istream & operator>>(istream &in, Autovettura &A){return(A.read(in));}
};


#endif
