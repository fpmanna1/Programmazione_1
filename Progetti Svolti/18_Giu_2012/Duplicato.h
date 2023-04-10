#ifndef DUPLICATO_H
#define DUPLICATO_H

using std::string;

namespace MS{
	
	class Duplicato{
		private:
			string message;
			string codice;
			
		public:
			Duplicato(string msg = "ERRORE INSERIMENTO", string c = "") : message(msg), codice(c){};
			const string what()
			{
				message+="   Il codice problematico e\' -> ";	
				return message+=codice;
			}
	};
}

#endif
