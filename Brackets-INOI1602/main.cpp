#include <bits/stdc++.h>

using namespace std;

size_t N, K;
long int V[700], max_sum[700][700]; uint B[700];

long int ans = -INT_MAX;

long int find_max_sum (long int start, long int end) {
    if (start >= end) return 0;
    if (max_sum[start][end] != -INT_MAX) return max_sum[start][end];

    #ifdef DEBUG
    printf ("Evaluating range (%ld, %ld)\n", start + 1, end + 1);
    #endif

    long int max_till_i = -INT_MAX;
    for (long int i = start + 1; i <= end; i++)
        if (B[start] + K == B[i]) {
            max_till_i = max(max_till_i, find_max_sum (start + 1, i - 1) + V[start] + V[i]);
            #ifdef DEBUG
            printf ("Match found at (%ld, %ld). Sum is: %ld: %ld (lbrac) + %ld (rbrac) + %ld (smaller range %ld, %ld)\n",
                start + 1, i + 1, find_max_sum (start + 1, i - 1) + V[start] + V[i],
                V[start], V[i], find_max_sum (start + 1, i - 1), start + 1 + 1, i - 1 + 1);
            #endif
        } else {
            max_till_i = max(max_till_i, max (find_max_sum (start + 1, i), find_max_sum (start, i - 1)));
        }

    max_sum[start][end] = max_till_i;
    return max_sum[start][end];
}

int main () {
    cin >> N >> K;
    for (size_t i = 0; i < N; i++) cin >> V[i];
    for (size_t i = 0; i < N; i++) cin >> B[i];

    for (size_t i = 0; i < N; i++)
        for (size_t j = i + 1; j < N; j++)
            max_sum[i][j] = -INT_MAX;

    for (size_t i = 0; i < N; i++)
            ans = max (ans, find_max_sum (i, N - 1));

    cout << ans << endl;
}