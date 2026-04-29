/*Problem: Using DFS and parent tracking, detect if undirected graph has a cycle.

Output:
- YES or NO*/

#include <stdio.h>

#define MAX 100

int adj[MAX][MAX];
int visited[MAX];
int n;
int cycle = 0;

/* DFS function with parent tracking */
void dfs(int node, int parent)
{
    visited[node] = 1;

    for (int i = 0; i < n; i++)
    {
        if (adj[node][i] == 1)
        {
            if (visited[i] == 0)
            {
                dfs(i, node);
            }
            else if (i != parent)
            {
                cycle = 1;
            }
        }
    }
}

int main()
{
    int edges, u, v;

    /* Input number of vertices */
    scanf("%d", &n);

    /* Input number of edges */
    scanf("%d", &edges);

    /* Initialize adjacency matrix */
    for (int i = 0; i < n; i++)
    {
        visited[i] = 0;
        for (int j = 0; j < n; j++)
        {
            adj[i][j] = 0;
        }
    }

    /* Input edges */
    for (int i = 0; i < edges; i++)
    {
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
        adj[v][u] = 1;   // Undirected graph
    }

    /* Run DFS from node 0 */
    dfs(0, -1);

    /* Output result */
    if (cycle)
        printf("YES");
    else
        printf("NO");

    return 0;
}
