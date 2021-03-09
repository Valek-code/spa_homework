#include <iostream>

using namespace std;
void Print(polinom p);

int f(int n);
int najveciBroj(int n);
double iznos(int brGodina, double kamata, double pocetniIznos);

int main()
{

	cout << "funckcija 1:  " << f(100) << endl;
	cout << "              ";
	cout << f(103) << endl;
	cout << "funckcija 2:  "
		 << "iznos: " << iznos(1, 1.2, 200.0) << endl;
	cout << "funckcija 3:  " << najveciBroj(12291432) << endl;
}

// Pomocna funkcija Print(polinom p)
void Print(polinom p)
{
	if (IsZero(p))
	{
		cout << 0 << endl;
		return;
	}
	for (int i = Degree(p); i >= 0; i--)
		cout << " " << Coef(p, i) << "*x^" << i << " ";
	cout << endl;
}

// 1. Napi�ite rekurzivnu funkciju koja racuna ukupno ustedeni iznos nakon x godina. Ustedeni iznos
//	  nakon isteka godine se racuna pomocu formule iznos(x) = kamata*iznos(x+1)+iznos(x-1)
//	  Argumenti funkcije su broj godina, kamata i pocetni iznos.

double iznos(int brGodina, double kamata, double pocetniIznos)
{
	if (brGodina == 1)
		return kamata * pocetniIznos + pocetniIznos;
	return iznos(brGodina - 1, kamata, pocetniIznos);
}

// 2. Napisite program koji ucitava prirodni broj n i ispisuje vrijednost f(n), gdje je funkcija
//	  f() zadana na sljedeci nacin =
//
//	  		f(n) = n-10			za n > 100
//			f(n) = f(n+11)		za n <= 100

int f(int n)
{
	if (n > 100)
		return n - 10;
	return f(n + 11);
}

// 3.Napisite rekurzivnu funkciju prima jedan cijeli broj i koja ispisuje najvecu znamenku u tom broju

int najveciBroj(int n)
{

	if (n < 10)
		return n;
	int broj = n % 10;
	int ostaliBrojevi = najveciBroj(n / 10);

	if (broj > ostaliBrojevi)
		return broj;
	return ostaliBrojevi;
}
