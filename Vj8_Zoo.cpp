#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Zivotinja {
public:
    string ime;
    string lokacija = "ZOO";
    double tezina;

    Zivotinja(string _ime) : ime(_ime) {}
    virtual ~Zivotinja() { cout << "Destruktor Zivotinja..." << endl; }

    virtual string GetLokacija() { return lokacija; };
};

class Pas : public Zivotinja {
public:
    Pas(string _ime) : Zivotinja(_ime) {
        lokacija = "ZOO-dvoriste";
        tezina = 10;
    }
    ~Pas() { cout << "Destruktor Pas" << endl; }

    string GetLokacija() override { return lokacija; }
};

class Riba : public Zivotinja {
public:
    Riba(string _ime) : Zivotinja(_ime) {
        lokacija = "ZOO-bazen";
        tezina = 3.5;
    }
    ~Riba() { cout << "Destruktor Riba" << endl; }
    string GetLokacija() override { return lokacija; }
};

class Sarun : public Riba {
public:
    Sarun(string _ime) : Riba(_ime) {}
};

double ProsjecnaTezina(vector<Zivotinja*> zoo) {
    double suma = 0;
    for (Zivotinja* zivotinja : zoo) {
        suma += zivotinja->tezina;
    }
    return suma / zoo.size();
}

int main() {
    Pas pas("Rex");
    Riba r1("R1"), r2("R2");

    vector<Zivotinja*> zoo = { &pas, &r1, &r2 };

    cout << pas.GetLokacija() << endl;
    cout << ProsjecnaTezina(zoo) << endl;

    Zivotinja* z = new Pas("Rex2");
    delete z;

    return 0;
}