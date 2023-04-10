#ifndef VOCE_H
#define VOCE_H

#include <iostream>
#include <cstring>

using std::istream;
using std::ostream;
using std::endl;

namespace MS{
	class Voce{
		friend ostream & operator<<(ostream &, const Voce &);
		friend istream & operator>>(istream &, Voce &);
		private:
			int codice;
			char * tipo;
			float prezzo;
			
		public:
			Voce();
			Voce(const int, const char *, const float );
			virtual ~Voce(){delete[] tipo;}
			Voce(const Voce &);
			
			const Voce & operator=(const Voce &);
			
			const int get_codice()const{return codice;}
			const char * get_tipo()const{return tipo;}
			const float get_prezzo()const{return prezzo;}
			
			virtual ostream & print(ostream &)const;
			virtual istream & input(istream &);
	};
}




#endif
