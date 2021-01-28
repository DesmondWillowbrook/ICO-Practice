#include <bits/stdc++.h>

using namespace std;

int main () {
    size_t N;
    cin >> N;

    uint a[N], tmp1, tmp2;
    for (size_t i = 0; i < N; i++) {scanf ("%d %d", &tmp1, &tmp2); a[i] = min (tmp1, tmp2);}

    for (long int i = N; i >= 1; i--) {
        if (a[i - 1] < i) {cout << i - 1 << endl; break;}
    }
}