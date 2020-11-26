#include "std_lib_facilities.h"

	//1.feladat 

	int ga[10]= {1,2,4,8,16,32,64,128,256,512};

	//2. feladat 

	void f(int arg[], int elem)
	{
		//a rész - új tömb
		int la[10];

		//b rész - másoljuk át ga->la[]-ba
		for (int i = 0; i < elem; ++i)
		{
			la[i] = ga[i];
		}

		//c rész - iratassuk ki
		for (int i = 0; i < elem; ++i)
		{
			cout << la[i] << " | ";
		}
		cout << endl;

		//d rész - pointer...
		int *p = new int[elem];

		//e,f,g rész - pointerbe másolása/kiiratása/deallokálás
		for (int i = 0; i < elem; ++i)
		{
			p[i] = la[i];
			cout << p[i] << " | ";
		}
		cout << endl;
		delete[] p;
		

	}

int fakt(int n)
{
	if (n > 1) 
		return n*(fakt(n-1));
	else 
		return 1;
}

int main()
try{

	//4.feladat

	//a rész 
	cout << "ga tömb" << endl;
	f(ga,10);

	//b rész
	int aa[10] {fakt(1),fakt(2),fakt(3),fakt(4),fakt(5),fakt(6),fakt(7),fakt(8),fakt(9),fakt(10)};

	//c rész
	cout << "aa tömb" << endl;
	f(aa,10);

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