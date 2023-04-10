/*
La classe dei farmaci di tipo A aggiunge una variabile membro di tipo intero che rappresenta la percentuale 
del costo che può essere rimborsato (è una semplificazione…), e una variabile booleana che stabilisce se il 
farmaco è ospedaliero. Si supponga che il costo effettivo di tali farmaci sia dato dal costo base diminuito 
della percentuale rimborsabile nel caso di farmaci non ospedalieri, e che il rimborso sia del 100% nel caso di 
farmaci ospedalieri. Si forniscano inoltre per tale classe gli operatori << e >>.
*/

#ifndef AFARMACO_H
#define AFARMACO_H
#include "Farmaco.h"
namespace MyNs {
	
class AFarmaco : public Farmaco {
	friend ostream & operator<<(ostream &,const AFarmaco &);
	friend istream & operator>>(istream &,AFarmaco &);		
	private:
		int primborso;
		bool ospedaliero;		
	public:
		AFarmaco(const char* = "",const char* = "",const float = 0,const Data & =0,const int =0,const bool=0);
		virtual float calc_cost() const;
		
	};
	
	
}
#endif
