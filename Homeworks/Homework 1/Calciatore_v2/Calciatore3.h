#include <iostream>
#include <cstring>

using namespace std;
// const int DIM
struct Calciatore {
	
	 char * Nome;   //  char Nome [DIM];
	 char * Cognome;
	 char * Squadra;
	 int Goal;
};

void createC(Calciatore & );
// Funzioni overloaded al solo scopo esemplificativo
void read(Calciatore & );
//void read(istream &, Calciatore & );
void write(const Calciatore &);
void write(ostream &, const Calciatore &);
inline void update(Calciatore & c, const int num) {c.Goal=num;}
bool equal(const Calciatore &, const Calciatore &);
inline  int get_n(const Calciatore & c) { return c.Goal;}





