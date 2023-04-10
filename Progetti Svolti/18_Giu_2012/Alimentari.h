#ifndef ALIMENTARI_H
#define ALIMENTARI_H

#include <iostream>
#include <cstring>
#include <fstream>

using std::ofstream;
using std::cin;
using std::cout;
using std::endl;
using std::ostream;
using std::istream;

namespace MS{
	
	class Alimentari{
		
		friend ostream & operator<<(ostream &, const Alimentari &);
		friend istream & operator>>(istream &, Alimentari &);
		
		protected:
			char * codice;
			char * descrizione;
			int MeseScadenza;
			float costo;
			
		public:
			Alimentari();
			Alimentari(const char *, const char *, int, float);
			Alimentari(const Alimentari &);
			~Alimentari(){delete[] codice; delete [] descrizione;}
			
			const Alimentari & operator=(const Alimentari &);
			
			void set_codice(const char *);
			void set_descrizione(const char *);
			void set_MeseScadenza(int ms){MeseScadenza=ms;};
			void set_costo(float c){costo=c;}
			
			virtual ostream & stampa(ostream &)const;
			virtual istream & input(istream &);
			virtual void store(ofstream & )const;
			
			const char * get_codice()const{return codice;}
			
			virtual void offerta() =0;
	};
}


#endif
