#ifndef RIUNIONE_H
#define RIUNIONE_H

#include "Evento.h"
#include "Elenco.h"

namespace MS{
	class Riunione : public Evento{
		friend ostream & operator<<(ostream &, const Riunione &);
		private:
			char * luogo;
			Elenco e; 
		protected:
			ostream & print(ostream &)const;
		public:
			Riunione(const char * = "unknown", const int & = 2, const int & = 30, const char * = "Napoli",const int & = 4);
			Riunione(const Riunione &);
			
			const Riunione & operator=(const Riunione &);
			
			void set_luogo(const char * l)
			{
				delete[] luogo;
				luogo = new char[strlen(l)+1];
				strcpy(luogo, l);
			}
			
			const char * get_luogo()const{return luogo;}
			
			Elenco & get_elenco(){return e;}
	};
}


#endif
