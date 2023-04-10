#include "Motoveicolo.h"

namespace MS{
	float Motoveicolo::calcolo_tassa()const
	{
		switch(classe)
		{
			case 0:
				if(potenza <= 11)
					return 28.60 * potenza;
					else
						return (28.60*11) + (4.5*(potenza - 11));
				break;
			case 1:
				if(potenza <= 11)
					return 2.9 * potenza;
					else
						return (2.90*11)+(4.35*(potenza-11));
				break;
			case 2:
				if(potenza <= 11)
					return 2.8 * potenza;
					else
						return (2.8*11)+(4.20*(potenza-11));
				break;
			case 3:
				if(potenza <= 11)
					return 2.70 * potenza;
					else
						return (2.70*11)+(4.05*(potenza-11));
				break;		
		}
		
	}
	
	ostream & Motoveicolo::print(ostream & out)const
	{
		Veicolo::print(out);
		out << " " <<cavalletto;
		return out;
	}
	
	ostream & operator<<(ostream & out, const Motoveicolo & a)
	{
		return a.print(out);
	}
	
	istream & Motoveicolo::input(istream & in)
	{
		Veicolo::input(in);
		cout<<"Inserisci il tipo di cavalletto (L per laterale, C per centrale) : ";
		in >> cavalletto;
		return in;
	}
	
	istream & operator>>(istream & in, Motoveicolo & a)
	{
		return a.input(in);
	}	
}
