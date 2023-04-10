#ifndef VETTORE_H
#define VETTORE_H

#include "Immagine.h"

typedef MS::Immagine T;

namespace MS{
	class Vettore{
		friend ostream & operator<<(ostream &, const Vettore &);
		friend istream & operator>>(istream &, Vettore &);
		protected:
			T* vet; //vettore di immagini allocato dinamicamente
			int dim;
			int nelem;
			ostream & print(ostream &)const;
			istream & input(istream &);
		public:
			explicit Vettore(const int & );
			Vettore(const Vettore &);
			~Vettore(){delete[] vet;}
			
			const Vettore & operator=(const Vettore &);
			
			const int get_dim()const{return dim;}
			
			const T & operator[](const int)const;
			T & operator[](const int);
	};
}



#endif
