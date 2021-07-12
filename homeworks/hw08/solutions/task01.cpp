#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

bool compare(pair<int, int>& l, pair<int, int>& r)
{
    return (l.first < r.first);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, s, e;
    vector<pair<int, int>> intervals;

    cin >> n;

    intervals.resize(n);

    for (int i = 0; i < n; i++)
    {
        cin >> s >> e;

        intervals[i] = { s,e };
    }

    sort(intervals.begin(), intervals.end(), compare);

    int result = 0;
    priority_queue<int, vector<int>, greater<int>> q;

    for (int i = 0; i < n; i++)
    {
        q.push(intervals[i].second);

        if (intervals[i].first < q.top())
            result++;
        else
            q.pop();
    }

    cout << result << '\n';
}