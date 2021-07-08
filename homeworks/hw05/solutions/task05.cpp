#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Neighbor_Node
{
    int x, y, steps_made;

    Neighbor_Node(int x, int y, int i)
    {
        this->x = x;
        this->y = y;
        this->steps_made = i;
    }
};

vector<vector<char>> maze;
vector<vector<bool>> visited;
int N, M;

int row_change[] = { 0, -1, 0, 1 };
int col_change[] = { 1, 0, -1, 0 };

bool can_visit(int row, int col)
{
    return (maze[row][col] == '.' || maze[row][col] == 'F') && visited[row][col] == false;
}

bool is_wall(char symbol)
{
    return (symbol == '#');
}

bool in_bounds(int row, int column)
{
    return ((row >= 0 && row < N) && (column >= 0 && column < M));
}

void visit(int row, int col, int step, queue<Neighbor_Node>& container)
{
    visited[row][col] = true;

    container.push(Neighbor_Node(row, col, step));
}

int solve(int start_row, int start_column, int end_row, int end_column)
{
    int result = -1;

    visited.resize(N);

    for (int i = 0; i < N; i++)
        visited[i].resize(M);

    queue<Neighbor_Node> steps;

    visit(start_row, start_column, 0, steps);

    while (steps.empty() == false)
    {
        Neighbor_Node front = steps.front();

        steps.pop();

        int r = front.x;
        int c = front.y;
        int count = front.steps_made;

        if (r == end_row && c == end_column)
        {
            result = count;

            break;
        }

        for (int i = 0; i < 4; i++)
        {
            while (is_wall(maze[r + row_change[i]][c + col_change[i]]) == false && in_bounds(r + row_change[i], c + col_change[i]))
            {
                r += row_change[i];
                c += col_change[i];
            }

            if (r != front.x || c != front.y)
            {
                if (visited[r][c] == false)
                    visit(r, c, count + 1, steps);

                r = front.x;
                c = front.y;
                count = front.steps_made;
            }

            if (can_visit(r + row_change[i], c + col_change[i]))
                visit(r + row_change[i], c + col_change[i], count + 1, steps);
        }
    }

    return result;
}

int main()
{
    int start_r = 0, start_c = 0;
    int end_r = 0, end_c = 0;

    cin >> N >> M;

    maze.resize(N);

    for (int i = 0; i < N; i++)
        maze[i].resize(M);

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> maze[i][j];

            if (maze[i][j] == 'S')
            {
                start_r = i;
                start_c = j;
            }
            else if (maze[i][j] == 'F')
            {
                end_r = i;
                end_c = j;
            }
        }
    }

    cout << solve(start_r, start_c, end_r, end_c) << endl;
}