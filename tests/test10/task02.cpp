#include <iostream>
#include <vector>
#include <unordered_map>
#include <climits>
using namespace std;

int v, e, k;
vector<pair<int, int>> g[100];
vector<bool> visited;
unordered_map<long long, int> frequencies;

void DFS(int current, int length, long long cost)
{
    if (length == k)
    {
        frequencies[cost]++;

        return;
    }

    visited[current] = true;

    for (size_t i = 0; i < g[current].size(); i++)
    {
        int next = g[current][i].first;
        int weight = g[current][i].second;

        if (visited[next] == false)
            DFS(next, length + 1, cost + weight);
    }

    visited[current] = false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> v >> e;

    visited.resize(v);

    int a, b, c;

    for (int i = 0; i < e; i++)
    {
        cin >> a >> b >> c;

        g[a - 1].push_back({ b - 1,c });
    }

    cin >> k;

    for (int i = 0; i < v; i++)
        DFS(i, 0, 0);

    int result = INT_MIN, max_frequency = INT_MIN;

    for (const auto& path : frequencies)
    {
        int current_length = path.first;
        int current_frequency = path.second;

        if (current_frequency > max_frequency || (current_frequency == max_frequency && current_length > result))
        {
            max_frequency = current_frequency;
            result = current_length;
        }
    }

    if (result == INT_MIN)
    {
        cout << -1 << '\n';

        return 0;
    }

    cout << result << '\n';
}