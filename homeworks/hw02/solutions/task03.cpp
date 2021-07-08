#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool can_become_palindrome(string input)
{
    size_t length = input.length();

    int odd_count = 0;

    int count_symbols[256] = { 0 };

    for (size_t i = 0; i < length; i++)
        count_symbols[(int)input[i]]++;

    for (int i = 0; i < 256; i++)
    {
        if (odd_count > 1)
            return false;

        if (count_symbols[i] % 2 != 0)
            odd_count++;
    }

    return true;
}

int main()
{
    int N;

    vector<string> input;

    cin >> N;

    string to_check;

    for (int i = 0; i < N; i++)
    {
        cin >> to_check;

        input.push_back(to_check);
    }

    for (size_t i = 0; i < input.size(); i++)
    {
        if (can_become_palindrome(input[i]))
            cout << "TRUE" << endl;
        else
            cout << "FALSE" << endl;
    }
}