#include "Cfarmaco.h"

namespace MyNs {
		CFarmaco::CFarmaco(const char* n,const char* p,const float c,const Data & s,const char * e) : Farmaco(n,p,c,s) {
			equivalente=new char[strlen(e)+1];
			strcpy(equivalente,e);
		}
		CFarmaco::CFarmaco(const CFarmaco & cf) : Farmaco(cf) {
			equivalente=new char[strlen(cf.equivalente)+1];
			strcpy(equivalente,cf.equivalente);			
		}
		const CFarmaco & CFarmaco::operator=(const CFarmaco & cf){
			if(this!=&cf){
				this->Farmaco::operator=(cf);
				delete [] equivalente;
				equivalente=new char[strlen(cf.equivalente)+1];
				strcpy(equivalente,cf.equivalente);
			}return *this;
		}
		float CFarmaco::calc_cost() const{
			if(!strcmp(equivalente,"non disponibile")) return get_c();
			else return ((get_c()*(85))/100); 
		}
		ostream & operator<<(ostream & out,const CFarmaco & cf){
			out<<(Farmaco&)cf<<' '<<cf.equivalente;
			return out;
		}
		istream & operator>>(istream & in,CFarmaco & cf){
			in>>(Farmaco&)cf;
			char buffer[100];
			in.ignore();
			in.getline(buffer,100);
			delete [] cf.equivalente;
			cf.equivalente=new char[strlen(buffer)+1];
			strcpy(cf.equivalente,buffer);
			return in;
		}
		
		void CFarmaco::set_nome(const char * n){
			delete [] equivalente;
			equivalente=new char[strlen(n)+1];
			strcpy(equivalente,n);			
		}
}
