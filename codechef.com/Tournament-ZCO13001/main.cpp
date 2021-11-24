#include <bits/stdc++.h>

using namespace std;

int main () {
    int N;
    cin >> N;

    int a[N];
    
    for (uint i = 0; i < N; i++) {
        cin >> a[i];
    }
    sort(a, a + N);

    unsigned long long int ans = 0;
    unsigned long long int sum = a[0];
    for (uint i = 1; i < N; i++) {
        ans += (i * a[i]) - sum;
        sum += a[i];
    }

    cout << ans << endl;
}