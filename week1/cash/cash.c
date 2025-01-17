#include <stdio.h>
#include <cs50.h>

const int QUARTERS = 25;
const int DIMES = 10;
const int NICKELS = 5;
const int PENNIES = 1;
int calculate_quarters(int *cents);
int calculate_dimes(int *cents);
int calculate_nickels(int *cents);
int calculate_pennies(int *cents);

int main(void)
{
  int cents;
  do
  {
    cents = get_int("Change owed: ");
  } while (cents <= 0);

  int quarters = calculate_quarters(&cents);
  int dimes = calculate_dimes(&cents);
  int nickels = calculate_nickels(&cents);
  int pennies = calculate_pennies(&cents);

  int total_cash = quarters + dimes + nickels + pennies;
  printf("%d\n", total_cash);
  return 0;
}

int calculate_quarters(int *cents)
{
  int quarters = 0;
  while (*cents >= QUARTERS)
  {
    quarters++;
    *cents -= QUARTERS;
  }
  return quarters;
}
int calculate_dimes(int *cents)
{
  int dimes = 0;
  while (*cents >= DIMES)
  {
    dimes++;
    *cents -= DIMES;
  }
  return dimes;
}
int calculate_nickels(int *cents)
{
  int nickels = 0;
  while (*cents >= NICKELS)
  {
    nickels++;
    *cents -= NICKELS;
  }
  return nickels;
}
int calculate_pennies(int *cents)
{
  int pennies = 0;
  while (*cents >= PENNIES)
  {
    pennies++;
    *cents -= PENNIES;
  }
  return pennies;
}