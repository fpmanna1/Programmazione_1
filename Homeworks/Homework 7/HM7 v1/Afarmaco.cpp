#include "Afarmaco.h"

namespace myNS{

Afarmaco::Afarmaco(const char * N, const char * P, const float C, const Data & D, int Perc, bool O) : Farmaco(N,P,C,D)
{
	this->percentuale = Perc;
	this->osp = O;
}

ostream & operator<<(ostream & out, const Afarmaco &af)
{
	out << (Farmaco&)af<<" "<<af.percentuale << " " << af.osp;
	return out;
}

istream & operator>>(istream & in, Afarmaco & af)
{
	in >> (Farmaco&)af;
	in >> af.percentuale;
	in >> af.osp;
	return in;
}

Afarmaco::float calc_cost() const
{
	if(osp) return 0;
	else
		 return ((get_Costo()*(100-percentuale))/100);
	}
}
