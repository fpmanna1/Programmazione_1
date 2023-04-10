#include "Catalogo.h"
#include "Pittura.h"
#include "Scultura.h"

using MS::Catalogo;
using MS::Pittura;
using MS::Scultura;
using MS::Errore;

int main() 
{
	Autore a1("Francesco Pio", 2000, 2999);
	Autore a2("Kiril", 2000, 2021);
	Pittura p1("Gioconda", "Bello", "A129IU", &a1, "acquerello", "quadro");
	Scultura s1("David", "Brutto", "C432ER", &a2, "marmo", 200);
	Pittura p2("Urlo", "Così", "ZZZZ3", &a1, "olio", "tela");
	Scultura s2("Michelangelo", "Carino", "C432ER", &a2, "terra", 10);
	
	Catalogo c;
	
	ofstream OutFile;
	
	Pittura* puntp1 = &p1;
	Pittura* puntp2 = &p2;
	Scultura* punts1 = &s1;
	Scultura* punts2 = &s2;
	
	c.insert(puntp1);
	c.insert(punts1);
	try{
		if(c.insert(punts2))
			cout<<"Elemento inserito"<<endl;
	}catch(Errore & e){
		cout << e.what()<<endl;
	} 
	c.insert(puntp2);
	cout<<endl; cout<<endl;
	
	OutFile.open("output_file.txt");
	if(!OutFile)
		cout<<"Errore nell'apertura del file!"<<endl;
		else
			OutFile<<c;
	OutFile.close();
	
	cout<<c;
	
	return 0;
}
