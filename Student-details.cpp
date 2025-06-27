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

        void displayAllStudents(){
            if(students.empty()){
                cout << "No students to details." << endl;
                return;
            }
            for(int i=0;i<students.size();i++){
                students[i].display();
            }
        }

        void removeStudenteByID(){

            ID id;

            cout << "Enter ID to remove :- ";
            cin >> id;

            for(int i=0;i<students.size();i++){
                if(students[i].id == id){
                    students.erase(students.begin() + i);
                    cout << "Student with ID " << id << " removed." << endl;
                    return;
                }
            }
            cout << "Student with ID " << id << " not found." << endl;
        }

        void searchStudentByID(){

            ID id;

            cout << "Enter ID to search :- ";
            cin >> id;

            for(int i=0;i<students.size();i++){
                if(students[i].id == id){
                    cout << "Student found :- " << endl;
                    students[i].display();
                    return;
                }
            }
            cout << "Student with ID " << id << " not found." << endl;
        }

        void menu(){
            int choice;

            do{
                cout << endl << "-------- Student Menagement Menu --------" << endl;
                cout << "Press 1. Add student." << endl;
                cout << "Press 2. Display All Students." << endl;
                cout << "Press 3. Remove Student by ID." << endl;
                cout << "Press 4. Search Student by ID." << endl;
                cout << "Press 0. Exit" << endl;

                cout << "Enter your choice :- ";
                cin >> choice;

                switch(choice){
                    case 1:
                        addStudents();
                        break;
                    case 2:
                        displayAllStudents();
                        break;
                    case 3:
                        removeStudenteByID();
                        break;
                    case 4:
                        searchStudentByID();
                        break;
                    case 0:
                        cout << "Exiting....." << endl;
                        break;
                    default:
                        cout << "Invalid choice!" <<endl;
                        break;
                }

            }while(choice != 0);
        }


};

int main(){

    StudentDetails<int> sd;
    sd.menu();

    return 0;
}