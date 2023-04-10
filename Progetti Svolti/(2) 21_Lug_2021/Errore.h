#ifndef ERRORE_H
#define ERRORE_H

#include <string>

using std::string;

namespace MS{
	class Errore{
		private:
			string message;
		public:
			explicit Errore(const string & msg = "Errore Generico!") : message(msg){}
			const string & what()const{return message;}
	};
}

#endif
