#include<iostream>
#include<vector>
using namespace std;

template<typename ID>
class Student {

    public:
        ID id;
        string name;

    Student(ID iD, string n){
        id = iD;
        name = n;
    }

    void display(){
        cout << "ID Num. :- " << id <<  ", Name :- " << name << endl;
    }

};

template<typename ID>
class StudentDetails{

    vector<Student <ID>> students;
    
    public:
        void addStudents(){
            ID id;
            string name;

            cout << "Enter ID number :- ";
            cin >> id;

            cout << "Enter student Name :- ";
            cin >> name;

            Student<ID> s(id,name);
            students.push_back(s);

        }


};

int main(){


    return 0;
}