#include <iostream>
#include <vector>

using namespace std;

struct Node {
    int value;
    vector<int> child;
};

bool isBinaryTree(vector<Node>& graph, int curr, int parent) {
    int childCount = 0;
    for(int child : graph[curr].child) {
        if(child == parent) {
            continue;
        }
        childCount++;
        if(!isBinaryTree(graph, child, curr)) {
            return false;
        }
    }
    return (childCount <= 2);
}
int main() {
    int n;
    cin >> n;
    vector<Node> edges(n);
    for(int i = 0; i < n-1; i++) {
        int x, y;
        cin >> x>> y;
        edges[x].child.push_back(y);
        edges[y].child.push_back(x);
    }
    
    if(isBinaryTree(edges, 0, -1)) {
        cout << "yes" << endl;
    } else {
        cout << "no" << endl;
    }
    return 0;
}