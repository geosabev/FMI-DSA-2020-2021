#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <climits>
#include <vector>
#include <stack>
using namespace std;

struct Point
{
    int x, y;

    Point(int x = 0, int y = 0)
    {
        this->x = x;
        this->y = y;
    }
};

size_t n;
vector<Point> input, polygon;
stack<Point> s;

double distance(const Point& p1, const Point& p2)
{
    return sqrt(((p1.x - p2.x) * (p1.x - p2.x)) + ((p1.y - p2.y) * (p1.y - p2.y)));
}

int orientation(const Point& p1, const Point& p2, const Point& p3)
{
    return (((p2.y - p1.y) * (p3.x - p2.x)) - ((p2.x - p1.x) * (p3.y - p2.y)));
}

bool compare_points(const Point& p1, const Point& p2)
{
    int o = orientation(input[0], p1, p2);

    if (o == 0)
        return (distance(input[0], p1) <= distance(input[0], p2));

    return (o < 0);
}

Point second_top(stack<Point> s)
{
    Point temp = s.top();
    s.pop();

    Point result = s.top();
    s.push(temp);

    return result;
}

int bottom_most_index()
{
    size_t result = 0, s = input.size();

    for (size_t i = 0; i < s; i++)
    {
        if ((input[result].y == input[i].y && input[result].x > input[i].x) || input[result].y > input[i].y)
            result = i;
    }

    return result;
}

void generate_convex_hull()
{
    size_t min_index = bottom_most_index(), new_size = 1;

    swap(input[0], input[min_index]);

    sort(input.begin() + 1, input.end(), compare_points);

    for (size_t i = 1; i < n; i++)
    {
        while (i < n - 1 && orientation(input[0], input[i], input[i + 1]) == 0)
            i++;

        input[new_size] = input[i];

        new_size++;
    }

    if (new_size < 3)
        return;

    s.push(input[0]);
    s.push(input[1]);
    s.push(input[2]);

    for (size_t i = 3; i < new_size; i++)
    {
        while (orientation(second_top(s), s.top(), input[i]) >= 0)
            s.pop();

        s.push(input[i]);
    }

    while (s.empty() == false)
    {
        polygon.push_back(s.top());

        s.pop();
    }
}

double calculate_perimeter()
{
    generate_convex_hull();

    size_t s = polygon.size();

    double result = 0;

    result = distance(polygon[0], polygon[s - 1]);

    for (size_t i = 0; i < s - 1; i++)
        result += distance(polygon[i], polygon[i + 1]);

    return result;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;

    input.resize(n);

    for (size_t i = 0; i < n; i++)
        cin >> input[i].x >> input[i].y;

    cout << fixed << setprecision(2);

    cout << calculate_perimeter() << '\n';
}