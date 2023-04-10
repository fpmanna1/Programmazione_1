#ifndef VOCE_H
#define VOCE_H 

#include <iostream>
#include <cstring>
using namespace std;

const int DIM = 400; //dimensione del buffer

typedef struct Voce{
    int key;
    char * description;
} Voce;

//void create(Voce &);
void read(Voce &);
inline void write(const Voce &v) { cout << v.key << ' ' << v.description; }
void copy(const Voce &, Voce &); //la destinazione è a destra (da notare la mancanza del const)
inline bool equal(const Voce &v1,const Voce &v2){ return(v1.key == v2.key) && (!strcmp(v1.description, v2.description)); }
//la valutazione di un'espressione booleana ritorna comunque un bool (che posso far ritornare direttamente dalla funzione)
inline bool greater_than (const Voce v1, const Voce v2){return(v1.key > v2.key); }
void destroy(Voce &);

#endif


