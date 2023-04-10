#ifndef ERRORE_H
#define ERRORE_H

#include <string>

using std::string;

namespace MS{
	class Errore{
		private:
			string message;
		public:
			Errore(const string & msg) : message(msg){}
			const string & what(){return message;}
	};
}



#endif
