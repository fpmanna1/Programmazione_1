#include "Data.h"

namespace MS{
	
	Data::Data(int g, int m, int a) : giorno(g), mese(m), anno(a){}
	
	ostream & operator<<(ostream & out, const Data & d)
	{
		out << d.giorno << " " << d.mese << " " << d.anno;
		return out;
	}
	
	const Data & Data::operator=(const Data & d)
	{
		if(this!=&d)
		{
			set_giorno(d.giorno);
			set_mese(d.mese);
			set_anno(d.anno);
		}
		return *this;
	}
}
