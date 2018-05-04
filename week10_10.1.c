#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct employee {
    char name[256];
    int emp_id;
    float salary;
};

void read_all_employee(struct employee emp[], int size);
void print_all_employee(struct employee emp[], int size);
float employee_total_salary(struct employee emp[], int size);
int search_largest_salary_index(struct employee emp[], int size);
int search_an_employee_salary(struct employee emp[], int size, char name[256]);
void read_employee(struct employee* emp);
void print_employee(struct employee* emp);

int main() {
    struct employee *EmployeePtr, Employee[1];
    int size = 0;
    printf("How many employee data you want to enter: ");
    do {
        scanf("%d", &size);
    } while(size <= 0);
    EmployeePtr = (struct employee *) malloc( sizeof(Employee[1]) * size);

    read_all_employee(EmployeePtr, size);
    printf("Employee details are:\n");
    print_all_employee(EmployeePtr, size);
    printf("Total: %f\n", employee_total_salary(EmployeePtr, size));
    int index = search_largest_salary_index(EmployeePtr, size);
    printf("Index of employee with largest salary: %d\n", index);
    print_employee(&EmployeePtr[index]);
    int i = search_an_employee_salary(EmployeePtr, size, EmployeePtr[index].name);
    if (i != -1) {
        printf("The salary of %s is %d\n", EmployeePtr[i].name, EmployeePtr[i].salary);
    } else {
        printf("Array does not contain an employee named %s\n", EmployeePtr[i].name);
    }
    printf("Employee details in reverse order are:\n");
    for (int j = size; j > 0; --j) {
        print_employee(&EmployeePtr[i]);
    }
}


/**
 * Reads [size] employee and stores in emp[] struct
 * @param emp
 * @param size
 */
void read_all_employee(struct employee emp[], int size) {
    for (int i = 0; i < size; ++i) {
        read_employee(&emp[i]);
    }
}

/**
 * Prints out [size] employee details from emp[] struct
 * @param emp
 * @param size
 */
void print_all_employee(struct employee emp[], int size) {
    for (int i = 0; i < size; ++i) {
        print_employee(&emp[i]);
    }
}

/**
 * calculated the total salary of all employee
 * @param emp
 * @param size
 * @return total_salary of all employee
 */
float employee_total_salary(struct employee emp[], int size) {
    float total_salary = 0;
    for (int i = 0; i < size; ++i) {
        total_salary += emp[i].salary;
    }
    return total_salary;
}

/**
 * Searched the largest salary in the employee lists
 * @param emp
 * @param size
 * @return array index of the largest salary
 */
int search_largest_salary_index(struct employee emp[], int size) {
    int index = 0;
    float max = 0;
    for (int i = 0; i < size; ++i) {
        if (emp[i].salary > max) {
            max = emp[i].salary;
            index = i;
        }
    }
    return index;
}

/**
 * searched employee salary
 * @param emp
 * @param size
 * @param name
 * @return index
 */
int search_an_employee_salary(struct employee emp[], int size, char name[256]) {
    int index = -1;
    for (int i = 0; i < size; ++i) {
        if (strcmp(emp[i].name,name) == 0) {
            index = i;
        }
    }
    return index;
}

/**
 * reads one employee data and inserts to emp
 * @param emp
 */
void read_employee(struct employee* emp) {
    printf("Enter name: ");
    scanf("%s", emp->name);
    printf("Enter employee id: ");
    scanf("%i", &emp->emp_id);
    do {
        printf("Enter employee salary: ");
        scanf("%f", &emp->salary);
    } while (emp->salary <= 0);
    printf("\n");
}

/**
 * prints out emp details
 * @param emp
 */
void print_employee(struct employee* emp) {
    printf("%s(%d): %f ", emp->name, emp->emp_id, emp->salary);
    emp->salary < 4000 ? printf("Level A\n") : printf("Level B\n");
}
