#include <bits/stdc++.h>

using namespace std;

int main () {
    size_t N;
    cin >> N;

    int arr [N];

    for (size_t i = 0; i < N; i++) cin >> arr[i];
    sort (arr, arr + N, greater<int>());

    unsigned long long int ans = 0;
    for (size_t i = 0; i < N; i++) ans = max(ans, (long long int) arr[i] * (i + 1));

    cout << ans << endl;
}