#ifndef AUTOVEICOLO_H
#define AUTOVEICOLO_H

#include "Veicolo.h"

namespace MS{
	
	class Autoveicolo : public Veicolo{
		
		friend ostream & operator<<(ostream &, const Autoveicolo &);
		friend istream & operator>>(istream &, Autoveicolo &);
		
		private:
			int num_porte;
			
		public:
			Autoveicolo() : Veicolo(), num_porte(4){}
			Autoveicolo(const string & ma, const string & mod, int pot, int c, int np) : Veicolo(ma, mod, pot, c), num_porte(np){}
			
			virtual float calcolo_tassa()const;
			
			virtual ostream & print(ostream &)const;
			virtual istream & input(istream &);
			
			bool operator==(const Autoveicolo &a){return (Veicolo::operator==(a) && num_porte == a.num_porte);}
	};
}


#endif
