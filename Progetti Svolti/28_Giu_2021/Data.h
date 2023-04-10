#ifndef DATA_H
#define DATA_H

#include <iostream>

using std::ostream;
using std::istream;
using std::endl;

namespace MS{
	class Data{
		friend ostream & operator<<(ostream & out, const Data & d)
		{
			out << d.giorno <<"-"<<d.mese<<"-"<<d.anno;
			return out;
		}
		friend istream & operator>>(istream & in, Data & d)
		{
			in >> d.giorno >> d.mese >> d.anno;
			return in;
		}
		private:
			int giorno;
			int mese;
			int anno;
		public:
			Data(const int & g = 12, const int & m = 12, const int & a = 2021) : giorno(g), mese(m), anno(a){}
			
			bool operator==(const Data & d)const
			{
				return(giorno==d.giorno && mese==d.mese && anno==d.anno);
			}
			
	};
}


#endif
