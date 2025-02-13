#include <iostream>
#include <vector>
#include <string>
#include <student.h>

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

// 3. Funksioni për të shtuar një student të ri
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

    // Shto studentin e ri në vektor
    studentList.push_back(newStudent);

    cout << "Studenti u shtua me sukses!\n";
}

// 4. Funksioni kryesor
int main() {
    int choice;

    while (true) {
        // Paraqesim menynë e thjeshtë
        cout << "\n===== MENU KRYESOR =====\n";
        cout << "1. Shto Student\n";
        cout << "2. Shfaq Studentet (Punë e ekipit tjetër)\n";
        cout << "3. Kerko Student (Punë e ekipit tjetër)\n";
        cout << "4. Fshi Student (Punë e ekipit tjetër)\n";
        cout << "5. Dal\n";
        cout << "Zgjedhja juaj: ";
        cin >> choice;

        // Menaxhimi i zgjedhjes së përdoruesit
        switch (choice) {
            case 1:
                addStudent(); // Shtimi i studentit (pjesa jote)
                break;
            case 2:
                cout << "\nShfaqja e studentëve është pjesë e punës së ekipit tjetër.\n";
                break;
            case 3:
                cout << "\nKërkimi i studentëve është pjesë e punës së ekipit tjetër.\n";
                break;
            case 4:
                cout << "\nFshirja e studentëve është pjesë e punës së ekipit tjetër.\n";
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
