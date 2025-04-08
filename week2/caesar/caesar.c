#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
int main(int argc, string argv[])
{

   // Make sure program was run with just one command-line argument
   if(argc != 2)
   {
     printf("Usage: ./caesar key\n");
     return 1;
   }
    // Make sure every character in argv[1] is a digit
    char *key = argv[1];
    for (int i = 0; key[i] != '\0'; i++) {
      if (!isdigit((unsigned char)key[i])) {
          printf("Usage: ./caesar key\n");
          return 1;
      }
  }
    // Convert argv[1] from a `string` to an `int`
    int number = atoi(argv[1]);
    // Prompt user for plaintext
    string plaintext = get_string("plaintext: "); 
    // Print ciphertext
    printf("ciphertext: ");
    // Loop through each character in the plaintext
    for (int i = 0, n = strlen(plaintext); i < n; i++)
    {
        // Check if the character is an uppercase letter
        if (isupper(plaintext[i]))
        {
            // Shift the character and wrap around using modulo
            printf("%c", ((plaintext[i] - 'A' + number) % 26) + 'A');
        }
        // Check if the character is a lowercase letter
        else if (islower(plaintext[i]))
        {
            // Shift the character and wrap around using modulo
            printf("%c", ((plaintext[i] - 'a' + number) % 26) + 'a');
        }
        else
        {
            // If it's not a letter, print it as is
            printf("%c", plaintext[i]);
        }
    }
    // Print a newline at the end
    printf("\n");
    return 0;
}