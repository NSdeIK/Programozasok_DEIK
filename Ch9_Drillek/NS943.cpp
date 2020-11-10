#include "std_lib_facilities.h"

class Datum //Dátum
	{
	private:  
		int y; //Év
		int m; //Hónap
		int d; //Nap
	public:
		Datum(int y, int m, int d);
		void napok_adasa(int n);

		int honap() {return m;}
		int nap() {return d;}
		int ev() { return y;}
	};

	Datum ma(1978, 6, 25); //Dátum változója...
	Datum holnap(ma);

	Datum::Datum(int y, int m, int d) // Ellenőrzés, hogy dátum-e
	{
		if(y < 1800 || y > 2100)
			cout << "Hiba: Érvénytelen év" << endl; //Ha egyezik,
		else if(m < 1 || m > 12)
			cout << "Hiba: Érvénytelen hónap" << endl; // akkor dobjon hibát..
		else if(d < 1 || d > 31)
			cout << "Hiba: Érvénytelen nap" << endl;
		else //Ha nem egyezik az adott feltételekkel, akkor tároljuk...
		{
			Datum::y = y;
			Datum::m = m;
			Datum::d = d;
		}
		return;
	}

	void Datum::napok_adasa(int n) 
	{         //Napok adása, és ellenőrizze ....           
		bool utolsonap = false; // Utolsó nap? 
		bool evvege = false; // Utolsó hónap?

		for (int i=0; i < n; ++i) // Napokat szépen egyesével hozzáadjuk
		{ 
			if(Datum::d == 31) utolsonap = true; // Utolsó nap 31?

			Datum::d = (Datum::d == 31) ? 1 : ++Datum::d; // Ha nem igaz, akkor +1 nap

				if(utolsonap) // Bekerül, ha igaz, akkor
				{ 
					utolsonap = false; // Átkerül hamisra
					Datum::m = (Datum::m == 12) ? 1 : ++Datum::m; //Hónap 12?, ha nem akkor hónap +1

					if(Datum::m == 12) evvege = true; //Bekerül, ha igaz, akkor
						if (evvege) 
						{
							evvege = false; // Átkerül hamisra
							++Datum::y; //Új évet adunk hozzá
						}
				}
		}
	}					

	ostream& operator<<(ostream& os, Datum& d) //Operátor túlterhelése?
	{
		return os << d.nap() << ", " << d.honap() << ", " << d.ev() << endl;
		//Visszaadjuk "függvény, év, hónap, nap"
	}

int main()
{

	holnap.napok_adasa(1);
	cout << endl << "Ma: " << ma << endl;
	cout << "Holnap " << holnap << endl;


	return 0;
}