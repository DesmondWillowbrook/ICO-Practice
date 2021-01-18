#include <bits/stdc++.h>

using namespace std;

size_t N;

int min_diff (pair<int, int>* arr, int* sol, size_t n) {
    if (sol[n] != INT_MAX) return sol[n];

    #ifdef DEBUG
    printf ("Min diff of pairs upto %ld: %d\n", n, min_diff (arr, sol, n - 1));
    #endif

    int curr_pair_diff = abs(arr[n].first - arr[n].second);
    sol[n] = min (abs (min_diff (arr, sol, n - 1) + curr_pair_diff),
                  abs (min_diff (arr, sol, n - 1) - curr_pair_diff));

    return sol[n];
}

int main () {
    cin >> N;
    pair<int, int> arr[N];
    for (size_t i = 0; i < N; i++) cin >> arr[i].first >> arr[i].second;

    int sol[N];
    sol[1] = abs(arr[0].first - arr[0].second);
    fill_n (sol + 2, N, INT_MAX);


    cout << min_diff(arr, sol, N - 1) << endl;
}