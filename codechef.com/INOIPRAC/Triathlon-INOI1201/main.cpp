#include <bits/stdc++.h>

using namespace std;

int main () {
    size_t N;
    cin >> N;

    uint ans;

    /*
    O (N) sol.:
    Ordering of tasks is done to minimize
    time taken to perform b + c tasks in the end.
    I.e. ans = COBOL_tasks + Min_overflow_b_c_tasks

    Observation:
        We want shortest task last.
    */

    uint min_end_trail = UINT_MAX, largest_task_end = 0;
    for (size_t i = 0; i < N; i++) {
        uint cobol, b, c; cin >> cobol >> b >> c;
        ans += cobol;
        min_end_trail = min (min_end_trail, b + c);

        // case where last citizen is NOT the citizen which finishes last
        // i.e. case where b+c tasks of previous citizen goes on after the last citizen
        largest_task_end = max (largest_task_end, cobol + b + c);
    }

    ans = max (ans + min_end_trail, largest_task_end);
    cout << ans << endl;
}