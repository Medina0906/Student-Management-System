#include <iostream>
#include <vector>
#include "student.h"
#include "add_student.cpp"
#include "display_search.cpp"
#include "update_delete.cpp"
#include "file_operations.cpp"

using namespace std;

int main() {
    // Lista kryesore e studentëve
    vector<Student> students;

    // Ngarkimi i të dhënave nga file në fillim
    loadFromFile(students);

    int choice;
    do {
        cout << "\n--- Sistemi i Menaxhimit të Studentëve ---\n";
        cout << "1. Shto student\n";
        cout << "2. Shfaq të gjithë studentët\n";
        cout << "3. Kërko student\n";
        cout << "4. Përditëso student\n";
        cout << "5. Fshi student\n";
        cout << "6. Ruaj të dhënat\n";
        cout << "7. Dalje\n";
        cout << "Zgjedhja juaj: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addStudent(students);
                break;
            case 2:
                displayStudents(students);
                break;
            case 3:
                searchStudent(students);
                break;
            case 4:
                updateStudent(students);
                break;
            case 5:
                deleteStudent(students);
                break;
            case 6:
                saveToFile(students);
                cout << "Të dhënat u ruajtën me sukses!\n";
                break;
            case 7:
                cout << "Duke dalë nga programi...\n";
                break;
            default:
                cout << "Zgjedhje e pavlefshme! Ju lutem provoni përsëri.\n";
        }
    } while (choice != 7);

    return 0;
}
