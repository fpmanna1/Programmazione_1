#include <iostream>
#include "Esercitazione.h"
#include "Tutorial.h"
#include "Errore.h"
#include "Serie.h"

/*using MS::Tutorial;
using MS::Errore;
using std::cin;
using std::cout;
using std::endl;
using MS::Docente;
using MS::Serie; */

using namespace MS;
using namespace std;

int main()
{
	Docente d1("Mattia", "Rossi", "DIETI", "Ingegnere");
	Tutorial t1("AA33", "merda", &d1);
	
	//cout << t1 <<endl;
	//cout << d1;
	Serie s("info");
	//try{
		s.insert(t1);
	
	/*}catch(Errore e)
	{
		cout<<e.what()<<endl;
	} */
	cout<<s;
	return 0;
}
