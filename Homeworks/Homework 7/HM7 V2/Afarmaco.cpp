#include "Afarmaco.h"

namespace MyNs{
	AFarmaco::AFarmaco(const char* n,const char* p,const float c,const Data & s,const int pr,const bool o) : Farmaco(n,p,c,s){
		primborso=pr;
		ospedaliero=o;
	}
	
	ostream & operator<<(ostream & out,const AFarmaco & af){
		out<<(Farmaco&)af<<' '<<af.primborso<<' '<<af.ospedaliero;
		return out;
	}
	
	istream & operator>>(istream & in,AFarmaco & af){
		in>>(Farmaco&)af>>af.primborso>>af.ospedaliero;
		return in;
	}
	
	float AFarmaco::calc_cost() const{
		if(ospedaliero) return 0;
		else return ((get_c()*(100-primborso))/100);
	}
	
}
