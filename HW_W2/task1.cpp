// Given a list A of n integer numbers 
// your task is to write a program to count the number of pairs (i,j) that A[i]=A[j].

#include <iostream>

using namespace std;

void init(int* a, int &n)
{
    for(int i = 0; i < n; i++)
        cin >> a[i];
}

int countPairNumber(int* a, int &n)
{
    int count = 0;
    for(int i = 0; i < n-1; i++)
    {
        for(int j = i+1; j < n; j++)
        {
            if(a[i] == a[j])
            {
                count++;
            }
        }
    }
    return count;
}


int main()
{
    int n;

    cin >> n;
    
    int *a = new int[n];

    init(a, n);
    cout << countPairNumber(a, n);
    
    return 0;
}