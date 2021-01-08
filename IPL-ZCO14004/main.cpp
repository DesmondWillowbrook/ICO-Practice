#include <bits/stdc++.h>

using namespace std;

size_t N;

#ifdef DEBUG
void print_arr (int* arr, int n) {
    for (size_t i = 0; i < N; i++) cout << arr[i] << " ";
    cout << endl;
}
#endif

int max_fee (int* arr, int sol[][2], int n, bool consecutive) {
    if (n == 0) return arr[0];
    if (n < 0) return -INT_MAX;

    if (consecutive)
        if (sol[n][0] != -INT_MAX) return max_fee (arr, sol, n - 1, false) + arr[n];
        else return sol[n][0];
    else
        if (sol[n][1] != -INT_MAX) return max_fee (arr, sol, n - 1, false) + arr[n];
        else return sol[n][1];
}

int main () {
    cin >> N;
    int arr[N];
    int sol[N][2]; // one index for if we select prev, the other for if we don't.
    fill (&sol[0][0], &sol[0][0] + sizeof(sol), -INT_MAX);
    for (size_t i = 0; i < N; i++) cin >> arr[i];

    max_fee (arr, sol, N - 1, false);
    cout << max (max_fee(arr, sol, N - 1, false), max_fee(arr, sol, N - 2, false));
}