#include <iostream>
#include <algorithm>
#include <climits>
#include <vector>
using namespace std;

int n, min_x, max_x, min_y, max_y;
vector<vector<int>> g;
vector<int> areas;
pair<int, int> directions[4] = { {-1,0},{0,1},{1,0},{0,-1} };

bool is_valid(int r, int c)
{
    return ((r >= 0 && r < n) && (c >= 0 && c < n) && g[r][c] == 1);
}

void dfs(int r, int c)
{
    if (r < min_x)
        min_x = r;

    if (r > max_x)
        max_x = r;

    if (c < min_y)
        min_y = c;

    if (c > max_y)
        max_y = c;

    g[r][c] = 0;

    for (int i = 0; i < 4; i++)
    {
        int neighbor_i = r + directions[i].first;
        int neighbor_j = c + directions[i].second;

        if (is_valid(neighbor_i, neighbor_j))
            dfs(neighbor_i, neighbor_j);
    }
}

void solve()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (g[i][j] == 1)
            {
                min_x = INT_MAX;
                max_x = INT_MIN;

                min_y = INT_MAX;
                max_y = INT_MIN;

                dfs(i, j);

                int area = (max_x - min_x + 1) * (max_y - min_y + 1);

                areas.push_back(area);
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;

    g.resize(n);

    for (int i = 0; i < n; i++)
        g[i].resize(n);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> g[i][j];

    solve();

    sort(areas.begin(), areas.end());

    for (int i = areas.size() - 1; i >= 0; i--)
        cout << areas[i] << ' ';
}