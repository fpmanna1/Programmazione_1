#ifndef CODA_H
#define CODA_H

#include "Eccezione.h"
#include "Veicolo.h"

using std::cout;
using std::endl;

namespace MS{
	typedef Veicolo* T;
	class Coda{
		friend ostream & operator<<(ostream &, const Coda &);
		
		private:
			static const int dim = 30;
			T* vet; //vettore di puntatori a veicolo allocato dinamicamente
			int testa;
			int coda;
			int nelem;
			
		public:
			Coda() : testa(0), coda(0), nelem(0){ //nota: mettere nel costruttore la dim in modo che l'utente possa sceglierla
				vet = new T[dim];
			}
			~Coda(){delete [] vet;}
			Coda(const Coda &);
			const Coda & operator=(const Coda &);
			bool empty()const{return nelem==0;}
			bool full()const{return nelem==dim;}
			bool insert(const T &) throw (Eccezione);
			bool pop();
			
			virtual ostream & print(ostream &)const;
			
			bool ricerca(const T &)const;
		
	};
}

#endif
