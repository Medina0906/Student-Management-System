#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

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

// 3. Funksioni per te paraqitur menyne kryesore
void displayMenu() {
    cout << "\n===== MENU KRYESOR =====\n";
    cout << "1. Shto Student\n";
    cout << "2. Shfaq Studentet\n";
    cout << "3. Kerko Student\n";
    cout << "4. Fshi Student\n";
    cout << "5. Dal\n";
    cout << "Zgjedhja juaj: ";
}

// 4. Funksioni per te shtuar studentin e ri
void addStudent() {
    Student newStudent;

    cout << "\n===== SHTO STUDENT =====\n";
    cout << "ID: ";
    cin >> newStudent.id;

    // Kontrollojme nese ekziston ID
    for (const auto& student : studentList) {
        if (student.id == newStudent.id) {
            cout << "Gabim: ID ekziston tashmë!\n";
            return;
        }
    }
    cout << "Emri: ";
    cin >> newStudent.emri;

    cout << "Mbiemri: ";
    cin >> newStudent.mbiemri;

    cout << "Mosha: ";
    cin >> newStudent.mosha;

    cout << "Nota Mesatare: ";
    cin >> newStudent.notaMesatare;

    // Shtojme studentin e ri ne vektor
    studentList.push_back(newStudent);

    cout << "Studenti u shtua me sukses!\n";
}

// 5. Fuksioni per te paraqitur te gjithe studentet
void displayStudents() {
    if (studentList.empty()) {
        cout << "\nNuk ka studentë të regjistruar!\n";
        return;
    }

    cout << "\n===== LISTA E STUDENTËVE =====\n";
    cout << setw(5) << "ID" << setw(15) << "Emri" << setw(15) << "Mbiemri" << setw(10) << "Mosha" << setw(15) << "Nota Mesatare\n";
    cout << "-------------------------------------------------\n";

    for (const auto& student : studentList) {
        cout << setw(5) << student.id << setw(15) << student.emri << setw(15) << student.mbiemri
             << setw(10) << student.mosha << setw(15) << student.notaMesatare << endl;
    }
}

// 6. Funksioni per te kerkuar nje student sipas ID
void searchStudent() {
    int id;
    cout << "\n===== KERKO STUDENT =====\n";
    cout << "Shkruaj ID-në e studentit: ";
    cin >> id;

    for (const auto& student : studentList) {
        if (student.id == id) {
            cout << "\nStudenti u gjet:\n";
            cout << "ID: " << student.id << ", Emri: " << student.emri << ", Mbiemri: " << student.mbiemri
                 << ", Mosha: " << student.mosha << ", Nota Mesatare: " << student.notaMesatare << endl;
            return;
        }
    }

    cout << "Studenti me ID " << id << " nuk u gjet.\n";
}

// 7. Funksioni per te fshire nje student sipas ID
void deleteStudent() {
    int id;
    cout << "\n===== FSHI STUDENT =====\n";
    cout << "Shkruaj ID-në e studentit për të fshirë: ";
    cin >> id;

    for (auto it = studentList.begin(); it != studentList.end(); ++it) {
        if (it->id == id) {
            studentList.erase(it);
            cout << "Studenti u fshi me sukses!\n";
            return;
        }
    }

    cout << "Studenti me ID " << id << " nuk u gjet.\n";
}

// 8. Funksioni kryesor
int main() {
    int choice;

    while (true) {
        displayMenu();
        cin >> choice;
        switch (choice) {
            case 1:
                addStudent();
                break;
            case 2:
                displayStudents();
                break;
            case 3:
                searchStudent();
                break;
            case 4:
                deleteStudent();
                break;
            case 5:
                cout << "Duke dalë nga programi...\n";
                return 0;
            default:
                cout << "Zgjedhje e pavlefshme! Ju lutem provoni përsëri.\n";
        }
    }

    return 0;
}
