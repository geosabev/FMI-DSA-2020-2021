#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n;
vector<vector<int>> g;
vector<int> degree, result;
queue<int> q;

void solve()
{
    for (int i = 0; i < n; i++)
    {
        if (degree[i] == 1)
        {
            q.push(i);
        }
    }

    while (q.empty() == false)
    {
        int s = q.size();

        result.clear();

        while (s > 0)
        {
            int current = q.front();

            q.pop();

            result.push_back(current);

            for (size_t i = 0; i < g[current].size(); i++)
            {
                degree[g[current][i]]--;

                if (degree[g[current][i]] == 1)
                    q.push(g[current][i]);
            }

            s--;
        }
    }

    sort(result.begin(), result.end());

    for (size_t i = 0; i < result.size(); i++)
        cout << result[i] << ' ';

    cout << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;

    g.resize(n);
    degree.resize(n, 0);

    int a, b;

    for (int i = 0; i < n - 1; i++)
    {
        cin >> a >> b;

        g[a].push_back(b);
        g[b].push_back(a);

        degree[a]++;
        degree[b]++;
    }

    solve();
}