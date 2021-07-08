#include <iostream>
#include <queue>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    long long needed, today, sum = 0;
    queue<long long> daily_benefit;

    cin >> N >> needed;

    for (int i = 0; i < N; i++)
    {
        cin >> today;

        if (sum < needed)
        {
            daily_benefit.push(today);
            sum += today;
        }
    }

    if (sum < needed && daily_benefit.size() == N)
    {
        cout << -1;
        return 0;
    }

    while (sum - daily_benefit.front() > needed)
        daily_benefit.pop();

    cout << daily_benefit.size();
}