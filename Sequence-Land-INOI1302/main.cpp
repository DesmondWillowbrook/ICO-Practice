#include <bits/stdc++.h>

using namespace std;

uint get_intersect_num (set<uint>& a, set<uint>& b) {
    auto a_it = a.begin(), b_it = b.begin();
    uint ans = 0;

    while (a_it != a.end() && b_it != b.end()) {
        if (*a_it == *b_it) {ans++; a_it++;}
        else if (*a_it < *b_it) a_it++;
        else if (*a_it > *b_it) b_it++;
    }

    return ans;
}

int main () {
    size_t N, K;
    cin >> N >> K;

    set<uint> s[N];
    set<uint> relative_set;

    for (size_t i = 0; i < N; i++) {
        size_t P; cin >> P;
        for (size_t j = 0; j < P; j++) {
            uint tmp; cin >> tmp;
            s[i].insert(tmp);
        }
    }

    set_union (relative_set.begin(), relative_set.end(),
                    s[0].begin(), s[0].end(), inserter(relative_set, relative_set.end()));

    bool change; uint ans = 1;
    do {
        change = false;
        for (size_t i = 1; i < N; i++) {
            if (s[i].empty()) continue;
            if (get_intersect_num(relative_set, s[i]) >= K) {
                change = true;
                set_union (relative_set.begin(), relative_set.end(),
                    s[i].begin(), s[i].end(), inserter(relative_set, relative_set.end()));
                s[i].clear();

                ans++;
            }
        }
    } while (change == true);

    cout << ans << endl;
}