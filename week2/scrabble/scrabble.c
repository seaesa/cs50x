#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

int get_score_of_word(char word);
int get_max_length(int value1, int value2);

int main(void)
{
  int score_player1 = 0, score_player2 = 0;
  // Prompt the user for two word s
  string player1 = get_string("Player 1: ");
  string player2 = get_string("Player 2: ");

  int biggest_length = get_max_length(strlen(player1), strlen(player2));
  // Compute the scrore of each word
  for (int i = 0; i < biggest_length; i++)
  {
    score_player1 += get_score_of_word(player1[i]);
    score_player2 += get_score_of_word(player2[i]);
  }
  // Print the winner
  if (score_player1 > score_player2)
  {
    printf("Player 1 wins!\n");
  }
  else if (score_player1 < score_player2)
  {
    printf("Player 2 wins!\n");
  }
  else
  {
    printf("Tie!\n");
  }
}

int get_max_length(int value1, int value2)
{
  return value1 > value2 ? value1 : value2;
}
int get_score_of_word(char word)
{
  switch (tolower(word))
  {
  case 'a':
  case 'e':
  case 'i':
  case 'l':
  case 'n':
  case 'o':
  case 'r':
  case 's':
  case 't':
  case 'u':
    return 1;
  case 'd':
  case 'g':
    return 2;
  case 'b':
  case 'c':
  case 'm':
  case 'p':
    return 3;
  case 'f':
  case 'h':
  case 'v':
  case 'w':
  case 'y':
    return 4;
  case 'k':
    return 5;
  case 'j':
  case 'x':
    return 8;
  case 'q':
  case 'z':
    return 10;
  default:
    return 0;
  }
}