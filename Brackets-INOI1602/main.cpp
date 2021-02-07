#include <bits/stdc++.h>

using namespace std;

size_t N, K;
long int V[710]; long long int max_sum[710][710]; uint B[710];

long long int ans = LONG_LONG_MIN;

long long int find_max_sum (long int start, long int end) {
    if (start >= end) return 0;
    if (max_sum[start][end] != LONG_LONG_MIN) return max_sum[start][end];

    #ifdef DEBUG
    printf ("Evaluating range (%ld, %ld)\n", start + 1, end + 1);
    #endif

    long long int max_till_end = LONG_LONG_MIN;

    for (long int i = start; i <= end; i++) {
        if (B[start] + K == B[i])
            max_till_end = max(max_till_end, find_max_sum (start + 1, i - 1) + find_max_sum (i + 1, end) + V[start] + V[i]);
    }
    max_till_end = max(max_till_end, find_max_sum (start + 1, end));

    max_sum[start][end] = max_till_end;
    return max_sum[start][end];
}

int main () {
    cin >> N >> K;
    for (size_t i = 0; i < N; i++) cin >> V[i];
    for (size_t i = 0; i < N; i++) cin >> B[i];

    for (size_t i = 0; i < N; i++)
        for (size_t j = i + 1; j < N; j++)
            max_sum[i][j] = LONG_LONG_MIN;

    ans = max (ans, find_max_sum (0, N - 1));

    cout << ans << endl;
}