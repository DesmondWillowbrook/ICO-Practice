#include <bits/stdc++.h>

typedef long long int ll;
using namespace std;

ll N, K;

int main () {
    cin >> N >> K; N--; // shift to 0-based indexing
    ll C[K]; for (size_t i = 0; i < K; i++) cin >> C[i];

    ll lcm = 1; ll ans = N;
    for (size_t i = 0; i < K; i++) {
        ans -= (N / C[i]);
        // compensate for duplicate deletions
        for (size_t j = 0; j < i; j++) ans += (N / (C[i] * C[j]));
    }
    cout << ans << endl;
}