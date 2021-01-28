#include <bits/stdc++.h>

using namespace std;

int main () {
    size_t N;
    cin >> N;

    uint a[N], tmp1, tmp2;
    for (size_t i = 0; i < N; i++) {scanf ("%d %d", &tmp1, &tmp2); a[i] = min (tmp1, tmp2);}

    uint ans = 0;
    for (size_t i = 1; i <= N; i++) {
        if (a[i - 1] >= i) ans++;
    }

    cout << ans << endl;
}