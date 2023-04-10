#ifndef ELENCOFRESCHI_H
#define ELENCOFRESCHI_H

#include <cstring>
#include "ProdottiFreschi.h"
#include "Duplicato.h"

using MS::ProdottiFreschi;
using MS::Duplicato;

namespace MS{
	
	typedef ProdottiFreschi T;
	
	class ElencoFreschi{
		
		friend ostream & operator<<(ostream &, const ElencoFreschi &);
		friend istream & operator>>(istream &, ElencoFreschi &);
		
		private:
			struct nodo;
			struct nodo{
				T elem;
				nodo* next;
			};
			nodo * testa;
			
		public:
			ElencoFreschi() : testa(0){}
			~ElencoFreschi();
			
			void insert(T & ) throw (Duplicato);
			bool inlist(const T &)const;
			bool full()const{return false;}
			bool empty()const{return testa==0;}
			virtual ostream & show(ostream &)const;
			void store(ofstream &)const;
			void elimina(const char * );
	};
}



#endif
