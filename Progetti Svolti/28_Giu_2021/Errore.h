#ifndef ERRORE_H
#define ERRORE_H

#include <string>

using std::string;

namespace MS{
	class Errore{
		private:
			string message;
		public:
			Errore() : message("Errore Generico"){}
			explicit Errore(const string & msg) : message(msg){}
			const string & what()const{return message;}
	};
}

#endif
