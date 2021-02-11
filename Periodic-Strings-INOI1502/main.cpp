// AMAZING!

#include <bits/stdc++.h>

using namespace std;

int main () {
    size_t N, M; cin >> N >> M;
    uint dp[N + 1];

    dp[1] = 2;
    for (size_t i = 2; i <= N; i++)
        dp[i] = (2 * dp[i - 1]) % M;

    for (size_t i = 1; i <= N/2; i++)
        for (size_t j = 2*i; j <= N; j += i /*iterates over all multiples of i*/)
            dp[j] = (dp[j] - dp[i] + M /*Adding M ensures no neg. values*/) % M;

    cout << dp[N] << endl;
}