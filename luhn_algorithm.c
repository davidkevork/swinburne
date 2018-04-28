#include <stdio.h>

/**
 * int array to store debit card numbers
 */
int card[16];

/**
 * @brief      Gets the card numbers into an array of int
 */
void getCard() {
  printf("Enter credit card numbers as the following example: 1111222233334444\n");
  char ch;
  int i = 0;
  while(ch != '\n' && i < 16) {
    ch = getchar();
    card[i] = ch - '0';
    i++;
  }
}

/**
 * @brief      Doubles every second number and calculates the sum
 *             If the doubled number is 2 digit (ex: 15) then the sum is calculated 1+5=6 and replace
 *
 * @return     The sum
 */
int sum1() {
  /**
   * Debit Cards have 16 digit and thus it is hard coded the size of the array
   * i += 2 since we are calculating every second digit
   * and no need to waste cpu on calculating if it is the second digit or not
   * So we just skip them
   */
  int sum = 0;
  for (int i = 0; i < 15; i += 2) {
    int temp = card[i] * 2;
    card[i] = (temp > 10 ? temp-10+1 : temp);
    sum += card[i];
  }
  printf("The sum of the doubled numbers are: %i\n", sum);
  return sum;
}

/**
 * @brief      Calculated the sum of every other number
 *
 * @return     The sum
 */
int sum2() {
  int sum = 0;
  for (int i = 1; i < 15; i += 2) {
    int temp = card[i] + card[i];
    sum += (temp > 10 ? temp-10+1 : temp);
  }
  printf("Sum of the rest of the numbers are: %i\n", sum);
  return sum;
}


/**
 * @brief      Checks if debit card number is valid
 *
 * @return     0
 */
int main() {
  getCard();
  
  int sum_1 = sum1();
  int sum_2 = sum2();
  
  int total = (sum_1 + sum_2) * 9;

  // checksum is done by taking (total modules 10 equals 0)
  if (total % 10 == 0) ? printf("Valid Debit Card Number\n") : printf("Invalid Debit Card Number\n");
  return 0;
}
