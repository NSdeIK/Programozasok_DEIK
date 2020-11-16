#include "std_lib_facilities.h"

int main()
try
{
	//Drill 1 feladat
	int szuletesi_ev = 1999;

	//Drill 2/3/4 feladat
	cout << "\nDecimális:\t" << showbase << dec << szuletesi_ev << endl;
	cout << "Hexadecimális:\t" << showbase << hex << szuletesi_ev << endl;
	cout << "Oktális:\t" << showbase << oct << szuletesi_ev << endl;

	//Drill 5/6 feladat --> Probléma az volt, hogy oktális értékre volt átváltva (20 helyett 024 lett)
	cout << showbase << dec << endl;
	cout << "Korom:\t" << 20 << '\n' <<endl;

	//Drill 7/8 feladat
	int a,b,c,d;
	cin >> a >> oct >> b >> hex >> c >> d;
	cout << a << '\t' << b << '\t' << c << '\t' << d << '\n' << endl;


	return 0;
}catch(exception&e)
{
	cerr << e.what() << endl;
	return 1;
}catch(...)
{
	cerr << "Hiba!" << endl;
	return 2;
}