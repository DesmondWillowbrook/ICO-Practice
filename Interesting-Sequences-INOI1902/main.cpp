/// https://www.codechef.com/INOIPRAC/problems/INOI1902

#include <bits/stdc++.h>

using namespace std;

pair<uint, uint> a[3001];

// Checks if subseq. of length L is possible
// with given cost.
bool assert_lsc (size_t n, uint l, uint cost) {
    uint dp[n]; //DP[i] defined as max. length of subsequence when it ends at index i.
    fill_n(dp, n, 1);

    for (size_t i = 0; i < n; i++) {
        for (size_t j = 0; j < i; j++) {
            if (abs ( (int) a[i].second - (int) a[j].second) >= cost) {
                dp[i] = max(dp[i], 1 + dp[j]);
                #ifdef DEBUG
                if (dp[i] >= l) {
                    for (size_t k = 0; k < n; k++) cout << dp[k] << " ";
                    cout << endl;
                }
                #endif
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

        uint lo = 0, hi = n - 1, mid;

        // handling non-distinct elements
        /*
        Here, if we have two equal elements,
        then best case where we have to use duplicates is:
        A1, A2, A1, A2, ...
        */
        for (size_t i = 1; i < n; i++) {
            if (a[i].first == a[i - 1].first)
                lo = max ((int) lo, abs ((int) a[i].second - (int) a[i - 1].second));
        }

        while (lo < hi) {
            mid = (hi + lo + 1) / 2;

            if (assert_lsc(n, l, mid))
                lo = mid;
            else
                hi = mid - 1;

            #ifdef DEBUG
            printf ("Checking %d: It is %d\n", mid, assert_lsc(n, l, mid));
            #endif
        }

        cout << lo << endl;
    }
}