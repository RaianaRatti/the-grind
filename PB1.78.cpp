/*
PB1.78 Warmer Temperatures
You are given a vector of integers, temps, that stores the daily temperature forecasts for the next
few days. Write a program that, for each index of the input vector, stores the number of days you
need to wait for a warmer temperature. If there is no future day where this is possible, a value of
0 should be stored.

Example 1: [55, 62, 46, 52, 51, 50, 51, 53, 63] returns [1, 7, 1, 4, 3, 1, 1, 1, 0], since you would need to wait 1 day on day 0 for a warmer temperature (55 →62), 7 days on
day 1 (62 →63), and so on.

Example 2: [74, 74, 73, 75, 74, 73, 72, 71, 70] returns [3, 2, 1, 0, 0, 0, 0, 0,
0].

Your program should run in O(n) time. You may use extra space to store your output, but the
rest of your program must use O(1) auxiliary space.

Implementation: You may use anything from the STL. Line limit: 20 lines of code.

[55, 62, 46, 52, 51, 50, 51, 53, 63]
[7, -16, 6, -1, -1, 1, 2, 10, 0]
[1, -16 + 17 = 1, 1, -1, -1, 1, 2, 10, 0]

[1, _, 1, _, _, 1, 1, 1, 0]

*/

#include <vector>
#include <queue>
#include <iostream>

using namespace std;

void print_vector(vector<int>& to_print) {
    for (size_t i = 0; i < to_print.size(); ++i) {
        cout << to_print[i];
        if (i < to_print.size() - 1) cout << ", ";
    }
    cout << endl;
}

vector<int> warmer_temperatures(vector<int> &temps) {
    vector<int> result(temps.size(), 0);
    int sum = 0;

    // gets the subtracted values
    for (int i = 0; i < temps.size() - 1; ++i) {
        result[i] = temps[i+1] - temps[i];
        sum += result[i];
    }
    
    int result_thus_far = 0;

    for (int i = 0; i < temps.size() - 1; ++i) {
        if (result[i] > 0) {
            result[i] = 1;
            result_thus_far += result[i];
            continue;
        }

        result_thus_far += result[i];

        result[i] = result[i] + (sum - result_thus_far);

        if (result[i] < 0) {
            result[i] = 0;
        }
    }

    return result;
}

int main() {
    vector<int> given = {55, 62, 46, 52, 51, 50, 51, 53, 63};
    vector<int> result = warmer_temperatures(given);
    
    print_vector(result);
}