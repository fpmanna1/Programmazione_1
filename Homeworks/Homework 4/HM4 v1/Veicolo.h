#ifndef VEICOLO_H
#define VEICOLO_H

#include <cstring>
#include <iostream>

using std::cin; using std::cout;
using std::endl;
using std::istream; using std::ostream;

class Veicolo{	
	private:
		char * Tipo;
		char * Marca;
		
	protected:
		virtual ostream & write(ostream &) const;
		virtual istream & read(istream &);
	
	public:
		friend ostream& operator<<(ostream &, const Veicolo &);
		friend istream& operator>>(istream &, Veicolo &);
		
		//COSTRUTTORI
		Veicolo(const char * = "", const char * = "");
		virtual ~Veicolo(){delete[] this->Tipo; delete[] this->Marca;}
		Veicolo(const Veicolo &);
		
		//SETTERS AND GETTERS
		const char * get_Tipo() const{ return this->Tipo;}
		const char * get_Marca() const{ return this->Marca;}
		void set_Tipo(const char * );
		void set_Marca(const char * );
		
		//OPERATORI
		bool operator==(const Veicolo &v) const{ return !strcmp(Tipo, v.Tipo) && !strcmp(Marca, v.Marca); }
		bool operator!=(const Veicolo &v) const{ return  !(*this==v);} //!operator==(V)
		const Veicolo & operator=(const Veicolo &);
		virtual double calcolo_Pedaggio()const =0;
};



#endif
