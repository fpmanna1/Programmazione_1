#ifndef PRODOTTIFRESCHI_H
#define PRODOTTIFRESCHI_H

#include "Alimentari.h"

namespace MS{
	
	class ProdottiFreschi : public Alimentari{
		
		friend ostream & operator<<(ostream &, const ProdottiFreschi &);
		friend istream & operator>>(istream &, ProdottiFreschi &);
		
		private:
			char * DataConfezione;
		protected:
			virtual ostream & stampa(ostream &)const;
			virtual istream & input(istream &);
		public:
			ProdottiFreschi();
			ProdottiFreschi(const char *, const char *, int, float, const char * );
			ProdottiFreschi(const ProdottiFreschi &);
			~ProdottiFreschi(){delete[] DataConfezione;}
			
			const ProdottiFreschi & operator=(const ProdottiFreschi &);
			
			void set_DataConfezione(const char * );
			
			void offerta();
			
			virtual void store(ofstream &)const;
	};
}

#endif
