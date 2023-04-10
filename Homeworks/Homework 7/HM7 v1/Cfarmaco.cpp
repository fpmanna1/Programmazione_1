#include "Cfarmaco.h"

namespace MyNS{
	Cfarmaco::Cfarmaco(const char * N, const char * P, const float C, const Data & D, const char * F) : Farmaco(N,P,C,D){
		this->fe = new char[strlen(F)+1];
		strcpy(fe,F);
	}
	
	Cfarmaco::Cfarmaco(const Cfarmaco & cf): Farmaco(cf){
		
		this->fe = new char[strlen(cf.fe)+1];
		strcpy(this->fe, cf.fe);
	}
	
	
	
	
	
	ostream & operator<<(ostream &out, const Cfarmaco &cf)
	{
		out<<(Farmaco&)cf << fe;
		return out;
	}
	
	istream & operator>>(istream &in, Cfarmaco &cf)
	{
		in>>(Farmaco&)cf;
		char buffer[100];
		in.getline(buffer,100);
		delete [] cf.fe;
		cf.fe= new char[strlen(buffer)+1];
		strcpy(cf.fe, buffer);
		return in;
	}

}
