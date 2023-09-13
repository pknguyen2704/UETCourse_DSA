// print to the screen the sentence in the reversed order//

#include <iostream>
#include <string.h>

using namespace std;
void Print(string &s)
{
    for(int i = s.length()-1; i >= 0; i--)
    {
        cout << s[i];
    }
}
int main()
{
    string s;
    getline(cin, s);
    Print(s);
    return 0;
}