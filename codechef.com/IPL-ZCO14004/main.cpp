#include <bits/stdc++.h>

using namespace std;

size_t N;

#ifdef DEBUG
void print_arr (int sol[][2]) {
    for (size_t i = 0; i < N; i++) {
        cout << "{ ";
        if (sol[i][0] != INT_MAX)
            cout << sol[i][0] << " ";
        else cout << "- ";

        if (sol[i][1] != INT_MAX)
            cout << sol[i][1] << " ";
        else cout << "- ";
        cout << "} ";
    }
    cout << endl;
}
#endif

// consec = 0 means previous not selected, consec = 1 means previous selected
int max_fee (int n, int* arr, int sol[][2], int consecutive) {
    if (n < 0) return 0;
    if (n == 0) return sol[0][consecutive] = arr[0];
    if (sol[n][consecutive] != INT_MAX) return sol[n][consecutive];

    #ifdef DEBUG
    printf ("Curr: %d\n", arr[n]);
    print_arr (sol);
    #endif

    if (consecutive == 0)
        return sol[n][consecutive] = max (max (max_fee (n - 2, arr, sol, 0), max_fee (n - 2, arr, sol, 1)), max_fee (n - 3, arr, sol, 1)) + arr[n];
    else
        return sol[n][consecutive] = max_fee (n - 1, arr, sol, 0) + arr[n];
}

int main () {
    cin >> N;
    int arr[N], sol[N][2];
    for (size_t i = 0; i < N; i++) {
        cin >> arr[i];

        sol[i][0] = INT_MAX; sol[i][1] = INT_MAX;
    }

    cout << max (max_fee (N - 2, arr, sol, 1), max(max_fee (N - 1, arr, sol, 0), max_fee (N - 1, arr, sol, 1))) << endl;
}