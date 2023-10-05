#include <iostream>
#include <vector>
#include <list>

using namespace std;
class HashTable {
    public:
        HashTable() {
            table.resize(size, make_pair(-1, 0));
            isOccupied.resize(size, false);
        }
        void insert(int key, int value) {
            int index = hashFunction(key);

            if (!isOccupied[index]) {
                table[index] = make_pair(key, value);
                isOccupied[index] = true;
            } else {
                index = linearProbe(index);
                table[index] = make_pair(key, value);
                isOccupied[index] = true;
            }
        }
        void printTable() {
            for (int i = 0; i < size; i++) {
                if (isOccupied[i]) {
                    std::cout << "Bucket " << i << ": (" << table[i].first << ", " << table[i].second << ")" << std::endl;
                } else {
                    std::cout << "Bucket " << i << ": Empty" << std::endl;
                }
            }
        }
    private:
        int size = 17;
        vector<pair<int, int>> table;
        vector<bool> isOccupied;

        int hashFunction(int key) {
            return (key + 3)%size;
        }

        int linearProbe(int index) {
            int i = 1;
            while (isOccupied[index]) {
                index = (index + i) % size;
                ++i;
            }
            return index;
        }
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