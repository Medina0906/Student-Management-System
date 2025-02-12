#include <iostream>   // Për hyrje dhe dalje në konzolë
#include <vector>  // Përdorimi i vektorit për ruajtjen e studentëve
#include <algorithm>
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

string toLowerCase(const string& str) {
    string lowerStr = str;
    transform(lowerStr.begin(), lowerStr.end(), lowerStr.begin(), ::tolower);
    return lowerStr;
}

// Funksioni për të kërkuar një student sipas ID-së ose emrit
void searchStudent(const vector<Student>& students, const string& query) {
   if (query.empty()) {   
    cout << "Ju lutem shkruani një ID ose një emër për të kërkuar!\n";
        return;
    } 

    string lowerQuery = toLowerCase(query); // Konverton inputin në shkronja të vogla
    bool found = false;

     // Kalon nëpër listën e studentëve dhe kontrollon për përputhje
    for (const auto& student : students) {
         string lowerName = toLowerCase(student.name);
        string lowerSurname = toLowerCase(student.surname);
        string lowerID = to_string(student.id);

        // Kontrollon nëse query përputhet me ID ose përmban pjesë të emrit/mbiemrit
        if (lowerID == lowerQuery || 
            lowerName.find(lowerQuery) != string::npos || 
            lowerSurname.find(lowerQuery) != string::npos) {
            
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
