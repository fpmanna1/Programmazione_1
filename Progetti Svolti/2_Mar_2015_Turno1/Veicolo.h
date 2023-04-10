#ifndef VEICOLO_H
#define VEICOLO_H

#include <iostream>
#include <fstream>
#include <cstring>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::istream;
using std::ostream;
using std::ofstream;
using std::string;

namespace MS{
	class Veicolo{
		friend ostream & operator<<(ostream &, const Veicolo &);
		friend istream & operator>>(istream &, Veicolo &);
		private:
			char * nome_tipo;
			char * marca;
		protected:
			virtual ostream & print(ostream &)const;
			virtual istream & input(istream &);
		public:
			Veicolo(const char * ="auto", const char * = "FIAT");
			Veicolo(const Veicolo &);
			virtual ~Veicolo(){delete[] nome_tipo; delete[] marca;}
			
			const Veicolo & operator=(const Veicolo &);
			
			const char * get_nome_tipo()const{return nome_tipo;}
			const char * get_marca()const{return marca;}
			
			virtual const char * totext() = 0;
			
			void set_nome_tipo(const char * nt)
			{
				delete[] nome_tipo;
				nome_tipo = new char[strlen(nt)+1];
				strcpy(nome_tipo, nt);
			}
			
			void set_marca(const char * m)
			{
				delete[] marca;
				marca = new char[strlen(m)+1];
				strcpy(marca, m);	
			}
	};
}

#endif
