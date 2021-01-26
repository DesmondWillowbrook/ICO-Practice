#include<bits/stdc++.h>

using namespace std;

uint get_end (pair<uint, uint> a) {
    return a.first + a.second;
}

bool cmp (pair<uint, uint> a, pair<uint, uint> b) {
    return get_end(a) < get_end(b);
}

int main () {
    size_t N; cin >> N;

    pair<uint, uint> events[N];
    for (size_t i = 0; i < N; i++) cin >> events[i].first >> events[i].second;
    sort (events, events + N, cmp);

    /*
    Greedy: select events with shortest ending times
    Also check for overlaps
    */

    uint ans = 0; long int prev_end = -1;
    for (size_t i = 0; i < N; i++) {
        if (prev_end + 1 < events[i].first) {
            prev_end = get_end(events[i]);
            ans++;
        }
    }
    cout << ans << endl;
}