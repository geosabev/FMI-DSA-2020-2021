#include <iostream>
#include <vector>
#include <climits>
using namespace std;

vector<long long> arr_t;

long long update_amounts(long long time, long long to_achieve)
{
    long long result = 0;

    for (size_t i = 0; i < arr_t.size(); i++)
    {
        result = result + (time / arr_t[i]);

        if (result > to_achieve)
            break;
    }


    return result;
}

long long find_optimal(long long needed)
{
    long long l = 1, r = LLONG_MAX;

    long long best_solution = LLONG_MAX;

    long long sum = 0;

    while (l <= r)
    {
        long long m = l + (r - l) / 2;

        sum = update_amounts(m, needed);

        if (sum >= needed)
        {
            if (m < best_solution)
                best_solution = m;

            r = m - 1;
        }
        else
            l = m + 1;
    }

    return best_solution;
}

int main()
{
    long long n;
    long long k;

    cin >> n >> k;

    arr_t.resize(k);

    for (long long i = 0; i < k; i++)
        cin >> arr_t[i];

    cout << find_optimal(n) << endl;
}