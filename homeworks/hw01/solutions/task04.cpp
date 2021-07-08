#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> extract_digits(long long int number)
{
    vector<int> result;

    while (number != 0)
    {
        result.push_back(number % 10);

        number = number / 10;
    }

    reverse(result.begin(), result.end());

    return result;
}

long long int calculate_combinations(int choices, int positions)
{
    long long int result = 1;

    for (int i = choices - positions + 1; i <= choices; i++)
        result *= i;

    return result;
}

long long int count_unique(long long int upper_bound)
{
    if (upper_bound == 0)
        return 0;
    else if (upper_bound > 9876543210)
        return count_unique(9876543210);

    long long int result = 0;

    vector<int> digits = extract_digits(upper_bound);
    vector<bool> status(10, false);

    size_t digits_count = digits.size();

    for (size_t i = 1; i < digits_count; i++)
        result = result + (9 * calculate_combinations(9, i - 1));

    result = result + ((digits[0] - 1) * calculate_combinations(9, digits_count - 1));

    size_t idx = 0;

    for (idx = 0; idx < digits_count - 1; idx++)
    {
        int current_digit = digits[idx];

        if (status[current_digit] == true)
            break;

        status[current_digit] = true;

        for (int j = 0; j < digits[idx + 1]; j++)
        {
            if (status[j] == false)
                result = result + (calculate_combinations(8 - idx, digits_count - idx - 2));
        }
    }

    if (idx == digits_count - 1 && status[digits[idx]] == false)
        result++;

    return result;
}

int main()
{
    long long int A, B;

    cin >> A >> B;

    cout << count_unique(B) - count_unique(A - 1);
}