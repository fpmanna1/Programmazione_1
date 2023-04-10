#ifndef LISTA_H
#define LISTA_H

#include "Errore.h"
#include <iostream>

using std::istream;
using std::ostream;
using std::endl;
using std::cout;

typedef string T;

namespace MS{
	class Lista{
		friend ostream & operator<<(ostream & out, const Lista &);
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
			virtual ostream & print(ostream &)const;
		public:
			Lista() : testa(0){}
			Lista(const Lista &);
			virtual ~Lista(){
				nodo* temp;
				while(testa)
				{
					temp=testa;
					testa=testa->next;
					delete temp;
				}
			}
			
			void elimina();
			
			const Lista & operator=(const Lista &);
			
			bool inlist(const T &)const;
			bool push(const T &) throw (Errore);
	};
}


#endif
