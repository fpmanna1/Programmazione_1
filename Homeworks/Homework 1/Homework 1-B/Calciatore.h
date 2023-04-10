#include <iostream>

using namespace std;
const int DIM = 20;  
 
typedef struct Calciatore{
	char nome[15];
	char cognome[15];
	char squadra[15];
	int goal;
}Calciatore;

typedef Calciatore Elenco[DIM];

void read(Calciatore &);
/*void stampa(Calciatore );
int get_goal(Calciatore &);
void update(Calciatore &, int ); */
inline void update(Calciatore &c, int num){c.goal= num;};
inline int get_goal(Calciatore &c){return c.goal;};
inline void stampa(Calciatore c){cout << c.nome<< " - " << c.cognome<< " - " << c.squadra << " - " << c.goal;}
bool equal(Calciatore , Calciatore );
void init(Elenco, int);
void write(Elenco, int);
int in(Elenco, int, Calciatore, int);
bool insert(Elenco, int, Calciatore);
void classifica(Elenco, int);
void copy(Elenco, int ,Elenco ,int );
