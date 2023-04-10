#ifndef ECCEZIONI_H
#define ECCEZIONI_H

#include <string>
using namespace std;

namespace MyNS{

	class Eccezioni{
		private:
			string message;
			Data info;
		public:
			Eccezioni(const Data & D, const char * e="Prodotto Scaduto") : info(D) 
			{
				message=e;
			}
			Data get_info()const{return info;}
			string what() const {return message;}
	};
}

#endif
