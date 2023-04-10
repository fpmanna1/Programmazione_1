#ifndef ELENCOORD_H
#define ELENCORD_H 
#include "Voce.h"

const int DIM_MAX=4;
typedef Voce* Elenco; 

void readElenco(Elenco &, const int );
void writeElenco(const Elenco &, const int );
bool in(const Elenco &, const int, const Voce& , int & );
inline bool full(const Elenco e, const int size){return (size==DIM_MAX);}
inline bool empty(const Elenco e, const int size){return (size==0);}
inline void swap(Voce &v1, Voce &v2){ Voce temp; temp=v1; v1=v2; v2=temp;}
bool insert_ord(Elenco &, int &, const Voce &);
void remove(Elenco &, int, const Voce );

#endif
