#include <iostream>
#include <vector>
#include <string>

using namespace std;

class HashTable {
    public:
        HashTable() {
            table.resize(tableSize, make_pair(-1, 0));
        }

        void insert(int key, int value) {
            int index = hash(key);

            if (table[index].first == -1) {
                table[index] = make_pair(key, value);
            } else {
                index = linearProbe(index);
                table[index] = std::make_pair(key, value);
            }
        }

        int get(int key) {
            int index = hash(key);
            for (int i = 0; i < tableSize; ++i) {
                if (table[index].first == key) {
                    return table[index].second;
                }
                index = (index + 1) % tableSize;
            }
            return 0;
        }

        void printTable() {
            for (int i = 0; i < tableSize; ++i) {
                if (table[i].first != -1) {
                    std::cout << "Bucket " << i << ": (" << table[i].first << ", " << table[i].second << ")" << std::endl;
                } else {
                    std::cout << "Bucket " << i << ": Empty" << std::endl;
                }
            }
        }
    private:
        int tableSize = 11;
        vector<pair<int, int>> table;

        int hash(int key) {
            return (2 * key + 5) % tableSize;
        }

        int linearProbe(int index) {
            int i = 1;
            while (table[index].first != -1) {
                index = (index + i) % tableSize;
                i++;
            }
            return index;
        }
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
