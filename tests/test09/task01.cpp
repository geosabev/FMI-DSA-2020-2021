#include <iostream>
#include <vector>
using namespace std;

vector<vector<bool>> g;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int m, n, q, city, city2;

    cin >> m;

    g.resize(m);

    for (int i = 0; i < m; i++)
        g[i].resize(m);

    for (int i = 0; i < m; i++)
    {
        cin >> n;

        for (int j = 0; j < n; j++)
        {
            cin >> city;

            g[i][city] = true;
            g[city][i] = true;
        }
    }

    vector<int> result;

    bool exists = true;

    cin >> q;

    for (int i = 0; i < q; i++)
    {
        cin >> n;

        vector<int> path;

        for (int j = 0; j < n; j++)
        {
            cin >> city;

            path.push_back(city);
        }

        for (int i = 0; i < n - 1; i++)
        {
            if (g[path[i]][path[i + 1]] == false)
            {
                exists = false;

                break;
            }
        }

        if (exists)
            result.push_back(1);
        else
            result.push_back(0);

        exists = true;
    }

    for (int i = 0; i < result.size(); i++)
        cout << result[i] << " ";
}