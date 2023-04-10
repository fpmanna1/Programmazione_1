#ifndef ECCEZIONE_H
#define ECCEZIONE_H

#include <string>

using std::string;

namespace MS{

	class Eccezione{
		private:
			string message;
		public:
			explicit Eccezione(string msg = "Errore") : message(msg){}
			const string what(){return message;} 
	};
}

#endif
