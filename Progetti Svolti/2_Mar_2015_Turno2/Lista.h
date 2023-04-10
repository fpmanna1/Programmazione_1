#ifndef LISTA_H
#define LISTA_H

#include "Processo.h"
#include "Eccezione.h"

using std::ofstream;

namespace MS{
	typedef Processo P;
	
	class Lista{
		private:
			struct nodo;
			struct nodo{
				P elem;
				nodo* next;
			};
			nodo * testa;
			bool full()const{return false;} //una coda non può essere piena, la mantengo per una questione di compatibilità
		public:
			Lista(){testa=0;}
			~Lista();
			bool insertTesta(const P&) throw (Eccezione);
			bool insertCoda(const P&) throw (Eccezione);
			
			bool empty()const{return testa==0;}
			bool rimuoviTesta(P & ); //nel caso mi interessa il valore tolto
			bool rimuoviCoda(P & );
			bool estrazione(P & );
			bool assenza();
			int getP()const;
			bool show()const;
			bool inlist(const P&  )const;
			void store(ofstream &);
	};
}





#endif
