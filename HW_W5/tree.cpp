#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Node {
    public:
        int value;
        Node* right;
        Node* left;

        Node();

        Node(int v) {
            left = nullptr;
            right = nullptr;
            value = v;
        }
};

class Tree {
    public:
        Node* root;
        Tree(int N, const vector<pair<int,int>>& edges) {
            vector<Node*> nodes(N);
            nodes[0] = new Node(1);
            root = nodes[0];

            for(int i = 0; i < N; i++) {
                for(int j = 0; j < edges[i].second; j++) {
                    Node* child = new Node(edges[i].first);
                    nodes[edges[i].first -1] = child;
                    if(j == 0) {
                        nodes[i]->left = child;
                    } else {
                        nodes[i]->right = child;
                    }
                }
            }
        }

        int calculateHeight(Node* root) {
            if (root == nullptr) {
                return 0;
            }
            int leftHeight = calculateHeight(root->left);
            int rightHeight = calculateHeight(root->right);

            return max(leftHeight, rightHeight) + 1;
        }

        void preorderTraversal(Node* root) {
            if(root == nullptr) {
                return;
            }

            cout << root->value << " ";

            preorderTraversal(root->left);
            preorderTraversal(root->right);
        }

        void postorderTraversal(Node* root) {
            if(root == nullptr) {
                return;
            }

            postorderTraversal(root->left);
            postorderTraversal(root->right);

            cout << root->value << " ";
        }

        bool isBinary(Node* root, vector<int>& result) {
            stack <Node*> s;
            Node* curr = root;
            while(curr != nullptr || !s.empty()) {
                while(curr != nullptr) {
                    s.push(curr);
                    curr = curr->left;
                }
                curr = s.top();
                s.pop();
                result.push_back(curr->value);
                curr = curr->right;
            }
            for(int i = 1; i < result.size(); i++) {
                if(result[i] <= result[i-1]) {
                    return false;
                }
            }
            return true;
        }
};

int main() {
    int m, n;
    cin >> m >> n;

    vector<pair<int,int>> edges(m);
    for(int i = 0; i < n; i++) {
        int u, v;
        cin >> u >> v;
        edges[u-1].first++;
        edges[v-1].second++; 
    }

    Tree tree(m, edges);
    cout << tree.calculateHeight(tree.root) << endl;

    cout << "Preorder Traversal: " << endl;
    tree.preorderTraversal(tree.root);
    cout << "Postorder Traversal" << endl;
    tree.postorderTraversal(tree.root);

    vector <int> inorderResult;
    bool isBinary = tree.isBinary(tree.root, inorderResult);
    if(isBinary) {
        cout << "Inorder Traversal: ";
        for(int value : inorderResult) {
            cout << value << " ";
        }
        cout << endl;
    } else {
        cout << "NOT BINARY TREE" << endl;
    }
    return 0;
}