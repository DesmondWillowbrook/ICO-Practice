#include <bits/stdc++.h>

typedef long long unsigned int ll;
using namespace std;

size_t N, K; ll C[20]; long long int ans;

// find HCF of two numbers (or GCD, if you prefer)
ll hcf (ll a, ll b) {
    if (a < b) swap (a, b);

    ll r;
    while (b != 0) {
        r = a % b;
        a = b;
        b = r;
    }

    return a;
}

// finds LCM of two numbers
ll lcm (ll a, ll b) {
    return (a * b) / hcf (a, b);
}

// subseq_len is important to know we want to subtract or add
// by Inclusion-Exclusion principle

void solve (size_t len, size_t subseq_len, size_t curr_lcm) {
    if (len >= K) return;

    #ifdef DEBUG
    printf ("len: %ld, subseq_len: %ld, curr_lcm: %ld\n", len, subseq_len, curr_lcm);
    #endif

    if (subseq_len % 2 == 1) ans += N / lcm (curr_lcm, C[len]);
    else ans -= N / lcm (curr_lcm, C[len]);

    solve (len + 1, subseq_len, curr_lcm); // case where current num. is not chosen
    if (lcm (curr_lcm, C[len]) <= N) solve (len + 1, subseq_len + 1, lcm (curr_lcm, C[len]));
}

int main () {
    cin >> N >> K; N--; // shift to 0-based indexing
    for (size_t i = 0; i < K; i++) cin >> C[i];

    ans = N;
    solve(0, 0, 1);

    cout << ans << endl;
}