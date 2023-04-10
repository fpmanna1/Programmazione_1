#ifndef PRENOTAZIONE_H
#define PRENOTAZIONE_H

#include <string>
#include <cstring>
#include <iostream>

using std::istream; using std::ostream; using std::cout; using std::endl;
using std::string;

namespace MS{
	class Prenotazione{
		friend ostream & operator<<(ostream &, const Prenotazione &);
		friend istream & operator>>(istream &, Prenotazione &);
		private:
			char codice[6];
			char* nome;
			char* cognome;
			int anno_nascita;
			string tipo;
			string prestazione;
		protected:
			virtual ostream & print(ostream &)const;
			virtual istream & input(istream &);
		public:
			Prenotazione(const char * = "12345", const char * = "Pippo", const char * = "Pluto", const int & = 1990, const string & = "tipo", const string & ="prestazione");
			Prenotazione(const Prenotazione &);
			virtual ~Prenotazione(){delete[] nome; delete[] cognome;}	
			const Prenotazione & operator=(const Prenotazione &);
			
			void set_nome(const char * n)
			{
				delete[] nome;
				nome = new char[strlen(n)+1];
				strcpy(nome, n);
			}
			
			void set_cognome(const char * c)
			{
				delete[] cognome;
				cognome = new char[strlen(c)+1];
				strcpy(cognome, c);
			}
			
			bool operator==(const Prenotazione & )const;
	};
}


#endif
