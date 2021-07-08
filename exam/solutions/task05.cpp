#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, k, t, b, to_process = 0;
    priority_queue<int, vector<int>, greater<int>> pq;
    vector<int> result;

    cin >> k >> t >> b;

    to_process = k * b;

    cin >> n;

    int current;

    for (int i = 0; i < n; i++)
    {
        cin >> current;

        pq.push(current);

        if ((i + 1) % t == 0 && b != 0)
        {
            for (int j = 0; j < k; j++)
            {
                result.push_back(pq.top());

                pq.pop();

                to_process--;
            }

            b--;

        }
    }

    if (to_process)
    {
        while (pq.empty() == false && to_process)
        {
            result.push_back(pq.top());
            pq.pop();

            to_process--;
        }
    }

    for (size_t i = 0; i < result.size(); i++)
        cout << result[i] << ' ';

    return 0;
}