#include "Elenco.h"

int main()
{
	/* MAIN DI PROVA PER LA PARTE "VOCE"
	Voce v1, v2;
	cout <<"Inserisci chiave numerica e descrizione del primo:  ";	
	read(v1);	
	write(v1); cout<<endl;
	cout <<"Inserisci chiave numerica e descrizione del secondo:  ";
	read(v2);
	write(v2); cout<<endl;
	if(greater_than(v1,v2))
		cout<<"Maggiore";
	cout<<"Voci dopo la modifica : ";
	copy(v1,v2); //copio in v2, v1
	write(v1); cout<<endl; write(v2); cout<<endl; */
	
	//MAIN DI PROVA PER LA PARTE "ELENCO"
	Elenco e1;
	Voce v1;
	int size=0, pos=0;  //size è una sorta di riempimento
	int sizealloc=0; //numero vettori effettivamente allocati nell'elenco
	cout<<"Quanti elementi devo allocare per il primo elenco? ";
	cin>>sizealloc;
	//INIZIALIZZO L'ELENCO
	iniz(e1, sizealloc);
	cout<<"Elenco inizializzato : ";
	writeElenco(e1, sizealloc);
	cout<<"Numero elementi che vuoi inserire : ";
	cin>>size;
	cout<<endl;
	//INSERIMENTO DATI ELENCO
	cout<<"Inserisci dati elenco : ";
	readElenco(e1, size);
	cout<<endl;
	//STAMPA ELENCO
	cout<<"Stampa elenco inserito : ";
	writeElenco(e1,sizealloc);
	//VERIFICA SE È PRESENTE UN CERTO ELEMENTO E NE INDICA LA POSIZIONE SE PRESENTE
	cout<<"Inserisci elemento da ricercare : ";
	//destroy(v1);
	//create(v1);
	read(v1);
	cout<<endl;
	if(in(e1, size, v1, pos))
		cout<<"L'elemento e\' presente in posizione "<<pos<<endl;
		else
			cout<<"L'elemento non e\' presente !"<<endl; 
			
	//INSERIMENTO ELEMENTO NELL'ELENCO NON ORDINATO
	cout<<"Inserisci ulteriore riga nell'elenco NON ordinato : ";
	read(v1); 
	//VERIFICA SE L'ELEMENTO È STATO INSERITO CORRETTAMENTE
	if(insert(e1, sizealloc, v1))
		cout<<"Elemento inserito correttamente!";
		else{
			cout<<"Elemento non inserito!";}
	cout<<endl;
	writeElenco(e1, sizealloc);
	cout<<endl; 
	
	//ORDINA ELENCO SUL CAMPO KEY
	cout<<"Elenco ordinato sul campo key : ";
	sort(e1, size);
	writeElenco(e1, sizealloc);
	cout<<endl; 
	//INSERIRE UN NUOVO ELEMENTO RISPETTANDO L'ORDINAMENTO
	cout<<"Inserisci ulteriore riga nell'elenco ordinato : ";
	read(v1);
	if(insert_ord(e1, sizealloc, v1))
		cout<<"Elemento inserito correttamente!";
			else
				cout<<"Elemento non inserito!";
	writeElenco(e1, sizealloc); 
	
	//RIMUOVERE UN ELEMENTO
	cout <<"Inserisci elemento che vuoi eliminare : ";
	read(v1);
	rm(e1, size, v1);
	writeElenco(e1, size);
	
	//CONTROLLA SE È ORDINATO
	if(is_sorted(e1, size))
		cout<<"Gia\' ordinato"<<endl;
		else
			cout<<"Non ordinato"<<endl; 
	//CONTROLLA SE È PIENO
	if(full(e1, sizealloc))
		cout<<"Pieno"<<endl;
		else
			cout<<"C'e\' ancora spazio"<<endl;
	//CONTROLLO SE È VUOTO
	if(empty(e1, sizealloc))
		cout<<"Vuoto"<<endl;
		else
			cout<<"Non vuoto!"<<endl;
    return 0;
}

