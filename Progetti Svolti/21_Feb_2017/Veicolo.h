#ifndef VEICOLO_H
#define VEICOLO_H

#include <string>
#include <fstream>
#include <iostream>

using std::string;
using std::ostream;
using std::istream;
using std::cout;
using std::endl;

namespace MS{
	
	class Veicolo{
		friend ostream & operator<<(ostream &, const Veicolo &);
		friend istream & operator>>(istream &, Veicolo &);
		
		protected:
			string marca;
			string modello;
			int potenza;
			int classe;
			
		public:
			Veicolo();
			Veicolo(const string &, const string &, int, int);
			
			virtual ostream & print(ostream &)const;
			virtual istream & input(istream &);
			
			virtual float calcolo_tassa()const = 0;
			
			const Veicolo & operator=(const Veicolo &);
			
			bool operator==(const Veicolo & v){return (marca==v.marca && modello==v.modello && potenza==v.potenza && classe==v.classe); }
	};
	
	
}

#endif
