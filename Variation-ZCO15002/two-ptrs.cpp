#include<bits/stdc++.h>

using namespace std;

size_t N, K;

int main () {
    cin >> N >> K;
    uint a[N];
    for (size_t i = 0; i < N; i++) cin >> a[i];
    sort (a, a + N);

    auto start = a, end = a;
    size_t ans = 0;

    while (start != a + N) {
        if (*end >= *start + K) {ans += (N - (end - a)); start++;}
        else end++;
    }

    cout << ans << endl;
}