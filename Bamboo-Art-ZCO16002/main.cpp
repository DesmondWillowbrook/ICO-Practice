#include<bits/stdc++.h>

using namespace std;

size_t N;

#ifdef DEBUG
void vis_arr (uint* arr, vector<size_t>& pts) {
    for (size_t i = 0; i < N; i++) cout << arr[i] << " ";
    cout << endl;

    for (size_t i = 0, ind = 0; i < N && ind < pts.size(); i++) {
        if (i == pts[ind]) {
            cout << "| "; ind++;
        } else cout << "  ";
        
        for (size_t i = 0; i < log10(arr[i]) - 1; i++) cout << " ";
    }
    cout << endl;
}
#endif

int main () {
    cin >> N;
    uint a[N];
    for (size_t i = 0; i < N; i++) cin >> a[i];
    sort(a, a + N);

    size_t ans = 0;

    for (size_t i = 0; i < N; i++) {
        for (size_t j = i + 1; j < N; j++) {
            int diff = a[j] - a[i]; size_t count = 2;
#ifdef DEBUG
            printf ("Evaluating next AP term of: a1 = %d, a2 = %d\n", a[i], a[j]);
            vector<size_t> pts {i, j};
#endif
            for (uint* next = a + j, *prev; next != a + N; count++) {
                prev = next;
                next = lower_bound (next + 1, a + N, *next + diff);
                if (*next != *prev + diff) break;
#ifdef DEBUG
                pts.push_back((size_t) (next - a));
                vis_arr(a, pts);
#endif
            }
#ifdef DEBUG
            pts.clear();
#endif
            ans = max (count, ans);
        }
    }
    cout << ans << endl;
}