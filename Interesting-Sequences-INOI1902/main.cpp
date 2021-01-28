/// https://www.codechef.com/INOIPRAC/problems/INOI1902

#include <bits/stdc++.h>

using namespace std;

pair<uint, uint> a[3001];

// Checks if subseq. of length L is possible
// with given cost.
bool assert_lsc (size_t n, uint l, uint cost) {
    uint dp[n]; //DP[i] defined as max. length of subsequence when it ends at index i.
    dp[0] = 1;


    for (size_t i = 0; i < n; i++) {
        for (size_t j = 0; j < i; j++) {
            if (abs ( (int) a[i].second - (int) a[j].second) >= cost) {
                dp[i] = max(dp[i], 1 + dp[j]);
                if (dp[i] >= l) return true;
            }
        }
    }

    return false;
}

int main () {
    uint t;
    cin >> t;

    uint n;
    uint l;

    while (t--) {
        cin >> n >> l;
        for (size_t i = 0; i < n; i++) {cin >> a[i].first; a[i].second = i;}

        // sort in descending order
        sort (a, a + n, greater<pair<uint, uint>>());
        /* now any subsequence of P is interesing
            Next is to find highest Cost arr.
            Here Cost => min (diff. of index of adj. elements (a[i].second))

            Here comes very clever part:
            When given a cost, it is very easy (Longest Subsequence with conditions problem)
            to figure out if there is sequence with the given cost.

            We can also see that this function is Monotonic, i.e. after False for Cost A,
            it WILL give False for Cost A + 1, and so on...

            So we can use Binary search to find the highest Cost that is possible!

            Handling non-equality cases:
        */

        uint lo = 0, hi = l, mid;
        while (lo < hi) {
            mid = lo + ((hi - lo) / 2);
            if (assert_lsc(n, l, mid))
                lo = mid + 1;
            else
                hi = mid - 1;
        }

        cout << lo << endl;
    }
}