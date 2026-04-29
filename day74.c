/*Problem Statement
Given an array of candidate names where each name represents a vote cast for that candidate, determine the candidate who received the maximum number of votes. In case of a tie, return the lexicographically smallest candidate name.

Input Format
First line contains an integer n representing number of votes.
Second line contains n space-separated strings representing candidate names.

Output Format
Print the name of the winning candidate followed by the number of votes received.

Sample Input
13
john johnny jackie johnny john jackie jamie jamie john johnny jamie johnny john

Sample Output
john 4

Explanation
Both john and johnny receive 4 votes, but john is lexicographically smaller, so john is declared the winner.*/

#include <stdio.h>
#include <string.h>

int main()
{
    int n, i, j;
    
    // Read number of votes
    printf("Enter number of votes: ");
    scanf("%d", &n);

    // Array to store votes (candidate names)
    char votes[n][50];

    // Read candidate names
    printf("Enter candidate names:\n");
    for(i = 0; i < n; i++)
    {
        scanf("%s", votes[i]);
    }

    // Array to store unique candidate names
    char candidate[n][50];
    int count[n];

    int unique = 0;

    // Count votes for each candidate
    for(i = 0; i < n; i++)
    {
        int found = 0;

        // Check if candidate already exists
        for(j = 0; j < unique; j++)
        {
            if(strcmp(candidate[j], votes[i]) == 0)
            {
                count[j]++;     // Increase vote count
                found = 1;
                break;
            }
        }

        // If candidate not found, add new candidate
        if(found == 0)
        {
            strcpy(candidate[unique], votes[i]);
            count[unique] = 1;
            unique++;
        }
    }

    // Find candidate with maximum votes
    int max = count[0];
    int index = 0;

    for(i = 1; i < unique; i++)
    {
        // If more votes found
        if(count[i] > max)
        {
            max = count[i];
            index = i;
        }
        // If tie, choose lexicographically smaller name
        else if(count[i] == max)
        {
            if(strcmp(candidate[i], candidate[index]) < 0)
            {
                index = i;
            }
        }
    }

    // Print winner and votes
    printf("%s %d", candidate[index], max);

    return 0;
