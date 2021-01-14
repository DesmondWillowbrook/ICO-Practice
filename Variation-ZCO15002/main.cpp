#include <bits/stdc++.h>

using namespace std;

size_t N, K;

int main () {
    cin >> N >> K;
    int a[N];

    for (size_t i = 0; i < N; i++) cin >> a[i];
    sort (a, a + N);

    size_t res = 0, ans = 0;
    for (size_t i = 0; i < N; i++) {
        res = lower_bound (a, a + N, a[i] + K) - a; //get index number
        #ifdef DEBUG
        if (res != N) printf ("Found least number >= %d + %ld: %d at index %ld\n", a[i], K, a[res], res);
        #endif
        if (res != N) ans += N - res;
    }

    cout << ans << endl;
}