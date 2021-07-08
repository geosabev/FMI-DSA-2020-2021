#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <climits>
using namespace std;

int main() {
    int N;
    vector<int> numbers;
    vector<int>::iterator it;

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        int num;

        cin >> num;

        numbers.push_back(num);
    }

    for (int i = 1; i < INT_MAX; i++)
    {
        it = find(numbers.begin(), numbers.end(), i);

        if (it == numbers.end())
        {
            cout << i;
            break;
        }
    }

    return 0;
}
