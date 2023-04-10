#ifndef SERVIZI_H
#define SERVIZI_H

#include "Data.h"
#include "Prenotazione.h"
#include <string>

using std::string;

typedef MS::Prenotazione T;

namespace MS{
	class Servizi{
		friend ostream & operator<<(ostream &, const Servizi &);
		friend istream & operator>>(istream &, Servizi &);
		private:
			char dirigente[20];
			string tipo;
			Data data;
		protected:
			T* vet;
			int dim;
			int nelem;
			
			virtual ostream & print(ostream &)const;
			virtual istream & input(istream &);
			bool full()const{return nelem==dim;}
			bool empty()const{return nelem==0;}
			bool inlist(const Prenotazione &)const;
		public:
			Servizi(const char * = "Colombo", const string & = "Ambulatorio", const int & = 14, const int & = 12, const int & = 2021, const int & = 5);
			Servizi(const Servizi &);
			virtual ~Servizi(){delete[] vet;}
			
			const Servizi & operator=(const Servizi &);	
			
			virtual bool prenota(const Prenotazione & ) = 0;
	};
}



#endif
