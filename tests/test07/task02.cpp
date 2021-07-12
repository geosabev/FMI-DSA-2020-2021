#include <iostream>
#include <queue>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;

    priority_queue<int> pq;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int num;

        cin >> num;

        if (num == -1 && pq.empty() == false)
        {
            cout << pq.top() << ' ';

            pq.pop();
        }
        else
        {
            if (num != -1)
                pq.push(num);
        }
    }
}