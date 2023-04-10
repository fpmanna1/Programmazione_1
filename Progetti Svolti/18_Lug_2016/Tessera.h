#ifndef TESSERA_H
#define TESSERA_H

#include "Carta.h"
#include "Data.h"

namespace MS{
	
	class Tessera : public Carta{
		
		friend ostream & operator<<(ostream &, const Tessera &);
		
		private:
			char * CF;
			Data DataRilascio;
			Data DataScadenza;
			
		public:
			Tessera(const char * = "", const char * = "", const char * = "", const char * = "");
			Tessera(const Tessera &);
			~Tessera(){delete [] CF;}
				
			virtual bool check(const char * );
			
			ostream & print(ostream &)const;
			
			void set_CF(const char *);
			void set_DataRilascio(const Data &d){DataRilascio=d;}
			void set_DataScadenza(const Data &d){DataScadenza=d;}
			
			const char * get_CF()const{return CF;}
			const Data & get_DataRilascio(){return DataRilascio;}
			const Data & get_DataScadenza(){return DataScadenza;}
			
			const Tessera & operator=(const Tessera &);
	};
	
}

#endif
