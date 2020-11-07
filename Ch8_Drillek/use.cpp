
#include "my.h"
////////////////////////////////////
int foo;

int main()
{
	//-----------------------------
	//foo drill 1.
	//-----------------------------
	foo = 7; // Adtuk foo-nak 7-es értéket
	print_foo(); // Kiíratja foo változót.
	print(99); // Függvény belül kiíratja 99 értékét


	//-----------------------------
	//swap drill 2.
	//-----------------------------
		int x=7;
		int y=9;
	//-----------------------------
			swap_v(x,y); //Okés
			swap_r(x,y); //Okés
			swap_cr(x,y);  //Nem okés - Oka: Nem cserélődik, konst miatt
			swap_v(7,9); //Okés
			//swap_r(7,9); //Nem okés - Oka: Nem cserélődik, érték referencia miatt 
			swap_cr(7,9); //Okés
	//-----------------------------
		const int cx= 7;
		const int cy= 9;
	//-----------------------------
			swap_v(cx,cy); //Okés
			//swap_r(cx,cy); //Nem okés - Oka: Nem cserélődik, const érték referencia miatt
			swap_cr(cx,cy);  //Okés
	//-----------------------------
		double dx=7.7;
		double dy=9.9;
	//-----------------------------
			swap_v(dx,dy); //Okés
			//swap_r(dx,dy); //Nem okés - Oka: ..., érték referencia miatt + int hiba
			swap_cr(dx,dy); //Okés
			swap_v(7.7,9.9); //Okés
			//swap_r(7.7,9.9); //Nem okés - Oka: ..., érték referencia miatt + int hiba
			swap_cr(7.7,9.9); //Okés

	return 0;
}