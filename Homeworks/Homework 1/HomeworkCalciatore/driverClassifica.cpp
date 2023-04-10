#include <iostream>
#include <fstream>

#include "Calciatore.h"
//#include "Elenco.h"

using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {

	Calciatore c1, c2, c3, c4;

	
//	Elenco E, E1; 
//	int dim, n, n1;
//	dim=4;
//	create(E, dim, n);
//	create(E1, dim, n1);
	
	cout << "Classifica Cannonieri della Champions League!" << endl;
	cout <<"\n";
	cout << "inserire i dati relativi al calciatore c1" << endl;
	read(c1);
	cout <<"\n";
	cout << "aggiorno il valore del campo Goal di c1" << endl;
	update(c1,4);
	cout << "goal: " << get_n(c1) << endl;
	
	cin.ignore();
	
	cout << "inserire i dati relativi al calciatore c2" << endl;
	read(c2);
	cout <<"\n";
	
	cout << "assegno a c4 il valore c2" << endl;
	c4=c2;
	
	if(equal(c4,c2)) cout << "c4,c2: i due calciatori sono uguali" << endl;
	else cout << "c4,c2: i due calciatori NON sono uguali" << endl;
	
	cin.ignore();
	
	cout << "inserire i dati relativi al calciatore c3" << endl;
	read(c3);
	cout <<"\n";
	
	if(equal(c1,c3)) cout << "c1,c3: i due calciatori sono uguali" << endl;
	else cout << "c1,c3: i due calciatori NON sono uguali" << endl;

	cout <<"\n";
/*
	cout << "inserisco in elenco cannonieri E il calciatore c1" << endl;
	if(insert(E,dim,n,c1)) cout << "inserimento riuscito" << endl;
	else cout << "inserimento non riuscito!!!!" << endl;
	
	cout << "inserisco in elenco  cannonieri E il calciatore c2" << endl;
	if(insert(E,dim,n,c2)) cout << "inserimento riuscito" << endl;
	else cout << "inserimento non riuscito!!!!" << endl;
	
	cout << "inserisco in elenco  cannonieri E il calciatore c3" << endl;
	if(insert(E,dim,n,c3)) cout << "inserimento riuscito" << endl;
	else cout << "inserimento non riuscito!!!!" << endl;
	
	cout << "inserisco in elenco  cannonieri E il calciatore c4" << endl;
	if(insert(E,dim,n,c4)) cout << "inserimento riuscito" << endl;
	else cout << "inserimento non riuscito!!!!" << endl;
	

    cout <<"\n";
	cout << "\n***** Elenco Cannonieri ******" << endl;
	
	write(E,n);
	
	cout << "copio l'elenco E in E1" << endl;
	copy(E1,n1,E,n,dim);
	
	cout << "ordino l'elenco E1 per avere la classifica dei cannonieri" << endl;
	classifica(E1,n1);
	
	cout <<"\n";
	cout << "\n***** Classifica Cannonieri ******" << endl;
	write(E1,n1);
	
	cout << "distruggo gli elenchi...." << endl;
	destroy(E,n);
	destroy(E1,n1);
	cout << "...fatto." << endl;
*/
	return 0;
}
