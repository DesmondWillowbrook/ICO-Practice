#include <bits/stdc++.h>

using namespace std;

int main () {
    size_t N, M; scanf ("%ld %ld", &N, &M);
    priority_queue<uint> q;

    int curr;
    for (size_t i = 0; i < N + M; i++) {
        scanf ("%d", &curr);
        if (curr == -1) {printf("%d\n", q.top()); q.pop();}
        else q.push(curr);
    }
}