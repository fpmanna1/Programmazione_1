#include "Garage.h"

namespace MS{
	int Garage::insert(Veicolo* v) throw(Eccezione)
	{
		if(full()) return -1;
		if(strcmp((*v).get_nome_tipo(), "auto")!=0 && strcmp((*v).get_nome_tipo(), "moto")!=0) 
			throw Eccezione("inserisci o un veicolo o una moto!");
		vet[nelem]=v; //inserisco un puntatore nel mio vettore
		nelem++;
		return nelem-1; //ritorna la posizione in cui ho inserito il mio veicolo
	}
	
	bool Garage::estrazione(const int & n)
	{
		if(empty()) return false;
		for(int i=n; i<nelem-1; i++)
			vet[i]=vet[i+1];
		nelem--;
		return true;
	}
	
	ostream & operator<<(ostream & out, const Garage & g)
	{
		return g.print(out);
	}
	
	ostream & Garage::print(ostream & out)const
	{
		out << "-----GARAGE------"<<endl;
		for(int i=0; i<nelem; i++)
		{
			out << "Posizione : "<<i<<endl;
			out << *(vet[i])<< endl;
		}
		return out;
	}
	
	void Garage::store(ofstream & OutFile)
	{
		OutFile.open("./garage_current.txt");
		if(OutFile)
		{
			for(int i=0; i<nelem; i++)
			{
				//OutFile << (*vet[i]).totext << endl;
			}
		}
		else
			cout << "Apertura file non riuscita!"<<endl;
		OutFile.close();
	}
}
