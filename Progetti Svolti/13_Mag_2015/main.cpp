#include "PilaOgg.h"

using std::cin; 
using MS::Pila; 
using MS::T; 
using MS::PilaOgg;
using MS::bad_insert;
using MS::Oggetto; 

int main() 
{
	Oggetto o, temp;
	char continua;
	bool scelta;
	short int opzione;
	ofstream OutFile;
	PilaOgg p1("Rombo");
	
	do{
		scelta=false;
		cout<<"Che operazione vuoi effettuare?"<<endl;
		cout<<"[1] Push"<<endl;
		cout<<"[2] Pop"<<endl;
		cout<<"[3] Top"<<endl;
		cout<<"[4] Stampa su file di testo"<<endl;
		cin>>opzione; cout<<endl;
		
		switch(opzione)
		{
			case 1:
				try{
					cout<<"Digita oggetto da inserire nella pila : ";
					cin>>o; cout<<endl;
					cout<<"L'oggetto inserito da tastiera e\' : "<<o<<endl;
					p1.push(o);
					p1.print();
				}catch(bad_insert & e){
					cout<<e.what()<<endl;
				}
				break;
				
			case 2:
				p1.pop(temp);
				p1.print();
				break;
				
			case 3:
				p1.top(temp);
				cout<<temp<<endl;
				break;
				
			case 4:
				OutFile.open("./dati.txt"); //vedi ios::out
				if(!OutFile)
					cout<<"Errore nell'apertura del file!"<<endl;
					else
						p1.fileprint(OutFile);
				cout<<"Stampa su file effettuata con successo!"<<endl;
				OutFile.close();
				break;
				
			default:
				cout<<"Inserisci un opzione valida!"<<endl;
				break;
		}
		cout<<endl;
		cout<<"Vuoi effettuare altre operazioni?"<<endl;
		cin>>continua;
		if(continua=='s' || continua=='S')
			scelta=true;
			else
				scelta=false;
	}while(scelta);

	return 0;
}
