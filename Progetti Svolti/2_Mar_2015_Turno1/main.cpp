#include "Auto.h"
#include "Garage.h"
#include "Moto.h"

using namespace MS;

int main()
{
	ofstream OutFile;
	Auto a("auto", "ciao", "manna");
	Moto m("moto", "ciao2", "manna2");
	Garage g;
	Veicolo * puntauto = new Auto();
	Veicolo * puntmoto = new Moto();
	puntauto = &a;
	puntmoto = &m;
	g.insert(puntauto);
	g.insert(puntmoto);
	g.insert(puntauto);
	g.insert(puntmoto);
	g.insert(puntauto);
	g.insert(puntmoto);
	
	g.estrazione(5);
	g.store(OutFile);
	
	cout << a.totext();
	
		
	return 0;
}
