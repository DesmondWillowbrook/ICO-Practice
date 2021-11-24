#include<bits/stdc++.h>

using namespace std;

size_t N;
unsigned long int T;
unsigned long long int ans = 0;

int main() {
    cin >> N >> T;
    unsigned long int arr[N];
    for (size_t i = 0; i < N; i++) cin >> arr[i];
    vector<unsigned long int> freq_of_ind (T, 0);

    for (size_t i = 0; i < N; i++) {
        for (size_t j = i + 1; j < N; j++) {
            if (arr[i] + arr[j] < T - 1) ans += freq_of_ind[T - (arr[i] + arr[j])];
            #ifdef DEBUG
            if (arr[i] + arr[j] < T - 1 && freq_of_ind[T - (arr[i] + arr[j])] > 0) {
                printf ("Searching to complete (%ld, %ld) = %ld\n", arr[i], arr[j], arr[i] + arr[j]);
                printf ("Ans (%lld) += %ld [%ld]\n", ans, freq_of_ind[T - (arr[i] + arr[j])], T - (arr[i] + arr[j]));
            }
            #endif
        }
        
        for (size_t k = 0; k < i; k++) {
            // update pairs data
            if (arr[i] + arr[k] < T - 1) freq_of_ind[arr[i] + arr[k]]++;
        }

        #ifdef DEBUG
        size_t _index_ = 0;
        while (freq_of_ind[_index_] == 0 && _index_ < T) _index_++;
        cout << "Updated pairs: (" << arr[i] << ", x)" << endl;
        for (; _index_ < T; _index_++)
            printf ("%ld: %ld, ", _index_, freq_of_ind[_index_]);
        cout << endl;
        #endif
    }

    cout << ans << endl;
}