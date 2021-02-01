#include<bits/stdc++.h>

using namespace std;

size_t N, M, A, B;

bool is_edge (set<uint>* arr, uint x, uint y) {
    return arr[x].find(y) == arr[x].end();
}

void remove_friend (set<uint>* arr, uint x) {
    for (size_t i = 0; i < arr[x].size(); i++)
        arr[i].erase(x);

    arr[x].clear();
}

void add_edge (set<uint>* arr, uint x, uint y) {
    arr[x].insert(y); arr[y].insert(x);
}

size_t degree (set<uint>* arr, uint x) {
    return arr[x].size();
}

int main () {
    cin >> N >> M >> A >> B;

    freopen ("partyin.txt", "r", stdin);
    freopen ("partyout.txt", "w", stdout);
    
    set<uint> friendship[N] = {{0}};
    for (size_t i = 0; i < M; i++) {
        size_t x, y; cin >> x; cin >> y;
        x--; y--; // shift to zero-based indexing
        add_edge(friendship, x, y);
    }

    bool change;
    do {
        change = false;
        for (size_t i = 0; i < N; i++) {
            // if friend does not satisfy both conditions to be invited
            if (!(degree (friendship, i) <= B && degree (friendship, i) >= A)) {
                change = true;
                remove_friend(friendship, i);
            }
        }
    } while (change != false);

    uint ans = 0;
    for (size_t i = 0; i < N; i++) ans += friendship[i].size();

    cout << ans << endl;
}