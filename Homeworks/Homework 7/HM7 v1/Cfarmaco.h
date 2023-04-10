#ifndef CFARMACO_H
#define CFARMACO_H

#include "Farmaco.h"

namespace MyNS{
class Cfarmaco : public Farmaco{
	friend ostream & operator<<(ostream &, const Cfarmaco &);
	friend istream & operator>>(istream &, Cfarmaco &);
	
	private:
		char * fe;
		
	public:
		Cfarmaco();
		Cfarmaco(const char * ="", const char * = "", const float = 0.0, const Data & = 0, const char * = "");
		Cfarmaco(const Cfarmaco &);
		
		virtual ~Cfarmaco(){delete[] fe;}
		const char * get_Fe()const {return fe;}
		void set_Fe(const char *f){
			delete [] fe;
			fe = new char[strlen(f)+1];
			strcpy(fe, f);
		}
}; 

}

#endif
