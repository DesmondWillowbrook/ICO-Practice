#include <bits/stdc++.h>

using namespace std;

int n, b, min_s, max_s;
int arr[(size_t) (10e3 + 1)];

int max_score(size_t n) {
    if (n == 0) {
        return arr[0];
    }

    int prev = max_score (n - 1);

    int ans = -1;
    #ifdef DEBUG
    printf ("Considering upto %ld\n", n);
    #endif
    // if prev + arr[n] is valid
    if (prev + arr[n] >= min_s && prev + arr[n] <= max_s) {
        #ifdef DEBUG 
        printf ("Possible ans: %d\n", prev + arr[n]);
        #endif
        ans = max(ans, prev + arr[n]);
    }
    // if prev - arr[n] is valid
    if (prev - arr[n] >= min_s && prev - arr[n] <= max_s) {
        #ifdef DEBUG 
        printf ("Possible ans: %d\n", prev - arr[n]);
        #endif
        ans = max(ans, prev - arr[n]);
    }

    return ans;
}

int main () {
    cin >> n >> b >> min_s >> max_s;
    arr[0] = b;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    cout << max_score(n) << endl;
}