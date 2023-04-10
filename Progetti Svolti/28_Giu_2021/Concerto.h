#ifndef CONCERTO_H
#define CONCERTO_H

#include "Evento.h"

namespace MS{
	class Concerto : public Evento{
		friend ostream & operator<<(ostream &, const Concerto &);
		friend istream & operator>>(istream &, Concerto &);
		private:
			char orchestra[20];
			char * direttore;
		protected:
			virtual ostream & print(ostream & )const;
			virtual istream & input(istream &);
		public:
			Concerto(const char * = "Napoli", const int & = 12, const int & = 12, const int & = 2021, const int & = 120, const char * = "San Carlo", const char * = "Sig. Colombo");
			Concerto(const Concerto &);
			~Concerto(){delete[] direttore;}
			
			const Concerto & operator=(const Concerto &);
			
			void set_direttore(const char * dir)
			{
				delete[] direttore;
				direttore = new char[strlen(dir)+1];
				strcpy(direttore, dir);
			}
			
			bool operator==(const Concerto & c)const
			{
				return(Evento::operator==(c) && strcmp(orchestra, c.orchestra)==0 && strcmp(direttore, c.direttore)==0);
			}
			
	};
	
}


#endif
