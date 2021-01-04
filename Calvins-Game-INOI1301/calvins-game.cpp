/// https://www.codechef.com/INOIPRAC/problems/INOI1301

#include<bits/stdc++.h>

using namespace std;

#ifdef DEBUG
void visualise_arr (int* arr, size_t n) {
    for (size_t i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
#endif

int dp[(size_t) 10e6 + 1];
int b_dp[(size_t) 10e6 + 1];
int arr[(size_t) 10e6 + 1];

uint n, k;


// k = 2, n = 4
// k = 2, n = 3 | k = 2, n = 2
// k = 2, n = 2 | k = 2, n = 1
int forward(int k, int n) { // k -> n
    if (k > n)
        return -INT_MAX;
    else if (k == n)
        return 0;

    // if dp[n] has already been calculated
    if (dp[n] != -INT_MAX)
        return dp[n];
    
    #ifdef DEBUG
    printf ("dp[%d] = max(forward(%d, %d) (%d), forward(%d, %d) (%d)) + arr[%d] (%d)\n", n, k, n - 1, forward(k, n - 1), k, n - 2, forward(k, n - 2), n, arr[n]);
    #endif

    return dp[n] = max(forward(k, n - 1), forward(k, n - 2)) + arr[n];
}

int backward(int end, int start) { // k -> n
    if (end < start)
        return -INT_MAX;
    if (end == start) {
        return 0;
    }

    // if dp[start] has already been calculated
    if (b_dp[start] != -INT_MAX)
        return b_dp[start];
    
    #ifdef DEBUG
    printf ("b_dp[%d] = max(%d, max(backward(%d, %d) (%d), backward(%d, %d) (%d))) + arr[%d] (%d)\n", start, b_dp[start], end, start + 1, backward(end, start + 1), end, start + 2, backward(end, start + 2), start, arr[start]);
    #endif

    return b_dp[start] = max(dp[start], max(backward(end, start + 1), backward(end, start + 2)) + arr[start]);
}

int main() {
    cin >> n >> k;
    k--;

    for (size_t i = 0; i < n; i++) {
        cin >> arr[i];
    }
    fill_n (dp, n, -INT_MAX);
    fill_n (b_dp, n, -INT_MAX);

    forward (k, n - 1);

    dp[k] = arr[k];

    #ifdef DEBUG
    visualise_arr (dp, n);
    #endif

    backward (n - 1, 0);

    #ifdef DEBUG
    visualise_arr (b_dp, n);
    #endif

    cout << b_dp[0] << endl;
}