#include "std_lib_facilities.h"

struct Adatbazis
{
	double telefonszam;
	string kereszt,vezeteknev, email;
};
void Kiiratas(const vector<Adatbazis>& l)
{
	cout << "Keresztnév" << "\tVezetéknév" << "\tEmail-cím" << "\tTelefonszám" << endl;
	for (const auto& v : l)
	{
		cout << "  " << v.kereszt; 
		cout << "\t\t" << v.vezeteknev; 
		cout << "\t\t" << v.email; 
		cout << "\t" << fixed << setprecision(0) << v.telefonszam << endl;
	}
}

int main()
try
{

	//Drill 10
	vector<Adatbazis> lekeres = {
		{204005000,"Nagy","Sándor","ns@gmail.com"},
		{204005010,"Nagy","Szilvia","nszil@gmail.com"},
		{204005020,"Nagy","József","njozs@gmail.com"},
		{204005030,"Nagy","Attila","natt@gmail.com"},
		{204005040,"Nagy","Levente","nlev@gmail.com"}
	};

	Kiiratas(lekeres);
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