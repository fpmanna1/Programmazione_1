#ifndef PILAOGG_H
#define PILAOGG_H

#include "Pila.h"
#include "bad_insert.h"

using std::ofstream;

namespace MS{
	
	class PilaOgg : public Pila{
		private:
			char * forma;
		public:
			PilaOgg(const char * = "Rombo");
			PilaOgg(const PilaOgg &);
			const PilaOgg & operator=(const PilaOgg &);
			
			void push(const T&) throw (bad_insert);
			virtual ~PilaOgg(){delete [] forma;}
			
			void set_forma(const char * f){strcpy(forma,f);}
			bool check(const T&);
			
			void print();
			void fileprint(ofstream &);
	};

}





#endif
