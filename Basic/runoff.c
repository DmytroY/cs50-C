// program that runs a runoff election

#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max voters and candidates
#define MAX_VOTERS 100
#define MAX_CANDIDATES 9

// preferences[i][j] is jth preference for voter i
int preferences[MAX_VOTERS][MAX_CANDIDATES];

// Candidates have name, vote count, eliminated status
typedef struct
{
    string name;
    int votes;
    bool eliminated;
}
candidate;

// Array of candidates
candidate candidates[MAX_CANDIDATES];

// Numbers of voters and candidates
int voter_count;
int candidate_count;

// Function prototypes
bool vote(int voter, int rank, string name);
void tabulate(void);
bool print_winner(void);
int find_min(void);
bool is_tie(int min);
void eliminate(int min);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: runoff [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX_CANDIDATES)
    {
        printf("Maximum number of candidates is %i\n", MAX_CANDIDATES);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
        candidates[i].eliminated = false;
    }

    voter_count = get_int("Number of voters: ");
    if (voter_count > MAX_VOTERS)
    {
        printf("Maximum number of voters is %i\n", MAX_VOTERS);
        return 3;
    }

    // Keep querying for votes
    for (int i = 0; i < voter_count; i++)
    {

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            // Record vote, unless it's invalid
            if (!vote(i, j, name))
            {
                printf("Invalid vote.\n");
                return 4;
            }
        }

        printf("\n");
    }

    // Keep holding runoffs until winner exists
    while (true)
    {
        // Calculate votes given remaining candidates
        tabulate();

        // Check if election has been won
        bool won = print_winner();
        if (won)
        {
            break;
        }

        // Eliminate last-place candidates
        int min = find_min();
        bool tie = is_tie(min);

        // If tie, everyone wins
        if (tie)
        {
            for (int i = 0; i < candidate_count; i++)
            {
                if (!candidates[i].eliminated)
                {
                    printf("%s\n", candidates[i].name);
                }
            }
            break;
        }

        // Eliminate anyone with minimum number of votes
        eliminate(min);

        // Reset vote counts back to zero
        for (int i = 0; i < candidate_count; i++)
        {
            candidates[i].votes = 0;
        }
    }
    return 0;
}

// Record preference if vote is valid
bool vote(int voter, int rank, string name)
{
    // TODO  int preferences[i][j]. i=voter, j-th preference for voter i.
    // looking for candidate index by name
    for (int c = 0; c < candidate_count; c++)
    {
        if (strcmp(name, candidates[c].name) == 0)
        {
            preferences[voter][rank] = c;
            //store the index of candidate
            return true;
        }
    }
    return false;
}

// Tabulate votes for non-eliminated candidates
void tabulate(void)
{
    // clear candidates ranks
    for (int c = 0; c < candidate_count; c++)
    {
        candidates[c].votes = 0;
    }
    
    // update cadidates ranks
    // itterate by voters
    for (int v = 0; v < voter_count; v++)
    {
        // itterate by ranks to the first not eliminated candidate
        for (int r = 0; r < candidate_count; r++)
        {
            if (candidates[preferences[v][r]].eliminated == false)
            {
                candidates[preferences[v][r]].votes++;
                break; // get out of r cycle
            }
        }
    }
    return;
}


// Print the winner of the election, if there is one
// If any candidate has more than half of the vote, their name should be printed and the function should return true
bool print_winner(void)
{
    for (int c = 0; c < candidate_count; c++)
    {
        if (candidates[c].eliminated == false && candidates[c].votes > voter_count / 2)
        {
            printf("%s\n", candidates[c].name);
            return true;
        }
    }
    return false;
}


// Return the minimum number of votes any remaining candidate has
int find_min(void)
{
    int min = voter_count;
    for (int c = 0; c < candidate_count; c++)
    {
        if (candidates[c].eliminated == false && min > candidates[c].votes)
        {
            min = candidates[c].votes;
        }
    }
    return min;
}

// Return true if the election is tied between all remaining candidates, false otherwise
bool is_tie(int min)
{
    for (int c = 0; c < candidate_count; c++)
    {
        if (candidates[c].eliminated == false && candidates[c].votes > min)
        {
            return false;
        }
    }
    return true;
    
    
    /*
    int min = voter_count;
    int max = 0;
    for (int c = 0; c < candidate_count; c++)
    {
        if(candidates[c].eliminated == false)
        {
            if(candidates[c].votes < min)
            {
                min = candidates[c].votes;
            }
            if(candidates[c].votes > max)
            {
                max = candidates[c].votes;
            }
        }
    }
    if(min == max)
    {
        return true;
    }
    return false;
    */
}

// Eliminate the candidate (or candidates) in last place
void eliminate(int min)
{
    for (int c = 0; c < candidate_count; c++)
    {
        if (candidates[c].eliminated == false && candidates[c].votes == min)
        {
            candidates[c].eliminated = true;
        }
    }
    return;
}
