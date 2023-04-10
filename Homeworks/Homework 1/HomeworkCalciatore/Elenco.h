#include "Calciatore.h"
// const int DIM=100;
typedef Calciatore * Elenco;       // definizione del nome Elenco
// typedef Calciatore Elenco[DIM]; // definizione del nome Elenco
 
void create(Elenco &, const int, int & nelem );
bool insert(Elenco, const int, int &, const Calciatore & c);
void write(const Elenco, const int);
bool in(const Elenco , const int , const Calciatore &, int  & pos);
void classifica(Elenco &, const int);
void copy(Elenco &, int &, const Elenco, const int, const int);
void  destroy(Elenco &, int &);

