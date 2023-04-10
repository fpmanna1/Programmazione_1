#ifndef EVENTO_H
#define EVENTO_H

#include <cstring>
#include "Data.h"

using std::cout;

namespace MS{
	class Evento{
		friend ostream & operator<<(ostream &, const Evento &);
		friend istream & operator>>(istream &, Evento &);
		private:
			char * luogo;
			Data data;
			int durata;
		protected:
			virtual ostream & print(ostream &)const;
			virtual istream & input(istream &);
		public:
			Evento(const char * = "Napoli", const int & = 12, const int & = 12, const int & = 2021, const int & = 120);
			Evento(const Evento &);
			virtual ~Evento(){delete[] luogo;}
			
			const Evento & operator=(const Evento &);
			
			bool operator==(const Evento &)const;
			
			void set_luogo(const char * l){
				delete[] luogo;
				luogo = new char[strlen(l)+1];
				strcpy(luogo, l);
			}
			
			
	};
}


#endif
