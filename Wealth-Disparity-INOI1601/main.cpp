#include<bits/stdc++.h>

using namespace std;

long int ans = -INT_MAX,
w[(unsigned long) 10e5],
p[(unsigned long) 10e5],
max_ans[(unsigned long) 10e5];

size_t N;

long int maxAnscestor (long int id) {
    id--; // shift to zero-based

    if (max_ans[id] != -INT_MAX) return max_ans[id];
    if (p[id] == -1) return max_ans[id] = w[id];

    max_ans[id] = max (w[id], maxAnscestor(p[id]));

    #ifdef DEBUG
    printf ("Max ancestor of %ld is %ld\n", id + 1, max_ans[id]);
    #endif

    return max_ans[id];
}

int main () { cin >> N;
    fill_n (max_ans, N, -INT_MAX);

    for (size_t i = 0; i < N; i++) cin >> w[i];
    for (size_t i = 0; i < N; i++) cin >> p[i];

    for (size_t i = 1; i <= N; i++) ans = max (ans, maxAnscestor(i) - w[i - 1]);

    cout << ans << endl;
}