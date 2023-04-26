#include <iostream>
using namespace std;
    
class Iznimka {
public:
    double broj1, broj2;
    Iznimka(double br1, double br2) : broj1(br1), broj2(br2){}

    void Ispis() {
        cout << "Nema smisla da su broj " << broj1 << " realan dio i broj " << broj2 << " imaginarni dio imaginarnog broja, zato sto je to samo broj 0!";
    }
};


class Kompleksni {
private:
    double re, im;
public:
    static int broj_kompleksnih;
    Kompleksni() {
        broj_kompleksnih++;
    }
    Kompleksni(double _re, double _im) : re(_re), im(_im){
        broj_kompleksnih++;
    }
    
    void setKompleksni(double a, double b) {
        try {
            if (a == 0 && b == 0) {
                throw Iznimka(a, b);
            }
            re = a;
            im = b;
        }
        catch (Iznimka iznimka) {
            iznimka.Ispis();
        }
    }
    Kompleksni operator+(const Kompleksni& Z) {
        return Kompleksni(re + Z.re, im + Z.im);      // ČLANSKI OPERATOR
    }

    Kompleksni operator-(const Kompleksni& Z) {
        return Kompleksni(re - Z.re, im - Z.im);      // ČLANSKI OPERATOR
    }

    Kompleksni& operator++() {         //PREFISK OPERATOR
        ++re;
        ++im;
        return *this;
    }

    Kompleksni operator++(int) {       // SUFIKS OPERATOR
        Kompleksni pom = *this;
        re++;
        im++;
        return pom;
    }

    friend istream& operator >>(istream& ulaz, Kompleksni& Z);
    friend ostream& operator <<(ostream& izlaz, Kompleksni Z);
    //friend Kompleksni operator-(const Kompleksni& Z1, const Kompleksni& Z);
    //friend Kompleksni operator+(const Kompleksni& Z1, const Kompleksni& Z); // PROZIVAMO DEKLARACIJU FRIEND ZBOG PRIVATE CLANOVA

    ~Kompleksni() {
        --broj_kompleksnih;
    }
};

ostream& operator <<(ostream& izlaz, Kompleksni Z) {
    izlaz << Z.re << " + " << Z.im << "i" << endl ;
    return izlaz;
}

istream& operator >>(istream& ulaz, Kompleksni& Z1) {
    ulaz >> Z1.re >> Z1.im;
    return ulaz;
}


int Kompleksni::broj_kompleksnih = 0;


//Kompleksni operator+(const Kompleksni& Z1, const Kompleksni & Z) {
//    return Kompleksni(Z1.re + Z.re, Z1.im + Z.im);                // NEČLANSKI OPERATOR
//}


//Kompleksni operator-(const Kompleksni& Z1, const Kompleksni& Z) {
//    return Kompleksni(Z1.re - Z.re, Z1.im - Z.im);               // NEČLANSKI OPERATOR
//}

int main()
{
    Kompleksni Z1(2,3);
    Kompleksni Z2(1,4);
    Kompleksni Z3 = Z1 + Z2;
    Kompleksni Z4 = Z1 - Z2;
    Kompleksni Z7;
    cout << "Kompleksnih ima: " << Kompleksni::broj_kompleksnih << endl;

    //ISPIS KOMPLEKSNOG BROJA Z2
    cout << Z2;
    Kompleksni Z5;
    cin >> Z5;
    cout << Z5 << endl;

    ++Z1;
    cout << Z1 << endl;

    Z5++;
    cout << Z5 << endl;

    Kompleksni Z6;
    Z6.setKompleksni(0, 0);

    
}
