// Dato un vettore di numeri complessi lo ordina secondo
// moduli crescenti.
// Esempio di esecuzione:
/*    
 Inserimento del vettore di numeri complessi.
 Inserisci il numero di elementi (n<100) dell' elenco : 3
 V[0]=
 Inserire Coefficiente reale: 20
 Inserire Coefficiente immaginario: 21
 V[1]=
 Inserire Coefficiente reale: 3
 Inserire Coefficiente immaginario: 4
 V[2]=
 Inserire Coefficiente reale: 119
 Inserire Coefficiente immaginario: 120
 Stampa del vettore inserito.
 V[0]= (20,21)
 V[1]= (3,4)
 V[2]= (119,120)
 Stampa sequenziale dei moduli nel vettore non ordinato.
29
5
169
 Ordino il vettore per moduli crescenti.
 Sono stati eseguiti 1 scambi...
 ...e 2 cicli.
 Fatto.
 Stampa sequenziale dei moduli nel vettore ordinato.
5
29
169
Premere un tasto per continuare . . .
*/

// NOTA: Per semplicità NON è stato definito mediante un typedef anche
// il tipo base del vettore, che quindi in questa versione è
// esplicitamente definito come 'Complesso'


#include "VettComplex.h"

int main() {

Vettore V;
Complesso C;
int n;
cout << "\n Inserimento del vettore di numeri complessi.";
LeggiElementi(V,n);
cout << "\n Stampa del vettore inserito.";
StampaVettore(V,n);
cout << "\n";
cout << "\n Stampa sequenziale dei moduli nel vettore non ordinato.";
cout << "\n";
for (int i=0; i<n; i++)
  cout << moduloComplex(V[i])<< endl;
cout << "\n";
cout << "\n Ordino il vettore per moduli crescenti.";
ModuloBubbleSort(V,n);
cout << "\n Fatto.";
cout << "\n Stampa sequenziale dei moduli nel vettore ordinato.";
cout << "\n";
for (int i=0; i<n; i++)
  cout << moduloComplex(V[i])<< endl;
cout << "\n";   
system("PAUSE");
return 0;
}

// MAIN DI PROVA DEL TIPO COMPLESSO
/*
int main()
{
Complesso c1, c2, somma, prodotto;
//acquisizione dati 
cout << "\n Lettura di C1: ";
leggiComplex(c1);
cout << "\n Lettura di C2: ";
leggiComplex(c2);
//modulo
cout << "\n Il modulo di C1: " << moduloComplex(c1);
cout << "\n Il modulo di C2: " << moduloComplex(c2);
//somma 
somma=sommaComplex(c1,c2);
cout << "\n somma: ";
stampaComplex(somma);
//prodotto 
prodotto=prodottoComplex(c1,c2);
cout << "\n prodotto: ";
stampaComplex(prodotto);

system("PAUSE");
return 0;
}
*/
