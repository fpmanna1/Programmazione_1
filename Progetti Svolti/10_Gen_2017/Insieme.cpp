#include "Insieme.h"

namespace MS{
	Insieme::Insieme(const Insieme & i) : dim(i.dim), nelem(i.nelem)
	{
		vet = new T[dim];
		for(int j=0; j<dim; j++)
			vet[j] = i.vet[j];
	}
	
	const Insieme & Insieme::operator=(const Insieme & i)
	{
		if(this!=&i)
		{
			dim = i.dim;
			nelem = i.nelem;
			for(int j=0; j<dim; j++)
				vet[j] = i.vet[j];
			
		}
		return *this;
	}
	
	ostream & Insieme::print(ostream & out)const
	{
		out << "------STAMPA INSIEME------"<<endl;
		for(int i=0; i<nelem; i++)
			out << *vet[i] << endl;
		return out;
	}
	
	ostream & operator<<(ostream & out, const Insieme & i)
	{
		return i.print(out);
	}
	
	bool Insieme::inlist(const T elem)const
	{
		if(empty()) return false;
		for(int i=0; i<nelem; i++)
			if(*vet[i]==*elem)
				return true;
				else
					return false;
	}
	
	bool Insieme::push(const T elem) throw (bad_item)  // ricoda T = Oggetto*
	{
		if(!full())
		{
			if(inlist(elem)) throw bad_item("Elemento gia' presente", elem);
			vet[nelem] = elem;
			nelem++;
			return true;
		}
		return false;
	}
	
	bool Insieme::pop()
	{
		if(empty()) return false;
		for(int i=0; i<nelem; i++)
			vet[i]=vet[i+1];
		nelem--;
		return true;
	}
	
	void Insieme::store()const
	{
		ofstream OutFile;
		OutFile.open("./dati.txt");
		if(!OutFile)
			cout << "Errore nell'apertura del file!"<<endl;
			else
				print(OutFile);
		OutFile.close();
	}
	
	void Insieme::leggidafile()
	{
		ifstream InFile;
		InFile.open("./prova.txt");
		while(!InFile.eof())
		{
			T temp;
			int codice;
			char descrizione[20];
			char forma[20];
			InFile >> codice; 
			InFile >> descrizione;
			InFile >> forma;
			temp->set_codice(codice); temp->set_descrizione(descrizione); temp->set_forma(forma);
			push(temp);
		}
		InFile.close();
	}
	
	const Insieme & Insieme::unione(const Insieme & i)const
	{
		int dimensione = get_nelem() + i.get_nelem();
		Insieme ins(dimensione);
		for(int j=0; j<nelem; j++)
			ins.push(vet[j]);
		for(int k=0; k<i.nelem; k++)
			ins.push(i.vet[k]);
		return ins;
	}
	
	const Insieme & Insieme::intersezione(const Insieme & i)const
	{
		int num_elem_max;
		if(get_nelem() > i.get_nelem())
			num_elem_max = get_nelem();
			else
				num_elem_max() = i.get_nelem();
		for(int j=0; j<num_elem_max; j++)
		{
			if(inlist(vet[i]))
		}
	}
}
