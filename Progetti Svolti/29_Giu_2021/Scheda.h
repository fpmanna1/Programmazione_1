#ifndef SCHEDA_H
#define SCHEDA_H

#include "Autore.h"
#include "cstring"

using MS::Autore;

namespace MS{
	class Scheda{
		friend ostream & operator<<(ostream &, const Scheda &);
		friend istream & operator>>(istream &, Scheda &);
		
		private:
			char * titolo;
			char * descrizione;
			char * codice;
			Autore * autore;
			
		public:
			Scheda();
			Scheda(const char *, const char *, const char *, Autore *);
			Scheda(const Scheda &);
			virtual ~Scheda(){delete[] titolo; delete [] descrizione; delete [] codice; autore=0;}
			
			const Scheda & operator=(const Scheda &);
			
			void set_titolo(const char *);
			void set_descrizione(const char *);
			void set_codice(const char *);
			void set_autore(Autore* a){*autore = *a;}
			
			virtual ostream & print(ostream &)const;
			virtual istream & input(istream &);
			
			const char * get_codice()const{return this->codice;}
			const char * get_descrizione()const{return descrizione;}
			const char * get_titolo()const{return titolo;}
	};
}

#endif
