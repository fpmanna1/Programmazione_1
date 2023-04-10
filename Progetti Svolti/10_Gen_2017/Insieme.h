#ifndef INSIEME_H
#define INSIEME_H

#include "Oggetto.h"
#include "bad_item.h"
#include <fstream>

using std::ofstream;
using std::ifstream;
using MS::Oggetto;

typedef Oggetto* T;

namespace MS{
	class Insieme{
		friend ostream & operator<<(ostream & out, const Insieme &);
		private:
			T* vet; // vettore allocato dinamicamente di puntatori a prodotto
			int dim;
			int nelem;
		protected:
			virtual ostream & print(ostream & out)const;
		public:
			explicit Insieme(const int & dim) : dim(dim), nelem(0){
				vet = new T[dim];
			}
			~Insieme(){delete[] vet;}
			Insieme(const Insieme &);
			
			const Insieme & operator=(const Insieme &);
			
			int get_dim()const{return dim;}
			int get_nelem()const{return nelem;}
			
			bool inlist(const T)const;
			
			bool push(const T) throw (bad_item);
			bool pop();
			bool full()const{return dim==nelem;}
			bool empty()const{return nelem==0;}
			
			void store()const;
			void leggidafile();
			
			const Insieme & intersezione(const Insieme & )const;
			const Insieme & unione(const Insieme &)const;
	};
}

#endif
