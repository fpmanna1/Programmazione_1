#ifndef PACCO_H
#define PACCO_H

#include <fstream>
#include <cstring>
#include <iostream>

using std::istream;
using std::ostream;
using std::endl;
using std::cout;

namespace MS{
	class Pacco{
		friend ostream & operator<<(ostream &, const Pacco &);
		friend istream & operator>>(istream &, Pacco &);
		private:
			int codice;
			float peso;
			char* indirizzo;
		protected:
			ostream & print(ostream &)const;
			istream & input(istream &);
		public:
			Pacco(const int & = 123, const float & = 5.5, const char * = "Via Roma");
			Pacco(const Pacco &);
			~Pacco(){delete[] indirizzo;}
			
			const Pacco & operator=(const Pacco &);
			
			void set_codice(int c){codice=c;}
			void set_peso(float p){peso=p;}
			void set_indirizzo(const char * i){
				delete[] indirizzo;
				indirizzo = new char[strlen(i)+1];
				strcpy(indirizzo, i);
			}
			
			int get_codice()const{return codice;}
			float get_peso()const{return peso;}
			const char * get_indirizzo()const{return indirizzo;}
	};
}

#endif
