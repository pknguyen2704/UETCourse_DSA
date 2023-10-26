#include <iostream>
#include <vector>

using namespace std;
struct Node {
    int data;
    vector<int> children;
};


bool isBalancedBinaryTree(vector<Node>& tree, int node, int& maxDepth) {
    if (tree[node].children.empty()) {
        return true; 
    }

    int firstMaxDepth = -1;
    int secondMaxDepth = -1;

    for (int child : tree[node].children) {
        int childDepth;
        if (!isBalancedBinaryTree(tree, child, childDepth)) {
            return false;
        }

        if (childDepth > firstMaxDepth) {
            secondMaxDepth = firstMaxDepth;
            firstMaxDepth = childDepth;
        } else if (childDepth > secondMaxDepth) {
            secondMaxDepth = childDepth;
        }
    }

    if (firstMaxDepth - secondMaxDepth > 1) {
        return false;
    }

    maxDepth = firstMaxDepth + 1;
    return true;
}

int main() {
    int n;
    cin >> n;

    vector<Node> tree(n);

    for (int i = 0; i < n-1; i++) {
        int parent, child;
        cin >> parent >> child;
        tree[parent].children.push_back(child);
    }

    int maxDepth = 0;
    if (isBalancedBinaryTree(tree, 0, maxDepth)) {
        cout << "yes" << endl;
    } else {
        cout << "no" << endl;
    }

    return 0;
}
