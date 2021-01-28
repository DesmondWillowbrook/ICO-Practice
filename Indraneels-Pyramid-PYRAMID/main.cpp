#include <bits/stdc++.h>

using namespace std;

int main () {
    size_t N;
    cin >> N;

    uint a[N], tmp1, tmp2;
    for (size_t i = 0; i < N; i++) {scanf ("%d %d", &tmp1, &tmp2); a[i] = min (tmp1, tmp2);}

    sort (a, a + N);

    uint ans = 1;
    for (size_t i = 0; i < N; i++) {
        if (a[i] >= ans) {
            #ifdef DEBUG
            printf ("a[%ld] (%d) >= %d\n", i, a[i], ans);
            #endif
            ans++;
        }
    }

    // -1 to account for over-count in last iteration of loop
    cout << ans - 1 << endl;
}