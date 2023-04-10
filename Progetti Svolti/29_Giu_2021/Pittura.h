#ifndef PITTURA_H
#define PITTURA_H

#include "Scheda.h"

namespace MS{
	class Pittura : public Scheda{
		friend ostream & operator<<(ostream &, const Pittura &);
		friend istream & operator>>(istream &, Pittura &);
		
		private:
			static const int lenght=20;
			char * tecnica;
			char tipo[lenght];
			
		public:
			Pittura();
			Pittura(const char *, const char *, const char *, Autore *, const char *, const char [lenght]);
			Pittura(const Pittura &);
			~Pittura(){delete[] tecnica;}
			
			const Pittura & operator=(const Pittura &);
			
			virtual ostream & print(ostream &)const;
			virtual istream & input(istream &);
			
			void set_tecnica(const char * t)
			{
				delete [] tecnica;
				tecnica = new char[strlen(t)+1];
				strcpy(tecnica, t);
			}
			
			void set_tipo(const char t[lenght]){strcpy(tipo, t);}
	};
}



#endif
