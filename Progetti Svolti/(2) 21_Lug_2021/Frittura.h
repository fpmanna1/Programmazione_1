#ifndef FRITTURA_H
#define FRITTURA_H

#include "Voce.h"

namespace MS{
	class Frittura : public Voce{
		friend ostream & operator<<(ostream & out, const Frittura & f){return f.print(out);}
		friend istream & operator>>(istream & in, Frittura & f){return f.input(in);}
		private:
			string ingrediente;
		protected:
			virtual ostream & print(ostream & out)const{
				Voce::print(out);
				out << "-----STAMPA DATI FRITTURA------"<<endl;
				out << "INGREDIENTE : "<<ingrediente<<endl;
				return out;
			}
			virtual istream & input(istream & in){
				Voce::input(in);
				cout << "Inserisci l'ingrediente principale : ";
				in >> ingrediente;
				return in;
			}
		public:
			Frittura(const int & cod = 234, const char * piatt = "Primo", const float &  cos = 4.6, const string & ing = "Patate") : Voce(cod, piatt, cos), ingrediente(ing){}
	};
}


#endif
