#include <iostream>
#include <vector>
using namespace std;
bool check[1000] = {0};

void DFS(int u, vector<int> arr[]) {
    check[u] = 1;
    for(int v = 0; v < arr[u].size(); v++) {
        if(check[arr[u][v]] == 0) {
            DFS(arr[u][v], arr);
        }
    }
}
void show(int n, vector<int> arr[]) {
    int res = 0;
    for(int i = 1; i <= n; i++) {
        if(check[i] == 0) {
            res++;
            DFS(i, arr);
        }
    }
    cout << res;
}
int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a[100];
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }

    show(n, a);
    return 0;
}