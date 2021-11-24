#include<bits/stdc++.h>

using namespace std;

void read_arr (uint* a, size_t n) {
    while (n--) {
        cin >> a[n];
    }
}

uint get_sum (uint* a, size_t n) {
    uint ans = 0;
    while (n--) {
        ans += a[n];
    }
    return ans;
}

int main () {
    uint t, max_swaps;
    int ans;
    cin >> t;

    size_t n, m;

    while (t--) {
        cin >> n >> m;
        
        uint a[n], b[m];

        #ifdef DEBUG
        printf("n = %ld, m = %ld\n", n, m);
        #endif

        read_arr(a, n);
        read_arr(b, m);

        sort(a, a + n); //ascending
        sort(b, b + m, greater<uint>()); //descending
        // since we want to match smallest of a[] with largest of b[] & swap

        #ifdef DEBUG
        copy(a, a + n,
            ostream_iterator<int>(cout, " "));
        cout << endl;
        copy(b, b + m,
            ostream_iterator<int>(cout, " "));
        cout << endl;
        #endif

        ans = 0;

        max_swaps = min(n, m);
        for (uint i = 0; i < max_swaps && get_sum(a, n) < get_sum(b, m); i++) {
            if (a[i] >= b[i]) {
                ans = -1;
                break;
            }
            
            #ifdef DEBUG
            printf("Swapping %d with %d\n", a[i], b[i]);
            #endif

            swap(a[i], b[i]);
            ans++;
        }

        cout << ans << endl;
    }
}