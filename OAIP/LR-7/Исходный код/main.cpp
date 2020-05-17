#include <iostream>
#include "Vector.h"
#include "Time.h"

using namespace std;

/**
 * Главная Функция
 * @return 
 */
int main() {
    //ДЕМОСТРАЦИЯ РАБОТЫ С БАЗОВЫМИ ЧИСЛОВЫМИ ТИПАМИ
    cout << "ДЕМОСТРАЦИЯ РАБОТЫ С БАЗОВЫМИ ЧИСЛОВЫМИ ТИПАМИ\n\n";
    
    //Инициализация, ввод и вывод значений вектора
    Vector<int> A(5, 5);
    cout << "\nВведите элементы вектора А<int> (5 штук):" << endl;
    cin >> A;
    cout << "\nВывод элементов вектора А после ввода с клавиатуры:" << endl;
    cout << A << endl;
    //Доступ по индексу
    cout << "\nВывод элемента A[2]:" << endl;
    cout << A[2] << endl;
    //Получение длины вектора
    cout << "\nВывод длинны вектора A:" << endl;
    cout << "\nsize=" << A() << endl << endl;

    //Инициализация и вывод значений вектора
    Vector<int> B(10, 1);
    cout << "\nВывод элементов вектора B (Vector<int> B(10, 1)):" << endl;
    cout << B << endl;
    //Операция присваивания
    B = A;
    cout << "\nВывод элементов вектора B операции B = A; :" << endl;
    cout << B << endl;
    //Операция сложения с константой
    B = A + 10;
    cout << "\nВывод элементов вектора B операции B = A + 10; :" << endl;
    cout << B << endl << endl;

    Vector<float> C(10, 1.6);
    cout << "\nВывод элементов вектора С (Vector<float> С(10, 1.6)):" << endl;
    cout << C << endl;

    C = C + 2.5;
    cout << "\nВывод элементов вектора С  после операции C = C + 2.5; :" << endl;
    cout << C << endl;

    C = C * 2;
    cout << "\nВывод элементов вектора С  после операции C = C * 2; :" << endl;
    cout << C << endl;

    Vector<double> D(10, 3.7);
    cout << "\nВывод элементов вектора D (Vector<double> D(10, 3.7)):" << endl;
    cout << D << endl;

    D = D + 3.5;
    cout << "\nВывод элементов вектора D  после операции D = D + 3.5; :" << endl;
    cout << D << endl;

    D = D * 5;
    cout << "\nВывод элементов вектора D  после операции D = D * 5; :" << endl;
    cout << D << endl;

    //ДЕМОСТРАЦИЯ С ПОЛЬЗОВАТЕЛЬСКИМ ТИПОМ
    cout << "ДЕМОСТРАЦИЯ РАБОТЫ С ПОЛЬЗОВАТЕЛЬСКИМ ТИПОМ\n\n";
    
    Time t;
    cout << "\nВедите время t; :" << endl;
    cin >> t;
    cout << "\nВывод времени t:" << endl;
    cout << t << endl << endl;;

    Time t2;
    cout << "\nВведите время t2:" << endl;
    cin >> t2;
    cout << "\nВывод времени t2:" << endl;
    cout << t2 << endl << endl;;

    Time st;
    st = t + t2;
    cout << "\nВывод времени st, где st = t + t2; :" << endl;
    cout << st << endl << endl;

    Time t3;
    cout << "\nВедите время t3; :" << endl;
    cin >> t3;
    cout << "\nВывод времени t3:" << endl;
    cout << t3 << endl << endl;

    Vector<Time>VT(5, t3);
    cout << "\nВедите время в вектор VT (VT(5, t3)) (5 штук):" << endl;
    cin >> VT;
    cout << "\nВывод вектора VT со временем после ввода с клавиатуры:" << endl;
    cout << VT;
    cout << "\nВывод времени VT[2]:" << endl;
    cout << VT[2] << endl;
    cout << "\nДлинна вектора VT = " << VT() << endl << endl;

    Vector <Time>VT2(10, t3);
    cout << "\nВывод вектора VT2 со временем (VT2(10, t3)):" << endl;
    cout << VT2 << endl;
    VT2=VT;
    cout << "\nВывод вектора VT2 после операции VT2=VT; :" << endl;
    cout << VT2 << endl;
    VT2 = VT + t3;
    cout << "\nВывод вектора VT2 после операции VT2=VT + t3; :" << endl;
    cout << VT2 << endl << endl;;

    Vector <Time>VT3(VT2);
    cout << "\nВывод вектора VT3 со временем (VT3(VT2)):" << endl;
    cout << VT3 << endl;
    VT3 = VT3 * t3;
    cout << "\nВывод вектора VT3 после операции VT3 = VT3 * t3; :" << endl;
    cout << VT3 << endl << endl; //3386510

    cout << endl << "Нажмите [Enter] для завершения программы!";
    cin.ignore();
    cin.get();

    return 0;
}
