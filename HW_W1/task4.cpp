// write to the screen the list of numbers after being increasingly sorted.
#include <iostream>
#include <vector>

using namespace std;

void Init(vector<int> &v, int n)
{
    for(int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        v.push_back(x);
    }
}
void SortIncreasingly(vector<int> &v, int n)
{
    for(int i = 0; i < n-1; i++)
    {
        for(int j = i+1; j < n; j++)
        {
            if(v[i] > v[j])
            {
                int tmp = v[i];
                v[i] = v[j];
                v[j] = tmp;
            }
        }
    }
}
void Print(vector<int> &v, int n)
{
    for(int i = 0; i < n; i++)
    {
        cout << v[i] << " ";
    }
}
int main()
{
    int n;
    cin >> n;
    vector <int> v;
    Init(v, n);

    SortIncreasingly(v, n);

    Print(v, n);

    return 0;
}