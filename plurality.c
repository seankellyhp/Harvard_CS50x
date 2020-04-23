#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// Candidates have name and vote count
typedef struct
{
    string name;
    int votes;
}
candidate;

// Array of candidates
candidate candidates[MAX];

// Number of candidates
int candidate_count;

// Function prototypes
bool vote(string name);
void print_winner(void);
void swap(int *votes1, int *votes2, string *name1, string *name2);
void bubble_sort(int n);
void print_results(int size);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: plurality [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }

    int voter_count = get_int("Number of voters: ");

    // Loop over all voters
    for (int i = 0; i < voter_count; i++)
    {
        string name = get_string("Vote: ");

        // Check for invalid vote
        if (!vote(name))
        {
            printf("Invalid vote.\n");
        }
    }

    // Display winner of election
    print_winner();
}


bool vote(string name)
{

    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(candidates[i].name, name) == 0)
        {
            candidates[i].votes += 1;
            return true;
        }
    }

    return false;
}


void swap(int *votes1, int *votes2, string *name1, string *name2)
{
    int temp = *votes1;
    *votes1 = *votes2;
    *votes2 = temp;

    string temp1 = *name1;
    *name1 = *name2;
    *name2 = temp1;
}

// Use Bubblesort
void bubble_sort(int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
    {

// Move the biggest vote count
        for (j = 0; j < n - i - 1; j++)
        {
            if (candidates[j].votes > candidates[j + 1].votes)
            {
                swap(&candidates[j].votes, &candidates[j + 1].votes, &candidates[j].name, &candidates[j + 1].name);
            }
        }
    }
}

/* Print outcome */
void print_results(int size)
{
    int max_vote = size - 1;
    for (int i = 0; i < size; i++)
    {
        if (candidates[i].votes == candidates[max_vote].votes)
        {
            printf("%s\n", candidates[i].name);
        }

    }
}

void print_winner(void)
{
    int n = candidate_count;
    bubble_sort(n);
    print_results(n);

}
