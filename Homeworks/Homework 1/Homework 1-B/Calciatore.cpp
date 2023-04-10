#include <iostream>
#include <string.h>
#include "Calciatore.h"

using namespace std;

static int glob=0;

void read(Calciatore &c)
{
	bool ripeti=false;
	do{
	ripeti=false;
	cout <<"nome : "; cin >> c.nome; 
	if(strlen(c.nome) > 14)
	{
		cout<<"Errore! Stringa troppo lunga! Reinserisci il nome!  -> ";
		ripeti = true;
	}
	}while(ripeti);
	
	do{
	ripeti=false;
	cout <<"cognome : "; cin >> c.cognome; 
	if(strlen(c.cognome) > 14)
	{
		cout<<"Errore! Stringa troppo lunga! Reinserisci il cognome!  -> ";
		ripeti = true;
	}
	}while(ripeti);
	
	do{
	ripeti=false;
	cout <<"squadra : "; cin >> c.squadra; 
	if(strlen(c.squadra) > 14)
	{
		cout<<"Errore! Stringa troppo lunga! Reinserisci la squadra!  -> ";
		ripeti = true;
	}
	}while(ripeti);
	cout <<"goal : "; cin.ignore() >> c.goal;
	cout<<endl;
}

//void stampa(Calciatore c){cout << c.nome<< " - " << c.cognome<< " - " << c.squadra << " - " << c.goal;}
//void update(Calciatore &c, int num){c.goal= num;}
//int get_goal(Calciatore &c){return c.goal;}

bool equal(Calciatore c, Calciatore c2)
{
	if(strcmp(c.nome, c2.nome)==0 && strcmp(c.cognome, c2.cognome)==0 && strcmp(c.squadra, c2.squadra)==0)
		return true;
	return false;
}

void init(Elenco l, int nelem)
{
	for(short int i=0; i<nelem; ++i)
	{
		strcpy(l[i].nome,"*");
		strcpy(l[i].cognome, "*");
		strcpy(l[i].squadra,"*");
		l[i].goal=0;
	}
}

void write(Elenco l, int nelem)
{
	for(short int i=0; i<nelem; ++i)
	{
		cout << l[i].nome<<" ";
		cout << l[i].cognome<<" ";
		cout << l[i].squadra<<" ";
		cout << l[i].goal<<" "<<endl;
	}
}

int in(Elenco l, int nelem, Calciatore c, int pos)
{
	for(int i=0; i<nelem; i++)
	{
		if((strcmp(c.nome, l[i].nome)==0 && (strcmp(c.cognome, l[i].cognome)==0 && (strcmp(c.squadra, l[i].squadra)==0))))
		{
			pos=i;
			glob=pos;
			return pos+1;
		}
	}
	return 0; //non è presente
}

bool insert(Elenco l, int nelem, Calciatore c)
{
	for(int i=0 ; i<nelem; i++)
	{
		read(c);
		if(in(l, nelem, c, glob)==0)
		{
			strcpy(l[i].nome,c.nome);
			strcpy(l[i].cognome,c.cognome);
			strcpy(l[i].squadra,c.squadra);
			l[i].goal=c.goal;
		}else{
			cout << "Gia' presente in posizione "<<in(l, nelem, c, glob)<< "! Inserisci un valore diverso!"<<endl;
			i=i-1;
		}
	}
}

void classifica(Elenco l, int nelem)
{
	/*char temp[15];
	int temp2 = 0; */
	Calciatore tempo;
	for(short int j=0;j<nelem-1;j++)
	{
		for(short int i=0;i<nelem-1;i++)
		{
			if(l[i].goal>l[i+1].goal)
			{
				tempo=l[i];
				l[i]=l[i+1];
				l[i+1]=tempo;
				/*strcpy(temp,l[i].nome);
				strcpy(l[i].nome,l[i+1].nome);
				strcpy(l[i+1].nome,temp);
				strcpy(temp,l[i].cognome);
				strcpy(l[i].cognome,l[i+1].cognome);
				strcpy(l[i+1].cognome,temp);
				strcpy(temp,l[i].squadra);
				strcpy(l[i].squadra,l[i+1].squadra);
				strcpy(l[i+1].squadra,temp);
				temp2=l[i].goal;
				l[i].goal=l[i+1].goal;
				l[i+1].goal=temp2; */
			}
		}
	}
}

void copy(Elenco l,int nelem,Elenco l2,int nelem2)
{
	for(int i=0; i<nelem2; i++)
	{
		l[i]=l2[i];
	}
	if(nelem2 < nelem)
	{
		for(int j=nelem2; j<nelem; j++)
		{
			strcpy(l[j].nome,"*");
			strcpy(l[j].cognome,"*");
			strcpy(l[j].squadra,"*");
			l[j].goal=0;
		}
	}
}
