#iclude <iostream>
#include <fstream>
#iclude <vector>
#iclude "student.h"
using namespace std;

//Funksioni për ëe ruajtur studentët në skedar
void saveToFile(const vector<Student>&students){
  ofstream file("students.dat", ios::binary);
 if(!file){
  cerr << "Gabim: Nuk mund të hapet skedari për ruajtje!" << endl;
 return;

}
for (const auto&student:students){
 file.write(reinterpret_cast<const char*>(&student), sizeof(Student));
}

file.close();
cout << "Studentët u ruajtën me sukses!" << endl;
}

//Funksioni për të lexuar studentët nga skedari
vector<Student>loadFromFile() {
  vector<Student>students;
  ifstream file("students.dat", ios::binary);
  if (!file) {
    cerr << "Gabim: Nuk mund të hapet skedari për lexim!" << endl;
    return students;
}

Student student;
while (file.read(reinterpret_cast<char*>(&student), sizeof(Student))) {
  students.push_back(student);
}

file.close();
cout << "Studentët u ngarkuan nga skedari!" << endl;
return students;
}

//Funskioni për të fshirë skedarin
void deleteFile() {
  if (remove("students.dat") == 0) {
    cout << "Skedari u fshi me sukses." << endl;
} else {
cerr << "Gabim gjatë fshirjes së skedarit."" << endl;

  }
}
