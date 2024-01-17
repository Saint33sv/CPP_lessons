#include <iostream>


using namespace std;

int main(){
    // Здесь вычисляются числа фибоначи
    double f1 = 0.0;
    double f2 = 1.0;
    double f3 = f1 + f2;
    double f4 = f2 + f3;
    double f5 = f3 + f4;

    // Здесь осуществляется вывод найденных чисел в консоль 
    cout << f1 << endl;
    cout << f2 << endl;
    cout << f3 << endl;
    cout << f4 << endl;
    cout << f5 << endl;
}