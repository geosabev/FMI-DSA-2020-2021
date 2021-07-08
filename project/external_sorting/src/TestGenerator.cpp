#include <iostream>
#include <fstream>
#include <random>
#include <string>
using namespace std;

void createTest()
{
    string name;

    int amount;

    cout << "Input filename and amount of integers to generate: ";

    cin >> name >> amount;

    random_device device;
    mt19937 generator(device());
    uniform_int_distribution<int> distribution(INT_MIN, INT_MAX);

    ofstream output;

    output.open(name + ".txt");

    while (amount)
    {
        output << distribution(generator) << '\n';

        amount--;
    }

    output.close();
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    createTest();

    return 0;
}