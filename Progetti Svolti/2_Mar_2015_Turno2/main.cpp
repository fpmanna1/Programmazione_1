/* Si realizzi la gerarchia Attivita (classe base), Processo (classe derivata). La classe Attivita ha le variabili menbro: 
	"	PID (intero), 
	"	Descrizione (stringa di caratteri allocata dinamicamente),
	"	Started (boolean). 
	La classe Processo aggiunge le variabili membro: 
	"	NomeImmagine (stringa di caratteri allocata dinamicamente) 
	"	Stato (carattere). Lo stato può essere R (in esecuzione), P (Pronto), W (In attesa). 
	Si implementino per le classi della gerarchia le funzionalità necessarie ad una corretta gestione dell'estensione dinamica, 
	l'overloading degli operatori >> e <<, le funzioni set e get. 
	Si implementi per entrambe le classi la funzionalità Attiva che implementata dalla classe 
	Attività pone a true la variabile membro Started e implementata dalla classe Processo pone a true la variabile membro Started e 
	a R la variabile membro Stato solo se lo stato corrente è P.
	Si realizzi quindi una coda di processi ricorrendo ad una implementazione mediante lista a puntatori. 
	la cui funzione di inserimento effettua un normale inserimento in coda FIFO, 
	mentre la funzione di estrazione elimina dalla coda il primo dei processi pronti. 
	Si gestiscano ovviamente i casi coda piena, coda vuota e assenza di processi pronti. 
	La funzione di inserimento lancia una eccezione (classe definita dallo studente) nel caso si tenti di inserire in coda un PID già presente. 
	
	Si implementino inoltre le funzionalità
	"	GetP che restituisce il numero dei processi pronti presenti nella coda,
	"	Schedule che fornito in ingresso un PID consente di attivare il processo corrispondente (se possibile) e 
		comporta la rimozione immediata dalla coda
	"	Show che stampa a video l'elenco dei processi in coda
	"	Store che stampa tale elenco su file di tipo testo.

Si realizzi un programma di test che consenta all'utente di operare sulla coda attraverso un menù, 
consentendo le operazioni di inserimento, attivazione, rimozione, show e stampa.
*/

#include <iostream>
#include <fstream>
#include "Processo.h"
#include "Lista.h"
#include "Eccezione.h"
#define DESTINAZIONE "dati.txt"

using std::cout; using std::cin;
using MS::Processo;
using MS::Attivita;
using MS::Lista;
using MS::Eccezione;
using std::ostream;
using std::ofstream;

int main() 
{

	char continua;
	short int opzione;
	Processo p1, temp;
	Lista list;
	ofstream OutFile;
	
	do{
		cout<<"---------------------PROGRAMMA DI GESTIONE DI UNA CODA DI PROCESSI---------------------------"<<endl;
		cout<<endl;
		cout<<"Scegli una delle seguenti opzioni :"<<endl;
		cout<<"[1] Inserimento processo"<<endl;
		cout<<"[2] Attivazione processo"<<endl;
		cout<<"[3] Inserimento in coda del processo (usa prima la [1])"<<endl;
		cout<<"[4] Rimozione processo dalla coda"<<endl;
		cout<<"[5] Stampa a video della coda"<<endl;
		cout<<"[6] Stampa su file della coda"<<endl;
		
		cin>>opzione;
		
		switch(opzione)
		{
			case 1:
				cout<<"Inserisci processo : "<<endl;
				cin>>p1;
				break;
			case 2:
				p1.Attiva();
				cout<<"Processo attivato con successo"<<endl;
				break;
			case 3:
				try{
					if(p1.get_pid()!=0)
					{
						list.insertCoda(p1);
						cout<<"Il processo ricevuto con l'opzione [1] e' stato inserito in coda"<<endl;
					}else cout<<"Utilizzare prima il comando [1] per prelevare un processo"<<endl;
					}catch(Eccezione& e)
					{
						cout<<e.what()<<endl;
					}
					
				break;
			case 4:
				if(list.estrazione(temp))
					cout<<"Processo correttamente estratto dalla coda!"<<endl;
					else{
						cout<<"Il processo non e\' stato estratto dalla coda!"<<endl;

					}
				break;
			case 5:
				cout<<"Stampa della coda di processi : "<<endl;
				list.show();
				break;
			case 6:
				OutFile.open("dati.txt");
				if(!OutFile)
					cout <<"Errore di apertura del file!"<<endl;
					else{ 
						list.store(OutFile);
					}
					OutFile.close();
				break;
			default:
				cout<<"Inserisci un numero da 1 a 6!!!"<<endl;
			}
		cout<<"Vuoi effettuare un'altra operazione? (S/N)"<<endl;
		cin>>continua;
		
	}while(continua=='s' || continua=='S');
	
	return 0;
}
