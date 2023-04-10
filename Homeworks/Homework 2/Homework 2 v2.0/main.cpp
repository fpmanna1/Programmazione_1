#include "Elenco.h"

int main()
{
	/*MAIN DI PROVA PER LA PARTE "VOCE" 
	Voce v1, v2;
	cout <<"Inserisci chiave numerica e descrizione del primo:  ";	
	read(v1);	
	write(v1); cout<<endl;
	cout <<"Inserisci chiave numerica e descrizione del secondo:  ";
	read(v2);
	write(v2); cout<<endl;
	if(greater_than(v1,v2))
		cout<<"Maggiore";
			else
				cout <<"Minore";
	cout<<"Voci dopo la modifica : ";
	copy(v1,v2); //copio in v2, v1
	write(v1); cout<<endl; write(v2); cout<<endl; 
	*/
	Elenco e;
	int pos, size=0;
	unsigned short int scelta;
	Voce v;
	char cont;
	bool ok=true, continua=true;
	do{
		ok=true;
		cout<<"Quanti elementi vuoi inserire ? (max "<<DIM_MAX<<") : ";
		cin>>size;
		if(size>DIM_MAX)
		{
			cout<<"Numero troppo grande!"<<endl;
			ok=false;
		}
	}while(!ok);
	cout<<"Inserisci elenco : ";
	readElenco(e, size);
	cout<<endl;
	cout<<"Visualizzazione Elenco : "<<endl;
	writeElenco(e, DIM_MAX);
	cout<<"\n"<<endl;
	cout<<"************************GESTIONE ELENCO***********************************"<<endl;
	ok=true;
	
	do{
		do{
		ok=true;
		cout<<"Seleziona l'azione da compiere : "<<endl;
		cout<<"(1) Verifica se e\' presente un certo elemento nell'elenco"<<endl;
		cout<<"(2) Ordina l'elenco sul campo key"<<endl;
		cout<<"(3) Verifica se l'elenco e\' pieno"<<endl;
		cout<<"(4) Verifica se l'elenco e\' vuoto"<<endl;
		cout<<"(5) Inserisce un nuovo elemento nella prima posizione libera"<<endl;
		cout<<"(6) Rimuove un elemento dall'elenco"<<endl;
		cout<<"(7) Verifica se l'elenco e\' ordinato"<<endl;
		cin>>scelta;
		if(scelta<0 || scelta>7)
		{
			cout<<"Errore! Inserisci un numero da 1 a 7"<<endl;
			ok=false;
		}
		}while(!ok);
		
		continua=false;
		switch(scelta)
		{
			case 1: cout<<"Inserisci elemento da ricercare : ";
					read(v);
					if(in(e, size, v, pos))
						cout<<"L'elemento inserito e\' presente in posizione "<<pos<<endl;
						else
							cout<<"Elemento non presente"<<endl;
				break;
			case 2: sort(e, size);
					cout<<"Elenco Ordinato : "<<endl;
					writeElenco(e, DIM_MAX);
					cout<<endl;
				break;
			case 3: if(full(e, size))
						cout<<"L'elenco e\' pieno"<<endl;
						else
							cout<<"L'elenco non e\' pieno"<<endl;
				break;
			case 4: if(empty(e, size))
						cout<<"L'elenco e\' vuoto"<<endl;
						else
							cout<<"L'elenco non e\' vuoto"<<endl;
				break;
			case 5: cout<<"Elemento da inserire : ";
					read(v);
					if(insert(e, size, v))
					{
						cout<<"Elemento inserito correttamente"<<endl;
						writeElenco(e, DIM_MAX);
					}else
							cout<<"Elemento non inserito";
				break;
			case 6: cout<<"Inserisci elemento da rimuovere: "; read(v); cout<<endl;
					remove(e, size, v);
					cout<<"Elemento rimosso"<<endl;
					writeElenco(e, DIM_MAX);
				break;
			case 7: if(is_sorted(e, size))
						cout<<"L'elenco e\' ordinato"<<endl;
						else
							cout<<"L'elenco non e\' ordinato"<<endl;
				break;
				
			default: cout<<"Inserisci un carattere valido!"<<endl;
				break;
		}
		cout<<"Vuoi effettuare qualche altra operazione? ";
		cin>>cont;
		if(cont=='s' || cont=='S')
			continua=true;	
	}while(continua);
	
	return 0;
} 
