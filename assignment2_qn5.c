#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define M_PI 3.14159

int get_menu();
int get_unit();
int get_calculation();
double diameter_to_radius(double diameter);
double random_value_generator(int min, int max);
double area(double radius);
double circumference(double radius);

int main()
{
    int menu = 0;
    unsigned unit;
    unsigned calc;
    do {
        menu = get_menu();
        switch (menu) {
            case 1:
                unit = get_unit();
                double radius = random_value_generator(5, 15);
                calc = get_calculation();
                printf("Radius = %f\n", radius);
                calc == 0 ?
                printf("Area = %f%s\n", area(radius), (unit == 0 ? "cm" : "m"))
                          :
                printf("Circumference = %f%s\n", circumference(radius), (unit == 0 ? "cm" : "m"));
                break;
            case 2:
                unit = get_unit();
                double diameter = random_value_generator(15, 30);
                calc = get_calculation();
                printf("Diameter = %f\n", diameter);
                calc == 0 ?
                printf("Area = %f%s\n", area(diameter_to_radius(diameter)), (unit == 0 ? "cm" : "m"))
                          :
                printf("Circumference = %f%s\n", circumference(diameter_to_radius(diameter)), (unit == 0 ? "cm" : "m"));
                break;
            default:
                printf("Enter a valid number.\n");
                break;
        }
    } while (menu != -1);
    return 0;
}

/**
 * Shows the menu to  user
 * @return option number that the user entered
 */
int get_menu() {
    int menu = 0;
    printf("Do you want to use radius or diameter for the calculation?\n");
    printf("Enter 1 for radius\n");
    printf("Enter 2 for diameter\n");
    printf("Enter -1 to exit\n");
    scanf("%d", &menu);
    return menu;
}

/**
 * Gets unit from user input
 * 0 for cm / 1 for m
 * @return unit
 */
int get_unit() {
    char unit[256];
    printf("Choose a unit, cm or m:");
    scanf("%s", unit);
    if (strcmp(unit, "cm") == 0) {
        return 0;
    } else if (strcmp(unit, "m") == 0) {
        return 1;
    } else {
        return get_unit();
    }
}

/**
 * Gets calculation from user input
 * User enters [A/a] for area and [C/c] for circumference
 * 0 for area / 1 for circumference
 * @return calculation
 */
int get_calculation() {
    char calc[256];
    printf("Enter calculation type.\n");
    printf("[A/a] for area\n");
    printf("[C/c] for circumference\n");
    scanf("%s", calc);
    if (strcmp(calc, "A") == 0 || strcmp(calc, "a") == 0) {
        return 0;
    } else if (strcmp(calc, "C") == 0 || strcmp(calc, "c") == 0) {
        return 1;
    } else {
        return get_calculation();
    }
}

/**
 * Calculates radius from diameter
 * @param diameter
 * @return radius
 */
double diameter_to_radius(double diameter)
{
    return diameter/2;
}

/**
 * Random Number Generator
 * @param min
 * @param max
 * @return random
 */
double random_value_generator(int min, int max)
{
    srand(time(NULL));
    return rand()%(max-min+1)+min;
}


/**
 * Calculates area from radius
 * @param radius
 * @return area
 */
double area(double radius)
{
    return M_PI * radius * radius;
}

/**
 * Calculates circumference from radius
 * @param radius
 * @return circumference
 */
double circumference(double radius)
{
    return 2 * M_PI * radius;
}
