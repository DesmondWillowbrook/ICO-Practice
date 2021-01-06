#include <bits/stdc++.h>

using namespace std;

size_t N;
uint dessert_cost [(size_t) 10e6];
uint min_cost_sol [(size_t) 10e6];
bool dessert_given [(size_t) 10e6];

// Give dessert to nth knight or n + 1th knight?
void give_dessert_to (int n) {
    int first = n, second = n + 1;
    if (first == -1) {
        
    }
}

// minimum cost, when we feed person at n
uint min_cost (int n) {
    if (n == 0) return dessert_cost[0];
    if (n < 0) return 0;

    if (min_cost_sol[n] != UINT_MAX) {
        return min_cost_sol[n];
    }
    #ifdef DEBUG
    printf ("Minimum cost of feeding %dth knight: min(%d, %d) + %d\n", n, min_cost (n - 1), min_cost (n - 2), dessert_cost[n]);
    #endif
    min_cost_sol[n] = min(min_cost (n - 1), min_cost (n - 2)) + dessert_cost[n];
    return min_cost_sol[n];
}

int main () {
    cin >> N;
    fill_n (min_cost_sol, N, UINT_MAX);

    for (uint i = 0; i < N; i++) {
        cin >> dessert_cost[i];
    }

    #ifdef DEBUG
    printf ("\n");
    #endif

    // It is guarenteed we are feeding 1st knight.
    min_cost (N - 1);

    if (N > 1) cout << min(min_cost_sol[N - 1] - dessert_cost[0], min_cost_sol[N - 2]) << endl;
    else cout << min_cost_sol[N - 1] << endl;
}