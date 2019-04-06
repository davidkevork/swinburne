#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

double random_number(int min, int max);
void ask_question(unsigned int* rows, unsigned int* columns, unsigned int* input_rows, unsigned int* input_columns);
int check_another();

int main() {
    srand(time(NULL));
    unsigned int rows = 0, columns = 0, input_rows = 0, input_columns = 0, another = 1;
    printf("If you give a number of rows and number of columns I will create a 2D array with random numbers between 0 and 9 (inclusive)\n");
    printf("Enter number of rows: ");
    scanf("%u", &rows);
    printf("Enter number of columns: ");
    scanf("%u", &columns);

    int array[rows][columns];

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            array[i][j] = random_number(0, 9);
            printf("%i ", array[i][j]);
        }
        printf("\n");
    }

    ask_question(&rows, &columns, &input_rows, &input_columns);
    printf("The value at row %u and column %u is %i\n", input_rows, input_columns, array[input_rows-1][input_columns-1]);

    do {
        another = check_another();
        if (another == 1) {
            ask_question(&rows, &columns, &input_rows, &input_columns);
            printf("The value at row %u and column %u is %i\n", input_rows, input_columns, array[input_rows-1][input_columns-1]);
        } else {
            another = 0;
            printf("Oh !! you decided to quit? Ok, no worries, see you later!\n");
        }
    } while (another == 1);
    return 0;

}

void ask_question(unsigned int* rows, unsigned int* columns, unsigned int* input_rows, unsigned int* input_columns)
{
    printf("If you give me a row number and column number I will give you the corresponding number\n");

    printf("Enter row number: ");
    scanf("%u", &(*input_rows));
    while (*input_rows > *rows) {
        printf("The row number %u is out of bound of this matrix, you only have %u rows\n", (*input_rows), *rows);
        printf("Re-enter row number: ");
        scanf("%u", &(*input_rows));
    }

    printf("Enter column number: ");
    scanf("%u", &(*input_columns));
    while (*input_columns > *columns) {
        printf("The column number %u is out of bound of this matrix, you only have %u column\n", *input_columns, *columns);
        printf("Re-enter column number: ");
        scanf("%u", &(*input_columns));
    }
}


int check_another()
{
    char answer[2];
    int y = -1, n = -1;
    printf("Do you want to find another number in the array, enter y or n: ");
    scanf("%s", answer);
    y = strcmp(answer, "y");
    n = strcmp(answer, "n");
    while (y != 0 && n != 0) {
        printf("Sorry this is not a right choice, please enter y or n: ");
        scanf("%s", answer);
        y = strcmp(answer, "y");
        n = strcmp(answer, "n");
    }
    return n == 0 ? 0 : 1;

}

double random_number(int min, int max)
{
    return rand()%(max-min+1)+min;
}
