#include "Voce.h"

void create(Voce &v)
{
	v.key=0;
	v.description=new char[4];
	strcpy(v.description, "NNN");
}

void read(Voce &v)
{
	v.key=0;
	v.description=new char[4];
	strcpy(v.description, "NNN");
    cin>>v.key;
    char buffer[DIM];
    //delete [] v.description;
    cin.ignore().getline(buffer,DIM);
    v.description = new char[strlen(buffer)+1]; //il +1 serve per riservare spazio al terminatore
    strcpy(v.description, buffer);
}

void copy(const Voce &v1, Voce &v2)
{
	v2.key = v1.key;
	delete [] v2.description;
	v2.description = new char[strlen(v1.description)+1];
	strcpy(v2.description,v1.description);
}

void destroy(Voce &v)
{
 	v.key = 0;
 	strcpy(v.description,'\0');
 	delete [] v.description;
}
