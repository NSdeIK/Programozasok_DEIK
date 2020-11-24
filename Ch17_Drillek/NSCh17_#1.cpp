#include "std_lib_facilities.h"

//----------------------------------------------------------
//Tömb
void print_array10(ostream& os, int* a)
{
	for (int i = 0; i < 10; ++i)
	{
		os << "int[" << i << "]: " << a[i] << " | Címe: [ " << &a[i] << " ]" << endl;
	}
}

void print_array(ostream& os, int* a, int n)
{
	for (int i = 0; i < n; ++i)
	{
		os << "int[" << i << "]: " << a[i] << " | Címe: [ " << &a[i] << " ]" << endl;
	}
}

int* allokalas(int n)
{
	int* a = new int[n];
	int kezdoertek = 100;
	for (int i = 0; i < n; ++i)
	{
		a[i] = kezdoertek++;

	}
	return a;
}
//----------------------------------------------------------

//----------------------------------------------------------
//Vektor
vector<int*> allokalasvektor(int n)
{
	vector<int*> elemek;
	int kezdoertek = 100;
	for (int i = 0; i < n; ++i)
	{
		elemek.push_back(new int{kezdoertek++});
	}
	return elemek;
}
void printVektor(vector<int*> v)
{
	for (long unsigned int i = 0; i < v.size(); ++i)
	{
		cout << "int[" << i << "]: " << *v[i] << " | Címe: [ " << &v[i] << " ]" << endl;
	}
	
}
void torlesVektor(vector<int*> v)
{
	for (auto& vektor : v)
	{
		delete vektor;
	}
}
//----------------------------------------------------------

int main()
try{

	//------------------------------------------------------------------------------
	//Drill 1 //Allokáljuk 10 elemet (integerrel)
	
	int* tizelem = new int[10];

	//Drill 2 //Irjuk ki 10 elemet
	cout << "--------------------------------" << endl;
		cout << "Drill 2 feladat kiiratása" << endl;
	cout << "--------------------------------" << endl;

	for(int i=0; i < 10; ++i)
	{
		cout << "int[" << i <<"]: " << tizelem[i] << " | Címe: [ " << &tizelem[i]<< " ]" << endl;
	}

	//Drill 3 //Deallokáljuk
	delete[] tizelem;

	//------------------------------------------------------------------------------

	//------------------------------------------------------------------------------
	//Drill 4 //printArray10 kiiratása
	
	cout << "--------------------------------" << endl;
		cout << "Drill 4 feladat kiiratása" << endl;
	cout << "--------------------------------" << endl;
	
	int* tizelem2 = new int[10];

	print_array10(cout, tizelem2);

	delete[] tizelem2;

	//------------------------------------------------------------------------------

	//------------------------------------------------------------------------------
	//Drill 5 // Allokáljuk tíz elemet, ami tartalmazza 100,101,102 stb.

	cout << "--------------------------------" << endl;
		cout << "Drill 5 feladat kiiratása" << endl;
	cout << "--------------------------------" << endl;

	int* tizelem3 = new int[10]{100,101,102,103,104,105,106,107,108,109};

	for (int i = 0; i < 10; ++i)
	{
		cout << "int[" << i <<"]: " << tizelem3[i] << " | Címe: [ " << &tizelem3[i]<< " ]" << endl;
	}
	delete[] tizelem3;
	//------------------------------------------------------------------------------

	//------------------------------------------------------------------------------
	//Drill 6 // Allokáljuk 11 elemet ...
	cout << "--------------------------------" << endl;
		cout << "Drill 6 feladat kiiratása" << endl;
	cout << "--------------------------------" << endl;

	int* tizenegyelem = new int[11]{100,101,102,103,104,105,106,107,108,109,110};

	for (int i = 0; i < 11; ++i)
	{
		cout << "int[" << i <<"]: " << tizenegyelem[i] << " | Címe: [ " << &tizenegyelem[i]<< " ]" << endl;
	}
	delete[] tizenegyelem;

	//------------------------------------------------------------------------------

	//------------------------------------------------------------------------------
	//Drill 7 

	cout << "--------------------------------" << endl;
		cout << "Drill 7 feladat kiiratása" << endl;
	cout << "--------------------------------" << endl;

	int* elemek = new int[2]{1234,4321};

	print_array(cout,elemek,3); // ...

	delete[] elemek;

	//------------------------------------------------------------------------------

	//------------------------------------------------------------------------------
	//Drill 8

	cout << "--------------------------------" << endl;
		cout << "Drill 8 feladat kiiratása" << endl;
	cout << "--------------------------------" << endl;

	//int* huszelem = new int[20]{1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
	int* huszelem = allokalas(20);

	print_array(cout,huszelem,20);

	delete[] huszelem;

	//------------------------------------------------------------------------------

	//------------------------------------------------------------------------------
	//Drill 10...
	cout << "***************************************" << endl;
	vector<int*> v_tizeselem = allokalasvektor(10);
	printVektor(v_tizeselem);
	cout << "***************************************" << endl;
	vector<int*> v_tizenegyelem = allokalasvektor(11);
	printVektor(v_tizenegyelem);
	cout << "***************************************" << endl;
	vector<int*> v_huszelem = allokalasvektor(20);
	printVektor(v_huszelem);
	cout << "***************************************" << endl;
	torlesVektor(v_tizeselem);
	torlesVektor(v_tizenegyelem);
	torlesVektor(v_huszelem);

	return 0;


}catch(exception& e)
{
	cerr << e.what() << endl;
	return 1;
}catch(...)
{
	cerr << "Hiba!" << endl;
	return 2;
}