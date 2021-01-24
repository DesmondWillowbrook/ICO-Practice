//TODO: Fix this problem

#include <bits/stdc++.h>

using namespace std;

size_t N, K;

size_t solve (vector<uint>& a, vector<uint>& b, size_t k) {
    priority_queue<uint> A, B;
    for (auto ele: a) A.push (ele);
    for (auto ele: b) B.push (-ele); // serves as min-heap

    for (; k != 0; k--) {
        // here b contains the biggest book, so we swap
        // smaller books from that shelf 
        // and big books from book shelf A
        // so eventually Big books are in B
        // and Small books are in A

        if (A.top() < -B.top()) break;
        // if biggest book of A is smaller than smallest book of B
        // then we have already achieved ideal position.

        #ifdef DEBUG
        printf ("Swapping: %d, %d\n", A.top(), -B.top());
        #endif

        int swp_a = A.top(); A.pop();
        int swp_b = B.top(); B.pop();
        A.push (-swp_b); B.push (-swp_a);
    }
    while (B.size() > 1) B.pop(); // to find greatest element in B

    #ifdef DEBUG
    cout << endl; // add distinction btw. different function runs.
    #endif

    return A.top() + (-B.top());
}

int main () {
    cin >> N >> K;
    vector<uint> a, b;

    uint in;
    for (size_t i = 0; i < N; i++) {cin >> in; a.push_back(in);}
    for (size_t i = 0; i < N; i++) {cin >> in; b.push_back(in);}

    // we want to dump taller textbooks in one shelf,
    // smaller in other.
    // Largest textbook is ALWAYS part of skew.
    // What we can do is replace largest textbook in other shelf with smaller one
    // so skew drops.

    cout << min(solve(a, b, K), solve(b, a, K)) << endl;
}