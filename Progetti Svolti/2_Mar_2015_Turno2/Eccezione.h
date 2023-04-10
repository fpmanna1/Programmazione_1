#ifndef ECCEZIONE_H
#define ECCEZIONE_H

#include <cstring>
using std::string;

namespace MS{
	
	class Eccezione{
		private:
			string message;
		public:
			Eccezione(string m) : message(m){}
			const string what() const{return message;}
	};
}

#endif
