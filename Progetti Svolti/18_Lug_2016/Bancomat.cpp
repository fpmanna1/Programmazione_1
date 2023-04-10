#include "Bancomat.h"


namespace MS{
	
	Bancomat::Bancomat(const char * t, const char * i, const char * nc, bool a) : Carta(t, i, nc)
	{
		attivata=a;
	}
	
	const Bancomat & Bancomat::operator=(const Bancomat & b)
	{
		if(this!=&b)
		{
			Carta::operator=(b);
			attivata = b.attivata;
			set_scadenza(b.scadenza);
		}
		return *this;
	}
	
	void Bancomat::attiva()
	{
		attivata=true;
		char offset[4]="AAA";
		char temp1[100];
		char temp2[6];
		char temp3[100];
		strcpy(temp3, get_numero_carta());
		for(int i=0; i<5; i++)
		{
			temp2[i]=temp3[i];
		}
		strcpy(temp1, temp2); //5 cifre
		strcat(temp1, offset); //+3
		
		if(this->pin)
			delete [] this->pin;
		pin = new char[strlen(temp1)+1];
		strcpy(pin, temp1);
	}
	
	bool Bancomat::check(const char * s) throw(Eccezione)
	{
		if(attivata=true)
		{
			if(strcmp(this->pin, s)!=0)
			{
				throw Eccezione("Pin errato");
				return false;
			}else{
				return true;
			}	
		}else{
			throw Eccezione("Tessera non attivata!");
			return false;
		}
	}
	
	ostream & Bancomat::print(ostream & out)const
	{
		Carta::print(out);
		out << " " << pin << " " << attivata << " " <<scadenza;
		return out;
	}
	
	ostream & operator<<(ostream &out, const Bancomat & b)
	{
		b.print(out);
		return out;
	}
	
	istream & Bancomat::input(istream & in)
	{
		Carta::input(in);
		char buffer[200];
		in.getline(buffer, 100);
		set_pin(buffer);
		in.getline(buffer, 100);
		int buffer2;
		in>>buffer2;
		attivata=buffer2;
		return in;
	}
	
	istream & operator>>(istream & in, Bancomat & b)
	{
		return b.input(in);
	
	}
}
