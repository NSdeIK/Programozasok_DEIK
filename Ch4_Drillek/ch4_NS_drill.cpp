#include "std_lib_facilities.h"

int main()
{
	/*double ertek1,ertek2;
	cout << "Kérem írjon be az első és második értéket! (Pl.: 5 10)" << endl << "Értékek: ";

	while(cin >> ertek1 >> ertek2)
	{
		cout << "\nElső szám értéke: " << ertek1 << endl << "Második szám értéke: " << ertek2 << endl;
		if(abs(ertek1-ertek2)<=0.01)
			cout << ertek1 << " és " << ertek2 << " majdnem egyenlőek egymással!\n";
		else if(ertek1<ertek2)
			cout << "\nLegkisebb értéke: " << ertek1 << endl << ertek1 << " < " << ertek2 << endl;
		else if(ertek1>ertek2)
			cout << "\nLegnagyobb értéke: " << ertek1 << endl << ertek1 << " > " << ertek2 << endl;
		else if(ertek1==ertek2)
			cout << ertek1 << " és " << ertek2 << "megegyezik egymással!\n"; 
		else
			cout << "Érvénytelen... ( Hibakód: |1| )";
	}*/


	//Beolvassuk az erteket
	string cm = "cm";
	string m = "m";
	string in = "in";
	string ft1 = "ft.";
	string ft2 = "ft";
	
	double ujertek, valtoertek;
	//...
	double maxertek=0,minertek=0,osszeadas =0,db=0;
	//Mértékegység
	string mertekegyseg ="";
	//Vektor ertekek
	vector<double> adatok;
	//Switchez való érték
	int ujmertekegyseg=0;
	cout << "Írj bármilyen értéket, és a mértékegységet! (Elfogadott mértékegységek: cm,m,in,ft)" << endl;
	while(cin >> ujertek >> mertekegyseg)
	{

		//Egyszerűbb, ha if-el oldjuk meg ezeket (de most gyakorlásképpen így oldottam meg)
		if(mertekegyseg == cm)
			ujmertekegyseg=1;
		else if(mertekegyseg == m)
			ujmertekegyseg=2;
		else if(mertekegyseg == in)
			ujmertekegyseg=3;
		else if(mertekegyseg == ft1)
			ujmertekegyseg=4;
		else if(mertekegyseg == ft2)
			ujmertekegyseg=4;
		//else if(mertekegyseg == "y" || "yard" || "meter" || "km" || "gallons") 
		else
		{
			cout << "Nincsen engedélyezve! (Illegális)" << endl;
			ujmertekegyseg=0;
		}
		//Mértékegység váltás
		switch(ujmertekegyseg)
		{
			case 0 :
				break;
			case 1 : //cm
				valtoertek=ujertek/100;
				cout << "Átváltás: " << valtoertek << " m" << endl;
				++db;
				break;
			case 2 : //m
				valtoertek=ujertek;
				cout << "Átváltás: " << valtoertek << " m" << endl;
				++db;
				break;
			case 3 : //in
				valtoertek=(ujertek*2.54)/100;
				cout << "Átváltás: " << valtoertek << " m" << endl;
				++db;
				break;
			case 4 : //ft
				valtoertek=(ujertek*12*2.54)/100;
				cout << "Átváltás: " <<valtoertek << " m" << endl;
				++db;
				break;
			default:
				break;
		}
		 //Mennyi lépést tettünk meg idáig...
		if(ujmertekegyseg!=0)
		{
			osszeadas+=valtoertek; //Összeadja az értékeket
			cout << "---------------------\n";
			cout << "Jelenlegi: "<< osszeadas << " méter. (Összesítve)" << endl << "Összesen: " << db << " db" << endl; //Hány méter összesítve
			cout << "---------------------\n";
			adatok.push_back(valtoertek); //Hozzáadja az értéket while kívül a vektornak.
				if(maxertek==0 && minertek ==0)
				{
					maxertek = valtoertek;
					minertek = valtoertek;
				}
				else if(valtoertek<minertek) //Ha van ennél kisebb érték, mint az előzőnél, akkor beilleszti új értéket.
				{
					minertek=valtoertek;
				}
				else if(valtoertek>maxertek) //Ha nagyobb érték, mint az előzőnél, akkor beilleszti új értéket.
				{
					maxertek=valtoertek;
				}
		}

	}

	sort(adatok); //Rendezi a sorrendet

	cout <<  "---------------------\n" << "Eddig beírt értékek" << endl <<  "---------------------\n";

	for (auto ertekek: adatok) //Sorolja az értékeket
	{
		cout << ertekek <<" m"<< endl;
	}

	cout << "---------------------\n";
	cout << "Legkisebb érték: " << minertek << " m\nLegnagyobb érték: " << maxertek << " m \n";

	

	return 0;

}
