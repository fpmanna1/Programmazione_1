#include "Elenco.h"

void writeElenco(const Elenco &E, const int dim)
{
	for(int i=0; i<dim; i++)
		cout <<E[i].get_Codice() << " "<< E[i].get_Descrizione()<<endl;
}

void readElenco(Elenco &E, const int dim)
{
	
	int i=0;
	while(i<dim)
	{
		Prodotto p;
		cin>>p;
		if(p.valido() && !giapresente(E,p, dim))
		{
			E[i]=p;
			i++;
		}
		else
			cout<<"Inserisci un prodotto valido!"<<endl;
		delete [] p.get_Descrizione();
	}
}

bool giapresente(const Elenco &E,const Prodotto &p, const int dim)
{
	for(int i=0; i<dim; i++)
		if(p==E[i])	
			return true;
	return false;
}

void remove(Elenco &E, const Prodotto &p ,int &dim)
{
	for(int i=0; i<dim; i++)
		if(p==E[i])
		{
			delete[] E[i].get_Descrizione();
			for(int j=i; j<dim-1; j++)
			{
				E[j]=E[j+1];
			}
		}
	Prodotto k;
	E[dim-1]=k;
	dim--;
}

