#ifndef AUTORE_H
#define AUTORE_H

#include <string>
#include <iostream>
#include <fstream>

using std::cout;
using std::endl;
using std::string;
using std::ostream;
using std::istream;

namespace MS{
	class Autore{
		friend ostream & operator<<(ostream &, const Autore &);
		friend istream & operator>>(istream &, Autore &);
		
		private:
			string nome;
			int nascita;
			int morte;
			
		public:
			Autore(const string & = "", int = 1900, int = 2000 );
			Autore(const Autore &);
			
			const Autore & operator=(const Autore &);
			
			void set_nome(const string & n){nome=n;}
			void set_nascita(int n){nascita=n;}
			void set_morte(int m){morte=m;}
	};
}


#endif
