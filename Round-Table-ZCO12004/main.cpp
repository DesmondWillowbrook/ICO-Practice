#include <bits/stdc++.h>

using namespace std;

size_t N;
uint dessert_cost [(size_t) 10e6];
uint min_cost_sol [(size_t) 10e6];
uint min_cost_sol_end [(size_t) 10e6];
bool dessert_given [(size_t) 10e6];

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

// minimum cost, when we feed person at n
uint min_cost_end (size_t n) {
    if (n == N - 1) return dessert_cost[N - 1];
    if (n > N - 1) return 0;

    if (min_cost_sol_end[n] != UINT_MAX) {
        return min_cost_sol_end[n];
    }
    #ifdef DEBUG
    printf ("Minimum cost of feeding %ldth knight: min(%d, %d) + %d\n", n, min_cost_end (n + 1), min_cost_end (n + 2), dessert_cost[n]);
    #endif
    min_cost_sol_end[n] = min(min_cost_end (n + 1), min_cost_end (n + 2)) + dessert_cost[n];
    return min_cost_sol_end[n];
}

int main () {
    cin >> N;
    fill_n (min_cost_sol, N, UINT_MAX);
    fill_n (min_cost_sol_end, N, UINT_MAX);

    for (uint i = 0; i < N; i++) {
        cin >> dessert_cost[i];
    }

    #ifdef DEBUG
    printf ("\n");
    #endif

    // It is guarenteed we are feeding 1st knight.
    cout << min(min_cost (N - 1), min_cost_end (0)) << endl;
}