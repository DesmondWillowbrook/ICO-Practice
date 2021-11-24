#include <bits/stdc++.h>

using namespace std;

#ifdef DEBUG
void visualise_brackets (int* brackets, size_t n) {
    for (uint i = 0; i < n; i++) {
        if (brackets[i] == 1) cout << "( ";
        else if (brackets[i] == 2) cout << ") ";
        else if (brackets[i] == 3) cout << "[ ";
        else if (brackets[i] == 4) cout << "] ";
    }
    cout << endl;
}
#endif

int main () {
    uint n;
    cin >> n;

    stack<int> brack;
    int in;
    while (cin >> in) {
        brack.push(in);
    }

    //printf ("%d %d %d\n", max_alternating_depth, max_round_symbols, max_square_symbols);
}