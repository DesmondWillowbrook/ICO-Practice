#include <bits/stdc++.h>

using namespace std;

size_t N, K;

size_t solve (vector<uint>& a, vector<uint>& b, size_t k) {
    priority_queue<uint> A, B;
    for (auto ele: a) A.push (ele);
    for (auto ele: b) B.push (-ele); // serves as min-heap

    for (; k != 0; k--) {
        if (A.top() > -B.top()) break;
        int swp_a = A.top(); A.pop();
        int swp_b = B.top(); B.pop();
        A.push (-swp_b); B.push (-swp_a);
    }
    while (B.size() > 1) B.pop(); // to find greatest element in B
    return A.top() + (-B.top());
}

int main () {
    cin >> N >> K;
    vector<uint> a, b;

    #ifdef DEBUG
    cout << "HEARTBEAT 0" << endl;
    #endif

    uint in;
    for (size_t i = 0; i < N; i++) {cin >> in; a.push_back(in);}
    for (size_t i = 0; i < N; i++) {cin >> in; b.push_back(in);}

    #ifdef DEBUG
    cout << "HEARTBEAT 1" << endl;
    #endif

    // we want to dump taller textbooks in one shelf,
    // smaller in other.
    // the more even distrib. we achieve, the less is Skew.
    // Largest textbook is ALWAYS part of skew.
    // What we can do is replace largest textbook in other shelf with smaller

    cout << min(solve(a, b, K), solve(b, a, K)) << endl;
}