#include "std_lib_facilities.h"

struct Datum //Dátum
	{  
		int y; //Év
		int m; //Hónap
		int d; //Nap
	};

	Datum ma; //Dátum változója...
	Datum holnap;

	void jelenlegi_datum(Datum& jeldat, int y, int m, int d) // Ellenőrzés, hogy dátum-e
	{
		if(y < 1800 || y > 2100)
			cout << "Hiba: Érvénytelen év" << endl; //Ha egyezik,
		else if(m < 1 || m > 12)
			cout << "Hiba: Érvénytelen hónap" << endl; // akkor dobjon hibát..
		else if(d < 1 || d > 31)
			cout << "Hiba: Érvénytelen nap" << endl;
		else //Ha nem egyezik az adott feltételekkel, akkor tároljuk...
		{
			jeldat.y = y;
			jeldat.m = m;
			jeldat.d = d;
		}
		return;
	}
	void napok_adasa(Datum jeldat,Datum& jeldat_uj, int n) 
	{         //Napok adása, és ellenőrizze ....           
		bool utolsonap = false; // Utolsó nap? 
		bool evvege = false; // Utolsó hónap?

		for (int i=0; i < n; ++i) // Napokat szépen egyesével hozzáadjuk
		{ 
			if(jeldat.d == 31) utolsonap = true; // Utolsó nap 31?

			jeldat.d = (jeldat.d == 31) ? 1 : ++jeldat.d; // Ha nem igaz, akkor +1 nap

				if(utolsonap) // Bekerül, ha igaz, akkor
				{ 
					utolsonap = false; // Átkerül hamisra
					jeldat.m = (jeldat.m == 12) ? 1 : ++jeldat.m; //Hónap 12?, ha nem akkor hónap +1

					if(jeldat.m == 12) evvege = true; //Bekerül, ha igaz, akkor
						if (evvege) 
						{
							evvege = false; // Átkerül hamisra
							++jeldat.y; //Új évet adunk hozzá
						}
				}
		}
		jeldat_uj= jeldat; // Megadtunk egy olyan változót, ami tároljon bele
	}						//Új dátumot

	ostream& operator<<(ostream& os, const Datum& d) //Operátor túlterhelése?
	{
		return os << d.d << ", " << d.m << ", " << d.y << endl;
		//Visszaadjuk "függvény, év, hónap, nap"
	}

int main()
{

	jelenlegi_datum(ma, 1978, 6, 25);
	napok_adasa(ma, holnap, 1);
	cout << endl << "Ma: " << ma << endl;
	cout << "Holnap " << holnap << endl;


	return 0;
}