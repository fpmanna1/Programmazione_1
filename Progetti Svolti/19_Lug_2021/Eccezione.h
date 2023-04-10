#ifndef ECCEZIONE_H
#define ECCEZIONE_H

#include <string>

using std::string;

namespace MS{
	class Eccezione{
		private:
			string message;
		public:
			Eccezione() : message("generico errore"){}
			explicit Eccezione(const string & msg) : message(msg){}
			const string & what()const{return message;}
	};
}

#endif
