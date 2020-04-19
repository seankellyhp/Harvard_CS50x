
// Program Start
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

// Function Prototypes

int count_letters(string t);
int count_words(string t);
int count_sentences(string t);
int cl_index(string t);
void print_index(int index_out);

// Main Function

int main(void)
{

// Get User Input
    string t;
    t = get_string("Text:");

// Calculate and Return Index

    int index_out = cl_index(t);
    print_index(index_out);

}


// All Helper Functions

// Count Letters

int count_letters(string t)
{
    int count = 0;
    for (int i = 0, n = strlen(t); i < n; i++)
    {

        if (isalpha(t[i]))
        {
            count++;
        }
        else
        {
            count = count + 0;
        }
    }
    return count;
}

// Count Words
int count_words(string t)
{
    int count = 1;
    for (int i = 0, n = strlen(t); i < n; i++)
    {

        if (isspace(t[i]))
        {
            count++;
        }
        else
        {
            count += 0;
        }

    }
    return count;

}

// Count Sentences

int count_sentences(string t)
{
    int count = 0;
    for (int i = 0, n = strlen(t); i < n; i++)
    {
        char t_cur = t[i];
        char t_exc = '!';
        char t_que = '?';
        char t_per = '.';

        if (t_cur == t_exc || t_cur == t_que || t_cur == t_per)
        {
            count++;
        }
        else
        {
            count += 0;
        }

    }
    return count;

}

/// Coleman Index

int cl_index(string t)
{

    int letters = count_letters(t);
    int words = count_words(t);
    int sentences = count_sentences(t);

    float avg_l = ((float) letters / (float) words) * 100;
    float avg_s = ((float) sentences / (float) words) * 100;

    int index = round((0.0588 * avg_l) - (0.296 * avg_s) - 15.8);

    return index;

}

// Cleaner Output

void print_index(int index_out)
{

    if (index_out < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index_out >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", index_out);
    }
}
