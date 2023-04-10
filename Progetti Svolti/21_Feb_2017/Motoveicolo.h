#ifndef MOTOVEICOLO_H
#define MOTOVEICOLO_H

#include "Veicolo.h"

namespace MS{
	
	class Motoveicolo : public Veicolo{
		
		friend ostream & operator<<(ostream &, const Motoveicolo &);
		friend istream & operator>>(istream &, Motoveicolo &);
		
		private:
			char cavalletto;
			
		public:
			Motoveicolo() : Veicolo(), cavalletto('l'){}
			Motoveicolo(const string & ma, const string & mod, int pot, int c, int cav) : Veicolo(ma, mod, pot, c), cavalletto(cav){}
			
			virtual ostream & print(ostream &)const;
			virtual istream & input(istream &);
			
			virtual float calcolo_tassa()const;
			
			bool operator==(const Motoveicolo & m){return (Veicolo::operator==(m) && cavalletto == m.cavalletto) ;}
	};
}


#endif
