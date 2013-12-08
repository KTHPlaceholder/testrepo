#include <iostream>
#include <stdlib.h>
#include <string>
#include "fibonacci.cpp"

int main()
{
        using namespace std;

        cout << "This is a boring program calculating the nth Fibonacci number.\nPlease enter which Fibonacci you want:";
        int n;
        cin >> n;
        string result = fibonacci(n);
        cout << result;

        return 0;
}