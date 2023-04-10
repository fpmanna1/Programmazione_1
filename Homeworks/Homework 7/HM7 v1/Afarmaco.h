#ifndef AFARMACO_H
#define AFARMACO_H

#include "Farmaco.h"

namespace MyNS{

class Afarmaco : public Farmaco{
	friend ostream & operator<<(ostream & , const Afarmaco &);
	friend istream & operator>>(istream &, Afarmaco &);
	
	
	private:
		int percentuale;
		bool osp;
	public:
		Afarmaco(const char * ="", const char * ="", const float = 0.0, const Data & =0, int =0, bool =false);
		virtual float calc_cost() const;
};


}

#endif
