#ifndef AUTO_H
#define AUTO_H

#include "Veicolo.h"

namespace MS{
	class Auto : public Veicolo{
		friend ostream & operator<<(ostream &, const Auto &);
		friend istream & operator>>(istream &, Auto &);
		private:
			char * alim;
		protected:
			virtual ostream & print(ostream &)const;
			virtual istream & input(istream &);
		public:
			Auto(const char * = "auto", const char *  = "ford", const char * = "Benzina");
			Auto(const Auto &);
			virtual ~Auto(){delete[] alim;}
			
			const Auto & operator=(const Auto &);
			
			void set_alim(const char * a)
			{
				delete[] alim;
				alim = new char[strlen(a)+1];
				strcpy(alim, a);
			}
			
			virtual const char * totext();
	};
}

#endif
