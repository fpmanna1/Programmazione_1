#include <iostream>
#include <cmath>

using namespace std;

struct Complesso {
double Re;
double Imm;
};


void leggiComplex(Complesso &);
void stampaComplex(const Complesso &);
Complesso sommaComplex(const Complesso, const Complesso);
Complesso prodottoComplex(const Complesso, const Complesso);
double moduloComplex(const Complesso &);

