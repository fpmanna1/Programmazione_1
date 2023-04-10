#ifndef DATA_H
#define DATA_H

#include <iostream>

using std::istream;
using std::ostream;
using std::cout;
using std::endl;

namespace MS{
	class Data{
		private:
			int giorno;
			int mese;
			int anno;
		public:
			Data(const int & g = 14, const int & m = 12, const int & a = 2021) : giorno(g), mese(m), anno(a){}
			
			friend ostream & operator<<(ostream & out, const Data & d)
			{
				out << d.giorno<<"-"<<d.mese<<"-"<<d.anno;
				return out;
			}
			
			friend istream & operator>>(istream & in, Data & d)
			{
				cout << "Inserisci giorno, mese e anno : ";
				in >> d.giorno >> d.mese >> d.anno;
				return in;
			}
			
			
	};
}


#endif
