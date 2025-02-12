#include <iostream>   // Për hyrje dhe dalje në konzolë
#include <vector>     // Përdorimi i vektorit për ruajtjen e studentëve
#include "student.h"  // Përfshirja e header-it që përmban strukturën e studentit

using namespace std;

// Funksioni për të shfaqur të gjithë studentët në listë
void displayStudents(const vector<Student>& students) {
    // Kontrollo nëse lista është bosh
    if (students.empty()) {
        cout << "Nuk ka studente ne liste." << endl;
        return;   // Dil nga funksioni nëse nuk ka studentë
    }

    // Printo listën e studentëve në një format të rregullt
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

// Funksioni për të kërkuar një student sipas ID-së ose emrit
void searchStudent(const vector<Student>& students, const string& query) {
    cout << "Duke kërkuar studentin...\n";   // Kjo është një mesazh që tregon përdoruesit se kërkimi është duke u kryer
    bool found = false;   // Variabël për të treguar nëse studenti u gjet

     // Kalon nëpër listën e studentëve dhe kontrollon për përputhje
    for (const auto& student : students) {
        if (to_string(student.id) == query || student.name == query) {
            cout << "Student i gjetur:\n";
            cout << "ID: " << student.id 
                 << " | Emri: " << student.name 
                 << " | Mbiemri: " << student.surname 
                 << " | Mosha: " << student.age 
                 << " | Nota Mesatare: " << student.gpa << endl;
            found = true;   // Shëno që studenti u gjet
        }
    }

     // Nëse studenti nuk u gjet, shfaq mesazhin përkatës
    if (!found) {
        cout << "Studenti nuk u gjet!\n";
    }
}
