#include "std_lib_facilities.h"

int main()
try
{
	//Drill 9-as
	cout << "\n****Float (defaultfloat)****\n";
	const float sorszam3 = 1234567.89;
	cout << "Alap:\t\t" << sorszam3 << endl;
	cout << "Defaultfloat:\t" << defaultfloat << sorszam3 << endl;
	cout << "Fixed:\t\t" << fixed << sorszam3 << endl;
	cout << "Scientific:\t" << scientific << sorszam3<< endl <<endl;

	cout << "\n****Const Double (Fixed)****\n";
	const double sorszam2 = 1234567.89;
	cout << "Alap:\t\t" << sorszam2 << endl;
	cout << "Defaultfloat:\t" << defaultfloat << sorszam2 << endl;
	cout << "Fixed:\t\t" << fixed << sorszam2 << endl;
	cout << "Scientific:\t" << scientific << sorszam2 << endl <<endl;
	
	cout << "\n****Double (Scientific)****\n";
	double sorszam = 1234567.89;
	cout << "Alap:\t\t" << sorszam << endl;
	cout << "Defaultfloat:\t" << defaultfloat << sorszam << endl;
	cout << "Fixed:\t\t" << fixed << sorszam << endl;
	cout << "Scientific:\t" << scientific << sorszam << endl <<endl;
	//setprecision(9);

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
