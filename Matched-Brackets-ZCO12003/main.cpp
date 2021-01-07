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

    int round_symbols = 0,
    max_round_symbols = 0;

    uint round_nesting_depth = 0;

    int square_symbols = 0,
    max_square_symbols = 0;

    uint square_nesting_depth = 0;

    uint alternating_depth = 0,
    max_alternating_depth = 0;

    uint prev = -1;
    while (cin >> n) {
        // increment number of symbols if operation is valid.
        if (round_symbols > 0) round_symbols++;
        if (square_symbols > 0) square_symbols++;

        // nesting depth logic (for symbol logic)
        if (n == 1) round_nesting_depth++;
        else if (n == 2) round_nesting_depth--;
        else if (n == 3) square_nesting_depth++;
        else if (n == 4) square_nesting_depth--;

        // validate/invalidate incrementing symbols
        // only start when top-level opening brace starts
        if (round_nesting_depth == 1 && n == 1) round_symbols = 1;
        else if (square_nesting_depth == 1 && n == 3) square_symbols = 1;
        // stop when top-level closing brace found
        else if (round_nesting_depth == 0 && n == 2) {
            max_round_symbols = max (max_round_symbols, round_symbols);
            round_symbols = 0;
        } else if (square_nesting_depth == 0 && n == 4) {
            max_square_symbols = max (max_square_symbols, square_symbols);
            square_symbols = 0;
        }

        // alternating depth logic
        if (prev != n) {
            if (n == 1 || n == 3) {
                alternating_depth++;
                max_alternating_depth = max (max_alternating_depth, alternating_depth);
            } else alternating_depth--;
            #ifdef DEBUG
            printf ("Updated alternating depth to: %d\n", alternating_depth);
            #endif
        }
        prev = n;
    }

    printf ("%d %d %d\n", max_alternating_depth, max_round_symbols, max_square_symbols);
}