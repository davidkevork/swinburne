#include <iostream>

struct SOFTWARE {
  double version;
  char firstname[20];
  char projectName[20];
  char license[10];
};

void print_date(struct SOFTWARE data) {
  std::cout << "\nVersion: " << data.version;
  std::cout << "\nFirst Name: " << data.firstname;
  std::cout << "\nProject Name: " << data.projectName;
  std::cout << "\nLicense: " << data.license;
}

int main() {
  struct SOFTWARE project;
  
  std::cout << "Enter Version: ";
  std::cin >> project.version;

  std::cout << "Enter First Name: ";
  std::cin >> project.firstname;

  std::cout << "Enter Project Name: ";
  std::cin >> project.projectName;

  std::cout << "Enter License name: ";
  std::cin >> project.license;

  print_date(project);
  
  return 0;
}
