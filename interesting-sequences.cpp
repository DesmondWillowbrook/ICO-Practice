/// https://www.codechef.com/INOIPRAC/problems/INOI1902

#include <bits/stdc++.h>

using namespace std;

uint max_cost(uint* a, uint n) {

}

int main () {
    uint t;
    cin >> t;

    uint n;
    uint l;

    while (t--) {
        cin >> n >> l;
        uint a[n];
        for (size_t i = 0; i < n; i++) {
            cin >> a[i];
        }

        if (l > n) { // If size wanted is more than that of array, we will have to repeat elements, thus min. cost will be zero.
            cout << 0 << endl;
            continue;
        }
    }
}