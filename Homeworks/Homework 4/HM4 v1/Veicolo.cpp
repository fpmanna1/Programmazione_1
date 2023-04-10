#include "Veicolo.h"

//AREA COSTRUTTORI
Veicolo::Veicolo(const char * T, const char * M)
{
	Tipo= new char[strlen(T)+1];
	strcpy(this->Tipo, T);
	Marca= new char[strlen(M)+1];
	strcpy(this->Marca, M);
}

Veicolo::Veicolo(const Veicolo &v)
{
	Tipo=new char[strlen(v.Tipo)+1];
	strcpy(this->Tipo, v.Tipo);
	Marca=new char[strlen(v.Marca)+1];
	strcpy(this->Marca, v.Marca);
}

//AREA GETTERS AND SETTERS

void Veicolo::set_Tipo(const char * T)
{
	delete [] this->Tipo;
	Tipo = new char[strlen(T)+1];
	strcpy(this->Tipo, T);
}

void Veicolo::set_Marca(const char * M)
{
	delete [] this->Marca;
	Marca = new char[strlen(M)+1];
	strcpy(this->Marca, M);
}


ostream & Veicolo::write(ostream & out) const {
    out << Tipo << ' ' << Marca;
    return out;
}

istream & Veicolo::read(istream & in){

	char buffer[300];
	in.getline(buffer, 300);
	set_Tipo(buffer);
	in.getline(buffer, 300);
	set_Marca(buffer);
	return in;
}
//OPERATORI DI SHIFT

ostream& operator<<(ostream &out, const Veicolo &v)
{
	return v.write(out);
}

istream& operator>>(istream &in, Veicolo &v)
{
	return v.read(in);
	/* 
		string tipo, marca;
		input >> tipo; input >> marca;
		if(v.Tipo ! = 0)
		{
			delete[] v.Tipo;
			V.Tipo = new char[tipo.size()+1];
			strcpy(v.Tipo, tipo.c_str());
		}
	
	*/
}

const Veicolo& Veicolo::operator=(const Veicolo &v)
{
	if(this!=&v)
	{
		set_Tipo(v.Tipo);
		set_Marca(v.Marca);
	}
	return *this;
}

