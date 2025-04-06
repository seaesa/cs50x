#include <ctype.h>
#include <cs50.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);
int main(void)
{
 // Prompt the user for some text
 string text = get_string("Text: ");
    // Count the number of letters, words, and sentences in the text
    int letters = count_letters(text);
    int words = count_words(text);
    int sentences = count_sentences(text);
    // Compute the average number of letters per 100 words
    float L = (float) letters / words * 100;
    // Compute the average number of sentences per 100 words
    float S = (float) sentences / words * 100; 
    // Compute the Coleman-Liau index
    float index = 0.0588 * L - 0.296 * S - 15.8;
    // Round the index to the nearest integer
    int grade = round(index);
    printf("Greade %i\n", grade);
    // Print the grade level
    if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (grade >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", grade);
    }
    // Compute the Coleman-Liau index

    // Print the grade level
}
int count_letters(string text)
{
    // Return the number of letters in text
    int count = 0;
    for (int i = 0; i < strlen(text); i++)
    {
        if (isalpha(text[i]))
        {
            count++;
        }
    }
    return count;
}
int count_words(string text)
{
    // Return the number of words in text
    int count = 0;
    for (int i = 0; i < strlen(text); i++)
    {
        if (isspace(text[i]) || text[i] == '\n' || text[i] == '\t')
        {
            count++;
        }
    } 
    return count +1; // Add one to count for the last word
}
int count_sentences(string text) {
    // Return the number of sentences in text
    // Add one to count for the last word
    int count = 0;
    for (int i = 0; i < strlen(text); i++)
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            count++;
        } 
    } 
    return count; 
}