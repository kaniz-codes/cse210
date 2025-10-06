#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct task
{
    int process_id;
    int cpu_time;
    int a_time;
    int w_time;
    int t_time;
    int c_time;
};

bool sortByArrival(const task &p1, const task &p2)
{
    return p1.a_time < p2.a_time;
}

bool sortByProcessID(const task &p1, const task &p2)
{
    return p1.process_id < p2.process_id;
}

int main()
{
    int n=0;
    cout << "Enter the number of process: ";
    cin >> n;
    
    int process_id[n]={0};
    int cpu_time[n]={0};
    int a_time[n]={0};
    cout<< endl;

    cout << "Enter the CPU times: "<< endl;
    for(int i=0; i<n; i++)
    {
        process_id[i]= i+1;
        cin>> cpu_time[i];
    }

    cout<< endl;

    cout<<"Enter arrival times: "<< endl;
    for(int i=0; i<n; i++)
    {
        cin>> a_time[i];
    }
    cout<<endl;

    vector<task> task={};
    for(int i= 0; i<n; i++)
    {
        tasks.push_back({process_id[i], cpu_time[i], a_time[i]});
    }

    sort(tasks.begin(), tasks.end(), sortByArrival);

    int time_frame=0;
    for(int i=0; i<n; i++)
    {
        time_frame += tasks[i].cpu_time;
        tasks[i].t_time= time_frame - tasks[i].cpu_time;

        if(i==0) 
        {
            tasks[i].w_time=0;
        }
        else
        {
            task[i].w_time= tasks[i].t_time - tasks[i].cpu_time;
        }

        sort(tasks.begin(), tasks.end(), sortByProcessID);

        float avg_w_time=0.0;
        float avg_t_time=0.0;

        float sum_w_time= 0.0;
        float sum_t_time= 0.0;

        for(int i=0; i<n; i++)
        {
            cout<< "Process "<< task[i].process_id<< ": "<< "Waiting time: "<< task[i].w_time<<"Turnarround time: "<< task[i].t_time<<endl;
        }

        cout<<endl;

        avg_w_time= sum_w_time/(float)n;
        avg_t_time= sum_t_time/(float)n;

        cout<<"Average waiting time: "<<avg_w_time<<endl;
        cout<<"Average turnarround timeL: "<<avg_t_time<<endl;
        return 0;

    }
}