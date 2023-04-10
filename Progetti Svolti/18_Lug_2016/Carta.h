#ifndef CARTA_H
#define CARTA_H

#include <cstring>
#include <fstream>
#include "Eccezione.h"

using std::ostream;
using std::istream;
using MS::Eccezione;

namespace MS{
	
	class Carta{
		friend ostream & operator<<(ostream &, const Carta &);
		friend istream & operator>>(istream &, Carta &);
		
		private:
			char * tipo;
			char * intestatario;
			char * numero_carta; //le prime 5 cifre devono essere numeri
			
		public:
			Carta(const char * = "", const char * = "", const char * ="");
			Carta(const Carta &);
			~Carta(){delete [] tipo; delete [] intestatario; delete [] numero_carta;}
			
			const Carta & operator=(const Carta &);
			
			void set_tipo(const char * t){strcpy(tipo,t);}
			void set_intestatario(const char * i){strcpy(intestatario, i);}
			void set_numero_carta(const char * nc){strcpy(numero_carta,nc);}
			
			const char * get_tipo()const{return tipo;}
			const char * get_intestatario()const{return intestatario;}
			const char * get_numero_carta()const{return numero_carta;}
			
			virtual ostream & print(ostream &)const;
			virtual istream & input(istream &);
			
			virtual bool check(const char *)=0;
			bool formato() throw (Eccezione);
	};
	
}


#endif
