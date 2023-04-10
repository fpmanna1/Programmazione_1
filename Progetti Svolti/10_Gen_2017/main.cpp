#include "Libro.h"
#include "Cellulare.h"
#include "Insieme.h"

using MS::Oggetto;
using std::cin;
using MS::Libro;
using MS::Cellulare;
using MS::Insieme;
using MS::bad_item;

int main() 
{
	
	/*Oggetto o;
	cout << o;
	cin >> o;
	cout << o; */
	Libro l;
	Cellulare c;
	Insieme i(5);
	i.push(&l);
	i.push(&c);
	/*try{
		i.push(&l);
	}catch(bad_item e)
	{
		e.what();
	}
	//i.pop(); */
	cout << i;
	
	cout<<"\n"<<endl;
	/*i2.leggidafile();
	cout << i2; */
	Insieme i3(4);
	
	Insieme i4(4);
	Libro l1(123, "eefvfe", "efvfvf","titolo", 245);
	Cellulare c1(345, "fvvvv", "wcede", "galaxy", 4.9);
	i4.push(&l1);
	i4.push(&c1);
	cout << i4;
	i3 = i.unione(i4);
	cout << i3;
	system("pause");
	return 0;
}
