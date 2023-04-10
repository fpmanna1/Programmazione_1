#include <iostream>
#include <cmath>
#include "Complesso.h"

using namespace std;

void leggiComplex(Complesso &numero)
{
	cin >> numero.re;
	cin >> numero.imm;
}

void stampaComplex (const Complesso &numero)
{
	cout << numero.re << "+" << numero.imm << "i" << endl;
}

Complesso sommaComplex(const Complesso numero1, const Complesso numero2)
{
	Complesso somma;
	somma.re=0;
	somma.imm=0;
	somma.re=numero1.re+numero2.re;
	somma.imm=numero1.imm+numero2.imm;
	return somma;
}

Complesso prodottoComplex(const Complesso numero1, const Complesso numero2)
{
	Complesso prodotto;
	prodotto.re = ((numero1.re)*(numero2.re) - (numero1.imm)*(numero2.imm));
	prodotto.imm = ((numero1.re)*(numero2.imm) + (numero1.imm)*(numero2.re));
	return prodotto;
}

double pot(const double &base, int esp) //funzione per il quadrato dei numeri
{
	double ris=1;
	for(short int i=0; i<esp; i++)
	{
		ris = ris * base;
	}
	return ris;
}

double moduloComplex(const Complesso &num)
{
	double modulo=0;
	//modulo=sqrt((num.re)*(num.re)+(num.imm)*(num.imm));
	modulo=sqrt(pot(num.re,2) + pot(num.imm,2));
	return modulo;
}

void LeggiElementi(Vettore vet, int &nelem)
{
	for(short int i=0; i<nelem; i++)
	{
		cout <<" Inserisci il " << i+1 << " elemento : " <<endl;
		leggiComplex(vet[i]);
	}
} 

void StampaVettore(const Vettore vet, const int nelem)
{
 	for(short int i=0; i<nelem; i++)
	{
		stampaComplex(vet[i]);
	}
}

void ModuloBubbleSort(Vettore vet, const int nelem)
{
	double vet2[DIM];
	short int temp;
	for(int i=0; i<nelem; i++)
	{
		vet2[i]=moduloComplex(vet[i]);
	}
	for(short int j=0;j<nelem-1;j++)
	{
		for(short int i=0;i<nelem-1;i++)
		{
			if(vet2[i]>vet2[i+1])
			{
				temp=vet2[i];
				vet2[i]=vet2[i+1];
				vet2[i+1]=temp;
			}
		}
	}
	for(short int i=0; i<nelem; i++)
	{
		cout << vet2[i] << " ";
	}		
}
