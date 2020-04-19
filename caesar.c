// Program Start
#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Prototypes
int validate_input(string t);
string transform_input(string t, int key);

// Main Function

int main(int argc, string argv[])
{

// Check Input

    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;

    }
    else

    {
// Check to see if argument is correct
        string t = argv[1];
        int valid = validate_input(t);

        if (valid == 0)
        {
// If correct then ask for new text
            int key = atoi(argv[1]);
            string plain_t = get_string("plaintext:");


// Transform the input text
            string index_t = transform_input(plain_t, key);

// Print the result
            printf("ciphertext: %s\n", index_t);

        }
        else
        {
// If input was incorrect throw error
            printf("Usage: ./caesar key\n");
            return 1;
        }

    }

// End
}




// Functions

string transform_input(string t, int key)
{

// Create new string out of input which will be changed letter by letter
    string new_string = t;
    for (int i = 0, n = strlen(t); i < n; i++)
    {

// If Alpha then change using algorithm

        if (isalpha(t[i]))
        {
            if (isupper(t[i]))
            {
                new_string[i] -= 65;
                new_string[i] = ((new_string[i] + key) % 26) + 65;

            }
            else
            {
                new_string[i] -= 97;
                new_string[i] = ((new_string[i] + key) % 26) + 97;

            }

        }
        else
        {
// If not Alpha then stay the same
            new_string[i] += 0;
        }

    }
// Output the transformed string
    return new_string;
}


int validate_input(string t)
{
    int input_error = 0;

    for (int i = 0, n = strlen(t); i < n; i++)
    {

        if (isdigit(t[i]))
        {
            input_error += 0;

        }
        else
        {
// If error then change value
            input_error += 1;
        }
    }
    return input_error;
}
