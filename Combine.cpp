#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <cmath>
using namespace std;

string stri;
int size;

void line(int leng = 25){								//Vypise caru o urcite delce
	for (int i = 0; i < leng; ++i){
		cout << "=";
	}
	cout << endl;
}

string pickOne(string str){								//Zkrati puvodni retezec aby kazdy znak byl pouze jednou
	string List;										//Tohle bude vystup
	int c, x;
	List += str[0];										//Na prvni misto vystupu da prvni znak ze vstupu, aby bylo s cim porovnavat dalsi
	for (int i = 0; i <= (str.size() - 1); ++i){		//str.size() - 1 protoze indexy jsou od 0
		for (x = 0; x <= (List.size() - 1); ++x){
			if (List[x] != str[i]){						//Porovnat jestli uz je znak v outputu
				c++;
			}
		}
		if (c == List.size()){							//Pokud jiz neni v Listu tak ho tam prida
			List += str[i];
		}
		c = 0;
	}
	line();
	return List;										//Funkce vrati string ve kterem je kazdy znak z puvodniho retezce pouze jednou
}
/*====================Combine==================*/
void combine(string str){								//Vznik kombinaci funguje na stejnem principu jako prevody cisel do jinych soustav
	size = str.size();
	string Text;										//String s vysledkem
	int x = 0;											//Hodnota ze ktere se pocita vysledek
	clock_t begin = clock();

	while(x < pow(size, size)){
		Text.clear();									//Vyamzani predchoziho vysledneho retezce
		int z = x;										//Hodnotu x si ulozime do z kde s ni budeme moci beztrestne pracovat
		for (int i = 0; i < size; ++i){					//'i' je hodnota ktera se pouzije pro upravu exponentu
			int powN = pow(size, size - 1 - i);			//powN je umocnena delka retezce
			int posZ = z/powN;							//posZ je hodnota indexu v retezci str (vstupni data)
			Text += str[posZ];							//Vysledny string + znak na miste s hodnotou odpovidajici posZ
			z = z%powN;									//'z' se ted rovna zbytku z deleni ktere jiz bylo zapsano do vysledneho stringu
		}
		x++;											//Zviseni hodnouty ze ktere se pocita exponent
		cout << Text << endl;							//Vypsani aktualniho retezce
	}
	clock_t end = clock();
	string info = to_string((int)(pow(size, size))) + " kombinaci z " + to_string(size) + " znaku. " + "Cas: " + to_string(double(end - begin) / CLOCKS_PER_SEC) + "s";		//Jen nejake info
	line(info.size() + 2);								//Linka akorat tak dlouha
	cout << info << endl;								//Vytisteni informaci
}
/*====================MAIN====================*/
int main(){
	cout << "Pismena pro kombinaci:" << endl;
	getline(cin, stri);									//Ziskani znaku
	stri = pickOne(stri);								//Zkraceni aby kazdy byl jen jednou
	cout << stri << endl;								//Vypsani upraveneho retezce
	line();												//Cara pro prahlednost
	combine(stri);										//Funkce vypisujici kombinace
	return 0;
}