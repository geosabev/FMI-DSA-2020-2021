#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Interval
{
    int start, end;
};

bool compare_by_start(const Interval& left, const Interval& right)
{
    return (left.start < right.start);
}

int main()
{
    int N;

    cin >> N;

    vector<Interval> input;

    Interval to_add;

    int start, end;

    for (int i = 0; i < N; i++)
    {
        cin >> start >> end;

        to_add.start = start;
        to_add.end = end;

        input.push_back(to_add);
    }

    sort(input.begin(), input.end(), compare_by_start);

    vector<Interval> result;

    result.push_back(input[0]);

    for (size_t i = 1; i < input.size(); i++)
    {
        Interval latest = result[result.size() - 1];

        if (latest.end < input[i].start)
            result.push_back(input[i]);

        else if (latest.end < input[i].end) {
            latest.end = input[i].end;
            result.pop_back();
            result.push_back(latest);
        }
    }

    for (size_t i = 0; i < result.size(); i++)
        cout << result[i].start << " " << result[i].end << endl;
}