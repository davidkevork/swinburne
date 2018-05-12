#include <stdio.h>
#include <string.h>

int main()
{
    char lalphabet[26] = "abcdefghijklmnopqrstuvwxyz";
    char halphabet[26] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int count[26] = {0};
    char input[40];

    printf("Enter several lines of text:\n");
    fgets(input, 40, stdin);

    for (int i = 0; i < strlen(input); ++i) {
        for (int j = 0; j < 26; ++j) {
            if ( (int)input[i] == (int)lalphabet[j] || (int)input[i] == (int)halphabet[j] ) {
                count[j] += 1;
            }
        }
    }

    printf("\n\n");
    for (int l = 0; l < 26; ++l) {
        printf("Letter %c appears %d times\n", lalphabet[l], count[l]);
    }
}
