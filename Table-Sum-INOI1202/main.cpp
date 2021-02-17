#include<bits/stdc++.h>

using namespace std;

size_t N;

int main () {
    cin >> N;
    multiset<uint> nums; uint a[N];

    for (size_t i = 0; i < N; i++) {
        cin >> a[i]; a[i] += i + 1;
        nums.insert(a[i]);
    }

    for (size_t i = 0; i < N; i++) {
        cout << *nums.rbegin() + i << " ";

        // update Nth number which has fallen off
        int n = N - 1 - i;

        #ifdef DEBUG
        printf ("For iteration %ld, falloff number is: [%d]\n", i + 1, n);
        #endif

        nums.erase (nums.find(a[n]));
        a[n] -= n; // revert to a[n] + 1
        nums.insert (a[n]);
    }
    cout << endl;
}