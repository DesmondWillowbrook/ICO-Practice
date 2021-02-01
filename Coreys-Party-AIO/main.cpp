#include<bits/stdc++.h>

using namespace std;

size_t N, M, A, B;

bool is_edge (vector<uint>* arr, uint x, uint y) {
    for (size_t i = 0; i < arr[x].size(); i++) if (arr[x][i] == y) return true;
    return false;
}

void remove_friendship (vector<uint>* arr, uint x) {
    for (size_t i = 0; i < arr[x].size(); i++)
        for (size_t j = 0; j < arr[arr[x][j]].size(); j++) {
            if (arr[arr[x][i]][j] == arr[x][i]) {
                arr[arr[x][i]].erase(arr[arr[x][i]].begin() + j);
                break;
            }
        }
}

void add_edge (vector<uint>* arr, uint x, uint y) {
    arr[x].push_back(y); arr[y].push_back(x);
}

size_t degree (vector<uint>* arr, uint x) {
    return arr[x].size();
}

int main () {
    cin >> N >> M >> A >> B;
    
    vector<uint> friendship[N] = {{0}};
    for (size_t i = 0; i < M; i++) {
        size_t x, y; cin >> x; cin >> y;
        add_edge(friendship, x, y);
    }

    bool change;
    for (size_t i = 0; i < N; i++) {
        // if friend does not satisfy both conditions to be invited
        if (!(degree (friendship, i) <= B && degree (friendship, i) >= A)) {
            
        }
    }
}