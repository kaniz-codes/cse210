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
    bool completed = false;
};

int main()
{
    int n = 0;
    cout << "Enter the number of processes: ";
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

    vector<task> tasks;
    for (int i = 0; i < n; i++)
    {
        tasks.push_back({process_id[i], c_time[i], a_time[i], 0, 0, false});
    }

    int time_frame = 0;
    int completed_tasks = 0;

    while (completed_tasks < n)
    {
        int id = -1;
        int min_ctime = 1000000000;

        for (int i = 0; i < n; i++)
        {
            if (!tasks[i].completed && tasks[i].a_time <= time_frame)
            {
                if (tasks[i].c_time < min_ctime)
                {
                    min_ctime = tasks[i].c_time;
                    id = i;
                }
                else if (tasks[i].c_time == min_ctime)
                {
                    if (tasks[i].a_time < tasks[id].a_time)
                    {
                        id = i;
                    }
                }
            }
        }

        if (id != -1)
        {
            tasks[id].w_time = time_frame - tasks[id].a_time;
            if (tasks[id].w_time < 0)
                tasks[id].w_time = 0;

            time_frame += tasks[id].c_time;
            tasks[id].t_time = time_frame - tasks[id].a_time;
            tasks[id].completed = true;
            completed_tasks++;
        }
        else
        {
            // No process has arrived yet — CPU is idle
            time_frame++;
        }
    }

    // Sort back by process ID for display
    sort(tasks.begin(), tasks.end(), [](const task &a, const task &b)
         { return a.process_id < b.process_id; });

    float sum_w_time = 0, sum_t_time = 0;

    for (const auto &t : tasks)
    {
        cout << "Process " << t.process_id << ": ";
        cout << "Waiting Time: " << t.w_time << " | ";
        cout << "Turnaround Time: " << t.t_time << endl;

        sum_w_time += t.w_time;
        sum_t_time += t.t_time;
    }

    cout << endl;
    cout << "Average Waiting Time: " << (sum_w_time / n) << endl;
    cout << "Average Turnaround Time: " << (sum_t_time / n) << endl;

    return 0;
}
