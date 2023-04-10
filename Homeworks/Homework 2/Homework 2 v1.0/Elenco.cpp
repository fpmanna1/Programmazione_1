#include "Elenco.h"

void iniz(Elenco &e1, const int sizealloc)
{
	e1=new Voce[sizealloc]; //alloco spazio per l'elenco (alloca sizealloc vettori di tipo Voce)
	for(int i=0; i<sizealloc; i++) //inizializzo l'elenco
	{
		e1[i].key=0;
		e1[i].description = new char[2];
		strcpy(e1[i].description, "*");
	}
}

void readElenco(Elenco &e, const int size) 
{ 
	for(int i=0; i<size; i++) 
		read(e[i]);
}
void writeElenco(const Elenco &e, const int size)
{
	for(int i=0; i<size; i++)
	{ 
		write(e[i]); cout<<endl;
	}
}

bool in(const Elenco &e, const int size, const Voce &v , int &pos)
{
	bool trovato=false;
	for(int i=0; i<size && !trovato; i++)
		if(equal(e[i],v))
		{
			trovato=true;
			pos=i;
		}
	return trovato;
}

bool sort(Elenco &e, const int size)
{
	int temp;
	bool done=false;
	bool giaordinato=true;
	for(int j=1; j<size && !done; j++)
	{
		done=true;
		for(int i=0; i<size-j; i++)
			if(greater_than(e[i],e[i+1]))
			{
				swap(e[i],e[i+1]); 
				done=false;
				giaordinato=false;
			}
	}	
	return giaordinato;
}

bool insert(Elenco &e, const int size,const Voce &v)
{
	for(int i=0; i<size; i++)
		if(!(strcmp(e[i].description, "*")))
		{
			e[i]=v;
			return true;
		}
	return false;
}

void rm(Elenco &e, int size, const Voce v)
{
	int pos=0;
	for(int i=0; i<size; i++)
		if(in(e, size, v, pos))
		{	
			e[pos].key=0;
			strcpy(e[pos].description, "*");
		}
}

bool full(const Elenco e, const int size)
{
	for(int i=0; i<size; i++)
		if(!strcmp(e[i].description, "*"))
			return false;
	return true;
}

bool empty(const Elenco e, const int size)
{
	if(full(e, size))
		return false;
		else
			for(int i=0; i<size; i++)
				if(strcmp(e[i].description, "*") != 0) //se almeno un campo non è vuoto
					return false;
	return true;
}

bool insert_ord(Elenco &e, const int size, const Voce &v)
{
	for(int i=0; i<size; i++)
	{
		if(e[i].key>v.key)
		{
			for(int j=size; j>i; j--)
				swap(e[j],e[j-1]);
			e[i]=v;
			return true;
		}else{
			for(int i=0; i<size; i++)
				if(!strcmp(e[i].description, "*"))
				{
					e[i]=v;
					return true;
				}
		}
	}
	return false;
}
 

