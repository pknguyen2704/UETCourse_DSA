#include<bits/stdc++.h>
using namespace std;

int n, m;
vector <int> a[100];
bool dd[1000] = {0};
int dem = 0;

void input()
{
    cin >> n >> m;
    for(int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
}

void show()
{
    for(int i = 1; i <= n; i++)
    {
        cout <<"DINH: " << i <<": ";
        for(int v = 0; v < a[i].size(); v++)
        {
            cout << a[i][v] << " ";
        }
        cout << endl;
    }
}
int tim()
{
    for(int i = 1; i <= n; i++)
    {
        if(dd[i] == 0)
            return i;
    }
    return 0;
}

void DFS(int u)
{
    dd[u] = 1;
    for(int v = 0; v < a[u].size(); v++)
    {
        if(dd[a[u][v]] == 0)
        {
            //dd[a[u][v]] = 1;
            DFS(a[u][v]);
        }
    }
}

void solve()
{
    show();
    int i;
    do
    {
        i = tim();
        if(i != 0)
        {
            dem++;
            DFS(i);
        }
    } while (i > 0);
    cout << dem;
}

int main()
{
    //freopen("dem_so_thanh_phan_lien_thong.inp","r", stdin);
    //freopen("dem_so_thanh_phan_lien_thong.out","w",stdout);

    input();
    solve();
    return 0;
}