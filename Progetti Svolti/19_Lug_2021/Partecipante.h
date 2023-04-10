#ifndef PARTECIPANTE_H
#define PARTECIPANTE_H

#include <string>
#include <cstring>
#include <iostream>
#include "Eccezione.h"

using std::string;
using std::endl;
using std::ostream;

namespace MS{
	class Partecipante{
		friend ostream & operator<<(ostream & out, const Partecipante & p)
		{
			return p.print(out);
		}
		private:
			string nome;
			char email[30];
		protected:
			ostream & print(ostream & out)const
			{
				out << "NOME PARTECIPANTE : "<<nome<<endl;
				out << "EMAIL : "<<email<<endl;
				return out;
			}
		public:
			Partecipante(const string & n = "Tizio", const char * e = "tizio.pippo@yahoo.it") : nome(n)
			{
				if(check_email(e))
					strcpy(email, e);
			}
			
			void set_nome(const string & n){nome=n;}
			void set_email(const char * e){strcpy(email, e);}
			
			const string & get_nome()const{return nome;}
			const char * get_email()const{return email;}
			
			bool operator==(const Partecipante & p)const{return(nome==p.nome && strcmp(email, p.email) == 0);}
			
			bool check_email(const char * em) throw(Eccezione)
			{
				bool spazio=false;
				bool chiocciola=false;
				for(int i=0; i<strlen(em) && !spazio; i++)
				{
					if(em[i]==' ')
						spazio=true;
				}
				for(int i=0; i<strlen(em) && !chiocciola; i++)
				{
					if(em[i]=='@')
						chiocciola=true;
				}
				if(spazio)
				{
				    throw Eccezione("non devi inserire spazi");
				    return false;
				}
				if(!chiocciola) 
				{
					throw Eccezione("devi inserire la chiocciola!");
					return false;
				}
				return true;
			}
			
	};

}
#endif
