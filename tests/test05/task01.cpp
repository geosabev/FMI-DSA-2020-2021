#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct Node
{
    int x, y, steps_made, value;

    Node(int x, int y, int i, int v)
    {
        this->x = x;
        this->y = y;
        this->steps_made = i;
        this->value = v;
    }
};

int n, m;
vector<vector<int>> input;
vector<vector<bool>> visited;

int x, y;
int steps;

int row_change[] = { 0, -1, 0, 1 };
int col_change[] = { 1, 0, -1, 0 };

bool in_bounds(int row, int column)
{
    return ((row >= 0 && row < n) && (column >= 0 && column < m));
}

bool can_visit(int row, int column)
{
    return (in_bounds(row, column) && input[row][column] != -1 && visited[row][column] == false);
}

void visit(int row, int col, int step, queue<Node>& container)
{
    visited[row][col] = true;

    container.push(Node(row, col, step, input[row][col]));
}

int solve(int start_row, int start_column, int steps_to_make)
{
    int result = 0;

    visited.resize(n);

    for (int i = 0; i < n; i++)
        visited[i].resize(m);

    queue<Node> steps;

    visit(start_row, start_column, 1, steps);

    while (steps.empty() == false)
    {
        Node front = steps.front();

        int r = front.x;
        int c = front.y;
        int s = front.steps_made;

        if (s == steps_to_make)
            result += front.value;

        steps.pop();

        for (int i = 0; i < 4; i++)
        {
            if (can_visit(r + row_change[i], c + col_change[i]))
                visit(r + row_change[i], c + col_change[i], front.steps_made + 1, steps);

        }
    }

    return result;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;

    input.resize(n);

    for (int i = 0; i < n; i++)
        input[i].resize(m);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> input[i][j];

    cin >> x >> y;

    cin >> steps;

    cout << solve(x - 1, y - 1, steps) << endl;

}