#ifndef PIZZA_H
#define PIZZA_H

#include "Voce.h"
#include "Ingredienti.h"

namespace MS{
	class Pizza : public Voce{
		friend ostream & operator<<(ostream &, const Pizza & );
		friend istream & operator>>(istream &, Pizza &); //numero di ingredienti prima di procedere all'inserimento
		
		private:
			char * nome;
			Ingredienti ingredienti;
		public:
			Pizza(const int =0, const char * ="tipo", const float =0, const char * ="margherita", const Ingredienti & = Ingredienti());
			Pizza(const Pizza &);
			virtual ~Pizza(){delete[] nome;}
			
			const char * get_nome()const{return nome;}
			
			const Pizza & operator=(const Pizza &);
			
			virtual ostream & print(ostream &)const;
		 	virtual istream & input(istream &);
	};
}

#endif
