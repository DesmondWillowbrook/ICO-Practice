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
    int n;
    cin >> n;

    stack<int> brack;

    int // this formatting is cursed - and I love it.
        max_round_span = 0, curr_round_span = 0,
        max_square_span = 0, curr_square_span = 0,
        curr_round_level = 0, curr_square_level = 0,
        curr_alternating_depth = 0, max_alternating_depth = 0;

    int in;
    while (cin >> in) {
        if (curr_round_level > 0) {curr_round_span++;}
        if (curr_square_level > 0) {curr_square_span++;}

        if (in == 1) {
            if (curr_alternating_depth == 0 || brack.top() == 3) {
                curr_alternating_depth++;
            }

            curr_round_level++;
            if (curr_round_level == 1) {
                curr_round_span = 1;
            }
        } else if (in == 2) {
            if (brack.top() == 4) {
                max_alternating_depth = max(max_alternating_depth, curr_alternating_depth);
                curr_alternating_depth--;
            }

            curr_round_level--;
            if (curr_round_level == 0) {
                max_round_span = max(max_round_span, curr_round_span);
                curr_round_span = 0;
            }
        }
        if (in == 3) {
            if (curr_alternating_depth == 0 || brack.top() == 1) {
                curr_alternating_depth++;
            }

            curr_square_level++;
            if (curr_square_level == 1) {
                curr_square_span = 1;
            }
        } else if (in == 4) {
            if (brack.top() == 2) {
                max_alternating_depth = max(max_alternating_depth, curr_alternating_depth);
                curr_alternating_depth--;
            }

            curr_square_level--;
            if (curr_square_level == 0) {
                max_square_span = max(max_square_span, curr_square_span);
                curr_square_span = 0;
            }
        }
        brack.push(in);

        #ifdef DEBUG
        // take a DEEP breath
        printf ("Curr token: %d\ncurr_round_span: %d\t\tcurr_square_span: %d\ncurr_round_level: %d\t\tcurr_square_level: %d\ncurr_alternating_depth: %d\n\n", 
        in, curr_round_span, curr_square_span, curr_round_level, curr_square_level, curr_alternating_depth);
        #endif
    }

    printf ("%d %d %d\n", max_alternating_depth, max_round_span, max_square_span);
}