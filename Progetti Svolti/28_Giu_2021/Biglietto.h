#ifndef BIGLIETTO_H
#define BIGLIETTO_H

#include "Evento.h"

namespace MS{
	class Biglietto{
		friend ostream & operator<<(ostream &, const Biglietto &);
		friend istream & operator>>(istream &, Biglietto &);
		private:
			int codice;
			float costo;
			Evento* evento; // contenimento lasco
		protected:
			virtual ostream & print(ostream &)const;
			virtual istream & input(istream &);
		public:
			Biglietto(const int & = 1234, const float & = 5.0, Evento* = 0);
			
			bool operator==(const Biglietto & b)const;
			
			const int & get_codice()const{return codice;}
			const float & get_costo()const{return costo;}
			const Evento & get_evento()const{return *evento;}
			
			
	};
}


#endif
