#include<bits/stdc++.h>

using namespace std;

uint train (uint strength) {
    //find sum of digits
    uint digit_sum = 0;
    for(uint n = strength; n != 0; n /= 10) digit_sum += n % 10;

    return pow(digit_sum, 3);
}

long long int dp [5001][5001], str[5001], xp[5001];

long long int maxXP (long long int n, long long int s) {
    if (s > n || s < 0) return -LONG_LONG_MAX;
    if (dp[n][s] != -LONG_LONG_MAX) return dp[n][s];

    dp[n][s] =
        max (/*train pokemon*/ maxXP (n - 1, s - 1),
            /*BATTLE*/ maxXP (n - 1, s) + (xp[n] * str[s]));

    #ifdef DEBUG
    printf ("Calculating: (%lld cities, trained %lld times, i.e. str = %lld) = %lld\n", n, s, str[s], dp[n][s]);
    #endif

    return dp [n][s];
}

int main () {
    /*
    Sol 2:
    Assertion: MaxXP upto N cities when training in S cities is constant

    MaxXP (n, s) = max (MaxXP (n - 1, s - 1), MaxXP (n - 1, s) + STR[s] * XP[n]) if n > s
                   MaxXP (n - 1, s - 1) if n == s
    This is ok as training in any S cities will yield the same strength.
    So there is a unique answer for each MaxXP (n, s), which is dependant on previous answers.
    This is DP problem, then.
    */

    size_t N; cin >> N;
    
    cin >> str[0];
    for (size_t i = 1; i <= N; i++) str[i] = str[i - 1] + train(str[i - 1]);
    #ifdef DEBUG
    for (size_t i = 0; i <= N; i++) printf ("Str. after training in %ld cities: %lld\n", i, str[i]);
    #endif

    for (size_t i = 1; i <= N; i++) cin >> xp[i];
    for (size_t i = 1; i <= N; i++) for (size_t j = 0; j <= N; j++) dp[i][j] = -LONG_LONG_MAX;

    long long int ans = 0;
    for (size_t i = 0; i <= N; i++) ans = max (ans, maxXP(N, i));
    cout << ans << endl;
}