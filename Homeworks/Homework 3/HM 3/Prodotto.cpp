#include "Prodotto.h"

//IMPLEMENTAZIONE COSTRUTTORI E DISTRUTTORE

/*Prodotto::Prodotto(){
	cout << "chiamato costruttore senza argomenti"<<endl;
	strcpy(Codice, "AA000");	
	Descrizione = new char[1];
	strcpy(Descrizione, "");
} */

Prodotto::Prodotto(const char * cod, const char *des) 
{
	strcpy(this->Codice, cod);
	Descrizione = new char[strlen(des)+1];
	strcpy(this->Descrizione, des);
}


Prodotto::Prodotto(const Prodotto &p)
{
	strcpy(this->Codice, p.Codice);
	Descrizione=new char[strlen(p.Descrizione)];
	strcpy(this->Descrizione, p.Descrizione);
}

//IMPLEMENTAZIONE OPERATORI

bool Prodotto::operator==(const Prodotto &p) const
{
	return(!strcmp(this->Codice, p.Codice) && !strcmp(this->Descrizione, p.Descrizione));
}

bool Prodotto::operator!=(const Prodotto &p)const
{
	return(strcmp(this->Codice, p.Codice) || strcmp(this->Descrizione, p.Descrizione));
}

ostream& operator<<(ostream &out, const Prodotto &p)
{
	return(out<<p.Codice << " " << p.Descrizione);	
}

istream& operator>>(istream &in, Prodotto &p)
{
	in>>p.Codice; in>>p.Descrizione;
	return in;
}

const Prodotto& Prodotto::operator=(const Prodotto &p)
{
	if(this!=&p)
	{
		strcpy(this->Codice, p.Codice);
		delete [] this->Descrizione;
		Descrizione= new char[strlen(p.Descrizione)+1];
		strcpy(this->Descrizione, p.Descrizione);
	}
	return *this;
}

bool Prodotto::valido()const
{
	if(strlen(this->Codice)!=5)
		return false;
		
	for(int i=0; i<2; i++) //controlla se i primi 2 elementi sono lettere maiuscole utilizzando il codice ASCII
		if(this->Codice[i]<65 || this->Codice[i]>90)
			return false;

	for(int j=2; j<strlen(this->Codice); j++) //controlla se gli ultimi 3 elementi sono numeri
		if(this->Codice[j]<48 || this->Codice[j]>57)
			return false;
	return true;
}




