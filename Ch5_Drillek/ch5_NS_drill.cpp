#include "std_lib_facilities.h"

int main()
try{

string success="Sikeres!";

    cout << " Success!\n " ; //Hiba: Cout Javítva: cout
    
    cout << " Success!\n";  // Hiba: '"' kihagyása Javítva "..." 
    
    cout << " Success " << "!\n"; // Hiba: '"' és ';' kihagyása Javítva "..." 
    
    cout << success << '\n'; //Hiba: success változó vagy "" Javítva string success="Success!" vagy "Success!"
    
    int res = 7; vector<int> v(10); v[5] = res; cout << " Success!\n " ; //string helyett int
    
    vector<int> v(10);v[5] = 7; if (v[5]==7) cout << " Success!\n " ; // v[5] és if !=7 helyett == 

    bool cond=true;
    if (cond) cout << " Success!\n " ; else cout << " Fail!\n " ; // új változó = bool cond... 

    bool c = true; if (c) cout << " Success!\n " ; else cout << " Fail!\n " ; // false = true helyett 
    
    string s = " ape " ; string c = " fool "; if (c>s) cout << " Success!\n " ;
    
    string s = " ape " ; if (s== " ape " ) cout << " Success!\n " ; // s== fool helyett ape

    string s = " fool " ; if (s== " fool " ) cout << " Success!\n " ;  // s = ape helyett fool és cout < helyett cout <<
    
    string s = " ape " ; if (s==" ape ") {s+=" fool "; cout << " Success!\n ";}// if(s+ "fool") hiba 

    vector<char> v(5); for (int i=0; 5>v.size(); ++i) ; cout << " Success!\n " ; // 0<v.size() ??
    
    vector<int> v(5); for (int i=0; i<=v.size(); ++i) ; cout << " Success!\n " ; //vector<char> ?? --> <int>

    string s = " Success!\n " ; for (int i=0; i<s.length(); ++i) cout << s[i]; //i<6 helyett i<9 vagy s.length()

    if (true) cout << " Success!\n " ; else cout << " Fail!\n " ; //then nem kell 

    int x = 2000; int c = x; if (c==2000) cout << " Success!\n " ; // char c helyett int c vagy double c 
    
    string s = " Success!\n " ; for (int i=0; i<s.length(); ++i) cout << s[i]; //10 helyett s.Length() 

    vector <int> v(5); for (int i=0; i<=v.size(); ++i) ; cout << " Success!\n " ; // vector <int> hiánya 
    
    int i=0; cin >> i; int j = 9; while (i<10) ++j; if (j<i) cout << " Success!\n " ; // cin >> i és j előtt int hiánya

    double x = 2; double d = ((5/x)-2); if (d==2/x-0.5) cout << " Success!\n ";  //int --> double / többi talán ()? 

    string s = " Success!\n " ; for (int i=0; i<=10; ++i) cout << s[i];  // kitöröljük <chart>

    int i=0,j=0;cin >> i; while (i<10) ++j; if (j<i) cout << " Success!\n " ;  // int j=0 hiánya + cin >> i...
    double x = 4; double d = 5/(x-2); if (d==(x/2)+0.5) cout << " Success!\n " ; //int --> double + egyenlet javítás 
    cout << "Success!\n " ; // cin helyett cout

    return 0;
}
catch (exception& e)
{
    cerr << "Hiba: " << e.what() << "\n";
    return 1;
}
catch(...)
{
    cerr << "Ismeretlen hiba!";
    return 2;
}