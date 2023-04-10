#ifndef PARCO_H
#define PARCO_H

#include "Attrazione.h"
#include "Scheda.h"

namespace MS{
	class Parco : public Attrazione{
		friend ostream & operator<<(ostream &, const Parco &);
		private:
			Scheda * vet;
			int dim;
			int nelem;
		protected:
			virtual ostream & print(ostream &)const;
		public:
			Parco(const char * n, const float & c, const int d) : Attrazione(n,c), dim(d), nelem(0)
			{
				vet = new Scheda[dim];
			}
			Parco(const Parco &);
			
			virtual ~Parco(){delete[] vet;}
			
			const Parco & operator=(const Parco &);
			
			bool inlist(Scheda &);
		    bool acquista_biglietto(string);
			double calcolo_incasso()const;
			
			bool insert(Scheda & );
			
	};
}


#endif
