#include "std_lib_facilities.h"

struct Pontok {

	double x,y;

};

vector<Pontok> eredeti_pontok,feldolgozott_pontok;

int main()
try{
	string fajl="sajadat.txt";
	double x,y;
	cout << "Kérem írjon be 7 pontokat (x és y) értékkel (Csak számokkal!): " << endl;
	int ossz=0;

	/*for (int i = 1; i < 8; ++i)
	{
		cout << "X["<<i<<"]: ";
			cin >> x;
		cout << "Y["<<i<<"]: ";
			cin >> y;
		eredeti_pontok.push_back(Pontok{x,y});
	}*/

	while(eredeti_pontok.size() != 7)
	{
		++ossz;
		cout << "X["<<ossz<<"]: ";
		cin >> x;
		cout << "Y["<<ossz<<"]: ";
		cin >> y;
		if(cin.good()) eredeti_pontok.push_back(Pontok{x,y});
		else
		{
			cerr << "Hiba!" << endl;
			return 0;
		}
	}

	cout << "------------------";
	cout << "Ellenőrzés (Kiiratás)";
	cout << "------------------" << endl;

	ofstream ost { fajl };

	int db=0;
	int db2=0;

	for(const auto& v : eredeti_pontok)
	{
		++db;
		 cout << "X["<< db <<"]: "<< v.x << " , " << "Y["<< db <<"]: "<< v.y << endl;

	}
	for(const auto& v : eredeti_pontok)
	{
		++db2;
		 ost << "X["<< db2 <<"]: "<< v.x << " , " << "Y["<< db2 <<"]: "<< v.y << endl;

	}

	ost.close();

	cout << "------------------";
	cout << "Ellenőrzés 2. (Beolvasás)";
	cout << "------------------" << endl;

	ifstream ist { fajl };
	if(!ist) error("Hiba!!!");

	//Beolvasási változók
	string Xvalt;
	double Xert;
	string vesszo;
	string Yvalt;
	double Yert;

	// Beolvasás adott változókkal
	while(ist >> Xvalt >> Xert >> vesszo >> Yvalt >> Yert)
	{
		//cout << Xvalt << " " << Xert << " " << vesszo << " " << Yvalt << " " << Yert << " " << endl;

		feldolgozott_pontok.push_back(Pontok{Xert,Yert});
	}

	int db3=0;
	for(const auto& v : feldolgozott_pontok)
	{
		++db3;
		 cout << "X["<< db3 <<"]: "<< v.x << " , " << "Y["<< db3 <<"]: "<< v.y << endl;
	}

	ist.close();
    // Két vektor ellenőrzése
	if(eredeti_pontok.size() == feldolgozott_pontok.size()) cout << "Minden rendben van!" << endl;
	else
		{
			cout << "Valami hiba történt! Oka:" << endl;
			cout << eredeti_pontok.size() << " eleme van 1.vektor" << endl;
			cout << feldolgozott_pontok.size() << " eleme van 2.vektor" << endl;
		}

}catch(exception& e)
{
	cerr << e.what() << endl;
	return 1;
}catch(...)
{
	cerr << "hiba" << endl;
	return 2;
}
