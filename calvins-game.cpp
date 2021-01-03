/// https://www.codechef.com/INOIPRAC/problems/INOI1301

#include<bits/stdc++.h>

using namespace std;

int main() {
    size_t n, k;
    cin >> n >> k;
    k--;

    int a[n] = {0};
    for (size_t i = 0; i < n; i++) {
        cin >> a[i];
    }

    int dp[n] = {0};
    dp[k] = 0;
    size_t pt_with_max_score = k;

    if (k + 1 < n) {
        dp[k + 1] = a[k + 1];

        for (size_t i = k + 2; i < n; i++) {
            dp[i] = max(dp[i - 1], dp[i - 2]) + a[i];
            if (dp[i] > dp[pt_with_max_score]) {
                pt_with_max_score = i;
            }
        }
    }

    dp[k] = a[k];
    for (size_t i = pt_with_max_score - 2; i >= 0; i++) {
        dp[i] = max(dp[i + 1], dp[i + 2]) + a[i];
    }


}