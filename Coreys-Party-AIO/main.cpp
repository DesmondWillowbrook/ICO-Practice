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
    freopen ("partyin.txt", "r", stdin);
    freopen ("partyout.txt", "w", stdout);
    
    cin >> N >> M >> A >> B;

    set<uint> friendship[N] = {{0}};
    for (size_t i = 0; i < M; i++) {
        size_t x, y; cin >> x; cin >> y;
        x--; y--; // shift to zero-based indexing
        add_edge(friendship, x, y);
    }

    #ifdef DEBUG
    printf ("Finished taking input\n");
    #endif

    bool change; size_t friend_num = N;
    
    do {
        change = false;
        for (size_t i = 0; i < N; i++) {
            // if friend does not satisfy both conditions to be invited
            if (friendship[i].empty()) continue;

            // Not satisfy criteria for being invited
            if (!(friend_num - degree (friendship, i) >= B && degree (friendship, i) >= A)) {
                #ifdef DEBUG
                printf ("Removing friend %ld as they had %ld friends\n", i, degree (friendship, i));
                #endif

                change = true;
                remove_friend(friendship, i);
                friend_num--;
            }
        }
    } while (change != false);

    cout << friend_num << endl;
}