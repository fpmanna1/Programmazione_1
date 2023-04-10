#ifndef ELENCO_H
#define ELENCO_H

#include "Biglietto.h"
#include "Errore.h"
#include <fstream>

using std::ofstream;
using MS::Biglietto;

typedef Biglietto T;

namespace MS{
	class Elenco{
		friend ostream & operator<<(ostream &, const Elenco &);
		private:
			struct nodo;
			struct nodo{
				T elem;
				nodo* next;
			};
			nodo* testa;
		protected:
			bool full()const{return false;}
			bool empty()const{return testa==0;}
			virtual ostream & print(ostream & )const;
		public:
			Elenco() : testa(0){}
			~Elenco()
			{
				nodo* temp = testa;
				while(temp!=NULL)
				{
					temp=testa;
					testa=testa->next;
					delete temp;
				}
			}
			bool push(const T &) throw (Errore);
			bool inlist(const Biglietto &)const;
			
			void store()const;
	};
}

#endif
