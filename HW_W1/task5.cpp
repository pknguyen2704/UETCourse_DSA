// Given 5 different numbers, your task is to write a C++ program to calculate the sum of the greatest number and the smallest number.

#include <iostream>

using namespace std;

int main()
{
    int numberQuantity = 5;
    int num1;
    
    cin >> num1;
    
    int minNum = num1;
    int maxNum = num1;

    for(int i = 1; i < numberQuantity; i++)
    {
        int x;
        cin >> x;
        if(x < minNum) minNum = x;
        if(x > maxNum) maxNum = x;
    }
    int result = minNum + maxNum;
    cout << result;

    return 0;
}