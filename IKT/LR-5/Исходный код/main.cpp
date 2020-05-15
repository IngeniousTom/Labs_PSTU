#include <iostream>
#include "Vector.h"
#include "Pair.h"
#include "Complex.h"

using namespace std;

int main() {
    Vector v(5);

    cout << "Ввод Pair a:\n";
    Pair a;
    cin >> a;

    cout << "\nВвод Complex b:\n";
    Complex b;
    cin >> b;

    Objecto *p = &a;
    v.add(p);
    p = &b;
    v.add(p);
    cout << v;

    cout << endl << "Нажмите [Enter] для завершения программы!";
    cin.ignore();
    cin.get();

    return 0;
}