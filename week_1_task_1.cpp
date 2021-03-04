#include <iostream>
#include "polinomATP.h"

using namespace std;
void Print(polinom p);

int neg_koef(polinom p);
bool comparePol(polinom p, polinom p2, int x);
void suprotan_p(polinom *p);



int main() {
	
	// Testni polinomi 
	polinom p, b;
	Attach(&p, 1, -1);
	Attach(&p, 2, -2);
	Attach(&p, 3, -3);
	Attach(&p, 4, 1);
	
	Attach(&b, 1, -1);
	Attach(&b, 2, -2);
	
	
	// Testiranje funkcija
	
	cout << neg_koef(p) << endl;
	comparePol(b,p,2);
	suprotan_p(&p);
	Print(p);
	
	system("pause");
	return 0;
}

// Pomocna funkcija Print(polinom p)
void Print(polinom p){
	if(IsZero(p)) {
		cout<<0<<endl;return;
	}
	for(int i=Degree(p);i>=0;i--)
			cout<<" "<<Coef(p,i)<<"*x^"<<i<<" ";
	cout<<endl;
}


/* 1. Napi�ite funkciju neg_koef() koja uzima polinom p i vra�a broj njegovih negativnih koeficijenata. */

int neg_koef(polinom p) {
	int brojac = 0;
	for(int i = 0; i < p.en; i++){
		if(p.values[i] < 0){
			brojac++;
		}
	}
	return brojac;
}

/* 2. Napi�ite funkciju koja prima dva polinoma p1 i p2 i vrijednost x i vra�a true ako prvi polinom ima ve�u vrijednost za x,
	odnosno false ako drugi polinom ima ve�u vrijednost za x. U glavnom programu ispi�ite rezultat rada funkcije funkcije. */

// �to ako nije vrijednost veca za x?

bool comparePol(polinom p, polinom p2, int x) {
	int pd1 = Degree(p);
	int pd2 = Degree(p2);
	int diff = pd1-pd2;
	
	if(diff == x) return true;
	else return false;
	
}

/* 3. Napi�ite funkciju void suprotan_p(polinom *p) koja �e zamijeniti sve koeficijente od p njima suprotnim brojevima. */

void suprotan_p(polinom *p) {
	for(int i = 0; i < p -> en; i++){
		p -> values[i] = -(p -> values[i]);
 	}
}
