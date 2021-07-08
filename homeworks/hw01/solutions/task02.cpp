#include <iostream>
#include <string>
#include <cmath>
using namespace std;

bool is_even(unsigned int n) {
    return ((n % 2) == 0);
}

int main() {
    int N;
    string people;

    int max_distance = 0;
    int current_distance = 0;
    int free_spots = 0;
    int latest_person = 0;

    bool started_free = false;

    cin >> N;
    cin >> people;

    for (unsigned int i = 0; i < N; i++)
    {
        if (i == 0 && people[i] == '-')
            started_free = true;

        if (people[i] == 'x')
        {
            if (started_free == true && free_spots == current_distance)
                max_distance = current_distance - 1;

            int middle = floor(current_distance / 2);

            if (is_even(current_distance) && current_distance != 0)
                middle--;

            if (middle > max_distance)
                max_distance = middle;

            current_distance = 0;

            latest_person = i;

            continue;
        }

        free_spots++;

        current_distance++;
    }

    if (free_spots == 0)
        max_distance = -1;
    else if ((current_distance == free_spots) && (current_distance > max_distance))
        max_distance = current_distance - 1;

    cout << max_distance;
}