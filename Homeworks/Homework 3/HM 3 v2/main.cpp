#include "Elenco.h"

int main() {
	
	//MAIN DI PROVA PRODOTTO
/*	Prodotto p1, p2, p3;
	bool valido=true;
	
	cout<<"visualizzazione di p1 con funzioni getters: ";
	cout<<p1.get_Codice()<<" "<<p1.get_Descrizione()<<endl;
	cout<<"Visualizzazione di p1 con operatore overloaded : ";
	cout<<p1<<endl;

	cout<<"operatore di assegnazione: assegno p1 a p2 : "<<endl;
	cout<<"Stampa di p2 : ";
	p2=p1;
	cout<<p2<<endl;
	
	do{
		valido=true;
		cout<<"Inserisci codice (rispettando il formato) e una descrizione : ";
		cin >> p3;
		cout<<endl;
		if(!p3.valido())
		{
			cout<<"Errore! Inserisci una stringa valida : "<<endl;
			valido=false;
		}
	}while(!valido);
	cout<< p2<<endl;
	if(p3==p2)
		cout<<"p3 e p2 sono uguali!"<<endl;
		else
			cout<<"p3 e p2 sono diversi!"<<endl;
	Prodotto p4(p3);
	cout<<"Stampa di p4: "<<p4<<endl; */
	
	//MAIN DI PROVA ELENCO
	
	Elenco e1;
	Prodotto p;
	int riemp;
	bool ok=true;
	do{
		ok=true;
		cout<<"Quanti prodotti vuoi inserire nell'elenco (MAX "<<SIZE<<") ? ->"; cin>>riemp;
		if(riemp > SIZE)
		{
			cout<<"Errore! Il numero di elementi non può superare"<<SIZE<<endl;
			ok=false;
		}	
	}while(!ok);
	readElenco(e1, riemp);
	cout<<"Visualizzazione Elenco : "<<endl;
	writeElenco(e1, riemp);
	cout<<endl; cout<<"Inserisci prodotto da ricercare : "; cin>>p;
	if(ricercaProdotto(e1, p, riemp))
		cout<<"Il prodotto e\' presente!"<<endl;
		else
			cout<<"Il prodotto non e\' presente!"<<endl;
	delete[] p.get_Descrizione(); 
	if(!empty(e1, riemp))
	{
		cout<<endl; cout<<"Inserisci prodotto da eliminare : "; cin>>p;
		if(giapresente(e1, p, riemp))
			remove(e1, p, riemp);
		writeElenco(e1, riemp);
	}
	
	if(full(e1, riemp))
		cout<<"L'elenco e\' pieno!"<<endl;
	if(empty(e1, riemp))
		cout<<"L'elenco e\' vuoto!"<<endl;
	
	system("pause");
	return 0;
}
