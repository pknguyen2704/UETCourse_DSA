#include <iostream>
#include <vector>
#include <list>

using namespace std;
struct Node{
    int key;
    int value;
};

class HashTable {
    public:
        HashTable() {
            table.resize(size);
        }
        void insert(int key, int value) {
            int index = hashFunction(key);
            table[index].push_back({key, value});
        }
        int get(int key) {
            int index = hashFunction(key);
            for(const Node& n : table[index]) {
                if(n.key == key) {
                    return n.value;
                }
            }
            return -1;
        }
        void printTable() {
            for(int i = 0; i < size; i++) {
                cout << "Bucket " << i << ": ";
                for(const Node& n : table[i]) {
                    cout << "(" << n.key << ", " << n.value << ")";
                }
                cout << endl;
            }
        }
    private:
        int size = 11;
        int hashFunction(int key) {
            return (2*key + 5)%size;
        }
        vector<list<Node>> table;
};
int main() {
    HashTable hashTable;

    int keys[] = {12,44,13,88,23,94,11,39,20,16,5};
    int values[] = {1,2,3,4,5,6,7,8,9,10,11};

    for(int i = 0; i < 11; i++) {
        hashTable.insert(keys[i], values[i]);
    }

    hashTable.printTable();
    return 0;
}