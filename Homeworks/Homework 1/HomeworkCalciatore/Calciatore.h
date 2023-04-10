#include <iostream>
#include <cstring>

using namespace std;

const int MAXS=100;
typedef char MyString[MAXS+1];

struct Calciatore {
	
	 MyString Nome;
	 MyString Cognome;
	 MyString Squadra;
	 int Goal;
};
// Funzioni overloaded al solo scopo esemplificativo
void read(Calciatore & );
void write(const Calciatore &);
inline void update(Calciatore & c, const int num) {c.Goal=num;}
bool equal(const Calciatore &, const Calciatore &);
inline  int get_n(const Calciatore & c) { return c.Goal;}





