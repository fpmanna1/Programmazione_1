#ifndef FILEEXCEP_H
#define FILEEXCEP_H

#include <string>

using std::string;

namespace MS{
	class FileExcep{
		private:
			string message;
		public:
			FileExcep() : message("Errore!"){}
			explicit FileExcep(const string & msg) : message(msg){}
			const string & what()const{return message;}
	};
}

#endif
