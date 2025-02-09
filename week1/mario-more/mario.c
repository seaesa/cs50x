#include <stdio.h>
#include <cs50.h>
int main(void)
{
  int height;
  char matrix[8][10] = {
      "#",
      "##",
      "###",
      "####",
      "#####",
      "######",
      "#######",
      "########",
  };
  do
  {
    height = get_int("Height: ");
  } while (height < 0 || height > 8);

  for (int i = 0; i < height; i++)
  {
    for (int j = height - i - 1; j > 0; j--)
    {
      printf(" ");
    }
    printf("%s  %s\n", matrix[i], matrix[i]);
  }
  return 0;
}