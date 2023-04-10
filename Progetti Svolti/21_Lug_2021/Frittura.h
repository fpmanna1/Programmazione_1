#ifndef FRITTURA_H
#define FRITTURA_H

#include "Voce.h"
#include <string>

using std::string;

namespace MS{
	class Frittura : public Voce{
		friend ostream & operator<<(ostream & out, const Frittura & f)
		{
			return f.print(out);
		}
		friend istream & operator>>(istream & in, Frittura & f)
		{
			return f.input(in);
		}
		private:
			string principale;
		public:
			Frittura() : Voce() , principale ("sconosciuto"){}
			Frittura(const int cod, const char * tip, const float p, const string & i) : Voce(cod, tip, p), principale(i){}
			
			const string & get_princ()const{return principale};
			
			ostream & print(ostream & out)const
			{
				Voce::print(out);
				out << principale;
				return out;
			}
			
			istream & input(istrem & in)
			{
				Voce::input(in);
				in >> principale;
				return in;
			}
	};
}


#endif
