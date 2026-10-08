/*
PB1.82 Minimal Sorting Window
Given a vector of integers (of size n, n > 1), find the smallest section of the vector such that sorting
that section will make the entire vector sorted (in increasing order). You should display the first
and last indices that need to be sorted (BOTH inclusive, using 0-based indexing). You can assume that your function WILL be called with a vector containing exactly one such section.
For example, given { 1, 2, 5, 7, 3, 6, 4, 8 }, your output should be: Sort from index 2 to index 6

Hint: You can use INT MAX and INT MIN for the largest and smallest values that can fit inside
a variable of type int.

Requirements: Your solution runtime must be no worse than O(n) time. You may use up to
O(1) auxiliary space.

Implementation: Limit: 20 lines of code (points deducted if longer). You may NOT use any
STL algorithms, functions or containers (except the provided vector).
*/

#include <vector>
#include <iostream>

using namespace std;

void find_subarray(const vector<int> &v) {
    int left = 0;
    int right = v.size() - 1;

    while (v[left] < v[left+1]) {
        left = left + 1;
    }
    while (v[right] > v[right-1]) {
        right = right - 1;
    }
    ++left; --right;

    int smallest_index_for_left = left - 1;
    int largest_index_for_right = right + 1;
    while (v[left] < v[left-1]) {
        if (v[left-1] < v[smallest_index_for_left]) {
            smallest_index_for_left = left - 1;
        }
        left = left - 1;
    }
    while (v[right] > v[right+1]) {
        if (v[right+1] > v[largest_index_for_right]) {
            largest_index_for_right = right + 1;
        }
        right = right + 1;
    }

    cout << "Sort from index " << left << " to index " << right << endl;
}

int main() {
    vector<int> test = {1, 2, 5, 7, 3, 6, 4, 8};
    find_subarray(test);
}