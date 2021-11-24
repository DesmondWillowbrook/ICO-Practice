#include <bits/stdc++.h>

using namespace std;

size_t N;

#ifdef DEBUG
void print_arr (int* arr) {
    for (size_t i = 0; i < N; i++) cout << arr[i] << " ";
    cout << endl;
}
#endif

int min_supw (int* arr, int* sol, int n) {
    if (n < 0) return INT_MAX;
    else if (n < 3) {sol[n] = arr[n]; return arr[n];}

    if (sol[n] != INT_MAX) return sol[n];
    sol[n] = min(min_supw (arr, sol, n - 1), min(min_supw (arr, sol, n - 2), min_supw (arr, sol, n - 3))) + arr[n];
    
    #ifdef DEBUG
    print_arr(sol);
    #endif

    return sol[n];
}

int main () {
    cin >> N;
    int arr[N];
    for (size_t i = 0; i < N; i++) cin >> arr[i];
    int sol[N];
    fill_n (sol, N, INT_MAX);

    #ifdef DEBUG // so sol can be visualised properly
    sol[0] = arr[0];
    #endif

    cout << min (min_supw(arr, sol, N - 1), min(min_supw(arr, sol, N - 2), min_supw(arr, sol, N - 3))) << endl;
}