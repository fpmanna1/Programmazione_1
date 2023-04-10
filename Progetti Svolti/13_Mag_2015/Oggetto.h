#ifndef OGGETTO_H
#define OGGETTO_H

#include <cstring>
#include <fstream>

using std::istream; using std::ostream;

namespace MS{
	
	class Oggetto{
		
		friend ostream & operator<<(ostream &, const Oggetto &);
		friend istream & operator>>(istream &, Oggetto &);
		
		private:
			int codice;
			char * descrizione;
			char * forma;
		public:
			Oggetto(const int = 0000, const char * = "*", const char * = "*");
			Oggetto(const Oggetto &);
			virtual ~Oggetto(){delete [] descrizione, delete [] forma;}
			
			const Oggetto & operator=(const Oggetto &);
			
			int get_codice()const{return this->codice;}
			const char * get_descrizione()const{return this->descrizione;}
			const char * get_forma()const{return this->forma;}
			
			void set_codice(int c){codice=c;}
			void set_descrizione(const char * d){
				delete [] descrizione;
				descrizione = new char[strlen(d)+1];
				strcpy(descrizione,d);
			}
			void set_forma(const char * f){
				delete[] forma;
				forma = new char[strlen(f)+1];
				strcpy(forma,f);
			}
	};
}

#endif
