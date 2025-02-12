#include <iostream>
#include <vector>
#include <string>
#include "student.h"

// Funksioni për përditësimin e të dhënave të studentëve
void updateStudent (std::vector<Student>& students) {
  int id;
  std::cout << "\nVendos ID e  studentit që dëshiron të përditësosh: ";
  std::cin >> id;

  bool found = false;
  for (auto& student : students) {
      if (student.id == id) {
          found = true;
          std::cout << "Student i gjetur: " << student.name << "\n";
          std::cout << "Vendos emrin e ri: ";
          std::cin.ignore();
          std::getline(std::cin, student.name);

          std::cout << "Vendos moshën e re: ";
          std::cin >> student.age;
