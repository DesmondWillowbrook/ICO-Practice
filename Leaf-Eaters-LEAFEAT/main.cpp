#include <bits/stdc++.h>

typedef long long int ll;
using namespace std;

ll N, K, C[20], ans;
bool used[20]; // for building a rep-free subseq.

// find HCF of two numbers (or GCD, if you prefer)
ll hcf (ll a, ll b) {
    if (a < b) swap (a, b);

    while (b != 0) {
        ll tmp_b = b;
        b = a % b;
        a = tmp_b;
    }

    return a;
}

// finds LCM of two numbers
ll lcm (ll a, ll b) {
    return (a * b) / hcf (a, b);
}

// subseq_len is important to know we want to subtract or add
// by Inclusion-Exclusion principle

ll solve (size_t len, size_t subseq_len) {
    if (subseq_len > len || len > N) return 0;

    
}

int main () {
    cin >> N >> K; N--; // shift to 0-based indexing
    for (size_t i = 0; i < K; i++) cin >> C[i];

    ans = N;

    for (size_t i = 1; i <= K; i++) {
        if (i % 2 == 1) ; 
        else ;
    }

    cout << ans << endl;
}