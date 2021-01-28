/// https://www.codechef.com/INOIPRAC/problems/INOI1902

#include <bits/stdc++.h>

using namespace std;

pair<uint, uint> a[3001];

uint max_cost(uint* a, uint n) {

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

            So we can use Binary search!
        */ 
    }
}