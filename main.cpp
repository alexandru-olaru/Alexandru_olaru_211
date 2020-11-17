#include <iostream>
#include <string.h>

using namespace std;

class Produs
{

private:
    string nume;

protected:
    float pretBrut;

public:

    virtual float calculatePret()
    {
        return pretBrut;
    }

    void afisareBrand()
    {
        cout << "brandd";
    }

    friend ostream &operator<<(ostream &out, const Produs &p)
    {
        out << p.nume;
        return out;
    }

    friend istream &operator>> (istream &in, Produs &p)
    {
        cout<< "Numele este: ";
        in >> p.nume;
        cout << "pretul: ";
        in >> p.pretBrut;

        return in;
    }

};

class ProdusPerisabil: public Produs
{
private:
    string dataExpirare;

public:

    float calculatePret()
    {
        return this -> pretBrut+(45*this -> pretBrut)/100;
    }


};

class ProdusNeperisabil: public Produs
{
private:
    int garantie;

public:
    float calculatePret()
    {
        return this -> pretBrut+(10*this->pretBrut)/100;
    }


};
int main()
{
/*
    Produs *p = new ProdusPerisabil();
    ProdusPerisabil a;
    p =&a;
    cin>>a;
    cout << p -> calculatePret();
*/

    Produs *p[10];
    p[1] = new ProdusPerisabil();
    p[2] = new ProdusNeperisabil();
    ProdusPerisabil a;
    ProdusNeperisabil b;
    p[1] = &a;
    p[2] = &b;
    cin>> a;
    cin>>a;
    cout << p[1] -> calculatePret()<<" "<< p[2] -> calculatePret();

    return 0;
}
