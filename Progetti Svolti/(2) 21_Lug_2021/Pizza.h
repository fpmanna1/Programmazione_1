#ifndef PIZZA_H
#define PIZZA_H

#include "Voce.h"
#include "Lista.h"

namespace MS{
	class Pizza : public Voce{
		friend ostream & operator<<(ostream &, const Pizza &);
		friend istream & operator>>(istream &, Pizza &);
		private:
			char* nome;
			Lista ingredienti;
		protected:
			virtual ostream & print(ostream &)const;
			virtual istream & input(istream &);
		public:
			Pizza(const int & = 234, const char * = "Primo", const float & = 4.6, const char * = "Margherita", const Lista & = Lista());
			Pizza(const Pizza &);
			virtual ~Pizza(){delete[] nome;}
			
			const Pizza & operator=(const Pizza &);
			
			void set_nome(const char * n)
			{
				delete[] nome;
				nome = new char[strlen(n)+1];
				strcpy(nome, n);
			}
			
			const char * get_nome()const{return nome;}
			
		 
			
	};
}

#endif
