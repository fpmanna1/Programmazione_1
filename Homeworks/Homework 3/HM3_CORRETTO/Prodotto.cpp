#include "Prodotto.h"

bool check_codice(const char *s)
{
	if(strlen(s)!=SMAX-1) return false;
	bool A=((s[0]>='A' && s[0]<='Z') && (s[1]>='A' && s[1]<='Z'));
	bool B=true;
	int i=2;
	while(i<SMAX-1)
		if(!(s[i]>='0' && s[i]<='9')) B=false;
	else i++;
	return(A&&B);
}

ostream& operator<<(ostream & out, const Prodotto &P){
	out << P.Codice << ' ' << ' ' << P.Descrizione;
	return out;
}; //non membro ma amiche

istream& operator<<(istream & in, Prodotto & P){
	char buffer[300];
	in.getline(buffer, 300);
	P.set_Descrizione(buffer);
	in.getline(buffer, 300);
	if(check_codice(buffer)) strcpy(P.Codice, buffer);
	else strcpy(P.Codice, ""); //così gli dice che qualcosa che è andato storto
	return in;
}; //non membro ma amiche

Prodotto::Prodotto(const char * C, const char * D){
	if(check_codice(C)) strcpy(Codice, C);
	else strcpy(Codice, "");
	Descrizione = new char[strlen(D)+1];
	strcpy(this->Descrizione, D);
	//qui non posso usare la set, perchè c'è una delete su un oggetto che ancora non esiste!
}

Prodotto::Prodotto(const Prodotto &P){
	strcpy(Codice, P.Codice);
	Descrizione = new char[strlen(P.Descrizione)+1];
	strcpy(this->Descrizione, P.Descrizione);
}

bool Prodotto::set_Codice(const char *s){
	if(check_codice(s)) 
	{
		strcpy(Codice, s); return true;
	}
	else return false;
}

void Prodotto::set_Descrizione(const char *s){
	delete[] this->Descrizione;
	Descrizione = new char[strlen(s)+1];
	strcpy(this->Descrizione, s);
}

const Prodotto & Prodotto::operator=(const Prodotto &P){
	if(this!=&P)
	{	
		set_Descrizione(P.Descrizione);
		set_Codice(P.Codice);
	}
	return *this;
}

bool Prodotto::operator==(const Prodotto &P) const{
	return(!strcmp(Codice, P.Codice) && !strcmp(Descrizione, P.Descrizione));
}

bool Prodotto::operator!=(const Prodotto &P) const{
	return!(*this==P);
}



