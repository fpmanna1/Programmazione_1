#ifndef ECCEZIONE_H
#define ECCEZIONE_H

#include <string>

using std::string;

class Eccezione{
	private:
		string message;
	public:
		Eccezione() : message("Generico errore"){}
		explicit Eccezione(const string & msg) : message(msg){}
		const string & what(){return message;}
};

#endif
