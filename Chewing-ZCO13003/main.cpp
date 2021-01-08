#include<bits/stdc++.h>

using namespace std;

#ifdef DEBUG
void print_arr_w_pointers (int* arr, size_t n, int* less, int* more) {
    for (size_t i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    for (size_t i = 0; i < n; i++) {
        if (arr + i == less || arr + i == more) cout << "^ ";
        else cout << "  ";
    }
    cout << endl;
}
#endif
int main() {
    size_t n;
    int k;
    cin >> n >> k;

    int arr[n];
    for (size_t i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort (arr, arr + n);

    long long unsigned int ans = 0;
    int* ptr; // for binary searching

    for (size_t i = 0; i < n && arr[i] < k; i++) {
        ptr = lower_bound (arr + i + 1, arr + n, k - arr[i]);
        ptr--; //get the value less than or equal to k - arr[i]
        #ifdef DEBUG
        print_arr_w_pointers(arr, n, arr + i, ptr);
        if (arr[i] + *ptr < k) cout << "Adding " << (ptr - arr) << endl;
        #endif
        // we only want value stricly less than k - arr[i]
        if (arr[i] + *ptr < k) ans += (ptr - arr - i);
    }

    cout << ans << endl;
}