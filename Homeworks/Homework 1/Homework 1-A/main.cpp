#include <iostream>
#include "Complesso.h"

using namespace std;

int main() 
{
	Complesso numero;
	Complesso numero2;
	Vettore vet;
	int nelem;
	
	//PARTE RELATIVA AI NUMERI COMPLESSI
	cout << "Inserisci il numero complesso (Re e Imm) : ";
	leggiComplex(numero);
	cout << "Il numero complesso inserito e' : ";
	stampaComplex(numero);
	cout << "Inserisci il secondo numero complesso (Re e Imm) : ";
	leggiComplex(numero2);
	cout << "Il numero complesso inserito e' : ";
	stampaComplex(numero2);
	cout<<"\n";
	cout << "La somma tra i due numeri complessi e\' : ";
	stampaComplex(sommaComplex(numero,numero2));
	cout << "Il prodotto tra i due numeri complessi e\' ";
	stampaComplex(prodottoComplex(numero,numero2));
	cout <<"Il modulo del primo numero complesso inserito e\' : "  << moduloComplex(numero) <<endl;
	cout <<"Il modulo del secondo numero complesso inserito e\' : " << moduloComplex(numero2) <<endl;
	cout << "Quanti elementi vuoi inserire nel vettore (MAX 20) ?  ";
	cin >> nelem;
	LeggiElementi(vet,nelem);
	cout << "\n";
	
	//PARTE RELATIVA AL VETTORE
	cout <<"Il vettore di complessi e\' : "<<endl;
	StampaVettore(vet, nelem);
	ModuloBubbleSort(vet, nelem);

	return 0;
}
