#include <iostream>
#include <vector>
#include <string>

using namespace std;

// 1. Definojme strukturen Student
struct Student {
    int id;
    string emri;
    string mbiemri;
    int mosha;
    double notaMesatare;
};

// 2. Krijojme nje vektor per ruajtjen e studenteve
vector<Student> studentList;

// 3. Funksioni per te shtuar studente
void addStudent() {
    Student newStudent;

    cout << "Enter ID: ";
    cin >> newStudent.id;

    cout << "Enter Emri: ";
    cin >> newStudent.emri;

    cout << "Enter Mbiemri: ";
    cin >> newStudent.mbiemri;

    cout << "Enter Mosha: ";
    cin >> newStudent.mosha;

    cout << "Enter Nota Mesatare: ";
    cin >> newStudent.notaMesatare;

    // Shtojme studentin e ri ne vektor
    studentList.push_back(newStudent);

    cout << "Studenti u shtua me sukses!\n";
}

int main() {
    int choice;

    while (true) {
        cout << "\n1. Shto Student\n";
        cout << "2. Paraqit Studentet\n";
        cout << "3. Dal\n";
        cout << "Zgjedhja juaj: ";
        cin >> choice;
      
      if (choice == 1) {
            addStudent();
        } else if (choice == 2) {

          // Paraqesim studenet
          cout << "Lista e studenteve:\n";
            for (const auto& student : studentList) {
                cout << "ID: " << student.id << ", Emri: " << student.emri << ", Mbiemri: " << student.mbiemri
                     << ", Mosha: " << student.mosha << ", Nota Mesatare: " << student.notaMesatare << endl;
            }
        } else if (choice == 3) {
            break;
        } else {
            cout << "Zgjedhje e pavlefshme!\n";
        }
    }

    return 0;
}
