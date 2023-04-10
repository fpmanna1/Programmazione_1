#include "Voce.h"
#include "Lista.h"
#include "Frittura.h"
#include "Pizza.h"

using MS::Voce;
using std::cin;
using MS::Lista;
using MS::Pizza;
using MS::Frittura;

int main()
{
	/*Voce v;
	cin >> v;
	cout << v; */
	Lista l;
	l.push("Basilico");
	l.push("Pomodoro");
	l.push("Mozzarella");
	Lista l2;
	l2.push("bianco");
	l2.push("nero");
	l2.push("blu");
	
	
	//cout << l2; 
	Pizza p(678, "Buffet", 6.8, "Margherita", l);
	/*Pizza p2(p);
	Pizza p3;
	cout << p3; */
	Pizza p2;
	cin >> p2;
	cout << p2;
	
	/*cout << endl;
	cout << l;
	Pizza p1;
	cin >> p1;
	cout << p1; */
	
	system("pause");
	return 0;
}
