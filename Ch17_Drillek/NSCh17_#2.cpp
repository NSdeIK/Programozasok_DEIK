#include "std_lib_facilities.h"

void print_array(ostream& os, int* a, int n)
{
	for (int i = 0; i < n; ++i)
	{
		os << "int[" << i << "]: " << a[i] << " | Címe: [ " << &a[i] << " ]" << endl;
	}
}

int main()
try{
	//Drill 1 feladat
	cout << "-------------------------------" << endl;
	int szam = 7;
	int* p1 = &szam;

	//Drill 2 feladat
	cout << "Érték: " << szam << " | P1 értéke: " << p1 << endl;

	//Drill 3 feladat
	int het [7] = {1,2,4,8,16,32,64};
	int* p2 = het;

	//Drill 4 feladat
	cout << "-------------------------------" << endl;
	print_array(cout, p2, 7);
	cout << "P2 értéke: " << p2 << endl;
	cout << "-------------------------------" << endl;

	//Drill 5 feladat
	int* p3=p2;

	//Drill 6 feladat
	p1=p2;

	//Drill 7 feladat
	p3=p2;

	//Drill 8 feladat
	cout << "P1 értéke: " << *p1  << " | Címe [ "<< p1  << " ]" << endl;
	print_array(cout, p2, 7);

	//Drill 9 feladat
	//Nem szükséges, mert nem allokáltunk free store-t (lokális változók)
	//delete[] p3,p2,p1; --> Hibát hoz "double free or corruption"

	//Drill 10 feladat
	cout << "\n-------------------------------(10 feladat)" << endl;
	int tiz [10] = {1,2,4,8,16,32,64,128,256,512};
	p1 = tiz;
	cout << "P1 értéke: " << *p1  << " | Címe [ "<< p1  << " ]" << endl;
	cout << "-------------------------------" << endl;

	//Drill 11 feladat
	cout << "-------------------------------(11 feladat)" << endl;
	int tizelem [10] = {05,15,25,35,45,55,65,75,85,95};
	p2 = tizelem;
	cout << "P2 értéke: " << *p2  << " | Címe [ "<< p2  << " ]" << endl;
	cout << "-------------------------------" << endl;

	//Drill 12 feladat
	for (int i = 0; i < 10; ++i)
	{
		p2[i]=p1[i];
	}
	cout << "-------------------------------(12 feladat)" << endl;
	cout << "P1 értéke: " << *p1  << " | Címe [ "<< p1  << " ]" << endl;
	cout << "P2 értéke: " << *p2  << " | Címe [ "<< p2  << " ]" << endl;
	cout << "-------------------------------" << endl;
	//Drill 13 feladat Smile :) 
	vector<int> v_tiz{1,2,4,8,16,32,64,128,256,512};
	vector<int> v_tizelem{05,15,25,35,45,55,65,75,85,95};
	p1 = &v_tiz[0];
	p2 = &v_tizelem[0];
	for (int i = 0; i < 10; ++i)
	{
		p2[i]=p1[i];
	}
	cout << "-------------------------------(13 feladat)" << endl;
	cout << "P1 értéke: " << *p1  << " | Címe [ "<< p1  << " ]" << endl;
	cout << "P2 értéke: " << *p2  << " | Címe [ "<< p2  << " ]" << endl;

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
