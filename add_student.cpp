#include <iostream>
#include <vector>
#include <string>
#include <iomanip> // Për formatimin e daljes

using namespace std;

// 1. Definimi i strukturës Student
struct Student {
    int id;             // ID unike e studentit
    string emri;        // Emri i studentit
    string mbiemri;     // Mbiemri i studentit
    int mosha;          // Mosha e studentit
    double notaMesatare; // Nota mesatare e studentit
};

// 2. Vektori global për të ruajtur studentët
vector<Student> studentList;

// 3. Funksioni për të shfaqur menynë kryesore
void displayMenu() {
    cout << "\n===== MENU KRYESOR =====\n";
    cout << "1. Shto Student\n";
    cout << "2. Shfaq Studentet\n";
    cout << "3. Kerko Student\n";
    cout << "4. Fshi Student\n";
    cout << "5. Dal\n";
    cout << "Zgjedhja juaj: ";
}

// 4. Funksioni për të shtuar një student të ri
void addStudent() {
    Student newStudent; // Krijimi i një objekti të ri të tipit Student

    cout << "\n===== SHTO STUDENT =====\n";
    cout << "ID: ";
    cin >> newStudent.id;

    // Kontrollojmë nëse ID ekziston
    for (const auto& student : studentList) {
        if (student.id == newStudent.id) {
            cout << "Gabim: ID ekziston tashmë!\n";
            return; // Nëse ID ekziston, dil nga funksioni
        }
    }

    // Marrim të dhënat e studentit nga përdoruesi
    cout << "Emri: ";
    cin >> newStudent.emri;

    cout << "Mbiemri: ";
    cin >> newStudent.mbiemri;

    cout << "Mosha: ";
    cin >> newStudent.mosha;

    cout << "Nota Mesatare: ";
    cin >> newStudent.notaMesatare;

    // Shtojmë studentin e ri në vektor
    studentList.push_back(newStudent);

    cout << "Studenti u shtua me sukses!\n";
}

// 5. Funksioni për të shfaqur të gjithë studentët
void displayStudents() {
    // Kontrollojmë nëse lista është bosh
    if (studentList.empty()) {
        cout << "\nNuk ka studentë të regjistruar!\n";
        return;
    }

    // Shfaqja e titullit të listës
    cout << "\n===== LISTA E STUDENTËVE =====\n";
    cout << setw(5) << "ID" << setw(15) << "Emri" << setw(15) << "Mbiemri" << setw(10) << "Mosha" << setw(15) << "Nota Mesatare\n";
    cout << "-------------------------------------------------\n";

    // Shfaq të dhënat e secilit student
    for (const auto& student : studentList) {
        cout << setw(5) << student.id << setw(15) << student.emri << setw(15) << student.mbiemri
             << setw(10) << student.mosha << setw(15) << student.notaMesatare << endl;
    }
}

// 6. Funksioni për të kërkuar një student sipas ID
void searchStudent() {
    int id;
    cout << "\n===== KERKO STUDENT =====\n";
    cout << "Shkruaj ID-në e studentit: ";
    cin >> id;

    // Kërkojmë studentin në listë
    for (const auto& student : studentList) {
        if (student.id == id) {
            // Nëse studenti gjendet, shfaq detajet
            cout << "\nStudenti u gjet:\n";
            cout << "ID: " << student.id << ", Emri: " << student.emri << ", Mbiemri: " << student.mbiemri
                 << ", Mosha: " << student.mosha << ", Nota Mesatare: " << student.notaMesatare << endl;
            return;
        }
    }

    // Nëse studenti nuk gjendet
    cout << "Studenti me ID " << id << " nuk u gjet.\n";
}

// 7. Funksioni për të fshirë një student sipas ID
void deleteStudent() {
    int id;
    cout << "\n===== FSHI STUDENT =====\n";
    cout << "Shkruaj ID-në e studentit për të fshirë: ";
    cin >> id;

    // Kërkojmë studentin në listë dhe e fshijmë
    for (auto it = studentList.begin(); it != studentList.end(); ++it) {
        if (it->id == id) {
            studentList.erase(it); // Fshi studentin
            cout << "Studenti u fshi me sukses!\n";
            return;
        }
    }

    // Nëse studenti nuk gjendet
    cout << "Studenti me ID " << id << " nuk u gjet.\n";
}

// 8. Funksioni kryesor
int main() {
    int choice;

    while (true) {
        displayMenu(); // Shfaqja e menysë
        cin >> choice;

        // Menaxhimi i zgjedhjes së përdoruesit
        switch (choice) {
            case 1:
                addStudent(); // Shtimi i studentit
                break;
            case 2:
                displayStudents(); // Shfaqja e studentëve
                break;
            case 3:
                searchStudent(); // Kërkimi i studentit
                break;
            case 4:
                deleteStudent(); // Fshirja e studentit
                break;
            case 5:
                cout << "Duke dalë nga programi...\n";
                return 0; // Dalja nga programi
            default:
                cout << "Zgjedhje e pavlefshme! Ju lutem provoni përsëri.\n";
        }
    }

    return 0;
}
