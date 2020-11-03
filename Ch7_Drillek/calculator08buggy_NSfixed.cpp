
/*
	calculator08buggy.cpp

	Helpful comments removed.

	We have inserted 3 bugs that the compiler will catch and 3 that it won't.
*/

#include "std_lib_facilities.h"

struct Token { // Token osztály ( vagyis ezek publikusok )
	char kind; // Milyen típusa a tokennek
	double value; //Milyen értéke van
	string name; // Változó nevet adunk (pl. x=, y =, stb.) // Alatti --> Konstruktorok
	Token(char ch) :kind(ch), value(0) { }  //Létrehozunk egy olyan mezőt, ami tartalmazza típus,és értéket
	Token(char ch, double val) :kind(ch), value(val) { } // Létrehozunk második mezőt, ami tartalmaza típus értékét, és valódi értékét
	Token(char ch, string n) : kind(ch), name(n) {} // Hiánya... // Ehhez hozzunk létre --> típus, és vált. nevet
};

class Token_stream {  // Token stream azt csinálja, hogy beolvassa az értékeket, ami cin-ből jön
	bool full; // Buffer van benne-e a Tokenben?
	Token buffer; // Ebben tartjuk értékeket, amikor visszatesszünk az értéket
public:
	Token_stream() :full(0), buffer(0) { } // Nincs Token a bufferben (Üres)

	Token get(); // Kapja Tokent
	void unget(Token t) { buffer = t; full = true; } // unget=putback, ami visszateszi a vizsgált tokent 
													// (buffer=t --> másolja t-t a bufferbe)
												   // full = buffer full-ban van
	void ignore(char); // Kidobálja ignorált karaktereket
};

//Összes const char helyett constexpr char
constexpr char let = 'L';
constexpr char quit = 'Q';
constexpr char print = ';';
constexpr char number = '8';
constexpr char name = 'a';  
constexpr char negyzet_gyok= '@';
constexpr char hatvertek= 'p';

const string declkey ="#";
const string quitkey= "quit";
const string negyzetkey = "sqrt";
const string hatvkey= "pow";

struct Variable {
	string name;
	double value;
	Variable(string n, double v) :name(n), value(v) { } // name = x,y,z stb. value = érték ami azt érzékeli,
};														// változónak értéke lesz, ha megadtunk neki

vector<Variable> names;

double get_value(string s)
{
	for (int i = 0; i < names.size(); ++i)
		if (names[i].name == s) return names[i].value;
	error("get: undefined name ", s);
	return 0;
}

void set_value(string s, double d)
{
	for (int i = 0; i <= names.size(); ++i)
		if (names[i].name == s) {
			names[i].value = d;
			return;
		}
	error("set: undefined name ", s);
}

bool is_declared(string s) 
{
	for (int i = 0; i < names.size(); ++i)
		if (names[i].name == s) return true;
	return false;
}


Token Token_stream::get()
{
	if (full) { full = false; return buffer; } // Van még egyáltalán token? Akkor eltávolítja a tokent a bufferből
	
	char ch;
	cin >> ch; // Beolvassa a karaktereket, és kihagyja (szóközt, újsort stb)

	switch (ch) { //Műveleti jeleket, ami visszakell adnia Tokennek (ch) (Token vizsgálat történik meg)
	case '(':     //Ha számok, és pont, akkor vissza adja értéket
	case ')':
	case '+':
	case '-':
	case '*':
	case '/':
	case '%':
	case ';':
	case '=':
	case ',':
		return Token(ch);
	case '.':
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':
	{	
		cin.unget(); // Vissza teszi a számot inputba
		double val;
		cin >> val; // Ha van pont, akkor ....
		return Token(number, val);
	}
	case '#':
		return Token(let); // Pl. #x=5, azaz let x=5 stb.

	default: // Nem szám vagy kifejezés
		if (isalpha(ch)) // Ha bármilyen betűt észlelünk, akkor ezt let-nek fogja érzékelni
		{                // Vagy olyan definíciót észlel, akkor azt a szabályt fogja alkalmazni
			string s;    // Mint pl. sqrt, pow stb.
			s += ch;

			while (cin.get(ch) && (isalpha(ch) || isdigit(ch))) 
				s+= ch; // s = ch helyett s+ = ch
				cin.unget();

			if (s == declkey) return Token(let);
				if (s == quitkey) return Token(quit); // Hiba: Token(name) --> Token(quit)
					if (s == negyzetkey) return Token(negyzet_gyok);
						if (s == hatvkey) return Token(hatvertek);
			else if(is_declared(s))
				return Token(number, get_value(s));

			return Token{name, s}; //return Token(name, s) hiba --> (name) lett
		}
		error("Bad token");
		
	}
	return 0;
}

void Token_stream::ignore(char c)
{
	if (full && c == buffer.kind) {
		full = false;
		return;
	}
	full = false;

	char ch;
	while (cin >> ch)
		if (ch == c) return;
}

Token_stream ts; //get () és putback() függvényeket tartalmazza/biztosítja

double expression();

double negyzetgyokfg(){ 
	char ch; 
	if(cin.get(ch) && ch != '(') error ("'(' hiba"); // Ha nincs sqrt() zárójel, akkor hibát hoz
	cin.putback(ch); //Ha van, akkor visszateszi...
	double d = expression(); //Az érték sqrt( érték )
	if (d < 0) error("Négyzetgyök: negatív szám"); // Ha sqrt ( érték<0) akkor hibát jelezzen
	return sqrt(d);
}
double hatvanyozas(){ // Ezt úgy kell elképzelni, hogy pow(d,i) 
 
	Token t = ts.get(); // Beolvassuk a tokeneket
 
	if(t.kind !='(')       //Ha előtte nincs ( jel, akkor hibát jelezzen
		error("'(' hiba a pownál");
	double d = expression();  //Ha van, utána olvasson be d értéket

	t = ts.get();
	if(t.kind !=',')      // d után vesszőt is érzékeljen, ha nincs hibát jelezzen
		error("',' hiba a pownál");
	double i= expression(); // ha megvan, akkor olvasson be az i értéket

	t = ts.get();   // )-legyen a vége, ha nincs, hibát jelezzen
	if(t.kind !=')')
		error("')' hiba a pownál");

	return pow(d, i); // Ha minden hiba nélkül lefut, akkor adja vissza 

}

double primary() // Azokat csinálja, ami van (), és azt kezeljen is, és a számok, 
{ //változók nevek, számok, -, +, sqrt,pow stb.
	Token t = ts.get();
	switch (t.kind) 
	{
		case '(':
		{	
			double d = expression();
			t = ts.get();
			if (t.kind != ')') error("'(' expected");
			return d; // return d hiánya
		}
	case '-':
		return - primary();
	case number:
		return t.value;
	case name:
		return get_value(t.name);
	case negyzet_gyok: // sqrt(16);
		return negyzetgyokfg();
	case hatvertek:
		return hatvanyozas();
	default:
		error("primary expected");
		return 0;
	}
}

double term() // *,/, %-t csinálja
{
	double left = primary();
	while (true) {
		Token t = ts.get();
		switch (t.kind) {
		case '*':
			left *= primary();
			break;
		case '/':
		{	double d = primary();
		if (d == 0) error("divide by zero");
		left /= d;
		break;
		}
		default:
			ts.unget(t);
			return left;
		}
	}
}

double expression() // + és -
{
	double left = term();
	while (true) {
		Token t = ts.get();
		switch (t.kind) {
		case '+':
			left += term();
			break;
		case '-':
			left -= term();
			break;
		default:
			ts.unget(t);
			return left;
		}
	}
}
double define_name(string var, double val) // Változó és érték --> berakjuk egy vektorba
{
	if(is_declared(var)) error(var, "Deklarálva van");
	names.push_back(Variable{var,val});
	return val;
}
double declaration() // Deklarációkat kezeli 
{
	Token t = ts.get();
	if (t.kind != 'a') error("name expected in declaration");
	string name = t.name;

	if (is_declared(name)) error(name, " declared twice");
	Token t2 = ts.get();

	if (t2.kind != '=') error("= missing in declaration of ", name);
	double d = expression();
	names.push_back(Variable(name, d));
	define_name(name,d);

	return d;
}

double statement() // Ha érzékeli let-et, akkor adjon vissza, ha nem akkor... (eldönti, hogy deklarálni akar-e)
{
	Token t = ts.get();
	switch (t.kind) {
	case let:
		return declaration();
	default:
		ts.unget(t);
		return expression();
	}
}

void clean_up_mess() //Törli a sort..
{
	ts.ignore(print);
}

const string prompt = "> ";
const string result = "= ";

void calculate() //Ha végezte számolást, akkor adjon még új lehetőségeket
{
	while (true) try { //Amíg igaz, míg nem nem szakítjuk
		cout << prompt; //Sor eleje > ....
		Token t = ts.get(); //Token beolvasása
		while (t.kind == print) t = ts.get(); //Ameddig ;-t nem kapja
		if (t.kind == quit) return; //Ha quit akkor kilép a programból
		ts.unget(t);
		cout << result << statement() << endl;
	}
	catch (runtime_error& e) {
		cerr << e.what() << endl;
		clean_up_mess();
	}
}

int main()

try {

	define_name("pi", 3.14159); //Ezeket definiáltunk (define_name) függvényt, ha pi-t írunk be,
	define_name("e", 2.71828);  //akkor automatikusan értéket adja vissza
	define_name("k", 1000);

	calculate();
	return 0;
}
catch (exception& e) { //Hiba kezelések
	cerr << "exception: " << e.what() << endl;
	char c;
	while (cin >> c && c != ';');
	return 1;
}
catch (...) {
	cerr << "exception\n";
	char c;
	while (cin >> c && c != ';');
	return 2;
}
