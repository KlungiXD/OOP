#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

class Proizvod {
private:
	string sifra, naziv;
public:
	Proizvod() = default;
	void setProizvod(string NoviNaziv) {
		for (int i = 0; i < NoviNaziv.size(); i++) {
			if (NoviNaziv[i] >= 'a' && NoviNaziv[i] <= 'z') {
				NoviNaziv[i] -= 32;
			}
		}
		naziv = NoviNaziv;
	}
	string getProizvod() const {
		return naziv;
	}
};

class Ducan {
public:
	string naziv, adresa;
	vector<Proizvod*>prodani_proizvodi;
	Ducan() = default;

	Ducan(const Ducan& d) {
		for (int i = 0; i < d.prodani_proizvodi.size(); i++) {
			prodani_proizvodi.push_back(new Proizvod);
			*prodani_proizvodi[i] = *d.prodani_proizvodi[i];
		}
	}

	Ducan& operator=(Ducan& d) {
		if (this != &d) {
			for (int i = 0; i < prodani_proizvodi.size(); i++) {
				delete prodani_proizvodi[i];
			}
			prodani_proizvodi.clear();

			//DEEP COPY
			for (int i = 0; i < d.prodani_proizvodi.size(); i++) {
				prodani_proizvodi.push_back(new Proizvod);
				*prodani_proizvodi[i] = *d.prodani_proizvodi[i];
			}
		}
		return *this;
	}


		Ducan& operator = (Ducan&& DucanTemp) {
			for (int i = 0; i < prodani_proizvodi.size(); i++) {
				delete prodani_proizvodi[i];
			}
			prodani_proizvodi.clear();

			for (int i = 0; i < DucanTemp.prodani_proizvodi.size(); i++) {
				prodani_proizvodi.push_back(DucanTemp.prodani_proizvodi[i]);
				DucanTemp.prodani_proizvodi[i] = NULL;
			}
			return *this;
		}
};
int main()
{
	Ducan Studenac;
	Ducan Lonia = Studenac; // KOPIRNI KONSTRUKTOR
	/////////////////////////////////////////
	Ducan Konzum, Pevex;
	Pevex = Konzum; // OPERATOR PRIDRUZIVANJA

	Ducan Kapitalac;
	Kapitalac = Ducan(); // OPERATOR PRIDRUZIVANJA SA SEMANTIKOM PRIJENOSA
}