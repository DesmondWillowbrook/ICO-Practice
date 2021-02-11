#include <bits/stdc++.h>

using namespace std;

size_t N, M;
uint dp[150000];

// modular exponentiation, req. to keep under limit
uint mod_exp (uint a, uint b) {
    uint ans = 1;
    for (uint i = 0; i < b; i++) {
        ans = (ans % M) * (a % M);
    }
    return ans;
}

uint pStr (uint n) {
    if (dp[n - 1] != UINT_MAX) return dp[n - 1];

    uint ans = mod_exp (2, n);
    for (uint i = 1; i <= n/2; i++)
        if (n % i == 0) ans = (ans % M) - (pStr(i) % M);
        
    ans %= M;

    #ifdef DEBUG
    printf ("Evaluating pStr(%d): %d\n", n, ans);
    #endif

    dp[n - 1] = ans;
    return dp[n - 1];
}

int main () {
    cin >> N >> M;
    fill_n (dp, N, UINT_MAX);
    cout << pStr(N) << endl;
}