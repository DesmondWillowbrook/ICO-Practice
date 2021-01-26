#include<bits/stdc++.h>

using namespace std;

int main () {
    size_t N;
    cin >> N;

    vector<uint> v;
    v.reserve(N);

    uint curr;
    for (size_t i = 0; i < N; i++) {
        cin >> curr;
        auto pos = lower_bound(v.begin(), v.end(), curr);
        v.insert(pos, curr);
        // +1 to compensate for zero-based indexing
        // i - because our list is in ascending order while we need to give descending one
        cout << (i - (pos - v.begin()) + 1) << endl;
    }
}