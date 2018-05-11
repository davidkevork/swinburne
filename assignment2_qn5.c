#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define M_PI 3.14159

int get_menu();
int get_unit();
int get_calculation();
float diameter_to_radius(float diameter);
float random_value_generator(int min, int max);
float area(float radius);
float circumference(float radius);

int main()
{
    int menu = 0;
    unsigned unit;
    unsigned calc;
    do {
        menu = get_menu();
        switch (menu) {
            case -1:
                return 0;
            case 1:
                unit = get_unit();
                float radius = random_value_generator(5, 15);
                calc = get_calculation();
                printf("Radius = %f\n", radius);
                calc == 0 ?
                printf("Area = %f\n", area(radius))
                          :
                printf("Circumference = %f\n", circumference(radius));
                break;
            case 2:
                unit = get_unit();
                float diameter = random_value_generator(15, 30);
                calc = get_calculation();
                printf("Diameter = %f\n", diameter);
                calc == 0 ?
                printf("Area = %f\n", area(diameter_to_radius(diameter)))
                          :
                printf("Circumference = %f\n", circumference(diameter_to_radius(diameter)));
                break;
            default:
                printf("Enter a valid number.\n");
                break;
        }
    } while (menu != -1);
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
    unsigned u;
    printf("Choose a unit.\n");
    printf("0 for cm\n");
    printf("1 for m\n");
    scanf("%u", &u);
    return (u != 0 && u != 1 ? get_unit() : u);
}

/**
 * Gets calculation from user input
 * User enters [A] for area and [C] for circumference
 * 0 for area / 1 for circumference
 * @return calculation
 */
int get_calculation() {
    char calc[1];
    printf("Enter calculation type.\n");
    printf("[A] for area\n");
    printf("[C] for circumference\n");
    scanf("%s", calc);
    if (strcmp(calc, "A") || strcmp(calc, "a")) {
        return 0;
    } else if (strcmp(calc, "C") || strcmp(calc, "c")) {
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
float diameter_to_radius(float diameter)
{
    return diameter/2;
}

/**
 * Random Number Generator
 * @param min
 * @param max
 * @return random
 */
float random_value_generator(int min, int max)
{
    srand(time(NULL));
    return rand()%(max-min+1)+min;
}


/**
 * Calculates area from radius
 * @param radius
 * @return area
 */
float area(float radius)
{
    return M_PI * radius * radius;
}

/**
 * Calculates circumference from radius
 * @param radius
 * @return circumference
 */
float circumference(float radius)
{
    return 2 * M_PI * radius;
}
