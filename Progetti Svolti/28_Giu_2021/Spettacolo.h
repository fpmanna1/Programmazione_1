#ifndef SPETTACOLO_H
#define SPETTACOLO_H

#include "Evento.h"
#include <string>

using std::string;
using std::cout;

namespace MS{
	class Spettacolo : public Evento{
		friend ostream & operator<<(ostream & out, const Spettacolo & s)
		{
			return s.print(out);
		}
		friend istream & operator>>(istream & in, Spettacolo & s)
		{
			return s.input(in);
		}
		private:
			string compagnia;
			string titolo;
		protected:
			virtual ostream & print(ostream & out)const{
				Evento::print(out);
				out << "-----STAMPA INFO SPETTACOLO-----"<<endl;
				out << "COMPAGNIA : "<<compagnia<<endl;
				out << "TITOLO : "<<titolo<<endl;
				return out;
			}
			virtual istream & input(istream & in)
			{
				Evento::input(in);
				cout << "Inserisci compagnia spettacolo :"<<endl;
				in >> compagnia;
				cout << "Inserisci titolo spettacolo : "<<endl;
				in >> titolo;
				return in;
			}
		public:
			Spettacolo(const char * l = "Napoli", const int & g = 12, const int & m = 12, const int & a = 2021, const int & dur = 120,
			 const string & tit = "titolo", const string & comp = "compagnia") : Evento(l, g, m, a, dur) , titolo(tit), compagnia(comp){}
			 
			 const Spettacolo & operator=(const Spettacolo & s)
			 {
			 	if(this!=&s)
			 	{
			 		Evento::operator=(s);
			 		compagnia=s.compagnia;
			 		titolo=s.titolo;
				}
				return *this;
			 }
			 
			bool operator==(const Spettacolo & s)const
			{
				return(Evento::operator==(s) && compagnia==s.compagnia && titolo==s.titolo);
			}
	};
}


#endif
