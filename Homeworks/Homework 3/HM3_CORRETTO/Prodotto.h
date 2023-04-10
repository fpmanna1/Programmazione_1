//compilazione condizionale
//bool check_codice(const char *);


#include <iostream>
#include <cstring>
using namespace std;
const int SMAX = 6;
class Prodotto{
	
	friend ostream& operator<<(ostream &, const Prodotto &);
	friend istream& operator<<(istream &, Prodotto &);
	private:
		char Codice[SMAX];
		char * Descrizione;
		//bool flag_di_stato;  per gestire il caso stringa vuota
	public:
		Prodotto(const char * C="" /* const char C[] */, const char * D= "");
		Prodotto(const Prodotto &);
		const char * get_Codice() const {return Codice;}
		//quello che è tornato è un indirizzo 00-11-00
		const char * get_Descrizione() const {return Descrizione;}
		void set_Descrizione(const char *);
		bool set_Codice(const char *); //controlla la stringa
		const Prodotto & operator=(const Prodotto &);
		bool operator==(const Prodotto &) const;
		bool operator!=(const Prodotto &) const;
		~Prodotto(){delete [] Descrizione;}
		
		
};
