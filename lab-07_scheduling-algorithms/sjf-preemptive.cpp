#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct task
{
    int process_id;
    int c_time;
    int a_time;
    int remaining_time;
    int w_time = 0;
    int t_time = 0;
    int completion_time = 0;
    bool is_started = false;
};

int main()
{
    int n;
    cout << "Enter the number of processes: ";
    cin >> n;

    int process_id[n], c_time[n], a_time[n];

    cout << "Enter the CPU times" << endl;
    for (int i = 0; i < n; i++)
    {
        process_id[i] = i + 1;
        cin >> c_time[i];
    }

    cout << "Enter the arrival times" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> a_time[i];
    }

    vector<task> tasks;
    for (int i = 0; i < n; i++)
    {
        tasks.push_back({process_id[i], c_time[i], a_time[i], c_time[i]});
    }

    int time_frame = 0;
    int completed = 0;
    int last_id = -1;

    while (completed < n)
    {
        int id = -1;
        int min_remaining = 1e9;

        for (int i = 0; i < n; i++)
        {
            if (tasks[i].a_time <= time_frame && tasks[i].remaining_time > 0)
            {
                if (tasks[i].remaining_time < min_remaining)
                {
                    min_remaining = tasks[i].remaining_time;
                    id = i;
                }
                else if (tasks[i].remaining_time == min_remaining)
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

            if (!tasks[id].is_started)
            {
                tasks[id].is_started = true;
            }

            tasks[id].remaining_time--;
            time_frame++;

            if (tasks[id].remaining_time == 0)
            {
                tasks[id].completion_time = time_frame;
                tasks[id].t_time = tasks[id].completion_time - tasks[id].a_time;
                tasks[id].w_time = tasks[id].t_time - tasks[id].c_time;
                completed++;
            }
        }
        else
        {

            time_frame++;
        }
    }

    sort(tasks.begin(), tasks.end(), [](const task &a, const task &b)
         { return a.process_id < b.process_id; });

    float total_w_time = 0, total_t_time = 0;

    for (const auto &t : tasks)
    {
        cout << "Process " << t.process_id << ": ";
        cout << "Waiting Time: " << t.w_time << " | ";
        cout << "Turnaround Time: " << t.t_time << endl;

        total_w_time += t.w_time;
        total_t_time += t.t_time;
    }

    cout << "\nAverage Waiting Time: " << (total_w_time / n) << endl;
    cout << "Average Turnaround Time: " << (total_t_time / n) << endl;

    return 0;
}
