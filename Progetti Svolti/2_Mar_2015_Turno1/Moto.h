#ifndef MOTO_H
#define MOTO_H

#include "Veicolo.h"

namespace MS{
	class Moto : public Veicolo{
		friend ostream & operator<<(ostream &, const Moto &);
		friend istream & operator>>(istream &, Moto &);
		private:
			char * tipo;
		protected:
			virtual ostream & print(ostream &)const;
			virtual istream & input(istream &);
		public:
			Moto(const char * = "moto", const char * = "Honda", const char * = "50cc");
			Moto(const Moto &);
			virtual ~Moto(){delete[] tipo;}
			
			const Moto & operator=(const Moto &);
			
			void set_tipo(const char * t)
			{
				delete[] tipo;
				tipo = new char[strlen(t)+1];
				strcpy(tipo, t);
			}
			
			virtual const char * totext();
			
	};
}


#endif
