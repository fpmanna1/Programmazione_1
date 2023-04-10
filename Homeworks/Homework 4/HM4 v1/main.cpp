#include "Autovettura.h"

int main() {
	Autovettura a("Supercar", "Porsche", "Panamera",  4 );
	Autovettura b("Utilitaria", "Fiat", "Panda", 8);
	cout<<"Inserisci tipo, marca, modello e classe : ";
	cin >> a; cout << "Autovettura inserita : "<<a <<endl;
	cout << "L' importo con IVA per a e' : "<<a.calcolo_Pedaggio()<< " euro"<<endl;
	Autovettura c(a);
	cout<<c<<endl;
	if(c>b)
		cout<<"c e\' maggiore di b"<<endl;
		else
			cout<<"b e\' maggiore di c"<<endl;
	if(c==a)
		cout <<"c e a sono uguali!"<<endl;
		else
			cout<<"c e a sono diversi!"<<endl;
	
	/*
		Veicolo * v[] = {&a, &b, &c};
		
		v[i]->calcolo_Pedaggio; // late binding
	
	
	*/
	return 0;
}
