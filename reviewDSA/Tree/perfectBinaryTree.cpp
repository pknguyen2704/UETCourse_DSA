#include <iostream>
#include <vector>

using namespace std;
struct Node {
    int data;
    vector<int> children;
};

bool isFullBinaryTree(vector<Node>& tree, int node) {
    if (tree[node].children.size() == 0) {
        return true;
    }

    if (tree[node].children.size() != 2) {
        return false;
    }

    return isFullBinaryTree(tree, tree[node].children[0]) && isFullBinaryTree(tree, tree[node].children[1]);
}

int main() {
    int n;
    cin >> n;

    vector<Node> tree(n);

    for (int i = 1; i < n; i++) {
        int parent, child;
        cin >> parent >> child;
        tree[parent].children.push_back(child);
    }

    if (isFullBinaryTree(tree, 0)) {
        cout << "yes" << endl;
    } else {
        cout << "no" << endl;
    }
    return 0;
}
