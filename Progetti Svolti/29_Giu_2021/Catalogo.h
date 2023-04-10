#ifndef CATALOGO_H
#define CATALOGO_H

#include "Scheda.h"
#include "Errore.h"
#include <fstream>

using MS::Scheda;
using std::endl;
using std::ofstream;

typedef Scheda* T;

namespace MS{
	class Catalogo{
			friend ostream & operator<<(ostream &, const Catalogo &); //deve stampare anche su file
		private:
			static const int dim = 20;
			T* vet; //vettore dinamico di puntatori a scheda
			char * titolo;
			int nelem;
			
		public:
			Catalogo() : nelem(0){
				vet = new T[dim];
			};
			~Catalogo(){delete[] vet;}
			bool empty()const{return nelem==0;}
			bool full()const{return dim==nelem;}
			bool insert(Scheda * ) throw(Errore);
			bool inlist(const char *);
			
			ostream & print(ostream &)const;
	};
}

#endif
