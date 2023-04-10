#ifndef VOCE_H
#define VOCE_H

#include <iostream>
#include <cstring>

using std::cout;
using std::endl;
using std::ostream;
using std::istream;

namespace MS{
	class Voce{
		friend ostream & operator<<(ostream & out, const Voce &);
		friend istream & operator>>(istream &, Voce &);
		private:
			int codice;
			char* piatto;
			float costo;
		protected:
			virtual ostream & print(ostream &)const;
			virtual istream & input(istream &);
		public:
			Voce(const int & = 234, const char * = "Primo", const float & = 4.6);
			Voce(const Voce &);
			virtual ~Voce(){delete[] piatto;}
			
			const Voce & operator=(const Voce &);
			
			void set_codice(int c){codice=c;}
			void set_piatto(const char * p){
				delete[] piatto;
				piatto = new char[strlen(p)+1];
				strcpy(piatto, p);
			}
			void set_costo(float c){costo=c;}
			
			int get_codice()const{return codice;}
			const char * get_piatto()const{return piatto;}
			float get_costo()const{return costo;}
	};
}


#endif
