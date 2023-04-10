#ifndef PILA_H
#define PILA_H

#include <iostream>
#include "Oggetto.h"

using std::cout; using std::endl;

namespace MS{
	
	typedef Oggetto T;
	
	class Pila{
		protected:
			T* vet; // T* perchè vuole un vettore allocato dinamicamente
			int nelem; //nelem è la mia testa, punta alla prima libera (vuota)
			static const int dim=50;
			
		public:
			Pila(const int );
			Pila(const Pila &);
			virtual ~Pila();
			const Pila & operator=(const Pila &);
			
			bool full(){return nelem==dim;}
			bool empty(){return nelem==0;}
			
			void push(const T& );
			void pop(T&);
			void top(T&);
			void print();
			
			void set_nelem(int n){this->nelem=n;}
			int get_nelem()const{return nelem;}
	};
	
}

#endif
