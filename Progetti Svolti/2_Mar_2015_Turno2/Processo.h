#ifndef PROCESSO_H
#define PROCESSO_H

#include "Attivita.h"

using std::ofstream;

namespace MS{
	class Processo : public Attivita{
		
		
		private:
			char * nome;
			char stato; //R in esecuzione, P pronto, W in attesa
		public:
			Processo(const int =0, const char * ="", bool =false, const char * ="",  char =' ');
			Processo(const Processo &);
			virtual ~Processo(){delete [] nome;}
			
			void set_nome(const char * N){
				delete [] this->nome;
				nome = new char[strlen(N)+1];
				strcpy(nome, N);
			}
			void set_stato(const char S){stato=S;}
			
			const char * get_nome()const{return nome;}
			const char get_stato()const{return stato;}
			
			const Processo & operator=(const Processo & );
			bool operator==(const Processo &);
			
			friend ostream & operator<<(ostream & , const Processo & );
			friend istream & operator>>(istream &, Processo &);
			
			virtual void Attiva();
		
	};
}

#endif
