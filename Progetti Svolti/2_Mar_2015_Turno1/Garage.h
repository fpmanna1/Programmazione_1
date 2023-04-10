#ifndef GARAGE_H
#define GARAGE_H

#include "Veicolo.h"
#include "Eccezione.h"
#include <fstream>

using std::ofstream;
using MS::Veicolo;

typedef Veicolo* T; 

namespace MS{
	class Garage{
		friend ostream & operator<<(ostream &, const Garage &);
		private:
			static const int dim = 20;
			T vet[dim]; //è un vettore di puntatori allocato staticamente
			int nelem;
			virtual ostream & print(ostream & )const;
		public:
			Garage() : nelem(0){}
			
			int get_nelem()const{return nelem;}
			
			bool full()const{return nelem==dim;}
			bool empty()const{return nelem==0;}
			
			int insert(Veicolo* v) throw(Eccezione);
			
			bool estrazione(const int &);
			
			void store(ofstream & );
	};
}

#endif
