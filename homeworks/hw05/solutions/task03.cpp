#include <iostream>
#include <stack>
#include <cmath>
using namespace std;

long long weight(long long truck)
{
    return (int)fabs(truck);
}

bool in_same_direction(long long old_truck, long long new_truck)
{
    return (old_truck != new_truck && ((old_truck < 0 && new_truck < 0) || (old_truck > 0 && new_truck > 0)));
}

bool crash(long long old_truck, long long new_truck)
{
    if ((old_truck > 0 && new_truck < 0))
        return true;

    return false;
}

int main()
{
    int N;
    long long new_truck;

    bool add = true;

    stack<long long> trucks;

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> new_truck;

        if (trucks.empty())
            trucks.push(new_truck);
        else if (in_same_direction(trucks.top(), new_truck))
            trucks.push(new_truck);
        else if (crash(trucks.top(), new_truck))
        {
            while (crash(trucks.top(), new_truck))
            {
                if (weight(trucks.top()) > weight(new_truck))
                {
                    add = false;

                    break;
                }
                else if (weight(trucks.top()) == weight(new_truck))
                {
                    trucks.pop();

                    add = false;

                    break;
                }
                else
                {
                    add = true;

                    trucks.pop();
                }

                if (trucks.empty())
                    break;
            }

            if (add)
                trucks.push(new_truck);
        }
        else
            trucks.push(new_truck);
    }

    if (trucks.empty())
        cout << '\n';
    else
    {
        stack<long long> to_print;

        while (trucks.empty() == false)
        {
            to_print.push(trucks.top());
            trucks.pop();
        }

        while (to_print.empty() == false)
        {
            cout << to_print.top() << ' ';
            to_print.pop();
        }
    }
}