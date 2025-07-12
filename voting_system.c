#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_CANDIDATE 6 // maximum candidates who can vote
typedef struct candidate
{
    int votes;
    char name[20];
    char symbol;
} Candidate;              // candidate structure
int Total_Candidates = 0; // total number of candidates present.
char symbols[MAX_CANDIDATE] = {'@', '#', '$', '%', '&', '*'};
int symbols_count = MAX_CANDIDATE; // counts total symbols in symbols array.

void remove_array_element(int index)
{
    for (int i = index; i < symbols_count - 1; i++)
    {
        symbols[i] = symbols[i + 1];
    }
    symbols_count--;
}

void disp_candidates(Candidate *c)
{
    for (int i = 0; i < Total_Candidates; i++)
    {
        printf("%s\t\t", c[i].name);
    }
    printf("\n");
    for (int i = 0; i < Total_Candidates; i++)
    {
        printf("%c\t\t", c[i].symbol);
    }
    printf("\n");
}
void vote(Candidate *c, int i)
{
    int choice;
    printf("Enter your vote, voter %d (1-%d): ", i + 1, Total_Candidates);
    if (scanf("%d", &choice) != 1)
    {
        printf("Invalid. Enter a number. Try again. ");
        while (getchar() != '\n')
            ;
        vote(c, i);
        return;
    }
    else if (choice < 1 || choice > Total_Candidates)
    {
        printf("Invalid candidate number. Try again. ");
        vote(c, i);
    }
    c[choice - 1].votes++;
}
void result(Candidate *c)
{
    Candidate winner = c[0];
    int freq = 0;
    for (int i = 0; i < Total_Candidates; i++)
    {
        if (c[i].votes > winner.votes)
        {
            winner = c[i];
            freq = 1;
        }
        else if (c[i].votes == winner.votes)
        {
            freq++;
        }
    }
    printf("\nRESULT\n");
    if (freq == 1)
    {
        printf("%s (%c) wins with %d votes !!", winner.name, winner.symbol, winner.votes);
    }
    else
    {
        printf("Tied between ");
        for (int i = 0; i < Total_Candidates; i++)
        {
            if (c[i].votes == winner.votes)
            {
                printf("%s (%c) ", c[i].name, c[i].symbol);
            }
        }
        printf("with votes %d.", winner.votes);
    }
}

int main()
{
    printf("Enter number of candidates present: ");
    scanf("%d", &Total_Candidates);
    if (Total_Candidates <= 1)
    {
        printf("Voting cannot begin with the given number of candidates.Restart again.");
        return 0;
    }
    if (Total_Candidates > MAX_CANDIDATE)
    {
        printf("There cannot be more than %d candidates.Restart again.", MAX_CANDIDATE);
        return 0;
    }
    Candidate *arr = (Candidate *)calloc(Total_Candidates, sizeof(Candidate)); // array for storing candidate details.

    for (int i = 0; i < Total_Candidates; i++)
    {
        int selection; // vote given by user.
        printf("Enter details of candidate %d.\n ", i + 1);
        for (int j = 0; j < symbols_count; j++)
        {
            printf("%d. %c  ", j + 1, symbols[j]);
        }
        printf("\n");

        do
        {
            printf("Enter number corresponding to symbol of Candidate %d: ", i + 1);
            if (scanf("%d", &selection) != 1)
            {
                printf("Invalid input. Please enter a number.\n");
                while (getchar() != '\n')
                    ;
                selection = -1;
            }
            else if (selection < 1 || selection > symbols_count)
            {
                printf("Invalid choice. Please enter a number between 1 and %d.\n", symbols_count);
            }
        } while (selection < 1 || selection > symbols_count);

        arr[i].symbol = symbols[selection - 1];
        remove_array_element(selection - 1);
        printf("Enter name of candidate %d. ", i + 1);
        scanf("%s", &arr[i].name);
    }
    int total_voters;
    printf("Enter total number of voters: ");
    scanf("%d", &total_voters);
    for (int i = 0; i < total_voters; i++)
    {
        disp_candidates(arr);
        vote(arr, i);
    }
    result(arr);
    free(arr);

    return 0;
}
