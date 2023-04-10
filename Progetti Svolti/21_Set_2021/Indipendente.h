#ifndef INDIPENDENTE_H
#define INDIPENDENTE_H

#include "Attrazione.h"

namespace MS{
	class Indipendente : public Attrazione{
		friend ostream & operator<<(ostream &, const Indipendente &);
		private:
			char * titolare;
			int incasso_corrente;
		protected:
			virtual ostream & print(ostream &)const;
		public:
			Indipendente();
			Indipendente(const char *, const float &, const char *, const int &);
			Indipendente(const Indipendente &);
			virtual ~Indipendente(){delete[] titolare;}
			
			const Indipendente & operator=(const Indipendente &);
			
			virtual bool acquista_biglietto(string );
			virtual double calcolo_incasso()const;
			
			void set_titolare(const char * t){
				delete[] titolare;
				titolare = new char[strlen(t)+1];
				strcpy(titolare, t);
			}

	};
}


#endif
