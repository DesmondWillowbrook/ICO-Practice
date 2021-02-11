#include <bits/stdc++.h>

using namespace std;

size_t N, M;
int dp[150010];

// modular exponentiation, req. to keep under limit
int mod_exp (int a, int b) {
    int ans = 1;
    for (int i = 0; i < b; i++) {
        ans = (ans % M) * (a % M);
    }
    return ans;
}

int pStr (int n) {
    if (dp[n - 1] != INT_MAX) return dp[n - 1];

    int ans = mod_exp (2, n);
    for (int i = 1; i <= n/2; i++)
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

    dp[0] = 2;
    fill_n (dp + 1, N, INT_MAX);

    cout << pStr(N) << endl;
}