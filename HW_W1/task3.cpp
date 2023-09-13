// Find the greatest common divisor of two integer number

#include <iostream>

using namespace std;

// Euclid Solution
int Gcd(int a, int b)
{
    if(a < 0) a = abs(a);
    if(b < 0) b = abs(b);
    // a < b
    int temp;
    if(a < b)
    {
        temp = a;
        a = b;
        b = temp;
    }
    while(b != 0)
    {
        temp = a%b;
        a = b;
        b = temp;
    }
    return a;
}
int main()
{
    int m, n;
    cin >> m >> n;
    cout << Gcd(m, n);

    return 0;
}