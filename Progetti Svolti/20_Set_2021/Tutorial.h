#ifndef TUTORIAL_H
#define TUTORIAL_H

#include "Docente.h"
#include <cstring>

namespace MS{
	class Tutorial{
		friend ostream & operator<<(ostream &, const Tutorial &);
		friend istream & operator>>(istream &, Tutorial &);
		
		private:
			char codice[5];
			char * titolo;
			Docente * tutor;
			
		public:
			Tutorial();
			Tutorial(const char [5] , const char *, Docente * );
			Tutorial(const Tutorial &);
			~Tutorial(){delete[] titolo;}
			
			ostream & print(ostream &)const;
			istream & input(istream &);
			
			const Tutorial & operator=(const Tutorial &);
			
			const char * get_codice()const{return codice;}
			
			virtual bool check()const;
			
			const char * get_titolo()const{return titolo;}
			const Docente get_tutor()const{return *tutor;}
			
			void set_codice(const char c[10]){strcpy(codice, c);}
			void set_titolo(const char * t)
			{
				delete[] titolo;
				titolo = new char[strlen(t)+1];
				strcpy(titolo, t);
			}
			void set_tutor(Docente * t){*tutor=*t;}
			
	};
}

#endif
