#include <iostream>
#include <vector>
using namespace std;

class Zaposlenik {
private:
    string ime;
    string prezime;
    int god_rad_staz;

public:
    void setGod(int NoveGod) {
        if (NoveGod >= 0 || NoveGod <=  35) {
            god_rad_staz = NoveGod;
        }
        else {
            god_rad_staz = god_rad_staz;
        }
    }

    int setGod() const {
        return god_rad_staz;
    }

    //ZA IMPLEMENTACIJU VAN KLASE
    //void setGod(int NoveGod);
    //int setGod() const;
};

// ILI IMPLEMENTACIJA VAN KLASE
//void Zaposlenik::setGod(int NoveGod) {
//    if (NoveGod >= 0 || NoveGod <= 35) {
//        god_rad_staz = NoveGod;
//    }
//    else {
//        god_rad_staz = god_rad_staz;
//    }
//}
//
//int Zaposlenik::setGod() const {
//    return god_rad_staz;
//}


class Tvrtka {
public:
    string OIB;
    string naziv;
    string adresa;
    vector<Zaposlenik*>zaposlenici;

    Tvrtka() = default;

    //kopirni konstruktor
    Tvrtka(const Tvrtka &t) {
        // DEEP COPY
        for (int i = 0; i < t.zaposlenici.size();i++) {
            zaposlenici.push_back(new Zaposlenik);
            *zaposlenici[i] = *t.zaposlenici[i];
        }
    }

    //OPERATOR PRIDRUZIVANJA
    Tvrtka& operator=(const Tvrtka &t) {
        if (this != &t) {
            // DEALOCIRANJE
            for (int i = 0; i < zaposlenici.size(); i++) {
                delete zaposlenici[i];
            }
            zaposlenici.clear();
            // DEEP COPY
            for (int i = 0; i < t.zaposlenici.size(); i++) {
                zaposlenici.push_back(new Zaposlenik);
                *zaposlenici[i] = *t.zaposlenici[i];
            }

        }
        return *this;
    }

    // OPERATOR PRIDRUZIVANJA SA SEMANTIKOM PRIJENOSA
    Tvrtka& operator= (Tvrtka&& privremenaT) {
    //DEALOKACIJA
        for (int i = 0; i < zaposlenici.size(); i++) {
            delete zaposlenici[i];
        }
        zaposlenici.clear();
        //PRIJENOS POKAZIVACA PRIVREMENOG ELEMENTA
        for (int i = 0; i < privremenaT.zaposlenici.size(); i++) {
            zaposlenici.push_back(privremenaT.zaposlenici[i]);
            privremenaT.zaposlenici[i] = NULL;
        }
        return *this;
    }

    //DESTRUKTOR
    ~Tvrtka() {
        for (int i = 0; i < zaposlenici.size(); i++)
            delete zaposlenici[i];
        zaposlenici.clear();
    }
};


int main()
{
    Tvrtka proizvodnja;
    Tvrtka pakiranje = proizvodnja; // poziv kopirnog konstruktora

    Tvrtka prijevoz, trgovina;

    trgovina = prijevoz; // poziv operator pridruzivanja

    Tvrtka ribolov;
    ribolov = Tvrtka(); //poziv operatora pridruzivanja sa semantikom prijenosa
}