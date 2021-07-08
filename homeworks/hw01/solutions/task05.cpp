#include <iostream>
#include <vector>
using namespace std;

const unsigned int DIVISOR = 1000000007;

long long int fast_power(long long int base, long long int power)
{
    long long int result = 1;

    while (power > 0)
    {
        if (power % 2 == 1)
            result = (result * base) % DIVISOR;

        base = (base * base) % DIVISOR;

        power = power / 2;
    }

    return result;
}

int main()
{
    int N;
    vector<long long int> input;

    cin >> N;

    input.resize(N);

    for (int i = 0; i < N; i++)
    {
        long long num;

        cin >> num;

        input[i] = num;
    }

    long long int result = 1;

    for (int i = 0; i < N; i++)
        result = ((result * input[i]) % DIVISOR);

    for (int i = 0; i < N; i++)
    {
        long long int modular_inverse = fast_power(input[i], DIVISOR - 2);

        cout << ((result * modular_inverse) % DIVISOR) << " ";
    }
}