/*Problem Statement
Given a string s consisting of lowercase letters, find the first repeated character in the string. A character is considered repeated if it appears more than once, and among all such characters, the one whose second occurrence has the smallest index should be returned.

Input Format
A single string s.

Output Format
Print the first repeated character. If no character is repeated, print -1.

Sample Input
geeksforgeeks

Sample Output
e*/


#include <stdio.h>

int main() {
    char s[1000];
    int freq[26] = {0};
    int i;

    // Input string
    scanf("%s", s);

    for (i = 0; s[i] != '\0'; i++) {
        int index = s[i] - 'a';

        // If already seen, print and exit
        if (freq[index] == 1) {
            printf("%c", s[i]);
            return 0;
        }

        // Mark as seen
        freq[index] = 1;
    }

    // If no repeated character
    printf("-1");

    return 0;
}
