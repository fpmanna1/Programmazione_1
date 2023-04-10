#include <iostream>
#include "ElencoFreschi.h"

using MS::Alimentari;
using MS::ProdottiFreschi;
using MS::ElencoFreschi;

int main()
{
	ProdottiFreschi p1("1", "Barattolo", 12, 3.5, "1/11/21");
	ProdottiFreschi p2("2", "Bicchiere", 10, 10.34, "2/11/21");
	ProdottiFreschi p3("3", "Mestolo", 1, 1, "3/11/21");
	ProdottiFreschi p4("4", "Pasta", 4, 2.30, "4/11/21");
	ProdottiFreschi p5("5", "Gelato", 9, 3.57, "5/11/21");
	
	ElencoFreschi e;
	ofstream OutFile;
	e.insert(p1);
	e.insert(p2);
	e.insert(p3);
	cout<<e<<endl;
	cout<<endl;
	e.elimina("1");
	cout<<e;
	
	return 0;
}
