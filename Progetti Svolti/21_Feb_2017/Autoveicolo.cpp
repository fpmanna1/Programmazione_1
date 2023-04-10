#include "Autoveicolo.h"

namespace MS{
	float Autoveicolo::calcolo_tassa()const
	{
		switch(classe)
		{
			case 0:
				if(potenza <= 100)
					return 3*potenza;
					else
						return 300 + (4.5*(potenza-100));
				break;
			case 1:
				if(potenza <= 100)
					return 2.9*potenza;
					else
						return 290 + (4.35*(potenza-100));
				break;
			case 2:
				if(potenza <= 100)
					return 2.8*potenza;
					else
						return 280 + (4.20*(potenza-100));
				break;
			case 3:
				if(potenza <= 100)
					return 2.70*potenza;
					else
						return 270 + (4.05*(potenza-100));
				break;
			case 4:
				if(potenza <= 100)
					return 2.58*potenza;
					else
						return 258 + (3.87*(potenza-100));
				break;
			case 5:
				if(potenza <= 100)
					return 2.58*potenza;
					else
						return 258 + (3.87*(potenza-100));
				break;
			case 6:
				if(potenza <= 100)
					return 2.58*potenza;
					else
						return 258 + (3.87*(potenza-100));
				break;		
		}
	}
	
	ostream & Autoveicolo::print(ostream & out)const
	{
		Veicolo::print(out);
		out << " "<<num_porte;
		return out;
	}
	
	ostream & operator<<(ostream & out, const Autoveicolo & a)
	{
		return a.print(out);
	}
	
	istream & Autoveicolo::input(istream & in)
	{
		Veicolo::input(in);
		cout<<"Inserisci il numero delle porte : ";
		in >> num_porte;
		return in;
	}
	
	istream & operator>>(istream & in, Autoveicolo & a)
	{
		return a.input(in);
	}
}

