#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <climits>
#include <vector>
using namespace std;

long long n, k, q;
vector<vector<long long>> points;

long long distance(const vector<long long>& point1, const vector<long long>& point2)
{
    long long result = 0;

    for (long long i = 0; i < k; i++)
        result += (point1[i] - point2[i]) * (point1[i] - point2[i]);

    return result;
}

struct point_comparator
{
    long long dimension;

    point_comparator(long long dimension = 0) : dimension(dimension) {}

    bool operator()(const vector<long long>& point1, const vector<long long>& point2)
    {
        return (point1[dimension] < point2[dimension]);
    }
};

struct Node
{
    vector<long long> point;

    long long axis;

    Node* left;
    Node* right;

    Node(const vector<long long>& point)
    {
        this->point = point;

        this->axis = 0;

        this->left = nullptr;
        this->right = nullptr;
    }
};

class KD_Tree
{
public:
    KD_Tree(vector<vector<long long>> p, long long d)
    {
        this->k = d;

        this->root = build(p, 0, p.size() - 1, 0);
    }

    double closest_point(const vector<long long>& p)
    {
        return (sqrt(this->nearest_neighbour(this->root, p)));
    }

private:
    long long k;
    Node* root;

    Node* build(vector<vector<long long>>& points, long long from, long long to, long long axis)
    {
        if (from > to)
            return nullptr;

        long long mid = (from + to) / 2;

        nth_element(points.begin() + from, points.begin() + mid, points.begin() + to + 1, point_comparator(axis));

        Node* node = new Node(points[mid]);

        node->axis = axis;

        node->left = build(points, from, mid - 1, (axis + 1) % k);
        node->right = build(points, mid + 1, to, (axis + 1) % k);

        return node;
    }

    long long nearest_neighbour(Node* node, const vector<long long>& p)
    {
        if (node == nullptr)
            return LLONG_MAX;

        long long result = distance(node->point, p);

        if (node->point[node->axis] <= p[node->axis])
        {
            result = min(result, nearest_neighbour(node->right, p));

            if (node->left && p[node->axis] - sqrt(result) <= node->point[node->axis])
                result = min(result, nearest_neighbour(node->left, p));
        }
        else
        {
            result = min(result, nearest_neighbour(node->left, p));

            if (node->right && p[node->axis] + sqrt(result) >= node->point[node->axis])
                result = min(result, nearest_neighbour(node->right, p));
        }

        return result;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> k;

    points.resize(n);

    for (long long i = 0; i < n; i++)
    {
        vector<long long> point(k);

        for (long long j = 0; j < k; j++)
            cin >> point[j];

        points[i] = point;
    }

    KD_Tree tree(points, k);

    cin >> q;

    cout << fixed << setprecision(3);

    for (long long i = 0; i < q; i++)
    {
        vector<long long> point(k);

        for (long long j = 0; j < k; j++)
            cin >> point[j];

        cout << tree.closest_point(point) << '\n';
    }
}