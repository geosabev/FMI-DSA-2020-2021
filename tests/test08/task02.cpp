#include <iostream>
#include <unordered_map>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, id, orders_count = 0;
    unordered_map<int, int> orders;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> id;

        orders_count++;

        if (orders.count(id) == 0)
            orders.insert({ id, 1 });
        else
        {
            orders[id]++;

            if (orders[id] == 10)
            {
                orders.erase(id);
                orders_count -= 10;
            }
        }
    }

    cout << orders.size() << ' ' << orders_count;
}