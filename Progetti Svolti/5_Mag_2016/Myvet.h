#ifndef MYVET_H
#define MYVET_H

#include "Vettore.h"
#include "Eccezione.h"
#include <fstream>

using std::ofstream;

namespace MS{
	class Myvet : public Vettore{
		
		public:
			explicit Myvet(const int & dim) : Vettore(dim){}
			Myvet(const Myvet & m) : Vettore(m){}
			
			const Myvet & operator=(const Myvet &);
			
			void sort();
			bool bin_search(const T & , int &, int , int )const throw(Eccezione);
			void store(const char * )const;
			bool ordinato()const;
	};
}


#endif
