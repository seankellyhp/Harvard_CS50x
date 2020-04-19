#include <cs50.h>
#include <stdio.h>

// Print Mario Style Blocks
int main(void)
{
    int n; 
    do
    {
        n = get_int("Height: ");
    }
    while (n < 1 || n > 8);

// If Correct Input then Print Block Size
    for (int i = 1; i < n + 1; i++)
    {
        int nHash = i;
        int nDot = n - i;

// Invisible Spaces
        for (int j = 0; j < nDot; j++)
        {
            printf(" ");

        }
        for (int j = 0; j < nHash; j++)
        {
            printf("#");

        }
        printf("\n");
    }
}
