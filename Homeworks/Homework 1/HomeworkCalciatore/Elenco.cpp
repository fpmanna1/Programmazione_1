#include "Elenco.h"

void swap(Calciatore &, Calciatore &);  //interna al modulo

// genera il vettore, cioè alloca lo spazio per un elenco di dimensione 
// dim (par. di ingresso alla funzione) e restituisce l'indirizzo del primo elemento 
void create(Elenco & l, const int dim, int & nelem) {	
	l=new Calciatore [dim];	 
	nelem=0;
}
 // consente l'inserimento del calciatore c nell'elenco nella prima 
// posizione libera se c non è presente nell'elenco e se l'elenco non è pieno, restituisce 
// true se c è stato inserito, false altrimenti
bool insert(Elenco l, const int dim, int & nelem, const Calciatore & c) {
	int pos;
	if(nelem<dim && !in(l,nelem,c,pos)) {
    	l[nelem]=c;
    	nelem++;
    	return true;
	}
	else return false;
}
 // consente la visualizzazione dell'elenco
void write(const Elenco l, const int nelem) {
	for(int i=0; i<nelem; i++) {
		write(l[i]);
	    cout << endl;
	}
 }
 // determina se l'elemento c esiste nell'elenco e in caso affermativo 
bool in(const Elenco l, const int nelem, const Calciatore & c, int  & pos) {
	bool trovato=false;
	int i=0;
	while(i<nelem && !trovato)
	 if(equal(l[i],c)) {
	 	trovato=true;
	 	pos=i;
	 }
	 else i++;
	 return trovato;
 }
// pos fornisce la posizione della sua prima occorrenza
  // ordina l'elenco sul campo Goal (in ordine crescente)
void classifica(Elenco l, const int nelem) {
	int i,j;

	for(i=1;i<nelem;i++) {
		// Analizza il sottoinsieme V[0]..V[n-i]
		for(j=0;j<nelem-i;j++) 
			if( get_n(l[j])>get_n(l[j+1]) ) 
				swap(l[j],l[j+1]);
	}
}
  
 // copia l'elenco l2 in l1
void copy(Elenco &l1, int & nelem1, const Elenco l2, const int nelem2, const int dim) {
	if (l1) delete [] l1;
	nelem1=nelem2;
	l1=new Calciatore[dim];
    for(int i=0; i<nelem2; i++)
        l1[i]=l2[i];
 }
 
 
 // distrugge l'elenco (deallocando il vettore)
void  destroy(Elenco & l, int & nelem) {
	delete [] l;
	l=0;
	nelem=0;
}


// Funzione che effettua lo scambio 
void swap(Calciatore & a, Calciatore & b) {

	Calciatore temp;

	temp=a;
	a=b;
	b=temp;
}
