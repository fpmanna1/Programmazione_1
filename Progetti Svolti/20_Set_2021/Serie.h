#ifndef SERIE_H
#define SERIE_H

#include "Tutorial.h"
#include "Errore.h"

using MS::Errore;
using MS::Tutorial;
using std::ofstream;
using std::endl;

typedef Tutorial T;

namespace MS{
	class Serie{
		friend ostream & operator<<(ostream &, const Serie &);
	
		private:
			string titolo;
			struct nodo;
			struct nodo{
				T elem;
				nodo* next;
			};
			nodo * testa;
			
		public:
			Serie(const string & tit = "mondo tutorial") : titolo(tit), testa(0){}
			~Serie(){
				nodo * temp = testa;
				while(temp!=NULL)
				{
					temp=testa;
					testa=testa->next;
					delete temp;
				}
			}
			
			ostream & print(ostream &)const throw(Errore);
			
			void insert(const T & );
			bool inlist(const char *);
			
			void store(ofstream & OutFile)
			{
				OutFile.open("./prova.txt");
				print(OutFile);
				OutFile.close();
			}
	};
}

#endif

