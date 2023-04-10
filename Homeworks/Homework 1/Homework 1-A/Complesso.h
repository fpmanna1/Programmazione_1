#include <iostream>

using namespace std;
const int DIM = 20;

typedef struct Complesso{
	double re;
	double imm;
}Complesso;

typedef Complesso Vettore[DIM];

void leggiComplex(Complesso &numero);
void stampaComplex(const Complesso &numero);
Complesso sommaComplex(const Complesso numero1, const Complesso numero2);
Complesso prodottoComplex(const Complesso numero1, const Complesso numero2);
double moduloComplex(const Complesso &num);
double pot(const double &base, int esp); 
void LeggiElementi(Vettore vet, int &nelem);
void StampaVettore(const Vettore vet, const int nelem);
void ModuloBubbleSort(Vettore vet, const int nelem);


