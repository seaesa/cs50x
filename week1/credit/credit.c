#include <cs50.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>

void swapArray(int array[], int length);
int getLengthOfNumber(long number);
int *convertNumberToArray(long number);
int getFirstDigit(long number);
void checkTypeCreditCard(long credit);
void verifyCreditCard(long credit);
void checkTypeCreditCard(long credit);
bool checkIsValidCreditCard(long credit);

int main(void)
{
  long credit;
  do
  {
    credit = get_long("Number: ");
    int lengthOfNumber = getLengthOfNumber(credit);
    if (lengthOfNumber < 13 || lengthOfNumber > 16)
    {
      printf("INVALID\n");
      break;
    }
    verifyCreditCard(credit);
  } while (credit <= 0);
  return 0;
}

int *convertNumberToArray(long number)
{
  static int digits[20];
  int count = 0;
  while (number > 0)
  {
    digits[count] = number % 10;
    number /= 10;
    count++;
  }
  return digits;
}

void swapArray(int array[], int length)
{
  int temp;
  int start = 0;
  int end = length - 1;
  while (start < end)
  {
    temp = array[start];
    array[start] = array[end];
    array[end] = temp;
    start++;
    end--;
  }
}

int getFirstDigit(long number)
{
  while (number >= 10)
    number /= 10;
  return number;
}
int getLengthOfNumber(long number)
{
  if (number == 0)
  {
    return 1;
  }
  if (number < 0)
  {
    number = -number;
  }
  return (long)log10(number) + 1;
}

void verifyCreditCard(long credit)
{
  int lengthOfNumber = getLengthOfNumber(credit);
  bool isCredit = checkIsValidCreditCard(credit);
  if (!isCredit)
  {
    printf("INVALID\n");
    return;
  }
  checkTypeCreditCard(credit);
}
void checkTypeCreditCard(long credit)
{
  switch (getFirstDigit(credit))
  {
  case 3:
    printf("AMEX\n");
    break;
  case 4:
    printf("VISA\n");
    break;
  case 5:
    printf("MASTERCARD\n");
    break;
  default:
    printf("INVALID\n");
    break;
  }
}

bool checkIsValidCreditCard(long credit)
{
  int lengthOfNumber = getLengthOfNumber(credit);
  int *digitArray = convertNumberToArray(credit);
  int sum = 0;
  for (int i = 1; i < lengthOfNumber; i += 2)
  {
    digitArray[i] *= 2;
  }
  for (int i = 0; i < lengthOfNumber; i++)
  {
    if (digitArray[i] >= 10)
    {
      int *caculate = convertNumberToArray(digitArray[i]);
      sum += (caculate[0] + caculate[1]);
      continue;
    }
    sum += (digitArray[i]);
  }
  int *card_id = convertNumberToArray(sum);
  if (card_id[0] != 0)
  {
    return false;
  }
  return true;
}