#include<bits/stdc++.h>

using namespace std;

int main() {
    uint t;
    cin >> t;

    uint n, k, d, ans = 0;
    uint tmp;

    while (t--) {
        ans = 0;
        cin >> n >> k >> d;

        while (n--) {
            cin >> tmp;
            ans += tmp;
        }
        ans /= k;

        if (ans > d) {
            ans = d;
        }
        cout << ans << endl;
    }
}