#include "VettComplex.h"

// Funzione per la lettura degli elementi dell'elenco
void LeggiElementi(Vettore Vet,int & nelem) {

	do {
	cout<<"\n Inserisci il numero di elementi (n<100) dell' elenco : ";
	cin>>nelem;
	} while(nelem>DIM);

	for(int i=0;i<nelem;i++) {
		cout<<"\n V["<<i<<"]= ";
		leggiComplex(Vet[i]);  
	}
}

// Funzione per la stampa degli elementi dell'elenco
void StampaVettore(const Vettore Vet, const int nelem) {

	for(int i=0;i<nelem;i++) {
		cout<<"\n V["<<i<<"]= ";
        stampaComplex(Vet[i]);  
	}
}

// Funzione di ordinamento per scambi
void ModuloBubbleSort(Vettore V, const int n) {

	int i,j;
	int nswaps=0;	// numero di scambi
	int ncycles=0;	// numero di iterazioni

	for(i=1;i<n;i++) {
		ncycles++;

		// Analizza il sottoinsieme V[0]..V[n-i]
		for(j=0;j<n-i;j++) {
			if(moduloComplex(V[j])>moduloComplex(V[j+1])) { 
				nswaps++;
				swap(V[j],V[j+1]);
			}
		}
        }

	cout<<"\n Sono stati eseguiti "<<nswaps<<" scambi...";
	cout<<"\n ...e "<< ncycles<<" cicli.\n";
}

// Funzione che effettua lo scambio 
void swap(Complesso & a, Complesso & b) {

	Complesso temp;

	temp=a;
	a=b;
	b=temp;
}

// Funzione che effettua lo scambio 
/* void swap(Complesso * a, Complesso * b) {

	Complesso temp;

	temp=*a;
	*a=*b;
	*b=temp;
} */






