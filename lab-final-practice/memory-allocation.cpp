/*======================
Name: Kaniz Fatema
ID: 20245103154
========================*/

#include <iostream>
using namespace std;

void firstfit(int n, int m, int process_size[], int partition_size[])
{
    int fragmentation=0;

    bool allocated[n] = {0};

    for (int i = 0; i < m; i++)
    {
        bool allocated_flag = 0;
        for (int j = 0; j < n; j++)
        {
            if (allocated[j] || process_size[i] > partition_size[j])
                continue;

            cout << "P" << i + 1 << " ->" << j + 1 << endl;
            allocated[j] = 1;
            allocated_flag = 1;
            fragmentation += partition_size[j] - process_size[i];
            break;

        }
        if (!allocated_flag)
        {
            cout << "P" << i + 1 << " -> Not Allocated" << endl;
        }
    }
    cout << endl;
    cout<< "Total internal Fragmentation: "<< fragmentation<<endl;
}

void bestfit(int n, int m, int process_size[], int partition_size[])
{
    int fragmentation = 0;
    bool allocated[n] = {0};

    for (int i = 0; i < m; i++)
    {
        int best_index = -1;
        for (int j = 0; j < n; j++)
        {
            if (!allocated[j] && process_size[i] <= partition_size[j])
            {
                if (best_index == -1 || partition_size[j] < partition_size[best_index])
                {
                    best_index = j;
                }
            }
        }

        if (best_index != -1)
        {
            cout << "P" << i + 1 << " ->" << best_index + 1 << endl;
            allocated[best_index] = 1;
            fragmentation += partition_size[best_index] - process_size[i];
        }
        else
        {
            cout << "P" << i + 1 << " -> Not Allocated" << endl;
        }
    }

    cout << endl;
    cout << "Total internal Fragmentation: " << fragmentation << endl;
}
void worstfit(int n, int m, int process_size[], int partition_size[])
{
    int fragmentation = 0;
    bool allocated[n] = {0};

    for (int i = 0; i < m; i++)
    {
        int worst_index = -1;
        for (int j = 0; j < n; j++)
        {
            if (!allocated[j] && process_size[i] <= partition_size[j])
            {
                if (worst_index == -1 || partition_size[j] > partition_size[worst_index])
                {
                    worst_index = j;
                }
            }
        }

        if (worst_index != -1)
        {
            cout << "P" << i + 1 << " ->" << worst_index + 1 << endl;
            allocated[worst_index] = 1;
            fragmentation += partition_size[worst_index] - process_size[i];
        }
        else
        {
            cout << "P" << i + 1 << " -> Not Allocated" << endl;
        }
    }
    cout << endl;
    cout << "Total Internal Fragmentation: " << fragmentation << endl;
}

int main()
{
    int n, m;

    cin >> n; // number of partitions
    int partition_size[n];
    // sizes of each partition
    for (int i = 0; i < n; i++)
    {
        cin >> partition_size[i];
    }

    // number of processes
    cin >> m;
    int process_size[m];
    // sizes of each process
    for (int i = 0; i < m; i++)
    {
        cin >> process_size[i];
    }
    
    cout << endl;
    cout << "First Fit:";
    cout << endl;
    firstfit(n, m, process_size, partition_size);

    cout << endl;
    cout << "Best Fit:";
    cout << endl;
    bestfit(n, m, process_size, partition_size);

    cout << endl;
    cout << "Worst Fit:";
    cout << endl;
    worstfit(n, m, process_size, partition_size);

    return 0;
}
