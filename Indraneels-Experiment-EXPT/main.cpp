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

}