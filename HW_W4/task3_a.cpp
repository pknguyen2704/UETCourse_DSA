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
        int size = 17;
        int hashFunction(int key) {
            return (key + 3)%size;
        }
        vector<list<Node>> table;
};
int main() {
    HashTable hashTable;

    int keys[] = {1,3,18,8,23,35,11,36,20,16};
    int value[] = {1,2,3,4,5,6,7,8,9,10};
    for(int i = 0; i < 10; i++) {
        hashTable.insert(keys[i], value[i]);
    }

    hashTable.printTable();
    return 0;
}