#include <bits/stdc++.h>
using namespace std;

int charToIndex(char c)
{
    return c - 'A';
}

bool hasCycle(int totalNodes, int adj[][100], int visited[], int inRecursion[])
{
    for (int u = 0; u < totalNodes; u++)
    {
        if (visited[u] == 0)
        {
            visited[u] = 1;
            inRecursion[u] = 1;

            for (int v = 0; v < totalNodes; v++)
            {
                if (adj[u][v] == 1)
                {
                    if (inRecursion[v] == 1)
                    {
                        return true;
                    }
                    if (visited[v] == 0)
                    {
                        if (hasCycle(totalNodes, adj, visited, inRecursion))
                        {
                            return true;
                        }
                    }
                }
            }
            inRecursion[u] = 0;
        }
    }
    return false;
}

int main()
{
    int edgeCount;
    cout << "Enter number of edges: ";
    cin >> edgeCount;

    int adj[100][100] = {0};
    int visited[100] = {0};
    int inRecursion[100] = {0};

    cout << "Edges:" << endl;
    for (int i = 0; i < edgeCount; i++)
    {
        char srcChar, dstChar;
        cin >> srcChar >> dstChar;
        int srcIdx = charToIndex(srcChar);
        int dstIdx = charToIndex(dstChar);
        adj[srcIdx][dstIdx] = 1;
    }

    if (hasCycle(100, adj, visited, inRecursion))
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }

    return 0;
}
