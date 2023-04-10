#ifndef EVENTO_H
#define EVENTO_H

#include <cstring>
#include <iostream>

using std::endl;
using std::cout;
using std::istream;
using std::ostream;

namespace MS{
	class Evento{
		friend ostream & operator<<(ostream &, const Evento &);
		private:
			char * descrizione;
			int ora;
			int minuti;
		protected:
			ostream & print(ostream &)const;
		public:
			Evento(const char * = "unknown", const int & = 2, const int & = 30);
			Evento(const Evento &);
			~Evento(){delete[] descrizione;}
			
			const Evento & operator=(const Evento & );
			
			void set_descrizione(const char * d){
				delete[] descrizione;
				descrizione = new char[strlen(d)+1];
				strcpy(descrizione, d);
			}
			void set_ora(const int & o){ora=o;}
			void set_minuti(const int & m){minuti=m;}
			
			const char * get_descrizione()const{return descrizione;}
			const int & get_ora()const{return ora;}
			const int & get_minuti()const{return minuti;}
			
	};
}

#endif
