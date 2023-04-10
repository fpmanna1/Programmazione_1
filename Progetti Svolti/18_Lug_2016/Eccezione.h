#ifndef ECCEZIONE_H
#define ECCEZIONE_H

using std::string;

namespace MS{
	
	class Eccezione{
		private:
			string msg;
		public:
			Eccezione(string m) : msg(m){}
			const string what(){return msg;}
	};
}


#endif
