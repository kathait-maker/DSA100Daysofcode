/*Problem Statement
Using DFS or BFS, count number of connected components.

Input Format
n m
edges

Output Format
Number of connected components.

Sample Input
6 3
1 2
2 3
5 6

Sample Output
3

Explanation
Components: {1,2,3}, {4}, {5,6}*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Adjacency list
int adj[MAX][MAX];
int visited[MAX];
int n;

// DFS function
void dfs(int node)
{
    int i;

    // Mark current node as visited
    visited[node] = 1;

    // Visit all adjacent nodes
    for(i = 1; i <= n; i++)
    {
        if(adj[node][i] == 1 && visited[i] == 0)
        {
            dfs(i);
        }
    }
}

int main()
{
    int m, i;
    int u, v;
    int components = 0;

    // Input number of vertices and edges
    printf("Enter number of vertices and edges:\n");
    scanf("%d %d", &n, &m);

    // Initialize adjacency matrix
    for(i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            adj[i][j] = 0;
        }
        visited[i] = 0;
    }

    // Input edges
    printf("Enter edges:\n");
    for(i = 0; i < m; i++)
    {
        scanf("%d %d", &u, &v);

        adj[u][v] = 1;
        adj[v][u] = 1; // Undirected graph
    }

    // Count components
    for(i = 1; i <= n; i++)
    {
        if(visited[i] == 0)
        {
            dfs(i);
            components++;
        }
    }

    // Output result
    printf("Number of connected components: %d\n", components);

    return 0;
}
