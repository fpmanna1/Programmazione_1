#include "Tutorial.h"

namespace MS{
	
	Tutorial::Tutorial()
	{
		strcpy(codice, "");
		titolo = new char[1];
		strcpy(titolo, "");
		tutor=0;
	}
	
	Tutorial::Tutorial(const char c [5], const char * t, Docente * tut)
	{
		strcpy(codice, c);
		titolo = new char[strlen(t)+1];
		strcpy(titolo, t);
		tutor = tut;
	}
	
	Tutorial::Tutorial(const Tutorial & t)
	{
		strcpy(codice, t.codice);
		titolo = new char[strlen(t.titolo)+1];
		strcpy(titolo, t.titolo);
		*tutor = *(t.tutor);
	}
	
	const Tutorial & Tutorial::operator=(const Tutorial & t)
	{
		if(this!=&t)
		{
			set_codice(t.codice);
			set_titolo(t.titolo);
			set_tutor(t.tutor);
		}
		return *this;
	}
	
	ostream & Tutorial::print(ostream & out)const
	{
		out << codice << " " << titolo << " Info docente : "<< *tutor;
		return out;
	}
	
	ostream & operator<<(ostream & out, const Tutorial & t)
	{
		t.print(out);
		return out;
	}
	
	istream & Tutorial::input(istream & in)
	{
		char buffer[100];
		in >> codice;
		in.getline(buffer, 100);
		set_titolo(buffer);
		in >> *tutor;
		set_tutor(tutor);
		return in;
	}
	
	istream & operator>>(istream & in, Tutorial & t)
	{
		return t.input(in);
	}
	
	bool Tutorial::check()const
	{
		if(strlen(codice)!=4)
				return false;
			if(codice[0] >= 'A' && codice[0] <= 'Z')
				if(codice[1] >= 'A' && codice[1] <= 'Z')
					if(codice[2] >= '0' && codice[2] <= '9')
						if(codice[3] >= '0' && codice[3] <= '9')
							return true;
		return false;
	}
}
