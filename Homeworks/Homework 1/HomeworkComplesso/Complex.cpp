#include "Complex.h"

void leggiComplex(Complesso & C) {    
cout << "\n Inserire Coefficiente reale: ";    
cin >> C.Re;
cout << "\n Inserire Coefficiente immaginario: ";    
cin >> C.Imm;
}

//visualizza il numero complesso come coppia di numeri reali: (Re,Im)
void stampaComplex(const Complesso & C) {
cout << "(" << C.Re << "," << C.Imm << ")";
}    

Complesso sommaComplex(const Complesso OP1, const Complesso OP2) {
Complesso somma;    
somma.Re = OP1.Re + OP2.Re;
somma.Imm = OP1.Imm + OP2.Imm;
return somma;
}    

Complesso prodottoComplex(const Complesso OP1, const Complesso OP2) {
Complesso prodotto;    
prodotto.Re = OP1.Re * OP2.Re - OP1.Imm * OP2.Imm;
prodotto.Imm = OP1.Imm * OP2.Re + OP2.Imm * OP1.Re;
return prodotto;
}    

double moduloComplex(const Complesso & C) {
    return sqrt(C.Re*C.Re+C.Imm*C.Imm);
}    
