#ifndef DATA_H
#define DATA_H

#include "fstream"

using std::ostream;

namespace MS{
	
	class Data{
		
		friend ostream & operator<<(ostream &, const Data &);
		
		private:
			int giorno;
			int mese;
			int anno;
		public:
			Data(int  = 1, int  = 1, int  = 1970);
			Data(const Data & d) : giorno(d.giorno), mese(d.mese), anno(d.anno){}
			
			void set_giorno(const int g){giorno=g;}
			void set_mese(const int m){mese=m;}
			void set_anno(const int a){anno=a;}
			
			const int get_giorno()const{return giorno;}
			const int get_mese()const{return mese;}
			const int get_anno()const{return anno;}	
			
			const Data & operator=(const Data &);
	};
}


#endif
