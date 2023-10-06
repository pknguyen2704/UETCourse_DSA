#include <iostream>
#include <map>

using namespace std;

struct Student {
    string name;
    string className;
};

map <int, Student> students;

void insert(int ID, const string& name, const string& className) {
    if(students.find(ID) != students.end()) {
        cout << "Error: This ID is exist" << endl;
    } else {
        Student newStudent;
        newStudent.name = name;
        newStudent.className = className;
        students[ID] = newStudent;
    }
}
void Delete(int ID) {
    if(students.find(ID) != students.end()) {
        students.erase(ID);
    }
    else {
        cout << "Student with this ID is not found" << endl;
    }
}
void Infor(int ID) {
    if(students.find(ID) != students.end()) {
        cout << students[ID].name << "," << students[ID].className << endl;
    } else {
        cout << "NA,NA" << endl;
    }
}
int main() {
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
            insert(id, name, studentClass);
        }
        else if(s.substr(0,5) == "Infor") {
            int id = 0;
            for(int i = 6; i < s.size()-1; i++) {
                if(s[i] >= '0' && s[i] <= '9') {
                    id = id*10 + (int)(s[i] - '0');
                }
            }
            Infor(id);
        }
        else if(s.substr(0, 6) == "Delete") {
            int id = 0;
            for(int i = 7; i < s.size()-1; i++) {
                if(s[i] >= '0' && s[i] <= '9') {
                    id = id*10 + (int)(s[i] - '0');
                }
            }
            Delete(id);
        }
        else {
            break;
        }
    }
    return 0;
}
