/*
Strategy:
Sort ranges by start then end
From first range, iterate until end of intersection and then increment answer

We iterate through the sorted bounds
We keep going through the bounds until
the bound in which we need to place an element to satisfy ALL we have iterated through
is no longer able to accomodate the next element.
Then we know we MUST place a number there, so we increment ans by one,
and then satisfy the next bounds.
*/

#include<bits/stdc++.h>

using namespace std;

size_t N;

#ifdef DEBUG
void print_arr (pair<uint, uint>* arr, pair<uint, uint> bounds) {
    printf ("bounds: (%d, %d)\n", bounds.first, bounds.second);
    for (size_t i = 0; i < N; i++) {
        printf ("(%d, %d)\n", arr[i].first, arr[i].second);
    }
}
#endif

int main () {
    cin >> N;
    pair<uint, uint> a[N];
    for (size_t i = 0; i < N; i++) cin >> a[i].first >> a[i].second;

    sort (a, a + N);

    /*
    By sorting, entries will be sorted start-wise, and within that, end-wise =>
    (1, 3), (1, 4), (2, 1), ...
    */

    pair<uint, uint> bounds = a[0];
    uint ans = 1;

    for (size_t i = 0; i < N; i++) {
        #ifdef DEBUG
        print_arr (a, bounds);
        #endif

        // check if current element is out of range of bounds
        // if so, then our intersection has ended.
        if (bounds.second < a[i].first) {bounds = a[i]; ans++; continue;}

        // if we get: (1, 3), (2, 4), then bounds should be: (2, 3)
        bounds.first = max (bounds.first, a[i].first);
        bounds.second = min (bounds.second, a[i].second);
    }
    cout << ans << endl;
}