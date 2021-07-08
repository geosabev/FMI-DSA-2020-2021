#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

int P, N;
vector<long long int> numbers;
long long int counter = 1;
long long int result = 1;

long long int calculate_food_amount(long long int index, long long int l, long long int r)
{
    if (r > l)
    {
        long long int mid_1 = (l + (r - l) / 3) + 1;
        long long int mid_2 = (r - (r - l) / 3) - 1;

        if (index >= mid_1 && index <= mid_2)
        {
            result = counter;
            counter = 1;

            return result;
        }

        if (index < mid_1)
        {
            counter++;
            return calculate_food_amount(index, l, mid_1 - 1);
        }
        else
        {
            counter++;
            return calculate_food_amount(index, mid_2 + 1, r);
        }
    }

    result = counter;
    counter = 1;

    return result;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> P >> N;

    numbers.resize(N);

    for (int i = 0; i < N; i++)
        cin >> numbers[i];

    for (int i = 0; i < N; i++)
        cout << calculate_food_amount(numbers[i], 1, (long long int)pow(3, P)) << endl;

}