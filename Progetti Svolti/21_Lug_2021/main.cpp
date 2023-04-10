#include "Voce.h"
#include "Ingredienti.h"
#include "Pizza.h"

using namespace MS;
using std::cin;
using std::cout;

int main() {
	
	/*Voce v;
	cin>>v;
	cout<<v;*/
	
	Ingredienti lista;
	Ingredienti lista2(lista);
	
	string s = "pomodoro";
	string s2 = "mozzarella";
	
	lista.push(s);
	cout << lista;
	cout<<endl;
	try{
		lista.push(s2);
	}catch(Errore & e)
	{	
		cout << e.what();
	}
	cout << lista <<endl;
	
	cout << lista2 << endl;
	Pizza p1(549, "al forno", 3.5, "ripieno", lista);
	cout << p1;
	return 0;
}
