#include "my.h"
#include "std_lib_facilities.h"


void print_foo()
{
	cout << foo << endl;
}
void print(int i)
{
	cout << i << endl;
}

void swap_v(int a, int b) // int értékét cserélődik (a=5, b=7 --> 7,5 lesz)
{
	int temp;
	temp=a;
	a=b;
	b=temp;
	cout << "swap_v: " << a <<","<<  b << endl;
}
void swap_r(int& a, int& b) // referenciát cserélődik
{
	int temp;
	temp=a;
	a=b;
	b=temp;

	cout << "swap_r: " << a <<","<<  b << endl;
}
void swap_cr(const int& a, const int& b) 
{
	int temp1 = a;
	int temp2 = b;

	swap_r(temp1,temp2);
	cout << "swap_cr: " << temp1 <<","<<  temp2 << endl;
}