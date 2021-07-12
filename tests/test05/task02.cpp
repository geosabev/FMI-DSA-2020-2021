#include <iostream>
#include <stack>
#include <queue>
#include <deque>
#include <vector>
#include <string>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    int sum = 0;
    int input;

    cin >> n;

    stack<int> num;
    stack<int> keep;
    stack<int> to_redo;

    for (int i = 0; i < n; i++)
    {
        cin >> input;

        if (input == -1)
        {
            if (num.empty() == false)
            {
                to_redo.push(num.top());

                sum = sum - num.top();

                num.pop();
            }
        }
        else if (input == -2)
        {
            if (to_redo.empty() == false)
            {
                num.push(to_redo.top());

                sum = sum + to_redo.top();

                to_redo.pop();
            }
        }
        else
        {
            num.push(input);
            sum = sum + input;
        }
    }

    cout << sum;
}