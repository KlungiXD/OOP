#include <cmath>
#include <iostream>

using namespace std;

bool jednaki_realni(double a, int b) {
    if (abs(a - b) < 0.00001)
        return true;
    return false;
}

class PotencijaBrojaException {
private:
    double potencija;

public:
    PotencijaBrojaException(double broj) : potencija(broj) {}

    void Ispis() {
        cout << "PotencijaBrojaException: potencija " << potencija
             << " ne smije biti negativna" << endl;
    }
};

class PotencijaBroja {
private:
    double baza;
    double potencija;

public:
    static int brojac_prirodnih;
    PotencijaBroja(double b, double p) : baza(b), potencija(p) {
        double vrijednost = pow(baza, potencija);
        int castana_vrijednost = (int)vrijednost;
        if (jednaki_realni(vrijednost, castana_vrijednost)) {
            brojac_prirodnih++;
        }
    }

    static int brojac() { return brojac_prirodnih; }
    void SetPotencija(double broj);
    friend ostream &operator<<(ostream &izlaz, PotencijaBroja &pb);
    friend istream &operator>>(istream &ulaz, PotencijaBroja &pb);
    friend double operator+(PotencijaBroja &prva, PotencijaBroja &druga);

    PotencijaBroja &operator++() {
        double vrijednost = pow(baza, potencija);
        double zeljena_vrijednost = vrijednost + 1;
        // na koji eksponent treba staviti bazu da bi dobili zeljenu vrijednost?
        // log_baza (zeljena vrijednost) = ln(zeljena_vrij) / ln(baza)
        potencija = log(zeljena_vrijednost) / log(baza);

        return *this;
    };

    PotencijaBroja operator++(int) {
        PotencijaBroja old = *this;
        operator++();
        return old;
    }
};

ostream &operator<<(ostream &izlaz, PotencijaBroja &pb) {
    izlaz << pb.baza << "^" << pb.potencija;
    return izlaz;
}

istream &operator>>(istream &ulaz, PotencijaBroja &pb) {
    ulaz >> pb.baza >> pb.potencija;
    return ulaz;
}

double operator+(PotencijaBroja &prva, PotencijaBroja &druga) {
    return pow(prva.baza, prva.potencija) + pow(druga.baza, druga.potencija);
}

void PotencijaBroja::SetPotencija(double broj) {
    if (broj < 0) {
        throw PotencijaBrojaException(broj);
    }
    potencija = broj;
}

int PotencijaBroja::brojac_prirodnih = 0;

int main() {
    PotencijaBroja potencija(16, 0.25);

    cout << PotencijaBroja::brojac() << endl;

    try {
        potencija.SetPotencija(-5);
    } catch (PotencijaBrojaException iznimka) {
        iznimka.Ispis();
    }

    cout << potencija << endl;
    PotencijaBroja a(1, 1);
    PotencijaBroja b(2, 2);

    cout << a + b << endl;

    cout << potencija << endl;
    ++potencija;
    potencija++;
    cout << potencija << endl;

    return 0;
}
