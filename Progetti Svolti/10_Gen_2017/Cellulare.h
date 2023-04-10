#ifndef CELLULARE_H
#define CELLULARE_H

#include "Oggetto.h"

namespace MS{
	class Cellulare : public Oggetto{
		friend ostream & operator<<(ostream &, const Cellulare &);
		friend istream & operator>>(istream &, Cellulare &);
		private:
			char* modello;
			int costo;
		protected:
			virtual ostream & print(ostream & )const;
			virtual istream & input(istream &);
		public:
			Cellulare(const int & = 78910, const char * = "Cellulare", const char * = "Rettangolare", const char * = "1+ 7 Pro", const float & = 1500);
			Cellulare(const Cellulare &);
			virtual ~Cellulare(){delete[] modello;}
			
			const Cellulare & operator=(const Cellulare &);
			
			void set_costo(float c){costo=c;}
			void set_modello(const char * m)
			{
				delete[] modello;
				modello = new char[strlen(m)+1];
				strcpy(modello, m);
			}
			
			int get_costo()const{return costo;}
			const char * get_modello()const{return modello;}
			
			bool operator==(const Cellulare &)const;
			
	};
}


#endif
