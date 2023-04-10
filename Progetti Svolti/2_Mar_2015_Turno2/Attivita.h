#ifndef ATTIVITA_H
#define ATTIVITA_H

#include <cstring>
#include <iostream>

using std::istream; using std::endl; using std::ostream; using std::ofstream;

namespace MS{
	
	class Attivita{
		private:
			int pid;
			char * descrizione;
			bool started;
			
		public:
			Attivita(const int =0, const char * ="", bool =false);
			Attivita(const Attivita &);
			virtual ~Attivita(){delete [] this->descrizione;}
			
			void set_pid(const int P) {this->pid=P;}
			void set_descrizione(const char * D){
				delete [] this->descrizione;
				this->descrizione=new char[strlen(D)+1];
				strcpy(this->descrizione, D);
			}
			void set_started(const bool S){started=S;}
			
			const int get_pid()const{return pid;}
			const char * get_descrizione()const {return this->descrizione;}
			const bool get_started()const {return this->started;}
			
			const Attivita & operator=(const Attivita & );
			bool operator==(const Attivita &);
			
			friend ostream & operator<<(ostream & , const Attivita & );
			friend istream & operator>>(istream &, Attivita & );	
			
			virtual void Attiva();		
	};
}


#endif
