#include <iostream>
#include <cstring>
#include <fstream>
#include <vector>

using namespace std;

class Banca
{
	const int ID_Banca;
	char* numeBanca;
	int cui;
	int* ratings;
	int nrRatings; // note de la 1 la 5
	float valoare; // valoare bancii
	bool functionala;
	char moneda;


public:
    static int anCurent;

	Banca(): ID_Banca(0)
	{
		this -> numeBanca = new char[strlen("Banca fantoma")+1];
		strcpy(this -> numeBanca, "Banca fantoma");

		this -> cui = 0;
		this -> nrRatings = 0;

        this -> ratings = new int[this -> nrRatings];

		this -> functionala = false;
		this -> valoare = 0;
		this -> moneda ='$';
	}

	Banca(int id, char* numeBanca, int cui, float val, bool func, char moneda, int nrRatings, int* ratings): ID_Banca(id)
	{
		this -> numeBanca = new char[strlen(numeBanca)+1];
		strcpy(this -> numeBanca,numeBanca);

		this -> nrRatings = nrRatings;
        this -> ratings = new int[this -> nrRatings];
        for(int i = 0; i < this -> nrRatings; i++)
            this -> ratings[i] = ratings[i];


		this -> cui = cui;
		this -> valoare = val;
		this -> functionala = func;
		this -> moneda = moneda;
	}

	Banca(int id): ID_Banca(id)
	{
	    this -> numeBanca = new char[strlen("Banca noua")+1];
	    strcpy(this -> numeBanca, "Banca noua");

	    this -> nrRatings = 0;
        this -> ratings = new int[this -> nrRatings];

	    this -> valoare = 0.0;
	    this -> cui  = 0;
	    this -> functionala = false;
	    this -> moneda = '$';

	}

	Banca(const Banca &bc):ID_Banca(bc.ID_Banca)
	{
        this -> numeBanca = new char[strlen(bc.numeBanca) + 1];
        strcpy(this -> numeBanca, bc.numeBanca);

        this -> nrRatings = bc.nrRatings;
        this -> ratings = new int[this -> nrRatings];
        for(int i = 0; i < this -> nrRatings; i++)
            this -> ratings[i] = bc.ratings[i];

        this -> cui = bc.cui;
        this -> valoare = bc.valoare;
        this -> functionala = bc.functionala;
        this -> moneda = bc.moneda;
	}

	void setNumeBanca(char *a)
	{
	    if(this -> numeBanca != NULL)
            delete[] numeBanca;
        this -> numeBanca = new char[strlen(a)+1];
        strcpy(this -> numeBanca,a);
	}

	void setCui(int a)
	{
	    this -> cui = a;
	}

	void setValoare(float a)
	{
	    this -> valoare = a;
	}

	void setFunctionala(bool a)
	{
	    this -> functionala = a;
	}

	void setMoneda(char a)
	{
	    this -> moneda = a;
	}

	void setRatings(int* a, int b)
	{
	    this -> nrRatings = b;

	    if(this -> ratings != NULL)
            delete[] this -> ratings;
        this ->ratings = new int[b];
        for(int i = 0; i<b; i++)
            this -> ratings[i] = a[i];
	}

	char* getNumeBanca()
	{
	    return this -> numeBanca;
	}

	int getCui()
	{
	    return this -> cui;
	}

	float getValoare()
	{
	    return this -> valoare;
	}

	bool getFunctionala()
	{
	    return this -> functionala;
	}

	char getMoneda()
	{
	    return this -> moneda;
	}

	int getID_Banca()
	{
	    return this -> ID_Banca;
	}

    int getNrRatings()
    {
        return this -> nrRatings;
    }

    int* getRatings()
    {
        return this -> ratings;
    }

	friend istream &operator>> (istream &in, Banca &b)
	{
	    char aux[100];

	    cout << "\nIntrodu nume banca: ";
	    in.get(aux, 100);
	    in.get();
	    if(b.numeBanca != NULL)
            delete[] b.numeBanca;
        b.numeBanca = new char[strlen(aux)+1];
        strcpy(b.numeBanca,aux);

        cout << "\nIntrodu CUI: ";
        in >> b.cui;

        cout << "\nSpune daca e functionala(1 = este, 0 = nu este): ";
        in >> b.functionala;

        cout << "\nIntrodu valoarea bancii: ";
        in >> b.valoare;

        cout << "\nCu ce moneda lucreaza?: ";
        in >> b.moneda;

        cout << "\nCate note a primit?:";
        in >> b.nrRatings;


        if(b.ratings != NULL)
            delete[] b.ratings;
        b.ratings = new int[b.nrRatings];

        cout << "\nCare sunt aceste note?: ";
        for(int i = 0; i < b.nrRatings; i++)
        {
            in >> b.ratings[i];
        }
	    return in;
	}

	friend ostream &operator<< (ostream &out, const Banca b)
	{
	    out << "Banca cu ID:" << b.ID_Banca << " si numele: *" << b.numeBanca << "* are o valoare de: " << b.valoare << b.moneda << " si are CUI: "<< b.cui;
	    if(b.functionala == 1)
            out << ".\nIn plus este functionala ";

	    else out << ". In plus nu este functionala ";

	    out << "si a primit "<<b.nrRatings<<" note:";
	    for(int i =0; i < b.nrRatings; i++)
            out << " " << b.ratings[i] ;
        out << "\n";

	    return out;
	}

	Banca &operator= (const Banca &b)
	{
	    if(this != &b)
        {
            if(this -> numeBanca != NULL)
                delete[] this -> numeBanca;
            this -> numeBanca = new char[strlen(b.numeBanca)+1];
            strcpy(this -> numeBanca, b.numeBanca);

            this -> nrRatings = b.nrRatings;
            if(this -> ratings != NULL)
                delete[] this-> ratings;
            this -> ratings = new int[this -> nrRatings];
            for(int i = 0; i < this -> nrRatings; i++)
                this -> ratings[i] = b.ratings[i];

            this -> cui = b.cui;
            this -> valoare = b.valoare;
            this -> functionala = b.functionala;
            this -> moneda = b.moneda;
        }

        return *this;
	}

	Banca &operator+ (float a)
	{
	    this -> valoare = this -> valoare + a;

	    return *this;
	}

	Banca &operator- (float a)
	{
	    this -> valoare = this -> valoare - a;

	    return *this;
	}

	const Banca operator++ ()
	{
	    this -> valoare++;
	    return *this;
	}

	const Banca operator++ (int)
	{
	    Banca aux(*this);
	    this -> valoare++;
	    return aux;
	}
	const Banca operator-- ()
	{
	    this -> valoare--;
	    return *this;
	}

	const Banca operator-- (int)
	{
	    Banca aux(*this);
	    this -> valoare--;
	    return aux;
	}

	friend bool operator== (const Banca &a, const Banca &b)
	{
	    if(a.valoare == b.valoare and a.cui == b.cui and a.moneda == b.moneda and strcmp(a.numeBanca,b.numeBanca)== 0 and a.functionala == b.functionala)
            return true;
        else return false;
	}

	friend bool operator< (const Banca &a, const Banca &b)
	{
	    if(a.valoare < b.valoare)
            return true;
        else return false;

	}

	friend bool operator> (const Banca &a, const Banca &b)
	{
	    if(a.valoare > b.valoare)
            return true;
        else return false;

	}

	friend bool operator<= (const Banca &a, const Banca &b)
	{
	    if(a.valoare <= b.valoare)
            return true;
        else return false;

	}

	friend bool operator>= (const Banca &a, const Banca &b)
	{
	    if(a.valoare >= b.valoare)
            return true;
        else return false;

	}

    int operator[] (int i)
	{
	    if(i >= 0 and this -> nrRatings > i)
            return this -> ratings[i];
        else
            cout << "indice invalid";
        return -1;
	}

	explicit operator int()
	{
	    return (int) this -> valoare;
	}

	~Banca()
	{
	    if(this -> numeBanca != NULL)
            delete[] this -> numeBanca;
        if(this -> ratings != NULL)
        {
            delete[] this -> ratings;
        }
	}

};

class Sediu
{
private:
    const int ID_Sediu;
    char* numeBanca;
    char* adresa;
    int nrNiveluri;
    int* nrBirouriNivel;
    bool areBancomat;
    float baniSeif;
    char moneda;

public:
    static void mesaj()
        {
            cout << "Bine ati venit la noi" << "\n";
        }

    Sediu():ID_Sediu(0)
    {
        this -> numeBanca = new char[strlen("Necunoscuta") + 1];
        strcpy(this -> numeBanca, "Necunoscuta");

        this -> adresa = new char[strlen("Necunoscuta") + 1];
        strcpy(this -> adresa, "Necunoscuta");

        this -> nrNiveluri = 0;
        this -> nrBirouriNivel = new int[this -> nrNiveluri];
        this -> areBancomat = false;
        this -> baniSeif = 0.0;
        this -> moneda = '$';

    }

    Sediu(int id): ID_Sediu(id)
    {
        this -> numeBanca = new char[strlen("Necunoscuta") + 1];
        strcpy(this -> numeBanca, "Necunoscuta");

        this -> adresa = new char[strlen("Necunoscuta") + 1];
        strcpy(this -> adresa, "Necunoscuta");

        this -> nrNiveluri = 0;
        this -> nrBirouriNivel = new int[this -> nrNiveluri];
        this -> areBancomat = false;
        this -> baniSeif = 0.0;
        this -> moneda = '$';
    }

    Sediu(Banca &b, int id, char* adresa, int nrNiveluri, int* nrBirouriNivel, bool areBancomat, float baniSeif):ID_Sediu(id)
    {
        this -> numeBanca = new char[strlen(b.getNumeBanca())+1];
        strcpy(this -> numeBanca, b.getNumeBanca());

        this -> adresa = new char[strlen(adresa)+1];
        strcpy(this -> adresa, adresa);

        this -> nrNiveluri = nrNiveluri;

        this -> nrBirouriNivel = new int[nrNiveluri];
        for(int i = 0; i < nrNiveluri; i++)
            this -> nrBirouriNivel[i] = nrBirouriNivel[i];

        this -> areBancomat = areBancomat;
        this -> baniSeif = baniSeif;
        this -> moneda = b.getMoneda();
    }

    Sediu(const Sediu &s):ID_Sediu(s.ID_Sediu)
    {
        this -> numeBanca = new char[strlen(s.numeBanca) +1];
        strcpy(this -> numeBanca, s.numeBanca);

        this -> adresa = new char[strlen(s.adresa) +1];
        strcpy(this -> adresa, s.adresa);

        this -> nrNiveluri = s.nrNiveluri;

        this -> nrBirouriNivel = new int[nrNiveluri];
        for(int i = 0; i < s.nrNiveluri; i++)
            this -> nrBirouriNivel[i] = s.nrBirouriNivel[i];

        this -> moneda = s.moneda;
        this -> areBancomat = s.areBancomat;
        this -> baniSeif = s.baniSeif;
    }

    void setNumeBanca(char* a)
    {
        if(this -> numeBanca != NULL)
            delete[] this -> numeBanca;
        this -> numeBanca = new char[strlen(a) + 1];
        strcpy(this -> numeBanca, a);
    }

    void setAdresa(char* a)
    {
        if(this -> adresa != NULL)
            delete[] this -> adresa;
        this -> adresa = new char[strlen(a)+1];
        strcpy(this -> adresa, a);
    }

    void setNrBirouriNiveluri(int a, int* b)
    {
        this -> nrNiveluri = a;

        if(this -> nrBirouriNivel != NULL)
            delete[] nrBirouriNivel;

        nrBirouriNivel = new int[a];
        for(int i = 0; i < a; i++)
            this -> nrBirouriNivel[i] = b[i];
    }

    void setAreBancomat(bool a)
    {
        this -> areBancomat = a;
    }

    void setBaniSeif( float a)
    {
        this -> baniSeif = a;
    }

    void setMoneda(char a)
    {
        this -> moneda = a;
    }

    char* getNumeBanca()
    {
        return this -> numeBanca;
    }

    char* getAdresa()
    {
        return this -> adresa;
    }

    int getNrNiveluri()
    {
        return this -> nrNiveluri;
    }

    int* getNrBirouriNivel()
    {
        return this -> nrBirouriNivel;
    }

    float getBaniSeif()
    {
        return this -> baniSeif;
    }

    char getMoneda()
    {
        return this -> moneda;
    }

    int getID_Sediu()
    {
        return int(this -> ID_Sediu);
    }

    bool getAreBancomat()
    {
        return this -> areBancomat;
    }

    friend ostream &operator<< (ostream &out, const Sediu s)
    {
        out << "Sediul bancii *" << s.numeBanca << "* are ID: " << s.ID_Sediu << " si se afla la adresa: " << s.adresa << ".\nAre " << s.nrNiveluri;
        out << " niveluri, fiecare avand urm nr de birouri:";

        for(int i = 0; i < s.nrNiveluri; i++)
            out << " " << s.nrBirouriNivel[i];
        out << ". In plus are "<< s.baniSeif << s.moneda<<" in cont si ";

        if(s.areBancomat == true)
            out << "are bancomat.\n";
        else
            out << "nu are bancomat.\n";

        return out;
    }

    friend istream &operator>> (istream &in, Sediu &s)
    {
        char aux1[100];
        char aux2[100];

        cout << "Introdu numele bancii: ";

        in.get(aux1,100);
        in.get();

        if(s.numeBanca != NULL)
            delete[] s.numeBanca;
        s.numeBanca = new char[strlen(aux1)+1];
        strcpy(s.numeBanca, aux1);

        cout << "\nIntrodu adresa: ";

        in.get(aux2, 100);
        in.get();

        if(s.adresa != NULL)
            delete[]  s.adresa;
        s.adresa = new char[strlen(aux2)+1];
        strcpy(s.adresa, aux2);

        cout << "\nIntrodu numarul nivelelor: ";
        in >> s.nrNiveluri;

        cout << "\nIntrodu nr birourilor pt fiecare nivel: ";

        if(s.nrBirouriNivel != NULL)
            delete[] s.nrBirouriNivel;
        s.nrBirouriNivel = new int[s.nrNiveluri];

        for(int i = 0; i < s.nrNiveluri; i++)
            in >> s.nrBirouriNivel[i];

        cout << "\nCati bani sunt in seif?:";
        in >> s.baniSeif;

        cout << "\nIntrodu moneda:";
        in >> s.moneda;

        cout << "\nAre bancomat?(1 = da, 0 = nu): ";

        in >> s.areBancomat;

        return in;

    }

    Sediu &operator= (const Sediu &s)
    {
        if(this != &s)
        {
            if(this -> numeBanca != NULL)
                delete[] this -> numeBanca;

            this -> numeBanca = new char[strlen(s.numeBanca)+1];
            strcpy(this -> numeBanca, s.numeBanca);

            if(this -> adresa != NULL)
                delete[] this -> adresa;

            this -> adresa = new char[strlen(s.adresa)+1];
            strcpy(this -> adresa, s.adresa);

            this -> nrNiveluri = s.nrNiveluri;

            if(this -> nrBirouriNivel != NULL)
                delete[] this -> nrBirouriNivel;

            this -> nrBirouriNivel = new int[nrNiveluri];
            for( int i = 0; i < nrNiveluri; i++)
                this -> nrBirouriNivel[i] = s.nrBirouriNivel[i];

            this -> moneda = s.moneda;
            this -> areBancomat = s.areBancomat;
            this -> baniSeif = s.baniSeif;
        }

        return *this;
    }

    friend bool operator== (const Sediu &a, const Sediu &b)
    {
        if(strcmp(a.numeBanca,b.numeBanca) == 0 and a.baniSeif == b.baniSeif and a.ID_Sediu == b.ID_Sediu)
            return true;
        else
            return false;
    }

    friend bool operator< (const Sediu &a, const Sediu &b)
    {
        if(a.baniSeif < b.baniSeif)
            return true;
        else
            return false;
    }

    friend bool operator> (const Sediu &a, const Sediu &b)
    {
        if(a.baniSeif > b.baniSeif)
            return true;
        else
            return false;
    }

    friend bool operator>= (const Sediu &a, const Sediu &b)
    {
        if(a.baniSeif >= b.baniSeif)
            return true;
        else
            return false;
    }

    friend bool operator<= (const Sediu &a, const Sediu &b)
    {
        if(a.baniSeif <= b.baniSeif)
            return true;
        else
            return false;
    }

    Sediu &operator+ (float a)
    {
        this -> baniSeif = this -> baniSeif + a;
        return *this;
    }

    Sediu &operator- (float a)
    {
        this -> baniSeif = this -> baniSeif - a;
        return *this;
    }

    const Sediu operator++ ()
    {
        this -> baniSeif++;
        return *this;
    }

    const Sediu operator++ (int)
    {
        Sediu aux(*this);
        this -> baniSeif++;
        return aux;
    }

    const Sediu operator-- ()
    {
        this -> baniSeif--;
        return *this;
    }

    const Sediu operator-- (int)
    {
        Sediu aux(*this);
        this -> baniSeif--;
        return aux;
    }

    int operator[] (int i)
    {
        if(i >= 0 and i < this -> nrNiveluri)
            return this -> nrBirouriNivel[i];
        else
            return -2;
    }

    explicit operator int()
    {
        return (int) this -> baniSeif;
    }

    ~Sediu()
    {
        if(this -> adresa != NULL)
            delete[] this -> adresa;
        if(this -> nrBirouriNivel != NULL)
            delete[] this -> nrBirouriNivel;
        if(this -> numeBanca != NULL)
            delete[] this -> numeBanca;
    }
};

class Angajat
{
    const int ID_Angajat;
    char* numeAngajat;
    int varsta;
    int nrCalificative;
    int* calificative;
    float salariu;
    int idSediu;
    char gen;
    char* numeBanca;

public:
    static void msj()
    {
        cout << "Bun venit angajatule!\n";
    }

    Angajat():ID_Angajat(0)
    {
        this -> numeAngajat = new char[strlen("Unknown")+1];
        strcpy(this -> numeAngajat, "Unknown");

        this -> varsta = 0;
        this -> nrCalificative = 0;
        this -> calificative = new int[nrCalificative];

        this -> salariu = 0;
        this -> idSediu = 0;
        this -> gen = 'N';

        this -> numeBanca = new char[strlen("Necunoscuta")+1];
        strcpy(this -> numeBanca, "Necunoscuta");

    }

    Angajat(int id):ID_Angajat(id)
    {
        this -> numeAngajat = new char[strlen("NewOne")+1];
        strcpy(this -> numeAngajat, "NewOne");

        this -> varsta = 0;
        this -> nrCalificative = 0;
        this -> calificative = new int[nrCalificative];

        this -> salariu = 0;
        this -> idSediu = 0;
        this -> gen = 'N';

        this -> numeBanca = new char[strlen("Necunoscuta")+1];
        strcpy(this -> numeBanca, "Necunoscuta");

    }

    Angajat(int id, char* nume, int varsta, char gen, int nrCal, int* calificative, float salariu, Sediu &s, Banca &b): ID_Angajat(id)
    {
        this -> numeAngajat = new char[strlen(nume)+1];
        strcpy(this -> numeAngajat, nume);

        this -> varsta = varsta;
        this -> gen = gen;
        this -> nrCalificative = nrCal;

        this -> calificative = new int[nrCalificative];
        for(int i = 0; i < nrCalificative; i++)
            this -> calificative[i] = calificative[i];

        this -> salariu = salariu;
        this -> idSediu = s.getID_Sediu();

        this -> numeBanca = new char[strlen(b.getNumeBanca())+1];
        strcpy(this -> numeBanca, b.getNumeBanca());
    }

    Angajat(const Angajat &a): ID_Angajat(a.ID_Angajat)
    {
        this -> numeAngajat = new char[strlen(a.numeAngajat)+1];
        strcpy(this -> numeAngajat, a.numeAngajat);

        this -> varsta = a.varsta;
        this -> gen = a.gen;
        this -> nrCalificative = a.nrCalificative;

        this -> calificative = new int[this -> nrCalificative];
        for(int i = 0; i < nrCalificative; i++)
            this -> calificative[i] = a.calificative[i];

        this -> salariu = a.salariu;
        this -> idSediu = a.idSediu;

        this -> numeBanca = new char[strlen(a.numeBanca)+1];
        strcpy(this -> numeBanca, a.numeBanca);

    }

    friend ostream &operator<< (ostream &out, const Angajat a)
    {
        if (a.gen == 'F')
            out << "Angajata ";
        else
            out << "Angajatul ";

        out << a.numeAngajat<< " in varsta de " << a.varsta << " ani lucreaza la sediul cu ID:" << a.idSediu << " al bancii *" << a.numeBanca;

        out << "*.\nIn plus are un salariu de " << a.salariu << "$. Pe timpul angajarii a obtinut " << a.nrCalificative <<" calificative:";

        for(int i = 0; i < a.nrCalificative; i++)
            out <<" "<< a.calificative[i];

        out << "\n";

        return out;
    }

    friend istream &operator>> (istream &in, Angajat &a)
    {
        char aux2[100];
        char aux1[100];

        cout << "Introdu numele angajatului: ";

        in.get(aux1, 100);
        in.get();

        if(a.numeAngajat != NULL)
            delete[] a.numeAngajat;

        a.numeAngajat = new char[strlen(aux1)+1];
        strcpy(a.numeAngajat, aux1);

        cout << "\nIntrodu varsta: ";
        in >> a.varsta;

        cout << "\nIntrodu genul: ";
        in >> a.gen;

        cout << "\nIntrodu salariul: ";
        in >> a.salariu;

        cout << "\nIntrodu nr de calificative: ";
        in >> a.nrCalificative;

        cout << "\nIntrodu calificativele: ";

        if(a.calificative != NULL)
            delete[] a.calificative;

        a.calificative = new int[a.nrCalificative];
        for(int i = 0; i< a.nrCalificative; i++)
            in >> a.calificative[i];

        cout << "\nIntrodu ID ul sediului: ";
        in >> a.idSediu;

        cout << "\nIntrodu numele Bancii:";

        in.get();
        in.get(aux2, 100);
        in.get();

        if(a.numeBanca != NULL)
            delete[] a.numeBanca;

        a.numeBanca = new char[strlen(aux2)+1];
        strcpy(a.numeBanca, aux2);

        cout << "\n";

        return in;
    }

    Angajat &operator= (const Angajat &a)
    {
        if(this != &a)
        {
            if(this -> numeAngajat != NULL)
                delete this -> numeAngajat;

            this -> numeAngajat = new char[strlen(a.numeAngajat)+1];
            strcpy(this -> numeAngajat, a.numeAngajat);

            this -> varsta = a.varsta;
            this -> gen = a.gen;
            this -> salariu = a.salariu;
            this -> nrCalificative = a.nrCalificative;

            this -> idSediu = a.idSediu;

            if(this -> calificative != NULL)
                delete this -> calificative;

            this -> calificative = new int[this -> nrCalificative];
            for(int i = 0; i < this -> nrCalificative; i++)
                this -> calificative[i] = a.calificative[i];

            if(this -> numeBanca != NULL)
                delete[] this -> numeBanca;
            this -> numeBanca = new char[strlen(a.numeBanca)+1];
            strcpy(this -> numeBanca, a.numeBanca);
        }

        return *this;

    }

    friend bool operator== (const Angajat &a, const Angajat &b)
    {
        if(strcmp(a.numeAngajat,b.numeAngajat) == 0 and a.varsta == b.varsta and a.idSediu == b.idSediu)
            return true;

        else
            return false;
    }

    friend bool operator< (const Angajat &a, const Angajat &b)
    {
        if(a.varsta < b.varsta)
            return true;
        else
            return false;
    }

    friend bool operator<= (const Angajat &a, const Angajat &b)
    {
        if(a.varsta <= b.varsta)
            return true;
        else
            return false;
    }

    friend bool operator> (const Angajat &a, const Angajat &b)
    {
        if(a.varsta > b.varsta)
            return true;
        else
            return false;
    }

    friend bool operator>= (const Angajat &a, const Angajat &b)
    {
        if(a.varsta >= b.varsta)
            return true;
        else
            return false;
    }

    Angajat &operator+ (float i)
    {
        this -> salariu = this -> salariu + i;

        return *this;
    }

    Angajat &operator- (float i)
    {
        this -> salariu = this -> salariu - i;

        return *this;
    }

    const Angajat &operator++()
    {
        this -> varsta++;

        return *this;
    }

    const Angajat operator++ (int)
    {
        Angajat aux(*this);

        this -> varsta++;

        return aux;
    }

    const Angajat &operator--()
    {
        this -> varsta--;

        return *this;
    }

    const Angajat operator-- (int)
    {
        Angajat aux(*this);

        this -> varsta--;

        return aux;
    }

    int operator[] (int i)
    {
        if(i >= 0 and i < this -> nrCalificative)
            return this -> calificative[i];

        else
            return -3;
    }

    explicit operator int()
    {
        return (int) this -> salariu;
    }

    ~Angajat()
    {
        if(this -> numeAngajat != NULL)
            delete[] this -> numeAngajat;

        if(this -> calificative != NULL)
            delete[] this -> calificative;

        if(this -> numeBanca != NULL)
            delete[] this -> numeBanca;

    }
};

class Client
{
    const int ID_Client;
    char* numeClient;
    int varsta;
    int nrCredite;
    float* credite;
    char gen;
    bool rauPlatnic;

public:
    static void msj()
    {
        cout << "Bine ai venit la noua ta banca\n";
    }

    virtual void mesajNou()
    {
        cout << "Bine ai venit!\n";
    }

    Client():ID_Client(0)
    {
        this -> numeClient = new char[strlen("ClientNou")+1];
        strcpy(this -> numeClient, "ClientNou");

        this -> varsta = 0;
        this -> nrCredite = 0;
        this -> gen = 'N';

        this -> credite = new float[nrCredite];

        this -> rauPlatnic = false;
    }

    Client(int id):ID_Client(id)
    {
        this -> numeClient = new char[strlen("ClientNou")+1];
        strcpy(this -> numeClient, "ClientNou");

        this -> varsta = 0;
        this -> nrCredite = 0;
        this -> gen = 'N';

        this -> credite = new float[nrCredite];

        this -> rauPlatnic = false;
    }

    Client(int id, char* nume, int varsta, char gen, int nrCredite, float* credite, bool platnic):ID_Client(id)
    {
        this -> numeClient = new char[strlen(nume)+1];
        strcpy(this -> numeClient, nume);

        this -> varsta = varsta;
        this -> gen  = gen;
        this -> nrCredite = nrCredite;

        this -> credite = new float[this -> nrCredite];
        for(int i = 0; i < this -> nrCredite; i++)
            this -> credite[i] = credite[i];

        this -> rauPlatnic = platnic;
    }

    Client(const Client &c):ID_Client(c.ID_Client)
    {
        this -> numeClient = new char[strlen(c.numeClient)+1];
        strcpy(this -> numeClient, c.numeClient);

        this -> varsta = c.varsta;
        this -> gen  = c.gen;
        this -> nrCredite = c.nrCredite;

        this -> credite = new float[this -> nrCredite];
        for(int i = 0; i < this -> nrCredite; i++)
            this -> credite[i] = c.credite[i];

        this -> rauPlatnic = c.rauPlatnic;
    }

    friend ostream &operator<< (ostream &out, const Client &c)
    {
        if(c.gen == 'F')
            out << "Clienta ";
        else
            out << "Clientul ";

        out << c.numeClient << " in varsta de " << c.varsta << " ani cu ID:" << c.ID_Client;

        if (c.rauPlatnic == true)
            out << " este rau platnic.\n";

        else
            out <<" nu este rau platnic.\n";

        if(c.nrCredite == 0)
            out << "Nu are credite";
        else
        {
            out << "Acesta are " << c.nrCredite << " credite($):";

            for(int i = 0; i < c.nrCredite; i++)
                out << " " << c.credite[i];
        }


        return out;
    }

    friend istream &operator>> (istream &in, Client &c)
    {
        cout << "Introdu numele clientului: ";

        char aux1[100];

        in.get(aux1,100);
        in.get();

        if(c.numeClient != NULL)
            delete[] c.numeClient;

        c.numeClient = new char[strlen(aux1)+1];
        strcpy(c.numeClient, aux1);

        cout << "\nIntrodu varsta: ";

        in >> c.varsta;

        cout << "\nIntrodu genul: ";

        in >> c.gen;

        cout << "\nIntrodu numarul de credite: ";
        in >> c.nrCredite;

        cout << "\nIntrodu valorile creditelor: ";

        if(c.credite != NULL)
            delete[] c.credite;

        c.credite = new float[c.nrCredite];
        for(int i = 0; i < c.nrCredite; i++)
            in >> c.credite[i];

        cout << "\nEste rau platnic?(1 = da, 0 = nu): ";
        in >> c.rauPlatnic;

        return in;

    }

    Client &operator= (const Client &c)
    {
        if(this != &c)
        {
            if(this -> numeClient != NULL)
                delete[] this -> numeClient;

            this -> numeClient = new char[strlen(c.numeClient)+1];
            strcpy(this -> numeClient, c.numeClient);

            this -> varsta = c.varsta;
            this -> gen = c.gen;
            this -> nrCredite = c.nrCredite;
            this -> rauPlatnic = c.rauPlatnic;

            if(this -> credite != NULL)
                delete[] this -> credite;

            this -> credite = new float[this -> nrCredite];
            for(int i = 0; i < this -> nrCredite; i++)
                this -> credite[i] = c.credite[i];

        }

        return *this;
    }

    friend bool operator== (const Client &a, const Client &b)
    {
        if (strcmp(a.numeClient, b.numeClient) == 0 and a.varsta == b.varsta)
            return true;
        else
            return false;
    }

    friend bool operator< (const Client &a, const Client &b)
    {
        if (a.varsta < b.varsta)
            return true;
        else
            return false;
    }

    friend bool operator<= (const Client &a, const Client &b)
    {
        if (a.varsta <= b.varsta)
            return true;
        else
            return false;
    }

    friend bool operator> (const Client &a, const Client &b)
    {
        if (a.varsta > b.varsta)
            return true;
        else
            return false;
    }

    friend bool operator>= (const Client &a, const Client &b)
    {
        if (a.varsta >= b.varsta)
            return true;
        else
            return false;
    }

    Client &operator+ (float i)
    {
        int aux = this -> nrCredite;

        float* a;

        a = new float[aux];
        for(int j = 0; j < aux; j++)
            a[j] = this -> credite[j];

        delete[] this -> credite;

        aux++;
        this -> credite = new float[aux];
        for(int j = 0; j < this -> nrCredite; j++)
            this -> credite[j] = a[j];

        this -> credite[aux-1] = i;
        this -> nrCredite = aux;
        delete[] a;

        return *this;
    }

    const Client operator++ ()
    {
        this -> varsta++;

        return *this;
    }

     const Client operator-- ()
    {
        this -> varsta--;

        return *this;
    }

    const Client operator++ (int)
    {
        Client aux(*this);

        this -> varsta++;

        return aux;
    }

    const Client operator-- (int)
    {
        Client aux(*this);

        this -> varsta--;

        return aux;
    }

    float operator[] (int i)
    {
        i--;

        if(i >= 0 and i< this -> nrCredite)
            return this -> credite[i];

        else
            return -4;
    }

    explicit operator int()
    {
        return (int) this -> varsta;
    }

     ~Client()
    {
        if(this -> numeClient != NULL)
            delete[] this -> numeClient;

        if(this -> credite != NULL)
            delete[] this -> credite;
    }

};

class CopilClient: public Client
{

    bool restrictieParinte;
public:

    void mesajNou()
    {
        cout << "Bine ai venit, viitor adult!\n";
    }
    CopilClient()
    {
        this -> restrictieParinte = false;
    }

    CopilClient(Client c,bool rest): Client(c)
    {
        this -> restrictieParinte = rest;
    }

    CopilClient(const CopilClient &cc): Client(cc)
    {
        this -> restrictieParinte = cc.restrictieParinte;
    }

    CopilClient &operator= (const CopilClient &cc)
    {
        if(this  != &cc)
        {
            Client(*this) = (Client&) cc;
            this -> restrictieParinte = cc.restrictieParinte;
        }
        return *this;
    }

    friend ostream &operator<<(ostream &out, CopilClient &cc)
    {
        out << (Client&) cc;

        if(cc.restrictieParinte == true)
            out << "\nAcesta are restrictie de la parinti\n";
        else
            out << "\nAcesta nu are restrictie de la parinti\n";


        return out;
    }

    friend istream &operator>>(istream &in, CopilClient &cc)
    {
        in >> (Client&) cc;

        cout << "\nSpune daca are restrictie de la parinti(1=da, 0=nu): ";
        in >> cc.restrictieParinte;
        return in;

    }

    ~CopilClient()
    {

    }
};

class Manager: public Angajat
{
    float oreBonus;

public:

    Manager()
    {
        oreBonus = 0;
    }
    Manager(Angajat a, float ore): Angajat(a)
    {
        oreBonus = ore;
    }

    Manager(const Manager &m): Angajat(m)
    {
        oreBonus = m.oreBonus;
    }

    Manager &operator= (const Manager &m)
    {
        if(this != &m)
        {
            Manager(*this) = (Manager&) m;
            this -> oreBonus = m.oreBonus;
        }
        return *this;
    }

    friend ostream &operator<< (ostream &out, Manager &m)
    {
        out << (Angajat&) m;

        out << "Acesta a facut " << m.oreBonus << " ore in plus\n";

        return out;

    }

    friend istream &operator>> (istream &in, Manager &m)
    {
        in >> (Angajat&) m;

        cout << "Introdu orele bonus: ";

        in >> m.oreBonus;

        return in;
    }

    ~Manager()
    {

    }

};

class CreditPersoana
{
    Client client;
    Sediu sediu;
    Angajat angajat;

public:

    CreditPersoana()
    {

    }

    CreditPersoana(Client c, Sediu s, Angajat a)
    {
        client = c;
        sediu = s;
        angajat = a;
    }

    CreditPersoana(const CreditPersoana &cp)
    {
        client = cp.client;
        sediu = cp.sediu;
        angajat = cp.angajat;
    }

    CreditPersoana &operator= (const CreditPersoana &cp)
    {
        if(this != &cp)
        {
            client = cp.client;
            sediu = cp.sediu;
            angajat = cp.angajat;
        }
        return *this;
    }

    friend ostream &operator<<( ostream &out, const CreditPersoana &cp)
    {
        out << "Detaliile creditului:\n-----------------------------------\nPersoana: ";
        out << cp.client << "\nSediu: ";
        out << cp.sediu << "Angajat: " << cp.angajat << "----------------------------------\n\n";

        return out;
    }

    ~CreditPersoana()
    {

    }
};


int main()

{
    ifstream file;

    file.open("datebanca.txt");

    int n;

    file >> n;

    vector<Banca> banci;
    vector<Sediu> sedii;
    vector<Angajat> angajati;
    vector<Client> clienti;
    vector<CreditPersoana> credite;
    vector<CopilClient> copii;
    vector<Manager> sefi;


    for(int i = 0; i < n; i++)
    {
        char nume[100];
        file.get();
        file.getline(nume, 100);

        int cui, num;
        float val;
        bool funct;
        char ban;

        file >> cui >> val >> funct >> ban >> num;

        int nums[num];
        
        for(int j = 0; j < num; j++)
           file >> nums[j];

        Banca b(i,nume,cui,val,funct,ban,num,nums);
        banci.push_back(b);

    }

     file.close();

     file.open("datesediu.txt");

     file >> n;

    for(int i = 0; i < n; i++)
    {
        char adress[100];
        int nrNiv;
        float seif;
        bool banc;

        file.get();
        file.getline(adress, 100);

        file >> nrNiv >> banc >> seif;

        int nrBirou[nrNiv];
        for(int j = 0; j < nrNiv; j++)
           file >> nrBirou[j];

        Sediu s(banci[0],i,adress,nrNiv,nrBirou,banc,seif);
        sedii.push_back(s);

    }

    file.close();

    file.open("dateangajati.txt");
    file >> n;

    for(int i = 0; i < n; i++)
    {
        int varsta, nrCal;
        char nume[150], gen;
        float salariu;

        file.get();
        file.get(nume, 150);

        file >> varsta >> gen >> nrCal;

        int calf[nrCal];
        for(int j = 0; j < nrCal; j++)
           file >> calf[j];

        file >> salariu;

        Angajat a(i,nume,varsta,gen,nrCal, calf,salariu,sedii[0],banci[0]);

        angajati.push_back(a);
    }

    file.close();

    file.open("dateclienti.txt");

    file >> n;

    for(int i = 0; i< n; i++)
    {
        char nume[150], gen;
        int nrCredite, varsta;
        bool plata;


        file.get();
        file.get(nume, 150);

        file >> varsta >> gen >> nrCredite;

        float credite[nrCredite];
        for(int j = 0; j < nrCredite; j++)
           file >> credite[j];

        file >> plata;

        Client c(i,nume,varsta,gen,nrCredite,credite,plata);

        clienti.push_back(c);
    }


    int rating[]= {4,3,5};
    char nume[] = "CTB";

    char adresa[100] = "str Turzii";
    int birouri[] ={23,42};

    int calif[] = {8,7,9};
    char nume2[] = "Florescu Alex";
    float note[] = {8,7,9};

    Banca b1(1, nume, 99333211, 54454.3, 1, '$', 3, rating);
    Sediu s1(b1,5,adresa,2,birouri,0,44345);
    Angajat a1(9, nume2, 33, 'M', 3, calif, 8877.5, s1, b1);
    Client c1(9,nume2,33,'M',3,note,0);
    CopilClient cc1(c1,1);
    Manager m1(a1,40);
    CreditPersoana cr1(c1,s1,angajati[0]);

    banci.push_back(b1);
    sedii.push_back(s1);
    angajati.push_back(a1);
    clienti.push_back(c1);
    copii.push_back(cc1);
    sefi.push_back(m1);
    credite.push_back(cr1);

    do
    {
    cout << "\n\n----------Bine ati venit la Gestiunea Bancilor :)----------\n\n" << "Lista departamentelor pe care le puteti selecta: \n 1.Banca \n 2.Sediu \n 3.Angajat \n 4.Client \n 5.Client copil \n 6.Manager \n 7.Lista credite\n 8.Iesire";
    cout << "\n\nIntrodu departamentul dorit: ";
    cin >> n;

    cout << "\n";

    switch(n)
    {

    case 1:
        {
            do
            {

                cout << "==========Bine ai venit la departamentul *Banca*==========\n\n";
                cout << "Lista optiuni: \n 1.Adaugare banca\n 2.Afisare banci\n 3.Creste valoarea bancii\n 4.Scade valoarea bancii\n 5.Eliminare banca\n 6.Iesire\n\nIntrodu optiunea: ";
                cin >> n;

                switch(n)
                {
                    case 1:
                        {
                            cout << "--=== Adaugare banca ===--\n\nIntrodu ID banca: ";
                            int q;
                            cin >> q;
                            Banca bb(q);
                            cin.get();
                            cin >> bb;
                            cout << "\n";
                            banci.push_back(bb);
                            break;
                        }
                   
                    case 2:
                        {
                            cout << "+++--- Afisare banci ---+++\n\n";
                            for (int x = 0; x < (int)banci.size(); x++)
                            cout << banci[x] << "\n";
                            break;
                        }
                    
                    case 3:
                        {
                            int s, q;
                            cout << "--- Creste valoarea bancii ---\n\nIntrodu pozita bancii din 2.Afisare banci(numerotare de la 0): ";
                            cin >> s;
                            cout << "Introdu valoarea pe care o adaugi: ";
                            cin >> q;
                            banci[s] = banci[s]+ q;
                            break;
                        }
                    
                    case 4:
                        {
                            int s, q;
                            cout << "--- Scade valoarea bancii ---\n\nIntrodu pozita bancii din 2.Afisare banci(numerotare de la 0): ";
                            cin >> s;
                            cout << "Introdu valoarea pe care o scazi: ";
                            cin >> q;
                            banci[s] = banci[s]- q;
                            break;
                        }
                    
                    case 5:
                        {
                            cout << "----- Eliminare banca ------\n\n Introdu banca ce vrei sa o elimini din 2.Afisare banci(numerotare de la 0): ";
                            int u;
                            cin >> u;
                            banci.erase(banci.begin()+u);
                            break;
                        }
                    
                    case 6:
                        {
                            cout << "--------- Iesire din departametul Banca ---------\n\n";
                            break;
                        }
                    
                    default:
                        {
                            cout << "\n--- Ai gresit valoarea... =( ---\n\n";
                        }

                }

            }while(n != 6);
            break;
        }

    case 2:
        {
            do
            {
                cout << "==========Bine ai venit la departamentul *Sediu*==========\n\n";
                cout << "Lista optiuni: \n 1.Adaugare sediu\n 2.Afisare sedii\n 3.Adauga bani seif\n 4.Scade bani seif\n 5.Eliminare sediu\n 6.Iesire\n\nIntrodu optiunea: ";
                cin >> n;

                switch(n)
                {
                    case 1:
                        {
                            cout << "--=== Adaugare sediu ===--\n\nIntrodu ID sediu: ";
                            int q;
                            cin >> q;
                            Sediu bb(q);
                            cin.get();
                            cin >> bb;
                            cout << "\n";
                            sedii.push_back(bb);
                            break;
                        }
                    
                    case 2:
                        {
                            cout << "+++--- Afisare sedii ---+++\n\n";
                            for (int x = 0; x < (int)sedii.size(); x++)
                            cout << sedii[x] << "\n";
                            break;
                        }
                    
                    case 3:
                        {
                            int s, q;
                            cout << "--- Adauga bani seif ---\n\nIntrodu pozita sediului din 2.Afisare sedii(numerotare de la 0): ";
                            cin >> s;
                            cout << "Introdu valoarea pe care o adaugi: ";
                            cin >> q;
                            sedii[s] = sedii[s]+ q;
                            break;
                        }
                  
                    case 4:
                        {
                            int s, q;
                            cout << "--- Scade bani din seif ---\n\nIntrodu pozita sediului din 2.Afisare sedii(numerotare de la 0): ";
                            cin >> s;
                            cout << "Introdu valoarea pe care o scazi: ";
                            cin >> q;
                            sedii[s] = sedii[s]- q;
                            break;
                        }
                    
                    case 5:
                        {
                            cout << "----- Eliminare sediu ------\n\n Introdu sediul ce vrei sa il elimini din 2.Afisare sedii(numerotare de la 0): ";
                            int u;
                            cin >> u;
                            sedii.erase(sedii.begin()+u);
                            break;
                        }
                   
                    case 6:
                        {
                            cout << "--------- Iesire din departametul Sediu ---------\n\n";
                            break;
                        }
                    
                    default:
                        {
                            cout << "\n--- Ai gresit valoarea... =( ---\n\n";
                        }
                }

            }while(n != 6);
            break;
        }

    case 3:
        {
            do
            {
                cout << "==========Bine ai venit la departamentul *Angajat*==========\n\n";
                cout << "Lista optiuni: \n 1.Adaugare angajat\n 2.Afisare angajat\n 3.Creste salariu\n 4.Scade salariu\n 5.Eliminare angajat\n 6.Iesire\n\nIntrodu optiunea: ";
                cin >> n;

                switch(n)
                {
                    case 1:
                        {
                            cout << "--==== Adaugare angajat ====--\n\nIntrodu ID angajat: ";
                            int q;
                            cin >> q;
                            Angajat bb(q);
                            cin.get();
                            cin >> bb;
                            cout << "\n";
                            angajati.push_back(bb);
                            break;
                        }
                   
                    case 2:
                        {
                            cout << "+++---+ Afisare angajati +---+++\n\n";
                            for (int x = 0; x < (int)angajati.size(); x++)
                            cout << angajati[x] << "\n";
                            break;
                        }
                    
                    case 3:
                        {
                            int s, q;
                            cout << "--- Creste salariu ---\n\nIntrodu pozita angajatului din 2.Afisare angajati(numerotare de la 0): ";
                            cin >> s;
                            cout << "Introdu valoarea pe care o adaugi: ";
                            cin >> q;
                            angajati[s] = angajati[s]+ q;
                            break;
                        }
                   
                    case 4:
                        {
                            int s, q;
                            cout << "--- Scade salariul ---\n\nIntrodu pozita sediului din 2.Afisare angajati(numerotare de la 0): ";
                            cin >> s;
                            cout << "Introdu valoarea pe care o scazi: ";
                            cin >> q;
                            angajati[s] = angajati[s]- q;
                            break;
                        }
                   
                    case 5:
                        {
                            cout << "----- Eliminare angajat ------\n\n Introdu angajatul ce vrei sa il elimini din 2.Afisare angajati(numerotare de la 0): ";
                            int u;
                            cin >> u;
                            angajati.erase(angajati.begin()+u);
                            break;
                        }
                   
                    case 6:
                        {
                            cout << "--------- Iesire din departametul Angajat ---------\n\n";
                            break;
                        }
                    
                    default:
                        {
                            cout << "\n--- Ai gresit valoarea... =( ---\n\n";
                        }
                }

            }while(n != 6);
            break;
        }

    case 4:
        {
            do
            {
                cout << "==========Bine ai venit la departamentul *Client*==========\n\n";
                cout << "Lista optiuni: \n 1.Adaugare client\n 2.Afisare client\n 3.Adauga credit\n 4.Eliminare client\n 5.Iesire\n\nIntrodu optiunea: ";
                cin >> n;

                switch(n)
                {
                    case 1:
                        {
                            cout << "--==== Adaugare client ====--\n\nIntrodu ID client: ";
                            int q;
                            cin >> q;
                            Client bb(q);
                            cin.get();
                            cin >> bb;
                            cout << "\n";
                            clienti.push_back(bb);
                            break;
                        }
                   
                    case 2:
                        {
                            cout << "+++---+ Afisare clienti +---+++\n\n";
                            for (int x = 0; x < (int)clienti.size(); x++)
                            cout << clienti[x] << "\n";
                            break;
                        }
                    
                    case 3:
                        {
                            int s;
                            float q;
                            cout << "--- Adauga credit ---\n\nIntrodu pozita clientului din 2.Afisare clienti(numerotare de la 0): ";
                            cin >> s;
                            cout << "Introdu valoarea creditului nou: ";
                            cin >> q;
                            clienti[s] = clienti[s]+ q;
                            break;
                        }
                   
                    case 4:
                        {
                            cout << "----- Eliminare client ------\n\n Introdu clientul ce vrei sa il elimini din 2.Afisare clienti(numerotare de la 0): ";
                            int u;
                            cin >> u;
                            clienti.erase(clienti.begin()+u);
                            break;
                        }
                    
                    case 5:
                        {
                            cout << "--------- Iesire din departametul Client ---------\n\n";
                            break;
                        }
                    
                    default:
                        {
                            cout << "\n--- Ai gresit valoarea... =( ---\n\n";
                        }
                }

            }while(n != 5);
            break;
        }
  
    case 5:
        {
            do
            {
                cout << "==========Bine ai venit la departamentul *Copil client*==========\n\n";
                cout << "Lista optiuni: \n 1.Adaugare copil\n 2.Afisare copii\n 3.Eliminare copil\n 4.Iesire\n\nIntrodu optiunea: ";
                cin >> n;

                switch(n)
                {
                    case 1:
                        {
                            cout << "--==== Adaugare copil ====--\n\n";

                            CopilClient bb;
                            cin.get();
                            cin >> bb;
                            cout << "\n";
                            copii.push_back(bb);
                            break;
                        }
                   
                    case 2:
                        {
                            cout << "+++---+ Afisare copii +---+++\n\n";
                            for (int x = 0; x < (int)copii.size(); x++)
                            cout << copii[x] << "\n";
                            break;
                        }
                   
                    case 3:
                        {
                            cout << "----- Eliminare copil ------\n\n Introdu copilul ce vrei sa il elimini din 2.Afisare copii(numerotare de la 0): ";
                            int u;
                            cin >> u;
                            copii.erase(copii.begin()+u);
                            break;
                        }
                    
                    case 4:
                        {
                            cout << "--------- Iesire din departametul copil ---------\n\n";
                            break;
                        }
                   
                    default:
                        {
                            cout << "\n--- Ai gresit valoarea... =( ---\n\n";
                        }
                }

            }while(n != 4);
            break;
        }

    case 6:
        {
            do
            {
                cout << "==========Bine ai venit la departamentul *Manager*==========\n\n";
                cout << "Lista optiuni: \n 1.Adaugare manager\n 2.Afisare manageri\n 3.Eliminare manager\n 4.Iesire\n\nIntrodu optiunea: ";
                cin >> n;

                switch(n)
                {
                    case 1:
                        {
                            cout << "--==== Adaugare manager ====--\n\n";

                            Manager bb;
                            cin.get();
                            cin >> bb;
                            cout << "\n";
                            sefi.push_back(bb);
                            break;
                        }
                    
                    case 2:
                        {
                            cout << "+++---+ Afisare manageri +---+++\n\n";
                            for (int x = 0; x < (int)sefi.size(); x++)
                            cout << sefi[x] << "\n";
                            break;
                        }
                    
                    case 3:
                        {
                            cout << "----- Eliminare manager ------\n\n Introdu managerul ce vrei sa il elimini din 2.Afisare manageri(numerotare de la 0): ";
                            int u;
                            cin >> u;
                            sefi.erase(sefi.begin()+u);
                            break;
                        }
                    
                    case 4:
                        {
                            cout << "--------- Iesire din departametul Manager ---------\n\n";
                            break;
                        }
                    
                    default:
                        {
                            cout << "\n--- Ai gresit valoarea... =( ---\n\n";
                        }
                }

            }while(n != 4);
            break;
        }

    case 7:
        {
            do
            {
                cout << "==========Bine ai venit la departamentul *Lista credite*==========\n\n";
                cout << "Lista optiuni: \n 1.Afisare credite\n 2.Iesire\n\nIntrodu optiunea: ";
                cin >> n;

                switch(n)
                {

                    case 1:
                        {
                            cout << "+++---+ Afisare credite +---+++\n\n";
                            for (int x = 0; x < (int)credite.size(); x++)
                            cout << credite[x] << "\n";
                            break;
                        }
                    
                    case 2:
                        {
                            cout << "--------- Iesire din departametul Lista credite ---------\n\n";
                            break;
                        }
                   
                    default:
                        {
                            cout << "\n--- Ai gresit valoarea... =( ---\n\n";
                        }
                }

            }while(n != 2);
            break;
        }
        
    case 8:
        {
            cout << "----- La revedere =) -----\n";
            break;
        }

    default:
        {
        cout << "--- Ai gresit valoarea... =( ---";
        }

    }
    }while(n!= 8);

	return 0;
	
}
