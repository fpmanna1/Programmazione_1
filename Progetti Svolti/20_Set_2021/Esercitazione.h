#ifndef ESERCITAZIONE_H
#define ESERCITAZIONE_H

#include "Tutorial.h"

namespace MS{
	class Esercitazione : public Tutorial{
		
		friend ostream & operator<<(ostream &, const Esercitazione &);
		friend istream & operator>>(istream &, Esercitazione &);
		
		private:
			int max;
			char * descrizione;
		public:
			Esercitazione();
			Esercitazione(const char [5] , const char *, Docente * , int, const char *);
			Esercitazione(const Esercitazione &);
			~Esercitazione(){delete[] descrizione;}
			
			const Esercitazione & operator=(const Esercitazione &);
			
			const int get_max()const{return max;}
			const char * get_des()const{return descrizione;}
			
			void set_max(int m){max=m;}
			void set_des(const char * d)
			{
				delete[] descrizione;
				descrizione = new char[strlen(d)+1];
				strcpy(descrizione, d);
			}
			
			ostream & print(ostream &)const;
			istream & input(istream &);
	};
}

#endif
