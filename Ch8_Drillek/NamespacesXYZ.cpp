#include "std_lib_facilities.h"

namespace X 
{
	double var;
		void print()
		{
			cout << "X: " << var << endl;
		}
}
namespace Y 
{
	double var;
		void print()
		{
			cout << "Y: " << var << endl;
		}
}
namespace Z 
{
	double var;
		void print()
		{
			cout << "Z: " << var << endl;
		}
}

int main()
{
	
//X érték
	X::var=7;
	X::print();

	//Y érték
		using namespace Y;
		var = 9;
		print();

			//Z érték
			{
				using Z::var;
				using Z::print;
				var = 11;
				print();
			}

	//Y érték
		print();

//X érték
	X::print();

}
