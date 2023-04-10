#ifndef SCULTURA_H
#define SCULTURA_H

#include "Scheda.h"

namespace MS{
	class Scultura : public Scheda{
		private:
			string materiale;
			int peso;
			
		public:
			Scultura() : Scheda(), materiale(""), peso(0){}
			Scultura(const char *tit, const char *des, const char *cod, Autore *aut, const string & mat, int pes) : Scheda(tit, des, cod, aut), 
			materiale(mat), peso(pes){} 
			Scultura(const Scultura & s) : Scheda(s), materiale(s.materiale), peso(s.peso){}
			
			const Scultura & operator=(const Scultura & s)
			{
				if(this!=&s)
				{
					Scheda::operator=(s);
					materiale=s.materiale;
					peso=s.peso;
				}
				return *this;
			} 
			
			virtual ostream & print(ostream & out)const
			{
				Scheda::print(out);
				out <<"Materiale : "<<materiale<<endl;
				out <<"Peso : "<<peso;
				return out;
			}
			
			virtual istream & input(istream & in)
			{
				Scheda::input(in);
				in>>materiale;
				in>>peso;
				return in;
			}
			
			friend ostream & operator<<(ostream & out, const Scultura & s)
			{
				return s.print(out);
			}
			
			friend istream & operator>>(istream & in, Scultura & s)
			{
				return s.input(in);
			}
	};
}


#endif
