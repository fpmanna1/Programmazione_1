#include "Coda.h"
#include "Eccezione.h"
#include "Autoveicolo.h"
#include "Motoveicolo.h"

using MS::Coda;
using MS::Eccezione;
using std::endl;
using std::cin;
using MS::Veicolo;
using MS::Autoveicolo;
using MS::Motoveicolo;
using MS::T;

int main() 
{
	Coda c;
	T temp, temp2;
	Autoveicolo a1("Fiat", "Panda", 200, 5, 3);
	Autoveicolo a2("Peaugeot", "300", 100, 5, 4);
	Autoveicolo a3("Fiat", "Panda", 200, 5, 3);
	Autoveicolo a4("Fiat", "Punto", 220, 3, 3);
	
	try{

		temp = new Autoveicolo("Fiat", "Panda", 200, 5, 3);
		c.insert(temp);
		temp = new Autoveicolo("Opel", "Corsa", 150, 4, 5);
		c.insert(temp);
		temp= new Motoveicolo("Honda", "X450Z", 50, 3, 'C');
		c.insert(temp);
		//c.pop();
		
		
		cout<<c<<endl;
	}catch(Eccezione e)
	{
		cout << e.what();
	} 
	return 0;
}
