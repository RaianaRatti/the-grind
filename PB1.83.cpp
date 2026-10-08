/*
PB1.83 Minimum of a Rotated Sorted Vector
Suppose you are given a vector of integers that is sorted in ascending order. However, this vector
has been rotated at some pivot unknown to you beforehand. For instance, [1, 2, 3, 4, 5] may
be given to you as [3, 4, 5, 1, 2], where the vector is rotated at 3. You may assume that no
duplicate exists in this vector.

Write a function that finds the minimum element in the vector.

Example: Given [3, 4, 5, 1, 2], you would return 1.

Complexity: O(log n) time, O(1) auxiliary space.

Implementation: You may use anything from the STL. Line limit: 15 lines of code.
*/

#include <vector>

using namespace std;

int find_rotated_minimum(vector<int> &vec) {
    int left = 0;
    int right = vec.size() - 1;

    while (left < right) {
        int mid = left + (right - left) / 2;

        if (vec[mid] > vec[right]) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    return vec[left];
}