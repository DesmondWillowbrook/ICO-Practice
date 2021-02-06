#include<bits/stdc++.h>

using namespace std;

long int ans = -INT_MAX;

int main () {
    size_t N; cin >> N;
    long int w[N], p[N];
    for (size_t i = 0; i < N; i++) cin >> w[i];
    for (size_t i = 0; i < N; i++) cin >> p[i];

    long int wealth, manager;
    for (size_t i = 0; i < N; i++) {
        wealth = w[i];        
        for (manager = p[i];; manager = p[manager]) {
            #ifdef DEBUG
            printf ("Start: %ld, at: %ld\n", i, manager);
            #endif

            if (manager == -1) break;
            else manager--;

            ans = max (ans, w[manager] - wealth);
        }
    }

    cout << ans << endl;
}