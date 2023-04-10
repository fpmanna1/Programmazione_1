#ifndef BANCOMAT_H
#define BANCOMAT_H

#include "Carta.h"
#include "Data.h"
#include "Carta.h"

using MS::Data;
using std::string;

namespace MS{
	
	class Bancomat : public Carta{
		friend ostream & operator<<(ostream &, const Bancomat &);
		friend istream & operator>>(istream &, Bancomat &);
		
		private:
			char * pin;
			bool attivata;
			Data scadenza;
			
			void set_pin(const char * p){
				delete [] pin;
				pin = new char[strlen(p)+1];
				strcpy(pin, p);
			}
				
		public:
			Bancomat(const char * = "", const char * = "", const char * ="", bool = false);
			Bancomat(const Bancomat &);
			~Bancomat(){delete [] pin;}
			
			virtual ostream & print(ostream &)const;
			virtual istream & input(istream &);
			const Bancomat & operator=(const Bancomat &);
			
			const Data & get_scadenza()const{return this->scadenza;}
			void set_scadenza(const Data & d){
				//scadenza.set_giorno(d.get_giorno());
				//scadenza.set_mese(d.get_mese());
				//scadenza.set_anno(d.get_anno());
				scadenza=d;
			}
			
			void attiva();
			virtual bool check(const char *) throw(Eccezione);
					
	};
}


#endif
