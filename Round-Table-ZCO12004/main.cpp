#include <bits/stdc++.h>

using namespace std;

size_t N;
uint dessert_cost [(size_t) 10e6];
uint min_cost_sol [(size_t) 10e6];

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

    min_cost (N - 1);

    cout << min_cost_sol[N - 1] << endl;
}