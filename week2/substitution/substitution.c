#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
char substitute(char ch,char* CIPHER_KEY);
char* encrypt(char* input, char* CIPHER_KEY);

const int ALPHABET_SIZE = 26; 

int main(int argc,char *argv[]) {
  // validdate key input
  if(argc != 2) {
    printf("Usage: ./substitution key");
    return 1;
  }else if(strlen(argv[1]) != ALPHABET_SIZE) {
    printf("Key must contain 26 characters.\n");
    return 1;
  }
  for(int i = 0; i < ALPHABET_SIZE; i++) {
    if(!isalpha(argv[1][i])) {
      printf("Key must only contain alphabetic characters.\n");
      return 1;
    }   
    for(int j = i + 1; j < ALPHABET_SIZE; j++) {
      if(toupper(argv[1][i]) == toupper(argv[1][j])) {
        printf("Key must not contain repeated characters.\n");
        return 1;
      }
    }
  }  
  string plaintext = get_string("plaintext: ");
  string ciphertext = encrypt(plaintext, argv[1]); 
  printf("ciphertext: %s\n", ciphertext);
  return 0; 
}
char *encrypt(char* input, char* CIPHER_KEY) { 
  char *ciphertext = malloc(ALPHABET_SIZE);
  for (int i = 0; input[i] != '\0'; ++i) {
    ciphertext[i] = substitute(input[i],CIPHER_KEY);
  }
  return ciphertext; 
}
char substitute(char ch,char* CIPHER_KEY) {
  if (isalpha(ch)) {
      int isLower = islower(ch);
      ch = toupper(ch); // Make uppercase for consistent indexing
      char encrypted = CIPHER_KEY[ch - 'A'];
      char result = isLower ? tolower(encrypted) : toupper(encrypted);
    return result;
    }
  return ch;  // Return non-alphabet characters unchanged
}