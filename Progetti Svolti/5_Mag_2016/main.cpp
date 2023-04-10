#include "Myvet.h"
#include <cstring>

using MS::Vettore;
using std::cin;
using std::cout;
using std::endl;
using MS::Myvet;

int main()
{
	Myvet v(4);
	cin >> v;
	cout << v;
	int pos;
	int last=v.get_dim()-1;
	int first=0;
	v.sort();
	
	cout << v;
	/*if(v.ordinato())
		cout << "vettore ordinato";
		else
			cout << "vettore non ordinato"; */
	/*try{
		if(v.bin_search(3, pos, first, last ))
			cout << "TROVATO"<<endl;
			else
				cout << "NON TROVATO"<<endl;
	}catch(Eccezione e)
	{
		cout << e.what()<<endl;
		v.sort();
	}  */
	char buffer[100];
	strcpy(buffer, "dati.txt");
	char * s = new char[strlen(buffer)+1];
	v.store(s);
	
	return 0;
}
