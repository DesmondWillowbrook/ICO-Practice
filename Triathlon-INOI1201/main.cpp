#include<bits/stdc++.h>

using namespace std;

int main () {
    size_t N;
    cin >> N;

    // we store time for the two events
    // in the first, so we don't need to write cmp function
    pair<uint, uint> a[N];
    for (size_t i = 0; i < N; i++) {
        uint temp;
        cin >> a[i].second >> a[i].first >> temp;
        a[i].first += temp;
    }

    sort (a, a + N, greater<pair<uint, uint>>());
    uint cobol_time = 0, end_task_trail_time = 0;
    for (size_t i = 0; i < N; i++) {
        cobol_time += a[i].second;
        end_task_trail_time = max (cobol_time, cobol_time + a[i].first);
    }

    cout << end_task_trail_time << endl;
}