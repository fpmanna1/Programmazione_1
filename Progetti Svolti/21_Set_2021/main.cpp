#include "Scheda.h"
#include "Attrazione.h"
#include "Parco.h"
#include "Indipendente.h"

using namespace MS;

int main() {
	
	Scheda s("ABCD", 20, 2, 45);
	Scheda s1("ADEF", 24, 68, 21);
	//cout << s;
	//cout << a;
	Parco p("ATTRAZIONE 1", 5.0, 3);
	
	p.insert(s);
	p.insert(s1);
	p.insert(s);
	Indipendente i;
	
	
	cout << p;
	
	p.calcolo_incasso();
		
	return 0;
}
