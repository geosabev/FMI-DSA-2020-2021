#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int n;
double median = 0;
priority_queue<double> smaller;
priority_queue<double, vector<double>, greater<double>> bigger;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cout << fixed << showpoint << setprecision(1);

    cin >> n;

    double input;

    for (int i = 0; i < n; i++)
    {
        cin >> input;

        if (smaller.size() > bigger.size())
        {
            if (input < median)
            {
                bigger.push(smaller.top());

                smaller.pop();
                smaller.push(input);
            }
            else
                bigger.push(input);

            median = (smaller.top() + bigger.top()) / 2.0;
        }
        else if (smaller.size() == bigger.size())
        {
            if (input > median)
            {
                bigger.push(input);

                median = bigger.top();
            }
            else
            {
                smaller.push(input);

                median = smaller.top();
            }
        }
        else
        {
            if (input > median)
            {
                smaller.push(bigger.top());

                bigger.pop();

                bigger.push(input);
            }
            else
                smaller.push(input);

            median = (smaller.top() + bigger.top()) / 2.0;
        }

        cout << median << '\n';
    }
}