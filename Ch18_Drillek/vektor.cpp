#include "std_lib_facilities.h"

//1.feladat
vector<int> gv = {1,2,4,8,16,32,64,128,256,512};

//2.feladat
void f(vector<int>& v)
{
	//a rész
	vector<int> lv(10);

	//b rész
	lv = v;

	//c rész
	for (const auto& vektor : lv)
	{
		cout << vektor << " | ";
	}
	cout << endl;

	//d rész
	vector<int> lv2 = v;

	//e rész
	for (const auto& vektor : lv2)
	{
		cout << vektor << " | ";
	}
	cout << endl;
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
	//4. feladat
	//a rész
	cout << "gv vektor" << endl;
	f(gv);

	//b rész
	//vector<int> vv = {1, fakt(2),fakt(3),fakt(4),fakt(5),fakt(6),fakt(7),fakt(8),fakt(9),fakt(10)};
	vector<int> vv(10);
	for (int i = 0; i < vv.size(); ++i)
	{
		vv[i] = fakt(i+1);
	}

	//c rész
	cout << "vv vektor" << endl;
	f(vv);
	

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