#include <iostream>
#include <vector>
#include <string>
#include "student.h" // Përfshirja e header-it që përmban strukturën e studentit

using namespace std;

// Funksioni për përditësimin e të dhënave të studentëve
// Marrja e ID dhe përditësimi i emrit, moshës dhe notës
void updateStudent(vector<Student>& students) {
    int id;
    cout << "\nVendos ID e studentit që dëshiron të përditësosh: ";
    cin >> id;

    bool found = false;
    for (auto& student : students) {
        if (student.id == id) {
            found = true;
            cout << "Student i gjetur: " << student.name << "\n";
            cout << "Vendos emrin e ri: ";
            cin.ignore();
            getline(cin, student.name);

            cout << "Vendos moshën e re: ";
            cin >> student.age;

            cout << "Vendos notën e re: ";
            cin >> student.grade;

            cout << "\nTë dhënat janë përditësuar me sukses!\n";
            break;
        }
    }
    
    if (!found) {
        cout << "Studenti me ID " << id << " nuk u gjet.\n";
    }
}

// Funksioni për fshirjen e një studenti nga lista sipas ID-së
void deleteStudent(vector<Student>& students) {
    int id;
    cout << "\nVendos ID e studentit që dëshiron të fshish: ";
    cin >> id;

    auto it = students.begin();
    bool found = false;

    while (it != students.end()) {
        if (it->id == id) {
            cout << "\nStudenti " << it->name << " është fshirë me sukses!\n";
            it = students.erase(it);
            found = true;
            break;
        } else {
            ++it;
        }
    }

    if (!found) {
        cout << "Studenti me ID " << id << " nuk u gjet.\n";
    }
}

// Funksioni për të shfaqur listën e studentëve ekzistues
// Shfaq të dhënat si ID, emri, mosha dhe nota
void displayStudents(const vector<Student>& students) {
    cout << "\nLista e Studentëve:\n";
    for (const auto& student : students) {
        cout << "ID: " << student.id << ", Emri: " << student.name 
             << ", Mosha: " << student.age << ", Nota: " << student.grade << "\n";
    }
}

// Funksioni kryesor për testimin e funksioneve (update, delete, display)
int main() {
    // Lista fillestare e studentëve
    vector<Student> students = {
        {1, "Arta Hoxha", 20, 9.5},
        {2, "Blerim Berisha", 21, 8.7},
        {3, "Dafina Mehmeti", 19, 9.0}
    };

    int choice;
    do {
        // Menu për zgjedhjen e funksioneve
        cout << "\n1. Shfaq studentët\n2. Përditëso student\n3. Fshi student\n4. Dalje\nZgjedhja juaj: ";
        cin >> choice;

        switch (choice) {
            case 1:
                displayStudents(students);
                break;
            case 2:
                updateStudent(students);
                break;
            case 3:
                deleteStudent(students);
                break;
            case 4:
                cout << "Duke dalë nga programi...\n";
                break;
            default:
                cout << "Zgjedhje e pavlefshme! Ju lutem provoni përsëri.\n";
        }
    } while (choice != 4);

    return 0;
}
