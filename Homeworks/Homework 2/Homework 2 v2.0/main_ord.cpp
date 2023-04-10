/*#include "ElencoOrd.h"

int main()
{
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
	cout<<"************************GESTIONE ELENCO ORDINATO***********************************"<<endl;
	ok=true;
	
	do{
		do{
		ok=true;
		cout<<"Seleziona l'azione da compiere : "<<endl;
		cout<<"(1) Verifica se e\' presente un certo elemento nell'elenco"<<endl;
		cout<<"(2) Verifica se l'elenco e\' pieno"<<endl;
		cout<<"(3) Verifica se l'elenco e\' vuoto"<<endl;
		cout<<"(4) Inserisce un nuovo elemento rispettando l'ordinamento"<<endl;
		cout<<"(5) Rimuove un elemento dall'elenco"<<endl;
		cin>>scelta;
		if(scelta<0 || scelta>5)
		{
			cout<<"Errore! Inserisci un numero da 1 a 5"<<endl;
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
			case 2: if(full(e, size))
						cout<<"L'elenco e\' pieno"<<endl;
						else
							cout<<"L'elenco non e\' pieno"<<endl;
				break;
			case 3: if(empty(e, size))
						cout<<"L'elenco e\' vuoto"<<endl;
						else
							cout<<"L'elenco non e\' vuoto"<<endl;
				break;
			case 4: cout<<"Elemento da inserire : ";
					read(v);
					if(insert_ord(e, size, v))
					{
						cout<<"Elemento inserito correttamente"<<endl;
						writeElenco(e, DIM_MAX);
					}else
							cout<<"Elemento non inserito";
				break;
			case 5: cout<<"Inserisci elemento da rimuovere: "; read(v); cout<<endl;
					cout<<"Elemento rimosso"<<endl;
					writeElenco(e, DIM_MAX);
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
} */
