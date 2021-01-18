#include <bits/stdc++.h>

using namespace std;

int main () {
    size_t N; cin >> N;
    int arr[N], in1, in2;

    for (size_t i = 0; i < N; i++) {
        cin >> in1 >> in2;
        arr[i] = abs (in1 - in2);
    }

    set<int> diffs ({0}), new_diffs;
    for (size_t i = 0; i < N; i++) {
        for (const int& diff: diffs) {
            new_diffs.insert (abs(diff - arr[i]));
            new_diffs.insert (abs(diff + arr[i]));
        }
        swap(diffs, new_diffs);
        new_diffs.clear();
    }

    cout << *diffs.begin() << endl;
}