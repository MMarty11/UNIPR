#include <iostream>
using namespace std;

/* 
  Classe che realizza il tipo di dato astratto "numero razionale"
*/   

// class Razionale {...} oppure #include "classe_razionale.cpp"

int main() {
  
    Razionale a;
    Razionale b(4,6);
    Razionale c(4);
    Razionale d(9,3);  
	  
    cout << "razionale a: " << a << endl;   // 0
    cout << "razionale b: " << b << endl;   // 2/3
    cout << "razionale c: " << c << endl;   // 4
    cout << "razionale d: " << d << endl;   // 3
    
    a = b + c;
    cout << "razionale b+c: " << a << endl;  // 14/3
    a = b * 3;
    cout << "razionale b*3: " << a << endl;  // 2
    a = Razionale(2) * 5;
    cout << "razionale 2*5: " << a << endl;  // 10
    a = b + Razionale(1,3);
    cout << "razionale b+1/3: " << a << endl;  // 1
   
    if(b < 2) cout << "minore" << endl;
	else cout << "maggiore" << endl;
	
	Razionale x,y;
	cout << "Dai una frazione o un intero: ";  
	cin >> x;
	cout << "Numero letto: " << x << endl;
	cout << "Dai una frazione o un intero: ";
	cin >> y;
	cout << "Numero letto: " << y << endl;
	cout << "somma di x e y: " << x + y << endl;
	Razionale z;
	cout << "Dai una frazione o un intero: ";  
	cin >> z;
	cout << "Numero letto: " << z << endl;
	
//    system("pause");
    return 0;
}

/* traccia esecuzione

razionale a: 0
razionale b: 2/3
razionale c: 4
razionale d: 3
razionale b+c: 14/3
razionale b*3: 2
razionale 2*5: 10
razionale b+1/3: 1
minore
Dai una frazione o un intero: 2/3
Numero letto: 2/3
Dai una frazione o un intero: 3
Numero letto: 3
somma di x e y: 11/3
Dai una frazione o un intero: 5/0
ATTENZIONE!: denominatore nullo
Numero letto: 5

*/

