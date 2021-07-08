#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Interval
{
    int start, end;
};

bool compare_intervals(const Interval& left, const Interval& right)
{
    if (left.start == right.start)
        return (left.end > right.end);

    return (left.start < right.start);
}

bool fully_overlaps(const Interval& container, const Interval& to_check)
{
    return ((to_check.start >= container.start && to_check.start <= container.end)
        && (to_check.end <= container.end && to_check.end >= container.start));
}

int main()
{
    int N;

    cin >> N;

    vector<Interval> input;
    vector<Interval> trusted;

    Interval to_add;

    int start, end;

    for (int i = 0; i < N; i++)
    {
        cin >> start >> end;

        to_add.start = start;
        to_add.end = end;

        input.push_back(to_add);
    }

    sort(input.begin(), input.end(), compare_intervals);

    int amount_not_to_trust = 0;

    trusted.push_back(input[0]);

    for (size_t i = 1; i < input.size(); i++)
    {
        if (fully_overlaps(trusted.back(), input[i]))
            amount_not_to_trust++;
        else
            trusted.push_back(input[i]);
    }

    cout << amount_not_to_trust << endl;
}