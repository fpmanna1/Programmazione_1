#ifndef LABORATORIO_H
#define LABORATORIO_H

#include "Servizi.h"

namespace MS{
	class Laboratorio : public Servizi{
		friend ostream & operator<<(ostream &, const Laboratorio &);
		friend istream & operator>>(istream &, Laboratorio &);
		private:
			char* analisi;
		protected:
			virtual ostream & print(ostream &)const;
			virtual istream & input(istream &);
		public:
			Laboratorio(const char * = "Colombo", const string & = "Laboratorio", const int & = 14, const int & = 12, const int & = 2021, const int & = 5, const char * = "Sangue");
			Laboratorio(const Laboratorio &);
			virtual ~Laboratorio(){delete[] analisi;}
			
			const Laboratorio & operator=(const Laboratorio &);
			
			void set_ana(const char * a)
			{
				delete[] analisi;
				analisi = new char[strlen(a)+1];
				strcpy(analisi, a);
			}		
			
			bool prenota(const Prenotazione & );
	};
}


#endif
