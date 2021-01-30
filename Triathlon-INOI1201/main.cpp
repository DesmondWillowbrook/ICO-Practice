#include<bits/stdc++.h>

using namespace std;

int main () {
    size_t N;
    cin >> N;
    
    size_t cobol = 1; long int end_task_time = 0;
    for (size_t i = 0, a, b, c; i < N; i++) {
        cin >> a >> b >> c;
        cobol += a;

        end_task_time += b + c;
        end_task_time -= a;
    }

    cout << cobol + end_task_time << endl;
}