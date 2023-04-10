#ifndef DATA_H
#define DATA_H

#include <iostream>
using std::istream;
using std::ostream;

namespace MyNS{
class Data{
	
	friend ostream & operator<<(ostream & out, const Data & D) //const perchè devo semplicemente stampare a video senza modifiche
	{
		out << D.giorno << " " << D.mese << " " << D.anno;
		return out;
	}
	
	friend istream & operator>>(istream & in, Data & D)
	{
		in >> D.giorno; in >> D.mese; in >> D.anno;
		return in;
	}
	
	private:
		int giorno;
		int mese;
		int anno;
	public:
		Data();
		Data(int g=1, int m=1, int a=1900) : giorno(g), mese(m), anno(a){}
		Data(const Data & D) //costruttore di copia : giorno(D.giorno), mese(D.mese), anno(D.anno)
		{	
			giorno=D.giorno;
			mese=D.mese;
			anno=D.anno;
			
		}
		//GETTERS AND SETTERS
		int get_Giorno() const{return giorno;}
		int get_Mese() const{return mese;}
		int get_Anno() const{return anno;}
		void set_Giorno(const int g){giorno=g;}
		void set_Mese(const int m){mese=m;}
		void set_Anno(const int a){anno=a;}
		
		//OPERATORI
		bool operator==(const Data & D) {return(giorno==D.giorno && mese==D.mese && anno==D.anno);}
		bool operator!=(const Data & D) {return !(*this==D);} //lo posso fare perchè ho definito l'== per la classe data 
		bool operator>(const Data & D) {return(anno>D.anno || (anno==D.anno && mese>D.mese) || (anno==D.anno && mese==D.mese && giorno>D.giorno));}
		bool operator<(const Data & D) {return !(*this > D);}
		bool operator>=(const Data & D) {return *this>D && *this==D;}
		bool operator<=(const Data & D) {return *this<D && *this==D;}
		
};
}

#endif

