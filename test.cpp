#include <vector>
#include<iostream>
#include <deque>
using namespace std;
template <class T>
vector<T> NeparniElementi(const vector<T>& vektor) {
	vector<T>neparni;
	for (int i = 0; i < vektor.size(); i++) {
		if (vektor[i] % 2 != 0) {
			neparni.push_back(vektor[i]);
		}
	}
	return neparni;
}

template <class T>
void ispis(vector<T> neparni) {
	for (int i = 0; i < neparni.size(); i++) {
		cout << neparni[i] << endl;
	}
}

//////////////////////////////////////////////////////////////



template <class T1, class T2>
auto suma(T1 a, T2 b) {
	return a + b;
}


int main() {
	
	vector<int> polje_elemenata = { 1,2,3,4,5,20,45,60,33,53,23,31 };
	ispis(NeparniElementi(polje_elemenata));

	cout << suma(2, 3) << endl;
}