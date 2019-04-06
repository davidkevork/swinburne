#include <stdio.h>
#include <string.h>

// structure definition
struct Date
{
    int yy, mm, dd;
};

struct Emp
{
    char EmpName[25];
    float Salary;
    struct Date hired;
};

void GetData(struct Emp *employee);
void PrintData(struct Emp *employee);
double GetAverage(struct Emp [], int n);

int main(int argc, char const *argv[])
{
    int n = 5;
    struct Emp a[n];
    for (int i = 0; i < n; ++i) {
        GetData(&a[i]);
    }
    for (int j = 0; j < n; ++j) {
        PrintData(&a[j]);
    }
    printf("Average salary: %f", GetAverage(a, n));
    return 0;
}

void GetData(struct Emp *employee) {
    printf("Enter Employee Name: ");
    scanf("%s", employee->EmpName);
    printf("Enter Employee Salary: ");
    scanf("%f", &employee->Salary);
    printf("Enter Date hired\n");
    printf("Enter date in (dd) format: ");
    scanf("%i", &employee->hired.dd);
    printf("Enter date in (mm) format: ");
    scanf("%i", &employee->hired.mm);
    printf("Enter date in (yy) format: ");
    scanf("%i", &employee->hired.yy);
}


void PrintData(struct Emp *employee) {
    printf("Name: %s, Salary: %f, Date hired: %d/%d/%d\n", employee->EmpName, employee->Salary, employee->hired.dd, employee->hired.mm, employee->hired.yy);
}

double GetAverage(struct Emp employee[], int n) {
    float avg = 0;
    for (int i = 0; i < n; ++i) {
        avg += employee[i].Salary;
    }
    return avg / n;
}
