#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

struct Test
{
    int time_of_arrival, lines;

    Test(int t = 0, int l = 0)
    {
        this->time_of_arrival = t;
        this->lines = l;
    }
};

struct Compare_Lines
{
    bool operator()(const Test& t1, const Test& t2)
    {
        return (t1.lines > t2.lines);
    }
};

bool compare_tests(const Test& t1, const Test& t2)
{
    return (t1.time_of_arrival < t2.time_of_arrival);
}

int n;
vector<Test> tests;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    long long t, l;

    cin >> n;

    tests.resize(n);

    for (int i = 0; i < n; i++)
    {
        cin >> t >> l;

        tests[i].time_of_arrival = t;
        tests[i].lines = l;
    }

    priority_queue<Test, vector<Test>, Compare_Lines> being_corrected;

    sort(tests.begin(), tests.end(), compare_tests);

    int idx = 0;
    long long current_time = tests[idx].time_of_arrival;
    long long waiting_time = 0;

    while (idx < n || being_corrected.empty() == false)
    {
        if (idx < n)
        {
            while (idx < n && tests[idx].time_of_arrival <= current_time)
            {
                being_corrected.push(tests[idx]);

                idx++;
            }
        }

        if (being_corrected.empty() == false)
        {
            if (being_corrected.top().time_of_arrival <= current_time)
            {
                Test current = being_corrected.top();

                being_corrected.pop();

                current_time += current.lines;

                waiting_time += (current_time - current.time_of_arrival);

                continue;
            }
        }

        current_time++;
    }

    cout << (waiting_time / n) << '\n';
}