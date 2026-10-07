/*
PB1.80 Sorting Student IDs
You work at the university registrar, and you have a vector of n student ID numbers that are
currently in use at the university. To make assigning new student IDs easier, you always keep your
vector of IDs in sorted order. However, a mischievous EECS 281 student hacked into the system
last night and shuffled the order of student IDs in your vector!

Fortunately, the hacker was nice enough to tell you that every ID number in the shuffled vector
is at most d positions away from its correct sorted position, where d is an integer in the range
[1, n). Your goal is to implement a function that can restore the sorted vector of student IDs, given
the value of d.

Complexity: O(n log d) time and O(d) auxiliary space.

Implementation: You may use anything from the STL. Limit: 20 lines of code (points de-
ducted if longer).

Example: Given d = 2 and ids = [2, 1, 3, 5, 7, 4, 6], restore sorted IDs() should
restore ids = [1, 2, 3, 4, 5, 6, 7].
*/

#include <vector>
#include <queue>

using namespace std;

// Make a priority queue, push elements into that pq, if the size exceeds d then write the popped() value of pq to ids (smallest value). Pop at very end till pq is empty
void restore_sorted_IDs(vector<int> &ids, size_t d) {
    priority_queue<int, vector<int>, greater<int>> window;
    size_t write = 0;
    for (size_t i = 0; i < ids.size(); ++i) {
        window.push(ids[i]);
        if (window.size() > d) {
            ids[write++] = window.top();
            window.pop();
        }
    }
    while (!window.empty()) {
        ids[write++] = window.top();
        window.pop();
    }
}