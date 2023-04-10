#ifndef LIBRO_H
#define LIBRO_H

#include "Oggetto.h"

namespace MS{
	class Libro : public Oggetto{
		friend ostream & operator<<(ostream &, const Libro &);
		friend istream & operator>>(istream &, Libro &);
		private:
			char* titolo;
			int pagine;
		protected:
			virtual ostream & print(ostream & )const;
			virtual istream & input(istream &);
		public:
			Libro(const int & = 1234, const char * = "Martello", const char * = "Quadrato", const char * = "Codice Da Vinci", const int & = 200);
			Libro(const Libro &);
			virtual ~Libro(){delete[] titolo;}
			
			const Libro & operator=(const Libro &);
			
			void set_pagine(int p){pagine=p;}
			void set_titolo(const char * t)
			{
				delete[] titolo;
				titolo = new char[strlen(t)+1];
				strcpy(titolo, t);
			}
			
			int get_pagine()const{return pagine;}
			const char * get_titolo()const{return titolo;}
			
			bool operator==(const Libro &)const;
			
	};
}


#endif
