#include<bits/stdc++.h>

using namespace std;

uint comp (pair<uint, uint> a, pair<uint, uint> b) {
    /*
    Finds minimum overflow time and returns it, i.e. how much time will these two events in total take to finish.
    */
    return (a.first + a.second) < (b.first + b.second) ?
        (a.first + a.second) - b.second :
        (b.first + b.second) - a.first;
}

int main () {
    size_t N;
    cin >> N;
    
    size_t cobol = 0, end_task_time = 0;
    for (size_t i = 0, a, b, c; i < N; i++) {
        cin >> a >> b >> c;
        cobol += a;

        end_task_time = max (cobol + b + c, end_task_time);
    }

    cout << cobol + end_task_time << endl;
}