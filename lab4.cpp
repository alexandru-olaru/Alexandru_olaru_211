#include <iostream>
#include <cstring>

using namespace std;


class Decoratiune
{

	char* decor;
	int pret;
	bool reciclabil;

	public:

		Decoratiune(char* decor, int pret, bool reciclabil)
		{
			this -> decor = new char[strlen(decor)+1];
			this -> pret = pret;
			this -> reciclabil = reciclabil;
		}

		char* getDecor()
		{
			return this -> decor;
		}

		int getPret()
		{
			return this -> pret;
		}

		bool getReciclabil()
		{
			return this -> reciclabil;
		}

		void afisare()
		{
			cout<<"Decorul cu numele: "<<this -> decor<<" are pretul "<<this -> pret<<" si este reciclabil("<< this -> reciclabil<<")\n";
		}
};

class ListaProduse
{
	Decoratiune *v = (Decoratiune*)malloc(105*sizeof(Decoratiune));
	int nr_elem = 0;

	public:

		void operator +(Decoratiune &decoratiune)
		{
			this -> nr_elem+= 1;
			this -> v[nr_elem] = decoratiune;
		}
};

int main()
{
	char decor1[] = "Glob";
	char decor2[] = "Dovleac";

	Decoratiune a(decor1, 23, 0);
	Decoratiune a2(decor2, 44,1);
	a.afisare();
	a2.afisare();
}
