#include <iostream>

// diamond pattern
int main(int argc, char const *argv[])
{
    unsigned int width = 0;
    unsigned int row = 0;
    std::cout << "Width of the shape? (Enter odd number only) ";
    std::cin >> width;
    std::cout << "Enter row number to get sum: ";
    std::cin >> row;

    int space = (width - 1) / 2;
    
    // shows the top part of the pyramid
    for(size_t i = 1; i <= row; i++)
    {
        for(size_t j = 1; j <= (2 * space); j++)
        {
            std::cout << " ";
        }
        space--;
        for(size_t k = 1; k < 2 * i; k++)
        {
            std::cout << " " << k;
        }
        std::cout << std::endl;
    }

    space = 1;
    
    // shows inverse pyramid
    for(size_t l = 1; l < row ; l++)
    {
        for(size_t m = 0; m < space; m++)
        {
            std::cout << "  ";
        }
        space++;
        for(size_t n = 1; n <= 2 * (row - l ) - 1; n++)
        {
            std::cout << " " << n;
        }
        std::cout << std::endl;
    }

    std::cout << "The sum of row " << row << " is " << row * width << std::endl;

    return 0;
}
