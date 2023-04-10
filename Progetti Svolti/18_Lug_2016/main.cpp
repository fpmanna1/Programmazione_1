#include <iostream>
#include "Carta.h"
#include "Tessera.h"
#include "Bancomat.h"

using MS::Tessera;
using  MS::Bancomat;
using MS::Carta;
using std::cin;
using std::cout;
using std::endl;


int main() 
{
	Carta *ptr1 = new Bancomat();
	cin>>*ptr1;
	cout<<"Carta Inserita: ";
	cout<<*ptr1;
	/*
	Carta *ptr2 = new Tessera();
	cin>>*ptr2;
	cout<<"Tessera Inserita: ";
	cout<<*ptr2; */
	
	return 0;
}
