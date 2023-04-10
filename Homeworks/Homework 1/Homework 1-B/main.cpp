#include <iostream>
#include <string.h>
#include "Calciatore.h"

using namespace std;

int main()
{
	Calciatore c, c2;
	Elenco l,l2;
	short int nelem;
	short int nelem2;
	//PARTE CALCIATORI
	char scelta;
	int num = 0;
	/* cout << "Inserisci il nome,cognome,squadra e goal del primo calciatore : ";
	read(c);
	cout << "Il calciatore inserito e\' : ";
	stampa(c);
	cout<<endl;
	cout << "Inserisci il nome,cognome,squadra e goal del secondo calciatore : ";
	read(c2); 
	cout << "Il calciatore inserito e\' : ";
	stampa(c2);
	cout<<endl;
	cout << "Vuoi modificare il valore dei goal ? (S/N) ";
	cin >> scelta;
	if(scelta == 's' || scelta == 'S')
	{
		cout << "Nuovo valore da inserire : ";
		cin >> num;
		update(c, num);
		cout << "Nuovo valore dei goal : " << get_goal(c);
	}
	if(equal(c,c2))
		cout << "I dati dei due calciatori sono uguali";
	else
		cout << "I dati dei due calciatori sono diversi";
	*/
	
	//PARTE ELENCO
	bool ok=false;
	do{
		ok=false;
		cout << "\n\nDimensioni elenco (MAX 20) : "; cin>>nelem;
		if(nelem > DIM)
		{
			cout<<"Devi inserire un numero <= a 20!!!!";
			ok=true;
		}
	}while(ok);
	init(l,nelem);
	init(l2,nelem);
	write(l, nelem);
	cout<<endl;
	insert(l, nelem, c);
	cout<<endl;
	write(l, nelem);
	classifica(l, nelem);
	cout<<"\nElenco ordinato sul campo goal : "<<endl;
	write(l, nelem);
	ok=false;
	do{
		ok=false;
		cout << "\n\nDimensioni secondo elenco (MAX 20) : "; cin>>nelem2;
		if(nelem2 > nelem)
		{
			cout<<"Devi inserire un numero <= a "<<nelem<<"!!";
			ok=true;
		}
	}while(ok);
	cout<<"\nInserimento del secondo elenco : "<<endl;
	insert(l2, nelem2, c);
	cout<<"Ecco il secondo elenco : "; write(l2, nelem);
	cout<<endl;
	cout<<"Primo Elenco prima : "<<endl;
	write(l,nelem);
	cout<<endl;
	copy(l,nelem,l2,nelem2);
	cout<<"Primo Elenco dopo : "<<endl;
	write(l, nelem);
	return 0;
}
