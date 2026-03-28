//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXXV
// Versuch 02 – Iterative vs. Rekursive Fibonacci
//
// Datei:  main.cpp
//////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <ctime>

using namespace std;

// (A) Iterative Version
int fibonacci(int n)
{
    if (n <= 1)
        return n;          // f(0)=0, f(1)=1
    int prev = 0;          // f(0)
    int curr = 1;          // f(1)
    for (int i = 2; i <= n; ++i)
    {
        int next = prev + curr;
        prev = curr;
        curr = next;
    }
    return curr;
}


int main()
{
    // Schritt 1: Fibonacci-Zahlen 0 bis 12 (iterativ)
    cout << "Fibonacci-Zahlen von 0 bis 12 (iterativ):" << endl;
    for (int i = 0; i <= 50; ++i)
    {
        cout << "f(" << i << ") = " << fibonacci(i) << endl;
    }

    return 0;
}
