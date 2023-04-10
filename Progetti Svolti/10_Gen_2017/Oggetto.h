#ifndef OGGETTO_H
#define OGGETTO_H

#include <iostream>
#include <cstring>

using std::cout;
using std::endl;
using std::istream;
using std::ostream;

namespace MS{
	class Oggetto{
		friend ostream & operator<<(ostream &, const Oggetto &);
		friend istream & operator>>(istream &, Oggetto &);
		private:
			int codice;
			char* descrizione;
			char* forma;
		protected:
			virtual ostream & print(ostream &)const;
			virtual istream & input(istream &);
		public:
			Oggetto(const int & = 1234, const char * = "Pala", const char * = "Rotonda");
			Oggetto(const Oggetto &);
			virtual ~Oggetto(){delete[] descrizione; delete[] forma;}
			
			const Oggetto & operator=(const Oggetto &);
			
			bool operator==(const Oggetto &)const;
			bool operator!=(const Oggetto &)const;
			
			void set_codice(int c){codice=c;}
			void set_descrizione(const char * des){
				delete[] descrizione;
				descrizione = new char[strlen(des)+1];
				strcpy(descrizione, des);}
			void set_forma(const char * f){
				delete[] forma;
				forma = new char[strlen(f)+1];
				strcpy(forma, f);
			}
			
			int get_codice()const{return codice;}
			const char * get_descrizione()const{return descrizione;}
			const char * get_forma()const{return forma;}
	};
}



#endif
