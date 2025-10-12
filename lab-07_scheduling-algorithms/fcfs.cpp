#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct task
{
    int process_id;
    int c_time;
    int a_time;
    int w_time;
    int t_time;
};

bool sortByArrival(const task &p1, const task &p2)
{
    return p1.a_time < p2.a_time;
}

bool sortByID(const task &p1, const task &p2)
{
    return p1.process_id < p2.process_id;
}

int main()
{
    int n = 0;
    cout << "Enter the number of process: ";
    cin >> n;
    cout << endl;

    int process_id[n] = {0};
    int c_time[n] = {0};
    int a_time[n] = {0};

    cout << "Enter the CPU times" << endl;
    for (int i = 0; i < n; i++)
    {
        process_id[i] = i + 1;
        cin >> c_time[i];
    }

    cout << endl;
    cout << "Enter the arrival times" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> a_time[i];
    }

    cout << endl;

    vector<task> tasks = {};
    for (int i = 0; i < n; i++)
        tasks.push_back({process_id[i], c_time[i], a_time[i]});

    sort(tasks.begin(), tasks.end(), sortByArrival);

    int time_frame = 0;
    for (int i = 0; i < n; i++)
    {
        if (time_frame < tasks[i].a_time)
            time_frame = tasks[i].a_time; // Handle idle time

        time_frame += tasks[i].c_time;
        tasks[i].t_time = time_frame - tasks[i].a_time;

        if (i == 0)
            tasks[i].w_time = 0;
        else
            tasks[i].w_time = tasks[i].t_time - tasks[i].c_time;
    }

    sort(tasks.begin(), tasks.end(), sortByID);

    float avg_w_time = 0.0;
    float avg_t_time = 0.0;

    float sum_w_time = 0.0;
    float sum_t_time = 0.0;

    for (int i = 0; i < n; i++)
    {
        cout << "Process " << tasks[i].process_id << ": ";
        cout << "Waiting Time: " << tasks[i].w_time << " | ";
        cout << "Turnaround Time: " << tasks[i].t_time << endl;

        sum_w_time += tasks[i].w_time;
        sum_t_time += tasks[i].t_time;
    }

    cout << endl;

    avg_w_time = sum_w_time / (float)n;
    avg_t_time = sum_t_time / (float)n;

    cout << "Average Waiting Time: " << avg_w_time << endl;
    cout << "Average Turnaround Time: " << avg_t_time;
    return 0;
}
