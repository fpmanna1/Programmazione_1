#include "Spettacolo.h"
#include "Concerto.h"
#include "Biglietto.h"
#include "Elenco.h"

using MS::Elenco;
using MS::Evento;
using std::cin;
using MS::Spettacolo;
using MS::Concerto;
using MS::Biglietto;
using MS::Errore;

int main()
{
	/*Evento e;
	cin >> e;
	cout << e; */
	Spettacolo s;
	/*cin >> s;
	cout << s; */
	Concerto c;
	/*cin >> c;
	cout << c; */
	Biglietto b1(123, 4.0, &s);
	Biglietto b2(456, 6.98, &c);
	/*cin >> b1;
	cout << b1;
	cout << endl;
	//cin >> b2;
	cout << b2; */
	
	Elenco e;
	e.push(b1);
	e.push(b2);
	try{
		e.push(b1);
	}catch(Errore e)
	{
		cout << e.what()<<endl;
	}
	e.store();
	
	cout << e;
	
	system("pause");
	return 0;
}
