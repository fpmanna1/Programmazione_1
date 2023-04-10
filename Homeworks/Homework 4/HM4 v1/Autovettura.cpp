#include "Autovettura.h"

bool check_Classe(short int C)
{
	return(C >= 2 && C <= 8);
}

Autovettura::Autovettura(const char *T, const char *M, const char *MO, short int C) : Veicolo(T,M){
	if(check_Classe(C))
	{
		this->Classe=C;
	}	else 
			this->Classe=2;
	Modello = new char[strlen(MO)+1];
	strcpy(Modello, MO);
}

Autovettura::Autovettura(const Autovettura &A) : Veicolo(A) 
{
	if(check_Classe(A.Classe))
	{
		Classe=A.Classe;
	}else 
		this->Classe=2; 
	Modello = new char[strlen(A.Modello)+1];
	strcpy(Modello, A.Modello);
}

void Autovettura::set_Modello(const char *M)
{
	delete [] this->Modello;
	Modello = new char[strlen(M)+1];
	strcpy(this->Modello, M);
}

const Autovettura& Autovettura::operator=(const Autovettura &A)
{
	if(this!=&A)
	{
		Veicolo::operator!=(A);
		Classe = A.Classe;
		delete [] Modello;
		Modello = new char[strlen(A.Modello+1)];
		strcpy(Modello, A.Modello);
	}
	return *this;
}

ostream & Autovettura::write(ostream &out) const
{
	Veicolo::write(out);
	out << " " << Modello << " " << Classe;
	return out;
}

istream & Autovettura::read(istream &in)
{
	Veicolo::read(in);
	char buffer[300];
	in.getline(buffer, 300);
	set_Modello(buffer);
	short int buffer2;
	in >> buffer2;
	set_Classe(buffer2);
	return in;
}

double Autovettura::calcolo_Pedaggio()const
{
	switch(this->Classe){
		case 2: 
			return 1.00;
			break;
		case 3:
			return 1.60;
			break;
		case 4:
			return 2.05;
			break;
		case 5:
			return 2.55;
			break;
		case 6:
			return 3.00;
			break;
		case 7:
			return 3.45;
			break;
		case 8:
			return 3.90;
			break;
		default:
			cout <<"Inserisci una classe da 2 a 8!"<<endl;
			break;
			
			/*
			double costo[7]={1.00f, 1.60f .....};
			return costo[Classe - 2];
			*/
	}
}
