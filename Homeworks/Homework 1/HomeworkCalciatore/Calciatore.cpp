#include "Calciatore.h"

// consente l'ingresso dei dati di un calciatore da tastiera. 
// Funzioni overloaded al solo scopo esemplificativo
void read(Calciatore & c) {
	cout << "Nome: " << endl;
	cin.getline(c.Nome,MAXS+1);
	cout << "Cognome: " << endl;
	cin.getline(c.Cognome,MAXS+1);
	cout << "Squadra: " << endl;
	cin.getline(c.Squadra,MAXS+1);
	cout << "Goal: " << endl;
	cin >> c.Goal;
}


// consente la visualizzazione dei dati di un calciatore a video
void write(const Calciatore & c) {
	cout << c.Nome << ' ' <<  c.Cognome << ' ' << c.Squadra << ' ' << c.Goal;
}

// Dato c restituisce il valore corrente del campo Goal
//int get_n(const Calciatore & c) { return c.Goal;}

// Dato c consente l'aggiornamento del campo Goal
//void update(Calciatore & c, const int num) {c.Goal=num;}

// relazione di uguaglianza, stabilisce cioè se i due calciatori in ingresso sono uguali
bool equal(const Calciatore & c1, const Calciatore & c2) {
	return (!strcmp(c1.Nome,c2.Nome) && !strcmp(c1.Cognome,c2.Cognome) && !strcmp(c1.Squadra,c2.Squadra) && (c1.Goal==c2.Goal));
}

