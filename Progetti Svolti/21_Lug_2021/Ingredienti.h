#ifndef INGREDIENTI_H
#define INGREDIENTI_H

#include "Errore.h"
#include <iostream>

using std::istream;
using std::ostream;
using std::endl;
using std::cout;

namespace MS{
	class Ingredienti{
		friend ostream & operator<<(ostream &, const Ingredienti &);
		
		private:
			struct nodo;
			struct nodo{
				string elem;
				nodo * next;
			};
			nodo * testa;
			
		public:
			Ingredienti() : testa(0){}
			Ingredienti(const Ingredienti & i);
			/*{
				nodo * temp = new nodo;
				temp = i.testa;
				nodo * temp2 = new nodo;
				while(temp!=NULL)
				{
					temp2->elem = temp->elem;
					push(temp2->elem);
					temp = temp->next;
				}	
			}  */	
		
			virtual ~Ingredienti();
			
			
			const Ingredienti & operator=(const Ingredienti &);  
			
			virtual void push(const string &) throw (Errore);
			bool inlist(const string &)const;
			
			virtual ostream & print(ostream &)const;
	};
}



#endif
