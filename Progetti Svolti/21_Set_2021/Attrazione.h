#ifndef ATTRAZIONE_H
#define ATTRAZIONE_H

#include <cstring>
#include <iostream>
#include <string>

using std::string;
using std::istream;
using std::ostream;
using std::cout;
using std::endl;

namespace MS{
	class Attrazione{
		friend ostream & operator<<(ostream &, const Attrazione &);
		friend istream & operator>>(istream &, Attrazione &);
		protected:
			char * nome;
			float costo;
			virtual ostream & print(ostream &)const;
			virtual istream & input(istream &);
		public:
			Attrazione();
			Attrazione(const char * , const float &);
			Attrazione(const Attrazione &);
			virtual ~Attrazione();
			
			const Attrazione & operator=(const Attrazione &);
			
			void set_nome(const char * n)
			{
				delete[] nome;
				n = new char[strlen(n)+1];
				strcpy(nome, n);
			}
			
			void set_costo(const float & c){costo = c;}
			
			const char * get_Nome()const{return nome;}
			const float & get_Costo()const{return costo;}
			
			virtual bool acquista_biglietto(string ) = 0;
			virtual double calcolo_incasso()const = 0;
	};
}


#endif
