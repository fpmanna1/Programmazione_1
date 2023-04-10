#ifndef ELENCO_H
#define ELENCO_H 
#include "Voce.h"

typedef Voce * Elenco; //definisco un vettore di puntatori

void iniz(Elenco &, const int );
void readElenco(Elenco &, const int );
void writeElenco(const Elenco &, const int );
bool in(const Elenco &, const int, const Voce& , int & );
bool sort(Elenco &, const int size);
void swap(Voce &, Voce &);
inline void swap(Voce &v1, Voce &v2){ Voce temp; temp=v1; v1=v2; v2=temp;}
bool insert(Elenco &, const int, const Voce &);
bool insert_ord(Elenco &, const int, const Voce &);
void rm(Elenco &, int, const Voce );
inline bool is_sorted ( Elenco &e, const int size){ return(sort(e, size)); }
bool full(const Elenco, const int);
bool empty(const Elenco, const int);

#endif
