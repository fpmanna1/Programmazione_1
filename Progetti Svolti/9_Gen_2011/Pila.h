#ifndef PILA_H
#define PILA_H

#include "Pacco.h"
#include "FileExcep.h"

using std::ifstream;

typedef MS::Pacco T;

namespace MS{
	class Pila{
		friend ostream & operator<<(ostream &, const Pila &);
		private:
			struct nodo;
			struct nodo{
				T elem;
				nodo* next;
			};
			int nelem;
			nodo* testa;
		protected:
			ostream & print(ostream &)const;
		public:
			Pila() : nelem(0), testa(0){}
			~Pila(){
				nodo* temp;
				while(testa)
				{
					temp=testa;
					testa=testa->next;
					delete temp;
				}
			}
			
			bool push(const T &);
			bool pop(const T &);
			const T & top()const;
			bool empty()const{return testa==0;}
			bool full()const{return false;}
			
			void leggidafile(ifstream &);
	};
}


#endif
