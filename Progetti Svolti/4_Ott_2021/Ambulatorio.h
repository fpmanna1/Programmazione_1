#ifndef AMBULATORIO_H
#define AMBULATORIO_H

#include "Servizi.h"
#include "Eccezione.h"

namespace MS{
	class Ambulatorio : public Servizi{
		friend ostream & operator<<(ostream &, const Ambulatorio &);
		friend istream & operator>>(istream &, Ambulatorio &);
		private:
			char* spec;
		protected:
			virtual ostream & print(ostream &)const;
			virtual istream & input(istream &);
		public:
			Ambulatorio(const char * = "Colombo", const string & = "Ambulatorio", const int & = 14, const int & = 12, const int & = 2021, const int & = 5, const char * = "Cardiologia");
			Ambulatorio(const Ambulatorio &);
			virtual ~Ambulatorio(){delete[] spec;}
			
			const Ambulatorio & operator=(const Ambulatorio &);
			
			void set_spec(const char * s)
			{
				delete[] spec;
				spec = new char[strlen(s)+1];
				strcpy(spec, s);
			}		
			
			virtual bool prenota(const Prenotazione & ) throw (Eccezione);
	};
}


#endif
