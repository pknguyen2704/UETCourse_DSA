#include <iostream>
#include <set>
#include <string>

using namespace std;

struct Student {
    int id;
    string name;
    string studentClass;

    Student(const int i, const string n, const string sc) {
        id = i;
        name = n;
        studentClass = sc;
    }

    bool operator<(const Student& other) const {
        return id < other.id;
    }
};

int main() {
    set <Student> studentSet;
    string s;
    while(cin >> s) {
        if(s.substr(0, 6) == "Insert") {
            int tmp = 7;
            int id = 0;
            while(s[tmp] != ',') {
                id = id*10 + (int)(s[tmp] - '0');
                tmp++;
            }
            //cout << id;
            tmp++;
            string name = "";
            while(s[tmp] != ',') {
                name += s[tmp];
                tmp++;
            }
            //cout << name;
            tmp++;
            string studentClass = "";
            while(s[tmp] != ')') {
                studentClass += s[tmp];
                tmp++;
            }
            //cout << id << " " << name << " " << studentClass;
            studentSet.insert(Student(id, name, studentClass));
        }
        else if(s.substr(0,5) == "Infor") {
            int id = 0;
            for(int i = 6; i < s.size()-1; i++) {
                if(s[i] >= '0' && s[i] <= '9') {
                    id = id*10 + (int)(s[i] - '0');
                }
            }
            auto it = studentSet.lower_bound(Student(id, "", ""));
            if(it != studentSet.end() && it->id == id) {
                cout << it->name << "," << it->studentClass << endl;
            } else {
                cout << "NA, NA" << endl;
            }
        }
        else if(s.substr(0, 6) == "Delete") {
            int id = 0;
            for(int i = 7; i < s.size()-1; i++) {
                if(s[i] >= '0' && s[i] <= '9') {
                    id = id*10 + (int)(s[i] - '0');
                }
            }
            auto it = studentSet.begin();
            while(it != studentSet.end()) {
                if(it->id == id) {
                    it = studentSet.erase(it);
                } else {
                    it++;
                }
            }
        }
        else {
            break;
        }
    }
    return 0;
}