#include <iostream>
#include <vector>
#include "student.h"

using namespace std;

void displayStudents(const vector<Student>& students) {
    if (students.empty()) {
        cout << "Nuk ka studente ne liste." << endl;
        return;
    }

    cout << "Lista e studenteve:\n";
    cout << "------------------------------------\n";
    for (const auto& student : students) {
        cout << "ID: " << student.id 
             << " | Emri: " << student.name 
             << " | Mbiemri: " << student.surname 
             << " | Mosha: " << student.age 
             << " | Nota Mesatare: " << student.gpa << endl;
    }
    cout << "------------------------------------\n";
}

void searchStudent(const vector<Student>& students, const string& query) {
    bool found = false;

    for (const auto& student : students) {
        if (to_string(student.id) == query || student.name == query) {
            cout << "Student i gjetur:\n";
            cout << "ID: " << student.id 
                 << " | Emri: " << student.name 
                 << " | Mbiemri: " << student.surname 
                 << " | Mosha: " << student.age 
                 << " | Nota Mesatare: " << student.gpa << endl;
            found = true;
        }
    }

    if (!found) {
        cout << "Studenti nuk u gjet!\n";
    }
}
