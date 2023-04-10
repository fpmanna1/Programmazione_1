#ifndef ELENCO_H
#define ELENCO_H
#include "Prodotto.h"

const int SIZE=5;
typedef Prodotto Elenco[SIZE];

void writeElenco(const Elenco &,const int);
void readElenco(Elenco &, const int);
bool giapresente(const Elenco &, const Prodotto &, const int);
inline bool ricercaProdotto(const Elenco &E,  Prodotto &p, const int dim){ return (giapresente(E, p, dim));}
void remove(Elenco &, const Prodotto & ,int &);

#endif
