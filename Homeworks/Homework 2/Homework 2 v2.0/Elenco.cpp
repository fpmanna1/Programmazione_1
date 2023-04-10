#include "Elenco.h"

void readElenco(Elenco &e, const int size) 
{ 
	e=new Voce[DIM_MAX]; 
	for(int i=0; i<DIM_MAX; i++) //inizializzo l'elenco
	{
		e[i].key=0;
		e[i].description = new char[2];
		strcpy(e[i].description, " ");
	}
	for(int i=0; i<size; i++) 
			read(e[i]);
	
}
void writeElenco(const Elenco &e, const int size)
{
	for(int i=0; i<DIM_MAX; i++)
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
	bool done=false, flag=true;  //il flag mi dice se è gia ordinato
	for(int j=1; j<size && !done; j++)
	{
		done=true;
		for(int i=0; i<size-j; i++)
			if(greater_than(e[i],e[i+1]))
			{
				swap(e[i],e[i+1]); 
				done=false;
				flag=false;
			}
	}	
	return flag;
}

bool insert(Elenco &e, int &size,const Voce &v)
{	
	int pos;
	if(!full(e,size) && !in(e,size,v,pos)) 
	{
		//destroy(e[size]);
    	//copy(v, e[size]);
    	size++;
    	return true;
	}
	return false;
}

void remove(Elenco &e, int size, const Voce v)
{
	int pos=0;
	for(int i=0; i<size; i++)
		if(in(e, size, v, pos))
		{	
			e[pos].key=0;
			strcpy(e[pos].description, " ");
			for(int j=pos; j<DIM_MAX-1; j++)
				swap(e[j],e[j+1]);
				/* 
					copy ..... */
		}
}

bool insert_ord(Elenco &e, int &size, const Voce &v)
{
	int pos;
	if(!full(e,size) && !in(e,size,v,pos) && is_sorted(e, size))
	{
		e[size]=v;
		for(int i=0; i<size ; i++)
			if(v.key<e[i].key)
			{
				for(int j=i; j<DIM_MAX-1; j++)
					swap(e[j], e[j+1]);
				return true;	
			}
	}
	return false;
}

 
