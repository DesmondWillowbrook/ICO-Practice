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

int main() {
    size_t n, k;
    cin >> n >> k;

    int a[n + 4] = {0};
    for (size_t i = 2; i < n + 2; i++) {
        cin >> a[i];
    }

    k += 1; //get k to 2-based indexing ( 2 <= k <= n + 1)

    int sol[n + 4] = {0};

    for(size_t i = k + 1; i <= n + 1; i++) {
        sol[i] = max(sol[i - 1], sol[i - 2]) + a[i];
    }

    #ifdef DEBUG
    visualise_arr(sol, n + 4);
    #endif

    sol[k] = a[k];
    for (int i = n + 1; i > k; i--) {
        sol[i] = max(sol[i], max(sol[i + 1], sol[i + 2]) + a[i]);
    }

    #ifdef DEBUG
    visualise_arr(sol, n + 4);
    #endif

    for (int i = k; i >= 2; i--) {
        sol[i] = max(sol[i + 1], sol[i + 2]) + a[i];
    }

    #ifdef DEBUG
    visualise_arr(sol, n + 4);
    #endif

    cout << sol[2] << endl;
}