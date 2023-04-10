#ifndef SCHEDA_H
#define SCHEDA_H

#include <iostream>
#include <string>

#include "Attrazione.h"
#include "Eccezione.h"

using std::istream;
using std::ostream;
using std::string;
using std::cout;
using std::endl;

namespace MS{
	class Scheda{
		friend ostream & operator<<(ostream &, const Scheda &);
		friend istream & operator>>(istream &, Scheda &);
		private:
			string codice;
			int M; //valore minimo
			int X; //credito iniziale
			int corrente; //credito corrente
			
		protected:
			virtual ostream & print(ostream &)const;
			virtual istream & input(istream &);
		public:
			Scheda();
			Scheda(const string & , int , int , int );
			
			const string & get_Codice()const{return codice;}
			const int & get_M()const{return M;}
			const int & get_X()const{return X;}
			const int & get_Corrente()const{return corrente;}
			
			void decrementa(const int &) throw(Eccezione);
			
			bool operator==(const Scheda &);
	};
}

#endif
