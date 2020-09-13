#include "std_lib_facilities.h"

int main()
{
//Drill 1
	string kereszt,barat;
	cout << "Kérem írjon be a keresztnevét!\n";
	cin >> kereszt;

	cout << endl << "Hello, " << kereszt << "!\n"; 
//Drill 2
	cout << endl << "Hogy vagy? Jól vagyok köszönöm!" << endl << "Milyen napod volt? Nagyon szuper volt!" << endl << "Szoktál fotózni mostanában? Igen, és nagyon remek fotókat csináltam!\n"<< endl;
//Drill 3
	cout << "Kérem írjon be a barátod keresztnevét!\n";
	cin >> barat;
	cout << endl << "Nem láttad mostanában " << barat << "-t?\n";
//Drill 4
	char nem=0;
	cout << "\nKérem írjon be, hogy a barátod F (férfi) vagy N (nő) nemhez tartozik...\n";
	cin >> nem;
	if(nem=='F')
		cout << "\nHa látsz " << barat << "-t, akkor kérd meg, hogy hívjon fel! (Please ask him to call me)\n";
	else if(nem=='N')
		cout << "\nHa látsz " << barat << "-t, akkor kérd meg, hogy hívjon fel! (Please ask her to call me)\n";
	else
		cout << "\nNem létezik ilyen!\n";

//Drill 5
	int kor;
	cout << "\nKérem írjon be a korát!\n";
	cin >> kor;
	cout << "\nHallom, hogy nemrég születésnapod volt, és " << kor <<" éves vagy!\n";
	if(kor <=0 || kor >=110)
	{
		simple_error("Viccelsz!?");
	}
//Drill 6
	if(kor <12)
		cout << "\nKövetkező évben " << kor+1 << " éves leszel!\n";
	else if(kor == 17)
		cout << "\nKövetkező évben tudsz szavazni!\n";
	else if(kor >=70)
		cout <<"\nRemélem élvezed nyugdíjas korát!\n";

//Drill 7

	cout << "Tisztelettel, \n\n" << kereszt << endl;
	return 0;
}