#include <stdio.h>
#include <cs50.h>
int main(void)
{
  int cash;
  do
  {
    cash = get_int("Change owed: ");
  } while (cash <= 0);
  return 0;
}