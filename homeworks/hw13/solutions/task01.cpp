#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int rows, cols, to_visit, result = 0, start_r = 0, start_c = 0, end_r = 0, end_c = 0;
vector<pair<int, int>> directions = { {0,-1},{1,0},{0,1},{-1,0} };
vector<vector<char>> maze;
vector<vector<bool>> visited;

int arr1[] = { 0,1,0,-1 };
int arr2[] = { -1,0,1,0 };
int n;

bool is_valid(int i, int j)
{
    if (i < 0 || j < 0 || i >= rows || j >= cols)
        return false;

    if (maze[i][j] == 'x' || visited[i][j])
        return false;

    return true;
}

void backtrack(int current_x, int current_y, int visited_count)
{
    if (maze[current_x][current_y] == 'e' && visited_count == to_visit)
    {
        result++;

        return;
    }

    for (int i = 0; i < 4; i++)
    {
        int neighbor_x = current_x + directions[i].first;
        int neighbor_y = current_y + directions[i].second;

        if (is_valid(neighbor_x, neighbor_y))
        {
            visited[neighbor_x][neighbor_y] = true;

            backtrack(neighbor_x, neighbor_y, visited_count + 1);

            visited[neighbor_x][neighbor_y] = false;
        }
    }

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> rows >> cols;

    maze.resize(rows);
    visited.resize(rows);

    for (int i = 0; i < rows; i++)
    {
        maze[i].resize(cols);
        visited[i].resize(cols);
    }

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cin >> maze[i][j];

            if (maze[i][j] == 's')
            {
                start_r = i;
                start_c = j;
            }
            else if (maze[i][j] == 'e')
            {
                end_r = i;
                end_c = j;

                to_visit++;
            }
            else if (maze[i][j] == '-')
                to_visit++;
        }
    }

    visited[start_r][start_c] = true;

    backtrack(start_r, start_c, 0);

    cout << result << '\n';

    return 0;
}