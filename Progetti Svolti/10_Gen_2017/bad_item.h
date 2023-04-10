#ifndef BAD_ITEM_H
#define BAD_ITEM_H

#include "string"
#include "Oggetto.h"

using std::string;


namespace MS{
	class bad_item{
		private:
			string message;
			Oggetto* o;
		public:
			explicit bad_item(const string & msg = "Errore", Oggetto* ogg = 0 ): message(msg), o(ogg){}
			void what()const{
				cout << "Errore! L'elemento "<<endl;
				cout << *o<<endl;
				cout << " e' gia' presente!"<<endl;
			}
	};
}

#endif
