/*
You can assume that you will always be able to attend at least one contest–that is,
there will always be a contest such that there is a V wormhole before it and a W wormhole after it.
Means: We only need to find the minimum amount of time between opening of wormhole V and W.

Formula:
If you leave through a V wormhole at time t1 and come back through a W wormhole at time t2,
then the total time you have spent is (t2 - t1 + 1)

Strategy:
Sort times of V, W, for each time V, perform binary search on W (using something like lower_bound)
Find minimum.
Grofit.
*/

#include<bits/stdc++.h>

using namespace std;

#define forn(i, x, y) for (uint i = x; i < y; i++)

#ifdef DEBUG
void print_arr (uint* arr, size_t n) {
    for (uint i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
#endif

int main() {
    uint n, x, y;
    cin >> n >> x >> y;
    uint v[x + 1];
    uint w[y + 1];

    // so access to Last iterator returned by binary search
    // yields predictable result
    v[x] = UINT_MAX;
    w[y] = UINT_MAX;

    pair<uint, uint> contests[n];

    // read contest timings
    forn(i, 0, n) {
        cin >> contests[i].first >> contests[i].second;
    }

    forn(i, 0, x) {
        cin >> v[i];
    }
    sort(v, v + x);

    forn(i, 0, y) {
        cin >> w[i];
    }
    sort(w, w + y);

    #ifdef DEBUG
    cout << "Sorted v: ";
    print_arr(v, x);
    cout << "Sorted w: ";
    print_arr(w, y);
    #endif

    uint ans = INT_MAX;
    for (uint i = 0; i < n; i++) {
        // Find first wormhole opening greater than time of start of contest
        // assert! ("start - 1 will be most optimal value")

        auto start = lower_bound(v, v + x, contests[i].first);
        // incase val == contests[i].first was not found
        if (*start > contests[i].first) {start--;}
        if (!(*start <= contests[i].first)) {continue;}

        auto end = lower_bound(w, w + y, contests[i].second);
        if (end == w + y) {continue;}

        #ifdef DEBUG
        printf ("For contest (%d, %d): start & end times are: (%d, %d)\n", contests[i].first, contests[i].second, *start, *end);
        #endif
        ans = min(ans, *end - *start + 1);
    }
    cout << ans << endl;
}