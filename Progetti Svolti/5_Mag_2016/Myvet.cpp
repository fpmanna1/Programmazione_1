#include "Myvet.h"

namespace MS{
	 
	void Myvet::sort()
	{
		for(int i=0; i<dim; i++)
			for(int j=0; j<dim; j++)
				if(vet[i]<vet[j])
				{
					T temp;
					temp=vet[j];
					vet[j]=vet[i];
					vet[i]=temp;
				}
	}
	
	const Myvet & Myvet::operator=(const Myvet & v)
	{
		if(this!=&v)
		{
			Vettore::operator=(v);
		}
		return *this;
	}
	
	bool Myvet::bin_search(const T & x, int & pos, int first, int last)const throw(Eccezione)
	{
		if(!ordinato()) throw Eccezione("Errore. Il vettore non e\' ordinato!");
		int med=0;
		if(last-first>0)
		{
			med=(last+first)/2;
			if(vet[med]==x)
			{
				pos=med;
				cout << "Elemento trovato in posizione "<<pos<<endl;
				return true;
			}
			else{
				if(vet[med]<x)
					return bin_search(x, pos, med+1, last);
					else
						return bin_search(x, pos, first, med-1);
				}
		}
		return false;
	}
	
	
	bool Myvet::ordinato()const
	{
		for(int i=0; i<dim-1; i++)
			if(vet[i]>vet[i+1])
				return false;
		return true;
	}
	
	void Myvet::store(const char * nome_file)const
	{
		ofstream OutFile;
		OutFile.open(nome_file);
		if(OutFile)
			cout<<"Errore nell'apertura del file!"<<endl;
			else
				print(OutFile);
		OutFile.close();
	}
	
}
