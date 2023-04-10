#include "Calciatore3.h"

void createC(Calciatore & C) {  // alloca spazio in area heap per le stringhe e assegna gli indirizzi ai puntatori
	 C.Nome=new char [4];
	 strcpy(C.Nome,"NNN");     // da valore all'area allocata
	 C.Cognome=new char [4];
	 strcpy(C.Cognome,"NNN");
	 C.Squadra=new char [4];
	 strcpy(C.Squadra,"NNN");
	 C.Goal=0;  // da un valore a goal
}

// consente l'ingresso dei dati di un calciatore da tastiera. 
// Funzioni overloaded al solo scopo esemplificativo
void read(Calciatore & C) {
	char buffer[300];
	delete [] C.Nome;
	cout << "Nome: " << endl;
	cin.getline(buffer,300);
	C.Nome= new char[strlen(buffer)+1];
	strcpy(C.Nome,buffer);
	delete [] C.Cognome;
	cout << "Cognome: " << endl;
	cin.getline(buffer,300);
	C.Cognome= new char[strlen(buffer)+1];
	strcpy(C.Cognome,buffer);
	delete [] C.Squadra;
	cout << "Squadra: " << endl;
	cin.getline(buffer,300);
	C.Squadra= new char[strlen(buffer)+1];
	strcpy(C.Squadra,buffer);
	cout << "Goal: " << endl;
	cin >> C.Goal;
}


// consente la visualizzazione dei dati di un calciatore a video
void write(const Calciatore & c) {
	cout << c.Nome << ' ' <<  c.Cognome << ' ' << c.Squadra << ' ' << c.Goal;
}

void write(ostream & out, const Calciatore & c) {
	out << c.Nome << ' ' <<  c.Cognome << ' ' << c.Squadra << ' ' << c.Goal;
}

// Dato c restituisce il valore corrente del campo Goal
//int get_n(const Calciatore & c) { return c.Goal;}

// Dato c consente l'aggiornamento del campo Goal
//void update(Calciatore & c, const int num) {c.Goal=num;}

// relazione di uguaglianza, stabilisce cioè se i due calciatori in ingresso sono uguali
bool equal(const Calciatore & c1, const Calciatore & c2) {
	return (!strcmp(c1.Nome,c2.Nome) && !strcmp(c1.Cognome,c2.Cognome) && !strcmp(c1.Squadra,c2.Squadra) && (c1.Goal==c2.Goal));
}

void copiaCalciatore(Calciatore & C1, const Calciatore & C2) {
	
	delete [] C1.Nome;
	delete [] C1.Cognome;
	delete [] C1.Squadra;
	C1.Nome=new char [strlen(C2.Nome)+1];
	strcpy(C1.Nome, C2.Nome);
	C1.Cognome=new char [strlen(C2.Cognome)+1];
	strcpy(C1.Cognome, C2.Cognome);
	C1.Squadra=new char [strlen(C2.Squadra)+1];
	strcpy(C1.Squadra, C2.Squadra);
	C1.Goal=C2.Goal;
	
}









