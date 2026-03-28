///////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXXV
// Versuch 02.2.1: Rekursive Fibonacci
//
// Datei:  RekursiveFibonacci.cpp
// Inhalt: Hauptprogramm
///////////////////////////////////////////////////////////////////////////////

#include <iostream>
using namespace std;

// Rekursive Fibonacci-Funktion
int fib(int n)
{
    if (n == 0)
    {
        return 0;           // Basisfall f(0) = 0
    }
    else if (n == 1)
    {
        return 1;           // Basisfall f(1) = 1
    }
    else
    {
        return fib(n - 1) + fib(n - 2);  // Rekursionsschritt
    }
}

int main()
{
    // Ausgabe der Fibonacci-Zahlen von 0 bis 25
    cout << "Fibonacci-Zahlen von 0 bis 25:" << endl;
    for (int i = 0; i <= 25; i++)
    {
        cout << "f(" << i << ") = " << fib(i) << endl;
    }
    return 0;
}
