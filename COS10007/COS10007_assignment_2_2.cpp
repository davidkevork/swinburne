#include <iostream>
#include <cstdlib>
#include <string>
#include <ctime>

#define M_PI 3.14159

int get_menu();
int get_unit();
std::string write_unit(int unit);
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
                {
                    unit = get_unit();
                    double radius = random_value_generator(5, 15);
                    std::cout << "Radius given by random number generator is:" << radius << write_unit(unit) << std::endl;
                    calc = get_calculation();
                    if (calc == 0) {
                        std::cout << "Area = " << area(radius) << write_unit(unit) << "²" << std::endl;
                    } else {
                        std::cout << "Circumference = " << circumference(radius) << write_unit(unit) << std::endl;
                    }
                }
                break;
            case 2:
                {
                    unit = get_unit();
                    double diameter = random_value_generator(15, 30);
                    std::cout << "Diameter given by random number generator is: " << diameter << write_unit(unit) << std::endl;
                    calc = get_calculation();
                    if (calc == 0) {
                        std::cout << "Area = " << area(diameter_to_radius(diameter)) << write_unit(unit) << "²" << std::endl;
                    } else {
                        std::cout << "Circumference = " << circumference(diameter_to_radius(diameter)) << write_unit(unit) << std::endl;
                    }
                }
                break;
            default:
                std::cout << "Enter a valid number." << std::endl;
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
    std::cout << std::endl << "Do you want to use radius or diameter for the calculation?"<< std::endl;
    std::cout << "Enter 1 for radius"<< std::endl;
    std::cout << "Enter 2 for diameter"<< std::endl;
    std::cout << "Enter -1 to exit"<< std::endl;
    std::cin >> menu;
    return menu;
}

/**
 * Gets unit from user input
 * 0 for cm / 1 for m
 * @return unit
 */
int get_unit() {
    std::string unit;
    std::cout << "Choose a unit, cm or m:";
    std::cin >> unit;
    if (unit.compare("cm") == 0) {
        return 0;
    } else if (unit.compare("m") == 0) {
        return 1;
    } else {
        return get_unit();
    }
}

/**
 * returns either cm or m based on unit
 * @param unit
 * @return unit
 */
std::string write_unit(int unit) {
    return (unit == 0 ? "cm" : "m");
}

/**
 * Gets calculation from user input
 * User enters [A/a] for area and [C/c] for circumference
 * 0 for area / 1 for circumference
 * @return calculation
 */
int get_calculation() {
    std::string calc;
    std::cout << "Enter calculation type.\n" << std::endl;
    std::cout << "[A/a] for area\n" << std::endl;
    std::cout << "[C/c] for circumference\n" << std::endl;
    std::cin >> calc;
    if (calc.compare("A") == 0 || calc.compare("a") == 0) {
        return 0;
    } else if (calc.compare("C") == 0 || calc.compare("c") == 0) {
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
