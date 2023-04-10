#ifndef IMMAGINE_H
#define IMMAGINE_H

#include <string>
#include <iostream>

using std::istream;
using std::ostream;
using std::string;
using std::endl;
using std::cout;

namespace MS{
	class Immagine{
		friend ostream & operator<<(ostream &, const Immagine &);
		friend istream & operator>>(istream &, Immagine &);
		private:
			string nome;
			int dimensione;
		public:
			Immagine(const string & n = "NOME IMMAGINE", const int & d = 1000) : nome(n), dimensione(d){}
		
			void set_nome(const string & s){nome=s;}
			void set_dimensione(const int & d){dimensione=d;}
		
			const string & get_nome()const{return nome;}
			const int & get_dimensione()const{return dimensione;}
		
			bool operator>(const Immagine &)const;
			bool operator<(const Immagine &)const;
			bool operator==(const Immagine &)const;
	};
}


#endif
