#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, m;

    cout << "Enter the number of processes: ";
    cin >> n;
    cout << "Enter the number of resources: ";
    cin >> m;

    vector<vector<int>> maxReq(n, vector<int>(m));
    vector<vector<int>> alloc(n, vector<int>(m));
    vector<int> total(m), available(m);

    // Input maximum resource
    for (int i = 0; i < n; i++)
    {
        cout << "Process " << i + 1 << ":\n";
        for (int j = 0; j < m; j++)
        {
            cout << "Maximum value for resource " << j + 1 << ": ";
            cin >> maxReq[i][j];
        }
    }

    // Input allocated resources
    for (int i = 0; i < n; i++)
    {
        cout << "Process " << i + 1 << ":\n";
        for (int j = 0; j < m; j++)
        {
            cout << "Allocated from resource " << j + 1 << ": ";
            cin >> alloc[i][j];
        }
    }

    // Input TOTAL resources, then derive AVAILABLE = TOTAL - sum(alloc column)
    for (int j = 0; j < m; j++)
    {
        cout << "Enter TOTAL units of resource " << j + 1 << ": ";
        cin >> total[j];
        int used = 0;
        for (int i = 0; i < n; i++)
            used += alloc[i][j];
        available[j] = total[j] - used;
        if (available[j] < 0)
        {
            cout << "Error: allocations exceed total for resource " << j + 1 << ".\n";
            return 0;
        }
    }

    // Calculate need = max - alloc
    vector<vector<int>> need(n, vector<int>(m));
    cout << "Need Matrix:\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            need[i][j] = maxReq[i][j] - alloc[i][j];
            if (need[i][j] < 0)
            {
                cout << "Error: allocation exceeds maximum for P" << i + 1
                     << ", resource " << j + 1 << ".\n";
                return 0;
            }
            cout << need[i][j] << " ";
        }
        cout << "\n";
    }

    // Banker's Algorithm
    vector<int> safeSequence;
    vector<bool> finished(n, false);
    vector<int> work = available;

    while ((int)safeSequence.size() < n)
    {
        bool found = false;
        for (int i = 0; i < n; i++)
        {
            if (!finished[i])
            {
                bool canRun = true;
                for (int j = 0; j < m; j++)
                {
                    if (need[i][j] > work[j])
                    {
                        canRun = false;
                        break;
                    }
                }
                if (canRun)
                {
                    for (int j = 0; j < m; j++)
                        work[j] += alloc[i][j];
                    safeSequence.push_back(i + 1);
                    finished[i] = true;
                    found = true;
                    break;
                }
            }
        }
        if (!found)
        {
            cout << "The system is NOT in a safe state.\n";
            return 0;
        }
    }

    cout << "The system is currently in a SAFE state.\nSafe sequence: < ";
    for (int i = 0; i < n; i++)
    {
        cout << "P" << safeSequence[i];
        if (i != n - 1)
            cout << " ";
    }
    cout << " >\n";
    return 0;
}
