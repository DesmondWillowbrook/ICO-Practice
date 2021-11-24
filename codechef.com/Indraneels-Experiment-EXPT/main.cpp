/*
* Problem is to find successive differences
* Then find common substring and print the numbers asssociated with them.
* => 2(N^2) memory usage (as difference changes based on which numbers are selected)
* O(N^2) for calculating successive differences
* O(N^2) for finding longest common subsequence
* (There is algorithm for finding it in O N log N time, but DP sol should suffice)
*/

#include<bits/stdc++.h>

using namespace std;

size_t N;

int* get_diff (int* arr, int pt_a, int pt_b) {
    if (pt_a > pt_b) swap (pt_a, pt_b);
    return (arr + ((pt_b * (pt_b - 1)) / 2) + pt_a);
}

#ifdef DEBUG
const uint space_len = 4;

template <typename T>
T uniform_spacing_print (T n) {
    for (int len = space_len - to_string(n).length(); len > 0; len--) cout << " ";
    return n;
}
#endif

int main () {
    cin >> N;
    int seq_a[N], seq_b[N];
    for (size_t i = 0; i < N; i++) cin >> seq_a[i];
    for (size_t i = 0; i < N; i++) cin >> seq_b[i];

    // diff_a stores for index X = {0...N}, the difference between [X] and { [0]...[X-1] }
    int diff[N*(N-1)/2];
    for (size_t i = 0; i < N; i++)
        for (size_t j = i + 1; j < N; j++) {
            *get_diff(diff, i, j) = abs(seq_a[i] - seq_b[j]);
        }
    
    /*
    From any two points on list A, B: a0, b0
    There atmost (N - a0) * (N - b0) paths to the next point: a1, b1, ... aN bN
    We can minimize this by asserting that there is a unique/optimal point for x, y, z.

    a2, b2 are defined as: the minimum index greater than a1, b1 to satisfy: [a1] - [b1] == [a2] - [b2]

    With this approach, we have figured out all potential subsequences we can form.
    Now how do we find longest one?

    Our paths are stored something like: (a1, b1) -> (a2, b2)
    Eg: (a1, b1) -> (a2, b2), (a3, b3) -> (a4, b4), etc.

    This is now problem of finding longest increasing subsequence (where a2 > a1 AND b2 > b1)
    */
}