#ifndef DOCENTE_H
#define DOCENTE_H

#include <string.h>
#include <fstream>

using std::string;
using std::ostream;
using std::istream;

namespace MS{

class Docente{
	private:
		string nome;
		string cognome;
		string affiliazione; 
		string titolo;
		
	public:
		Docente() : nome(""), cognome(""), affiliazione(""), titolo(""){}
		Docente(string n, string c, string a, string t) : nome(n), cognome(c), affiliazione(a), titolo(t) {}
		
		const string & get_nome()const{return nome;}
		const string & get_cognome()const{return cognome;}
		const string & get_affiliazione()const{return affiliazione;}
		const string & get_titolo()const{return titolo;}
		
		void set_nome(const string & n){nome=n;}
		void set_cognome(const string & c){cognome=c;}
		void set_affiliazione(const string & a){affiliazione=a;}
		void set_titolo(const string & t){titolo=t;}
		
		friend ostream & operator<<(ostream & out, const Docente & d)
		{
			out << d.nome << " " << d.cognome << " " << d.affiliazione << " " << d.titolo;
			return out;
		}
		
		friend istream & operator>>(istream & in, Docente & d)
		{
			in >> d.nome;
			in >> d.cognome;
			in >> d.affiliazione;
			in >> d.titolo;
			return in; 
		}
};

}

#endif
