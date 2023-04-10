#include "Pila.h"

using MS::Pacco;
using MS::Pila;
using std::cin;
using MS::FileExcep;

int main()
{
	
	Pacco pacco;
	Pacco p2(123, 4.6, "pippo");
	/*cin >> p;
	cout << p; */
	T t;
	
	Pila p;
	p.push(pacco);
	p.push(pacco);
	p.push(p2);
	//p.pop(t);
	//cout << p;
	
	ifstream InFile;
	Pila p4;
	p4.leggidafile(InFile);
	cout << p4;
	
	
	
	system("pause");
	return 0;
}
