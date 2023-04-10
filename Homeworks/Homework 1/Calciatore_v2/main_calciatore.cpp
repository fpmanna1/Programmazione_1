#include <iostream>
#include <fstream>
#include "Calciatore3.h"
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	
	ofstream myfile;
	Calciatore C, C1;  // alloca 2 ptr e un intero in area stack non inizializzati
	createC(C);  // non è una inizializzazione perchè è chiamata DOPO la definizione di C

	
	
	createC(C1);
	cout << C.Nome << C.Squadra << C.Goal << endl;
	cout << "inserisci C:" << endl;
	read(C);
	cout << "stampo su file i dati del Calciatore C: " << endl;
		
	myfile.open("file.txt", ios::app);
	if(!myfile) cout << "errore in apertura file" << endl;
	else {
	write(myfile,C); 
	myfile << "\n";
	myfile.close();
	}
	cout << "stampo a video i dati del Calciatore C: " << endl;
	write(cout,C);
	
	C1=C; // copia gli indirizzi
	cout << "\n";
	cout << "Calciatore C1: " << endl;
	write(C1);
	
	cout << C.Goal; // accesso alla rappresentazione del tipo
	cout << get_n(C);  // accesso controllato
	
	return 0;
}















