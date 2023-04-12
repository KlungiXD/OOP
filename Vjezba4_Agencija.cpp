#include <iostream>
#include <vector>
using namespace std;

class Putnik {
private:
    string ime, prezime, destinacija;
    int cijena_puta;
public:
    Putnik() {}
    void setCijena(int NovaCijena) {
        if (NovaCijena >= 0 || NovaCijena <= 25000) {
            cijena_puta = NovaCijena;
        }
    }
    int getCijena() const {
        return cijena_puta;
    }
};

class Agencija {
public:
    string naziv, adresa;
    vector<Putnik*>putnici;
    Agencija() {};
    Agencija(const Agencija& p) {
        for (int i = 0; i < putnici.size(); i++) {
            putnici.push_back(new Putnik);
            *putnici[i] = *p.putnici[i];
        }
    }
    Agencija( Agencija&& TempPutnici) {
        for (int i = 0; i < putnici.size(); i++) {
            putnici.push_back(TempPutnici.putnici[i]);
            TempPutnici.putnici[i] = NULL;
        }
    }
    Agencija& operator =(Agencija&& TempPutnici) {
        for (int i = 0; i < putnici.size(); i++) {
            delete putnici[i];
        }
        putnici.clear();
        for (int i = 0; i < putnici.size(); i++) {
            putnici.push_back(TempPutnici.putnici[i]);
            TempPutnici.putnici[i] = NULL;
        }
        return *this;
    }
};
int main()
{
    Agencija fastTravel;
    Agencija farTravel = fastTravel; // POZIV KOPIRNOG KONSTRUKTORA

    Agencija goodTravel;
    goodTravel = move(Agencija());  // PRIJENOSNI KONSTRUKTOR

    Agencija UKtravel;
    UKtravel = Agencija(); // OPERATOR PRIDRUZIVANJA PRIJENOS

}