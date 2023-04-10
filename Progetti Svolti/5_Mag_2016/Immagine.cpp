#include "Immagine.h"

namespace MS{
	
	bool Immagine::operator>(const Immagine & i)const
	{
		return(dimensione > i.dimensione);
	}
	
	bool Immagine::operator<(const Immagine & i)const
	{
		return(dimensione < i.dimensione);
	}
	bool Immagine::operator==(const Immagine & i)const
	{
		return(dimensione == i.dimensione && nome == i.nome);
	}
	
	ostream & operator<<(ostream & out, const Immagine & i)
	{
		out << "NOME IMMAGINE : "<<i.nome<<endl;
		out << "DIMENSIONE : "<<i.dimensione<<" Kb"<<endl;
		return out;
	}
	
	istream & operator>>(istream & in, Immagine & i)
	{
		cout << "Inserisci nome e dimensione dell'immagine : ";
		in >> i.nome;
		in >> i.dimensione;
		return in;
	}
}

