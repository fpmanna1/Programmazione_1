#ifndef BADINSERT_H
#define BADINSERT_H

#include <cstring>

using std::string;

namespace MS{
	
	class bad_insert{
		private:
			string msg;
		public:
			explicit bad_insert(string m = "errore") : msg(m){}
			const string what(){return msg;}
	};
}

#endif
