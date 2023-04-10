#ifndef ELENCO_H
#define ELENCO_H

#include "Partecipante.h"

using MS::Partecipante;

typedef Partecipante T;

namespace MS{
	class Elenco{
		friend ostream & operator<<(ostream &, const Elenco &);
		private:
			T* vet; //vettore di partecipanti allocato dinamicamente
			int dim;
			int nelem;
			
			bool full()const{return nelem==dim;}
			bool empty()const{return nelem==0;}
			bool inlist(T, int &)const;
			
		public:
			explicit Elenco(const int & d = 10) :dim(d), nelem(0)
			{
				vet = new T[dim];
			}
			
			Elenco(const Elenco & e) : dim(e.dim), nelem(e.nelem)
			{
				for(int i=0; i<dim; i++)
					vet[i] = e.vet[i];
			}
			
			~Elenco(){delete[] vet;}
			
			const Elenco & operator=(const Elenco &);
			
			bool insert(T );
			bool elimina(T);
			
			const Elenco & infinito();	
			
			const int & get_dim()const{return dim;}
			
			void set_nelem(const int & n){nelem=n;}
			
	};
}


#endif
